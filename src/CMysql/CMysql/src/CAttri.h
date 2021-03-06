#pragma once
#include <afxwin.h>
#include "CValue.h"
#include "CMysqlMacro.h"

class CMysqlAPI CAttri{
public:
	BOOL Type;
	CString strFieldName;
	int nLength;
	bool bHasDefault;
	CValue vDefault;
	bool bPrimaryKey;
	bool bUniqueKey;
	bool bNotNull;
	bool bAutoIncrement;
	bool bBlob;
	bool bZeroFill;
public:
	CAttri();
	CAttri(const CAttri& attri);
	CAttri operator= (const CAttri& attri);

	//CAttri& operator->();
	void a();
};