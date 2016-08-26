#include <SDKDDKVer.h>
#include "CAceHttpClient.h"
#include "CDeleteMapWatch.h"

typedef struct Threadpackage{
	CAceHttpClient* pThis;
	ACE_SOCK_Stream* ppeer;
	int RecvMaxLength;
	CMutex* pmutex;
	BOOL DataStyle;
	ACE_INET_Addr* paddr;
	ACE_Time_Value* ptimeout;
	int CheckKeyClient;
	char* pBuf;
	CString strProtocol;
}Threadpackage;

CAceHttpClient::~CAceHttpClient(){
	delete paddr;
	delete pconnector;
	delete ptimeout;
}

void CAceHttpClient::init(CString strIP,int port,int ConnectWaitTime,int RecvMaxLength,int DataStyle){
	paddr = new ACE_INET_Addr(port,strIP);
	pconnector = new ACE_SOCK_Connector;
	ptimeout = new ACE_Time_Value(ConnectWaitTime,0);
	this->strIP           = strIP        ;
	this->port            = port         ;
	this->RecvMaxLength   = RecvMaxLength;
	this->DataStyle       = DataStyle    ;
	CheckKeyClient        = 0            ;
	return;
}

DWORD WINAPI ThreadRecvHandling(LPVOID lpParam){
	Threadpackage package = *((Threadpackage *)lpParam);
	delete (Threadpackage *)lpParam;

	package.pmutex->Lock();
	//�ж���������
	if(package.DataStyle == 1){
		CHttpString str;
		str.str = package.pBuf;
		//���յ��ķ�����Ϣ�����麯��
		package.pThis->ReceiveRspJson(str.GetJsonData(),package.strProtocol,package.pThis->mapCheck[package.CheckKeyClient],str);
		//ɾ��map�еļĴ����
		package.pThis->DeleteMap(package.CheckKeyClient);
	}
	package.pmutex->Unlock();

	free(package.pBuf);
	return 0;
}

DWORD WINAPI ThreadRecv(LPVOID lpParam){
	Threadpackage package = *((Threadpackage *)lpParam);
	delete (Threadpackage *)lpParam;

	char* pbuf = (char *)calloc(package.RecvMaxLength,1);
	//����
	int RecvLength = package.ppeer->recv(pbuf,package.RecvMaxLength); //��������
	//��ֵ�Ŵ���
	if(RecvLength >= 0){
		pbuf[RecvLength] = 0;

		DWORD ThreadID = 0;
		package.pBuf = (char *)calloc(RecvLength + 1,1);
		memcpy(package.pBuf,pbuf,RecvLength);
		Threadpackage *ppackage = new Threadpackage;
		*ppackage = package;
		Create_Thread(ThreadRecvHandling,ppackage,ThreadID);

		
	}
	//ʹ��֮���ͷţ��ڶ�ʱ�����ͷ�
	//delete package.ppeer;
	free(pbuf);
	return 0;
}

int CAceHttpClient::SendJsonReq(Cjson jsonReq,CString strProtocol,Cjson jsonCheckPackage,int nDeleteTime,int sendTimes){
	if(DataStyle != 1){
		AfxMessageBox("��ǰ����jsonģʽ");
		return 0;
	}

	//����Կ�װѰ�������map��
	mapCheck[++CheckKeyClient] = jsonCheckPackage;

	WatchPac* pWatchPackage = new WatchPac;
	pWatchPackage->CheckKeyClient = CheckKeyClient;
	pWatchPackage->pThis = this;
	pWatchPackage->ppeer = ppeer;
	pWatchPackage->pifPeerExist = &ifPeerExist;
	
	//���û��ͨ·
	if(ifPeerExist != 1){
		//����һ��ͨ·
		ppeer = new ACE_SOCK_Stream;
		ifPeerExist = 1;
		pWatchPackage->ppeer = ppeer;
		//����
		int nResult = pconnector->connect(*ppeer,*paddr,ptimeout);
		if(nResult != 0){
			AfxMessageBox("����ʧ��");
			return -1;
		}
	}
	//��ʱ������
	else{
		Watch.CountDown(nDeleteTime * 1000,pWatchPackage);
	}
	
	//����
	CHttpString strSendString;
	strSendString.InitClient(strIP,port);
	strSendString.ProtocolStyle(strProtocol,1);
	strSendString.SetJson(jsonReq);
	int nResult = ppeer->send((LPSTR)(LPCTSTR)strSendString.str,strSendString.str.GetLength()); //��������

	//�̲߳���
	Threadpackage *ppackage = new Threadpackage;
	ppackage->pmutex = &mutex;
	ppackage->ppeer = ppeer;
	ppackage->pThis = this;
	ppackage->RecvMaxLength = RecvMaxLength;
	ppackage->DataStyle = DataStyle;
	ppackage->paddr = paddr;
	ppackage->ptimeout = ptimeout;
	ppackage->CheckKeyClient = CheckKeyClient;
	ppackage->strProtocol = strProtocol;
	//�����̣߳����ں�̨���շ���������������
	DWORD ThreadID = 0;
	Create_Thread(ThreadRecv,ppackage,ThreadID);

	//��ʱ������һ��ʱ��֮��Ѷ�Ӧ�İ���ɾ������ֹ������Ϊ���粻�ö��治����Ϣ�����
	Watch.CountDown(nDeleteTime * 1000,pWatchPackage);
	return nResult;
}

void CAceHttpClient::DeleteMap(int CheckKeyClient){
	mutexDeleteMap.Lock();
	auto it = mapCheck.begin();
	for(;it != mapCheck.end();++it){
		if(it->first == CheckKeyClient){
			mapCheck.erase(it);
			return;
		}
	}
	mutexDeleteMap.Unlock();
	//���ܻ�����Ҳ�����������������˻ظ����Ⱥ���Ļ�
	return;
}
/*
class CClient : public CAceHttpClient{
	void ReceiveRspJson(Cjson jsonRsp,CString strProtocol,Cjson jsonCheckPackage,CHttpString str){
		if(strProtocol == "/TCWeb/httpweb/getRoomList.do"){
			AfxMessageBox(jsonRsp.toCString());
			int x = jsonRsp["result"].size();
			AfxMessageBox(jsonCheckPackage.toCString());
		}
		return;
	}
};

int main(int argc,char* argv[]){
	CClient client;
	client.init("192.168.1.46",8280,3,10240);
	Cjson jsonpackage;
	jsonpackage["2"] = 2;
	client.SendJsonReq(Cjson(),"/TCWeb/httpweb/getRoomList.do",jsonpackage);
	getchar();
	return 0;
}*/