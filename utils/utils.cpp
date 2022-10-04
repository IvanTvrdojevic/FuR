//******************************************************************************
// INCLUDES
//******************************************************************************
#include <comdef.h>

#include "utils.h"
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
float RADstringToFloat(RADstring str)
{
	String strTmp = StringReplace(str, _D(","), _D("."), TReplaceFlags() << rfReplaceAll);
	TFormatSettings fmt = TFormatSettings::Create();
	fmt.DecimalSeparator = _D('.');
	return StrToFloat(strTmp, fmt);
}

STLstring strConvert(RADstring inString){
	return STLstring(inString.c_str());
}

RADstring strConvert(STLstring inString){
	return RADstring(inString.c_str());
}

RADstring removeWhitespacesFromString(RADstring const& input)
{
	STLstring tmpStr = strConvert(input);

	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), '\t'), tmpStr.end());
	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), '\n'), tmpStr.end());
	tmpStr.erase(std::remove(tmpStr.begin(), tmpStr.end(), ' '), tmpStr.end());

	return strConvert(tmpStr);
}

RADstring getErrorMessage(DWORD errorMessageID)
{
	// source: https://stackoverflow.com/questions/1387064/how-to-get-the-error-message-from-the-error-code-returned-by-getlasterror

	//Ask Win32 to give us the string version of that message ID.
	//The parameters we pass in, tell Win32 to create the buffer that holds the message for us (because we don't yet know how long the message string will be).
	LPTSTR messageBuffer = NULL;
	size_t size = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
								NULL, errorMessageID, 0, (LPTSTR)&messageBuffer, 0, NULL);

	RADstring resString(messageBuffer);

	//Free the Win32's string's buffer.
	LocalFree(messageBuffer);

	return resString;
}

RADstring getErrorMessage(HRESULT errorMessageID)
{
	// source: https://stackoverflow.com/questions/7008047/is-there-a-way-to-get-the-string-representation-of-hresult-value-using-win-api

	_com_error err(errorMessageID);
	LPCTSTR messageBuffer = err.ErrorMessage();

	return RADstring(messageBuffer);
}

RADstring getErrorMessageFromShellExecute(HINSTANCE errorMessageID){
	int errorMessageIDdword = (int)errorMessageID;

	if(errorMessageIDdword < 0 || errorMessageIDdword > 32)
		return "ShellExecute executed sucessfully.";

	if(errorMessageIDdword == 0)
		return "The operating system is out of memory or resources.";

	return  getErrorMessage((DWORD)errorMessageIDdword);
}

void addUniqueItemToComboBox(TComboBox* comboBox, RADstring item){
	if(item == "") item = comboBox->Text;
	addUniqueItemToItemsListField(item, comboBox);
}

bool IsPrinterOnline(RADstring printerName)
{
	// sources
	// https://stackoverflow.com/questions/12971053/check-if-installed-network-printer-is-online
	// https://docs.microsoft.com/en-us/troubleshoot/windows/win32/printer-print-job-status

	HANDLE hPrinter;
	if(OpenPrinter(const_cast<LPTSTR>(strConvert(printerName).c_str()), &hPrinter, NULL) == 0){
		/*OpenPrinter call failed*/
		return false;
	}

	DWORD dwBufsize = 0;
	PRINTER_INFO_2* pinfo = 0;
	int nRet = 0;
	nRet = GetPrinter(hPrinter, 2, (LPBYTE)pinfo, dwBufsize, &dwBufsize); //Get dwBufsize

	DWORD dwGetPrinter = 0;
	if(nRet == 0){
		dwGetPrinter = GetLastError();
	}

	PRINTER_INFO_2* pinfo2 = (PRINTER_INFO_2*)malloc(dwBufsize); //Allocate with dwBufsize
	nRet = GetPrinter(hPrinter, 2, reinterpret_cast<LPBYTE>(pinfo2), dwBufsize, &dwBufsize);
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

//******************************************************************************


