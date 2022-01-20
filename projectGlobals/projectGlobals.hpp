//******************************************************************************
// INCLUDES
//******************************************************************************
#include "unitMain.h"
#include "unitAdditionalOptions.h"
//******************************************************************************


//******************************************************************************
// METHODS
//******************************************************************************

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// MESSAGE DIALOGS
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
template <typename T_MSG>
void showMessageCustomWrp(T_MSG message){
	showMessageCustom(message, formAdditionalOptions->spinEditMessageFontSize->Value,
							   formAdditionalOptions->colorListBoxMessageFontColor->Selected);
}

template <typename T_MSG>
void DBG_MSG(T_MSG message){

	String messageSpec;
	if constexpr (std::is_same<T_MSG, HWND>::value)
		messageSpec = (int)message;
	else
		messageSpec = message;

	if(formMain->Memo1->Visible){
		formMain->Memo1->Lines->Add(messageSpec);
	}
	else if(formMain->enableDbgOut){
		showMessageCustomWrp(messageSpec);
	}
}

template <typename T_MSG>
void DBG_MSG(std::vector<T_MSG> messages){
	for(int i = 0; i < messages.size(); i++)
		DBG_MSG(messages[i]);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															   	 MESSAGE DIALOGS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************
