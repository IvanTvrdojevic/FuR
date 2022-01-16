//******************************************************************************
// INCLUDES
//******************************************************************************
#include "utils.h"

#include "unitShowMessageCustom.h"
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
bool IsPrinterOnline(wstring printerName)
{
	// sources
	// https://stackoverflow.com/questions/12971053/check-if-installed-network-printer-is-online
	// https://docs.microsoft.com/en-us/troubleshoot/windows/win32/printer-print-job-status

	HANDLE hPrinter;
	if(OpenPrinter(const_cast<LPWSTR>(printerName.c_str()), &hPrinter, NULL) == 0){
		/*OpenPrinter call failed*/
		return false;
	}

	DWORD dwBufsize = 0;
	PRINTER_INFO_2* pinfo = 0;
	int nRet = 0;
	nRet = GetPrinter(hPrinter, 2,(LPBYTE)pinfo, dwBufsize, &dwBufsize); //Get dwBufsize

	DWORD dwGetPrinter = 0;
	if(nRet == 0){
		dwGetPrinter = GetLastError();
	}

	PRINTER_INFO_2* pinfo2 = (PRINTER_INFO_2*)malloc(dwBufsize); //Allocate with dwBufsize
	nRet = GetPrinter(hPrinter, 2,reinterpret_cast<LPBYTE>(pinfo2), dwBufsize, &dwBufsize);
	if(nRet == 0){
		dwGetPrinter = GetLastError();
		return false;
	}

	if(pinfo2->Attributes & PRINTER_ATTRIBUTE_WORK_OFFLINE){
		free(pinfo2);
		ClosePrinter(hPrinter);
		return false;
	}

	free(pinfo2);
	ClosePrinter(hPrinter);
	return true;
}

void addUniqueItemToComboBox(TComboBox* comboBox, String item){
	if(item == "") item = comboBox->Text;
	addUniqueItemToItemsListField(item, comboBox);
}

String removeWhitespacesFromString(String const& input)
{
	AnsiString tmpAnsi = input;
	std::string tmpStr(tmpAnsi.c_str(), tmpAnsi.Length());

	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), '\t'), tmpStr.end());
	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), '\n'), tmpStr.end());
	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), ' '), tmpStr.end());

	tmpAnsi = AnsiString(tmpStr.c_str());

    return tmpAnsi;
}

String getErrorMessage(DWORD errorMessageID)
{
	// source: https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror

	LPSTR messageBuffer = nullptr;

	//Ask Win32 to give us the string version of that message ID.
	//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
								 NULL, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&messageBuffer, 0, NULL);

	//Copy the error message into a std::string.
	string message(messageBuffer, size);

	//Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return String(message.c_str(), message.length());
}

String getErrorMessageFromShellExecute(HINSTANCE errorMessageID){
	int errorMessageIDdword = (int)errorMessageID;

	if(errorMessageIDdword < 0 || errorMessageIDdword > 32)
		return "ShellExecute executed sucessfully.";

	if(errorMessageIDdword == 0)
		return "The operating system is out of memory or resources.";

	return  getErrorMessage((DWORD)errorMessageIDdword);
}

void showMessageCustom(String message, int fontSize, TColor fontColor){
	formShowMessageCustom->labelCustomMessage->Caption = message;
	formShowMessageCustom->labelCustomMessage->Font->Size = fontSize;
	formShowMessageCustom->labelCustomMessage->Font->Color = fontColor;

	formShowMessageCustom->ShowModal();
}

void showMessageCustom(int message, int fontSize, TColor fontColor){
	showMessageCustom(IntToStr(message), fontSize, fontColor);
}
//******************************************************************************

