//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "common.h"
#include "utils.h"

#include "unitLogo.h"
#include "unitCorruptSettings.h"
#include "unitSetConfigFolder.h"
#include "unitMain.h"
#include "unitShowMessageCustom.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TformCorruptSettings *formCorruptSettings;

//---------------------------------------------------------------------------
__fastcall TformCorruptSettings::TformCorruptSettings(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TformCorruptSettings::resetConfigFile(){
	DeleteFile(labelPathToFile->Caption);
}

void TformCorruptSettings::showXMLInMemo(){
	memoXMLFile->Lines->LoadFromFile(labelPathToFile->Caption);
}

void TformCorruptSettings::checkXMLInMemo(){
	String memoLines = memoXMLFile->Lines->Text;
	TXMLDocument* XMLDocumentOwnerHeap = new TXMLDocument(formCorruptSettings);


    try{
		if(FileExists(labelPathToFile->Caption))
			XMLDocumentOwnerHeap->LoadFromXML(memoLines);
			btnSaveChanges->Enabled = true;
	}
	catch(...){
		showMessageCustom("oopsie whoopsie");
		btnSaveChanges->Enabled = false;
		return;
	}
}

void TformCorruptSettings::saveXMLAndContinue(){
	memoXMLFile->Lines->SaveToFile(labelPathToFile->Caption, TEncoding::UTF8);
	Close();
	formLogo->fadeTimer->Enabled = true;
}

void __fastcall TformCorruptSettings::Button2Click(TObject *Sender)
{
	// WIN API
	{
		TASKDIALOGCONFIG config 		= {0};
		config.cbSize                   = sizeof(config);
		config.hInstance                = NULL;

		config.pszMainIcon              = TD_WARNING_ICON;
		config.pszWindowTitle           = L"Upozorenje!";
		config.pszMainInstruction       = L"Jeste li sigurni da želite napraviti novi file?";
		config.pszContent               = L"Postojeća datoteka biti će izbrisana!";

		config.dwCommonButtons          = NULL;

		config.pButtons                 = (TASKDIALOG_BUTTON []){
										  {IDOK, L"Potvrdi"},
										  {IDCANCEL, L"Povratak"}
										  };

		TASKDIALOG_BUTTON buttons[]     = {
										  {IDOK, L"Potvrdi"},
										  {IDCANCEL, L"Povratak"}
										  };

		config.cButtons                 = ARRAYSIZE(buttons);

		config.nDefaultButton           = IDCANCEL;

		int nButtonPressed = 0;
		TaskDialogIndirect(&config, &nButtonPressed, NULL, NULL);

		switch(nButtonPressed)
		{
			case IDOK:
				resetConfigFile();
				break;
			case IDCANCEL:
					// do something else
				break;
			default:
				break;
		}
	}



	/*
	// RAD VCL wrapper of WIN API TaskDialogIndirect - more code but also more control
	{
		TTaskDialog *taskDialog = new TTaskDialog(this);
		taskDialog->MainIcon = tdiWarning;
		taskDialog->Caption = "Upozorenje";
		taskDialog->Title = "Naslov";
		taskDialog->Text = "Poruka";

		taskDialog->CommonButtons = TTaskDialogCommonButtons();

		TTaskDialogBaseButtonItem *button = taskDialog->Buttons->Add();
		button->Caption = "Potvrdi";
		button->ModalResult = mrOk;

		button = taskDialog->Buttons->Add();
		button->Caption = "Povratak";
		button->ModalResult = mrCancel;

		taskDialog->Buttons->DefaultButton = button;

		taskDialog->Execute();

		switch (taskDialog->ModalResult)
		{
			case mrOk:
					// do something
				break;
			case mrCancel:
					// do something else
				break;
			default:
				break;
		}
	}




	// RAD VCL wrapper of WIN API TaskDialogIndirect - less code but also less control
	{
		int nButtonPressed = TaskMessageDlg("Naslov",
											"Poruka",
											mtWarning,
											TMsgDlgButtons() << mbOK << mbCancel,
											0,
											mbCancel,
											(String[]){"Potvrdi", "Povratak"},
											1);

		switch(nButtonPressed)
		{
			case IDOK:
					// do something
				break;
			case IDCANCEL:
					// do something else
				break;
			default:
				break;
		}
	}
	*/
}

//---------------------------------------------------------------------------
void __fastcall TformCorruptSettings::buttonCloseAndFixClick(TObject *Sender)
{
	std::wstring exeCmd = L"notepad";
	std::wstring paramCmd = L"\"" + std::wstring(labelPathToFile->Caption) + L"\"";

	// POOR MANS EXECUTE PROCESS
	ShellExecute(GetDesktopWindow(), L"open", exeCmd.c_str(), paramCmd.c_str(), NULL, SW_SHOWMAXIMIZED);
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TformCorruptSettings::groupBoxConfigMouseEnter(TObject *Sender)
{
	labelPathToFile->Hint = labelPathToFile->Caption;
	labelPathToFile->ShowHint = true;
}
//---------------------------------------------------------------------------

void __fastcall TformCorruptSettings::Button3Click(TObject *Sender)
{
	showXMLInMemo();
	groupBoxConfig->Top = 200 + DEFAULT_MARGIN;
	groupBoxConfig->Visible = true;
	formCorruptSettings->Top = (Screen->Height - formCorruptSettings->Height)/2;
}
//---------------------------------------------------------------------------

void __fastcall TformCorruptSettings::FormShow(TObject *Sender)
{
	labelPathToFile->Caption = formSetConfigFolder->getProgramDataFileName();
}
//---------------------------------------------------------------------------

void __fastcall TformCorruptSettings::Button4Click(TObject *Sender)
{
	checkXMLInMemo();
}
//---------------------------------------------------------------------------

void __fastcall TformCorruptSettings::btnSaveChangesClick(TObject *Sender)
{
	checkXMLInMemo();
	saveXMLAndContinue();

}
//---------------------------------------------------------------------------

