#ifndef utilsH
#define utilsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hrdstop

#include <vector>
//******************************************************************************


//******************************************************************************
// TYPES
//******************************************************************************
typedef std::basic_string<TCHAR> STLstring;
typedef String RADstring;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
STLstring strConvert(RADstring inString);
RADstring strConvert(STLstring inString);
RADstring removeWhitespacesFromString(RADstring const& input);

RADstring getErrorMessage(DWORD errorMessageID);
RADstring getErrorMessage(HRESULT errorMessageID);
RADstring getErrorMessageFromShellExecute(HINSTANCE errorMessageID);

template <typename T_FIELD>
void addUniqueItemToItemsListField(RADstring item, T_FIELD* itemsListField);

void addUniqueItemToComboBox(TComboBox* comboBox, RADstring item = "");

bool IsPrinterOnline(RADstring printerName);
//******************************************************************************


//******************************************************************************
// HPP IMPLEMENTATIONS FILES
//******************************************************************************
#include "utils.hpp"
//******************************************************************************

//------------------------------------------------------------------------------
#endif

