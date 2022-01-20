//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hdrstop

USEFORM("Forms\unitShowMessageCustom.cpp", formShowMessageCustom);
USEFORM("Forms\unitMain.cpp", formMain);
USEFORM("Forms\unitLogo.cpp", formLogo);
USEFORM("Forms\unitCorruptSettings.cpp", formCorruptSettings);
USEFORM("Forms\unitClose.cpp", formClose);
USEFORM("Forms\unitAdditionalOptions.cpp", formAdditionalOptions);
USEFORM("Forms\unitOpenNew.cpp", formOpenNew);
USEFORM("Forms\unitSetPrinter.cpp", formSetPrinter);
USEFORM("Forms\unitSetConfigFolder.cpp", formSetConfigFolder);
USEFORM("Forms\unitSaveMessage.cpp", formSaveMessage);
USEFORM("Forms\unitPrintMessage.cpp", formPrintMessage);
USEFORM("Forms\unitOptions.cpp", formOptions);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TformLogo), &formLogo);
		Application->CreateForm(__classid(TformAdditionalOptions), &formAdditionalOptions);
		Application->CreateForm(__classid(TformClose), &formClose);
		Application->CreateForm(__classid(TformCorruptSettings), &formCorruptSettings);
		Application->CreateForm(__classid(TformOpenNew), &formOpenNew);
		Application->CreateForm(__classid(TformOptions), &formOptions);
		Application->CreateForm(__classid(TformPrintMessage), &formPrintMessage);
		Application->CreateForm(__classid(TformSaveMessage), &formSaveMessage);
		Application->CreateForm(__classid(TformSetConfigFolder), &formSetConfigFolder);
		Application->CreateForm(__classid(TformSetPrinter), &formSetPrinter);
		Application->CreateForm(__classid(TformShowMessageCustom), &formShowMessageCustom);
		Application->CreateForm(__classid(TformMain), &formMain);
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
