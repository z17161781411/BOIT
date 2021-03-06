#include<Windows.h>
#include"DirManagement.h"



BOOL InitializeUserDefaultToken(long long QQID)
{
	//初始化默认权限
	PerUserCreateFileIfNExist(QQID, L"Token\\PrivilegeRunCode");
}

BOOL InitializeGroupDefaultToken(long long GroupID)
{
	//初始化默认权限
	PerGroupCreateFileIfNExist(GroupID, L"Token\\PrivilegeRunCode");
}


BOOL CheckUserToken(long long QQID, WCHAR* TokenStr)
{
	if (PerUserCreateDirIfNExist(QQID, L"Token"))
	{
		InitializeUserDefaultToken(QQID);
	}

	WCHAR TokenFile[MAX_PATH];
	GetPerUserDir(TokenFile, QQID);
	PathAppendW(TokenFile, L"Token");
	PathAppendW(TokenFile, TokenStr);
	if (PathFileExistsW(TokenFile))
	{
		return TRUE;
	}

	return FALSE;
}



BOOL CheckGroupToken(long long GroupID, WCHAR* TokenStr)
{
	if (PerGroupCreateDirIfNExist(GroupID, L"Token"))
	{
		InitializeGroupDefaultToken(GroupID);
	}

	WCHAR TokenFile[MAX_PATH];
	GetPerGroupDir(TokenFile, GroupID);
	PathAppendW(TokenFile, L"Token");
	PathAppendW(TokenFile, TokenStr);
	if (PathFileExistsW(TokenFile))
	{
		return TRUE;
	}

	return FALSE;
}


