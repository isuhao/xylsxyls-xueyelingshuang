#include <SDKDDKVer.h>
#include "CDeleteMapWatch.h"
#include "CAceTCPServer.h"

void CDeleteMapWatch::Do(void *pDo,BOOL* nDelete){
	WatchPac package = *(WatchPac*)pDo;
	delete (WatchPac*)pDo;
	package.pThis->DeleteMap(package.CheckKeyServer);
	*nDelete = 1;
	delete this;
	return;
}