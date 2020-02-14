#include<Windows.h>
#include"CommandManager.h"
#include"APITransfer.h"
#include"InlineCommand.h"

MSGPROC CmdMsg_help_Proc(long long GroupID, long long QQID, WCHAR* AnonymousName, WCHAR* Msg)
{
	WCHAR * HelpInfoStr = 0;

	int TotLen = 0;
	AcquireSRWLockShared(&CommandChainLock);
	__try
	{
		if (!RootCommand)
		{
			__leave;
		}
		for (pBOIT_COMMAND pList = RootCommand; pList; pList = pList->NextCommand)
		{
			TotLen += lstrlenW(pList->CommandName[0]);
			TotLen += lstrlenW(pList->ManualMsg);
			TotLen += 3;
		}
		TotLen += 100;//Ԥ����ռ�

		HelpInfoStr = malloc(sizeof(WCHAR) * TotLen);
		ZeroMemory(HelpInfoStr, sizeof(WCHAR) * TotLen);

		wcscpy_s(HelpInfoStr, TotLen, L"������Ϣ:\n");
		wcscat_s(HelpInfoStr, TotLen, L"����	ʹ�÷���\n");
		wcscat_s(HelpInfoStr, TotLen, L"����������������\n");
		for (pBOIT_COMMAND pList = RootCommand; pList; pList = pList->NextCommand)
		{
			wcscat_s(HelpInfoStr, TotLen, (pList->CommandName[0]));
			wcscat_s(HelpInfoStr, TotLen, L"	");
			wcscat_s(HelpInfoStr, TotLen, (pList->ManualMsg));
			wcscat_s(HelpInfoStr, TotLen, L"\n");
		}
	}
	__finally 
	{
		ReleaseSRWLockShared(&CommandChainLock);
	}
	
	

	

	if (HelpInfoStr)
	{
		SendBackMessage(GroupID, QQID, HelpInfoStr);
	}
	
	
	return 0;
}