#include<Windows.h>
#include"APITransfer.h"
#include"CommandManager.h"
#include"InlineCommand.h"

int RegisterInlineCommand()
{
	pBOIT_COMMAND Command_qwq = RegisterCommand(L"qwq", CmdMsg_qwq_Proc, L"����", BOIT_MATCH_FULL);
	AddCommandAlias(Command_qwq, L"pwp");
	RegisterCommand(L"about", CmdMsg_about_Proc, L"����", BOIT_MATCH_FULL);
	RegisterCommand(L"TreeNewBee", CmdMsg_commingfeature_Proc, L"��ţ��(�����еĹ���)", BOIT_MATCH_FULL);
	RegisterCommandEx(L"run", CmdMsg_run_Proc, CmdEvent_run_Proc, L"���д���", BOIT_MATCH_PARAM);
	RegisterCommand(L"help", CmdMsg_help_Proc, L"������Ϣ", BOIT_MATCH_PARAM);
	
	return 0;
}