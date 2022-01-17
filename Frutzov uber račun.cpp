//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include "common.h"

USEFORM("unitSaveMessage.cpp", formSaveMessage);
USEFORM("unitPrintMessage.cpp", formPrintMessage);
USEFORM("unitOptions.cpp", formOptions);
USEFORM("unitOpenNew.cpp", formOpenNew);
USEFORM("unitMain.cpp", formMain);
USEFORM("unitShowMessageCustom.cpp", formShowMessageCustom);
USEFORM("unitSetPrinter.cpp", formSetPrinter);
USEFORM("unitSetConfigFolder.cpp", formSetConfigFolder);
USEFORM("unitLogo.cpp", formLogo);
USEFORM("Forms\unitAdditionalOptions.cpp", formAdditionalOptions);
USEFORM("unitCorruptSettings.cpp", formCorruptSettings);
USEFORM("Forms\unitClose.cpp", formClose);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TformLogo), &formLogo);
		Application->CreateForm(__classid(TformMain), &formMain);
		Application->CreateForm(__classid(TformShowMessageCustom), &formShowMessageCustom);
		Application->CreateForm(__classid(TformSetPrinter), &formSetPrinter);
		Application->CreateForm(__classid(TformSetConfigFolder), &formSetConfigFolder);
		Application->CreateForm(__classid(TformSaveMessage), &formSaveMessage);
		Application->CreateForm(__classid(TformPrintMessage), &formPrintMessage);
		Application->CreateForm(__classid(TformOptions), &formOptions);
		Application->CreateForm(__classid(TformOpenNew), &formOpenNew);
		Application->CreateForm(__classid(TformCorruptSettings), &formCorruptSettings);
		Application->CreateForm(__classid(TformAdditionalOptions), &formAdditionalOptions);
		Application->CreateForm(__classid(TformClose), &formClose);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//******************************************************************************
