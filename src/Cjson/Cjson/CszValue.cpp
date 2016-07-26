#include <SDKDDKVer.h>
#include "CszValue.h"
#include "CStringManagerAPI.h"

CszValue::CszValue(){

}

CszValue::CszValue(CString strValue){
	int num = 0;
	int begin = 0;
	int i = -1;
	while(1){
		i++;
		//�������ĩβ��ȡ�����һ�����˳�
		if(strValue[i] == 0){
			CstrValue strValueTemp = strValue.Mid(begin,i - begin);
			CszOneValue szOneValueTemp(num,strValueTemp);
			vecszOneValue.push_back(szOneValueTemp);

			CTypeValue strTypeValue = strValueTemp;
			vecszValue.push_back(strTypeValue);
			break;
		}
		//������ҵ��˶���˵��������һ���ֶ�ֵ
		if(strValue[i] == ','){
			CstrValue strValueTemp = strValue.Mid(begin,i - begin);
			CszOneValue szOneValueTemp(num,strValueTemp);
			vecszOneValue.push_back(szOneValueTemp);
			//
			CTypeValue strTypeValue = strValueTemp;
			vecszValue.push_back(strTypeValue);
			num++;
			//ȡ���ź��λ����Ϊ��ʼ����Ϊi����ѭ����ʼ��++�����Բ���Ҫ��
			begin = i + 1;
		}
		//����ҵ���һ��{˵���ҵ���һ��json
		if(strValue[i] == '{'){
			CStringManager manager = strValue;
			int nRight = manager.FindOther('{','}',i);
			CString strJsonTemp = strValue.Mid(i,nRight - i + 1);
			Cjson json;
			json.LoadJson(strJsonTemp);
			vecjson.push_back(json);
			//
			CTypeValue jsonTypeValue = json;
			vecszValue.push_back(jsonTypeValue);
			num++;
			//ȡ���ź��λ����Ϊ��ʼ
			while(1){
				//��ֹ�ڽ���ʱ����Ϊû�ҵ����ŵ���i����ԭ�������ŵ�λ�ã��Ȱ�i�ŵ������ŵ�λ�ã�ѭ����ʼ��ʱ�����++��Ѱ����һλ
				i = nRight;
				nRight++;
				if(strValue[nRight] == 0) return;
				if(strValue[nRight] == ','){
					begin = nRight + 1;
					//i����ȡ���ŵ�λ�ã�ѭ����ʼ��ʱ�������++
					i = nRight;
					break;
				}
			}
		}
	}
}

CszValue::~CszValue(){

}

int CszValue::size(){
	return vecszValue.size();
}