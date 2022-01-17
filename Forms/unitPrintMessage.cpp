//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <vector>

#include "utils.h"

#include "unitMain.h"
#include "unitOptions.h"
#include "unitPrintMessage.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
#pragma package(smart_init)
#pragma resource "*.dfm"
TformPrintMessage *formPrintMessage;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
__fastcall TformPrintMessage::TformPrintMessage(TComponent* Owner)
	: TForm(Owner)
{
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// WIN API METHODS - these dont do anything, just as an example
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
struct handleData {
	unsigned long processId;
	vector<HWND> processWindowHandles;
};

BOOL isMainWindow(HWND handle)
{
	return IsWindowVisible(handle) && GetWindow(handle, GW_OWNER) == (HWND)0;
}

BOOL CALLBACK enumWindowsCallback(HWND handle, LPARAM lParam)
{
	unsigned long processId = 0;
	GetWindowThreadProcessId(handle, &processId);

	handleData& data = *(handleData*)lParam;
	if(data.processId != processId || !isMainWindow(handle))
		return TRUE;

	data.processWindowHandles.push_back(handle);
	return TRUE;
}

vector<HWND> findProcessWindows(unsigned long processId)
{
	handleData data;
	data.processId = processId;
	EnumWindows(enumWindowsCallback, (LPARAM)&data);

	return data.processWindowHandles;
}

HWINEVENTHOOK winEventHook;
void CALLBACK WinEventProc(	HWINEVENTHOOK hook,
							DWORD event,
							HWND hwnd,
							LONG idObject,
							LONG idChild,
							DWORD dwEventThread,
							DWORD dwmsEventTime)
{
	DBG_MSG("ENTER WinEventProc");

	if(event != EVENT_OBJECT_CREATE) return;

	DBG_MSG((int)hwnd);

	DWORD currProcessID = GetCurrentProcessId();

	if(!isMainWindow(hwnd))
		return;

	ShowWindow(hwnd, SW_SHOWMAXIMIZED);
	UnhookWinEvent(winEventHook);

	unsigned long processId = 0;
	GetWindowThreadProcessId(hwnd, &processId);
	DBG_MSG("windowHWND " + IntToStr((int)hwnd));
	DBG_MSG("windowProcessId " + IntToStr((int)processId));
	DBG_MSG("EXIT WinEventProc");
}

void __fastcall setupWinEventHook(TObject *Sender)
{
	winEventHook = SetWinEventHook(	EVENT_OBJECT_CREATE,
									EVENT_OBJECT_CREATE,
									NULL,
									WinEventProc,
									0,
									0,
									WINEVENT_OUTOFCONTEXT | WINEVENT_SKIPOWNPROCESS);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    	 WIN API METHODS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<


void TformPrintMessage::showOrHide(TLabel* label, TButton* button){
	label->Caption = formMain->getReceiptFileName();
	label->Visible = !label->Visible;

	if(label->Visible){
		button->Caption = "Sakrij lokaciju";
	}
	else{
		button->Caption = "Prikaži lokaciju";
	}
}

void TformPrintMessage::changeVisibility(TLabel* label, TButton* button){
	label->Visible = false;
	button->Caption = "Prikaži lokaciju";
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// FORM CONTROLS EVENTS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void __fastcall TformPrintMessage::Button2Click(TObject *Sender)
{
	// THIS LAUNCHES Microsoft Edge as pdf reader - not very portable!!!! Check later!!!
	wstring exeCmd = L"msedge";
	wstring paramCmd = L"\"" + wstring(formMain->outFileName) + L"\"";

    // POOR MANS EXECUTE PROCESS
	ShellExecute(GetDesktopWindow(), L"open", exeCmd.c_str(), paramCmd.c_str(), NULL, SW_SHOWMAXIMIZED);

	// THIS ALSO SHOULD WORK AND IT SHOULD BE BETTER WAY TO EXECUTE A PROCESS
	/*
	SHELLEXECUTEINFO ShExecInfo = {0};
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_WAITFORINPUTIDLE;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = exeCmd.c_str();
	ShExecInfo.lpParameters = paramCmd.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_SHOWMAXIMIZED;
	ShExecInfo.hInstApp = NULL;
	ShellExecuteEx(&ShExecInfo);
	*/

    // !!!!!!! DONT DO THIS - MOUSE STOPS WORKING !!!!!!!!
	//ShowWindow(GetTopWindow(NULL), SW_SHOWMAXIMIZED);
}

void __fastcall TformPrintMessage::Button1Click(TObject *Sender)
{
	formPrintMessage->Close();
}

void __fastcall TformPrintMessage::FormShow(TObject *Sender)
{
	labelPrintMessage1->Caption = "Broj kopija: " + IntToStr(formMain->spinEditCopies->Value);

	AnsiString tmpAstr = formOptions->comboBoxPrinters->Text;
	string tmpStr = string(tmpAstr.c_str(), tmpAstr.Length());
	wstring wstringPrinterName = wstring(tmpStr.begin(), tmpStr.end());

	if(IsPrinterOnline(wstringPrinterName)){
		labelPrintMessage2->Caption = "Printer spojen, printanje u tijeku!";
	}else{
		labelPrintMessage2->Caption = "Printanje će započeti kad spojite printer!";
	}

	changeVisibility(labelFolder, buttonMore);
}

void __fastcall TformPrintMessage::buttonMoreClick(TObject *Sender)
{
	showOrHide(labelFolder, buttonMore);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//														    FORM CONTROLS EVENTS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************





