//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unitLogo.h"
#include "unitCorruptSettings.h"
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
		config.pszWindowTitle           = L"Upozorenje!!!";
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
		taskDialog->Caption = "Upozorenje!";
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
	// example: calling this wrapper doesnt have the option to set the window caption
	// - its always "Warning!" (while previous wrapper enables setting it to "Upozorenje!")
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
void __fastcall TformCorruptSettings::Button1Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TformCorruptSettings::FormClose(TObject *Sender, TCloseAction &Action)

{
	formLogo->fadeTimer->Enabled = true;
}
//---------------------------------------------------------------------------
