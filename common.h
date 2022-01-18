#ifndef commonH
#define commonH
//------------------------------------------------------------------------------

//******************************************************************************
// DEFINES
//******************************************************************************
#define PROGRAM_NAME_OFFICIAL "FISKALNI RACUN"

#define PROGRAM_FOLDER "Frutzov Uber Racun"
#define PROGRAM_DATA_FILENAME "programData.xml"

#define RECEIPT_SUFFIX_ENABLE true
#define RECEIPT_START_NUMBER 0
#define RECEIPT_NAME "racun"
#define RECEIPT_EXTENSION ".fur"
#define RECEIPT_MASK "*" RECEIPT_EXTENSION

#define REGISTRY_KEY "\\SOFTWARE\\" PROGRAM_FOLDER
#define REGISTRY_SUBKEY_PROGRAM_DATA_NAME "programDataPath"

#define DEFAULT_MESSAGE_FONT_SIZE 14
#define DEFAULT_MESSAGE_FONT_COLOR clRed

#define DEFAULT_MARGIN 30


#define DEBUG_BEGIN "Q"
#define DEBUG_MEMO DEBUG_BEGIN "memo"
#define DEBUG_NOVAL DEBUG_BEGIN "noval"
#define DEBUG_ENABLEOUT DEBUG_BEGIN "dbgout"
#define DEBUG_DISABLE DEBUG_BEGIN "nodbg"
#define DEBUG_RESET DEBUG_BEGIN "reset"

#define EASTER_EGG "frutz"
//******************************************************************************


//******************************************************************************
// INCLUDES
//******************************************************************************
#include <vcl.h>
#pragma hrdstop

#include "programDataBindings.h"
//******************************************************************************


//******************************************************************************
// GLOBAL VARS
//******************************************************************************
extern TXMLBinding_programData programData;
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************
void setupFormVisuals(TForm* form);
//******************************************************************************

//------------------------------------------------------------------------------
#endif
