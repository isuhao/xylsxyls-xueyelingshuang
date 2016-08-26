#pragma once
#include "Cjson/CjsonAPI.h"
#include <afxwin.h>
#include "CAceHttpClientMacro.h"

//Ĭ�ϱ�ͷ��������Content-Type��Content-Length
class Cjson;
class CAceHttpClientAPI CHttpString{
public:
	CString str;

public:
	void InitClient(CString strIP,int port,CString ContentType = "application/json;charset=UTF-8");
	//1��ʾ�ɹ�����
	void InitServer(int flag,CString ContentType = "application/json;charset=UTF-8");
	//���ӱ�ͷ
	void AddMessage(CString strHead,CString strValue);
	//1��ʾpost����
	void ProtocolStyle(CString strProtocol,int flag);
	//��ȡURI
	CString GetProtocol();
	//��ȡ������
	CString GetStyle();
	//��������
	void SetJson(Cjson json);
	//��ȡ����
	Cjson GetJsonData();
	//��ȡ����
	CString GetContentType();
	//��ȡ����
	int GetContentLength();
	//��ȡ���ݣ�����ʵ�ʽ��ճ���
	CString GetData();
};