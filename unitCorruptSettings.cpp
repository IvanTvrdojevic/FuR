//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "common.h"

#include "unitLogo.h"
#include "unitCorruptSettings.h"
#include "unitSetConfigFolder.h"
#include "unitMain.h"
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
void __fastcall TformCorruptSettings::Button2Click(TObject *Sender)
{
	// WIN API
	{
		TASKDIALOGCONFIG config 		= {0};
		config.cbSize                   = sizeof(config);
		config.hInstance                = NULL;

		config.pszMainIcon              = TD_WARNING_ICON;
		config.pszWindowTitle           = L"Upozorenje";
		config.pszMainInstruction       = L"Naslov";
		config.pszContent               = L"Poruka";

		config.dwCommonButtons          = NULL;

		config.pButtons                 = (TASKDIALOG_BUTTON []){
										  {IDOK, L"Potvrdi"},
										  {IDCANCEL, L"Povratak"}
										  };
		config.cButtons                 = ARRAYSIZE(config.pButtons);

		config.nDefaultButton           = IDCANCEL;

		int nButtonPressed = 0;
		TaskDialogIndirect(&config, &nButtonPressed, NULL, NULL);

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
void __fastcall TformCorruptSettings::FormClose(TObject *Sender, TCloseAction &Action)

{
	formLogo->fadeTimer->Enabled = true;
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
	memoXMLFile->Lines->LoadFromFile(labelPathToFile->Caption);
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

