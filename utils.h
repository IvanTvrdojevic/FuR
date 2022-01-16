#ifndef utilsH
#define utilsH
//------------------------------------------------------------------------------

//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hrdstop

#include <vector>

#include "common.h"

#include "unitMain.h"
#include "unitAdditionalOptions.h"

using namespace std;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
bool IsPrinterOnline(wstring printerName);

template <typename T_FIELD>
void addUniqueItemToItemsListField(String item, T_FIELD* itemsListField);

void addUniqueItemToComboBox(TComboBox* comboBox, String item = "");

String removeWhitespacesFromString(String const& input);

String getErrorMessage(DWORD errorMessageID);
String getErrorMessageFromShellExecute(HINSTANCE errorMessageID);

void showMessageCustom(String message, 	int fontSize = DEFAULT_MESSAGE_FONT_SIZE,
										TColor fontColor = DEFAULT_MESSAGE_FONT_COLOR);

void showMessageCustom(int message, int fontSize = DEFAULT_MESSAGE_FONT_SIZE,
									TColor fontColor = DEFAULT_MESSAGE_FONT_COLOR);

template <typename T_MSG>
void showMessageCustomWrp(T_MSG message);

template <typename T_MSG>
void DBG_MSG(T_MSG message);

template <typename T_MSG>
void DBG_MSG(vector<T_MSG> messages);

//******************************************************************************
#include "utils.hpp"

//------------------------------------------------------------------------------
#endif
