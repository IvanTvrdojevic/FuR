//******************************************************************************
// METHODS
//******************************************************************************
template <typename T_FIELD>
void addUniqueItemToItemsListField(String item, T_FIELD* itemsListField){
	if(itemsListField == NULL || item == "")
		return;

	bool isNew = true;
	for(int i = 0; i < itemsListField->Items->Count; i++)
		if(item == itemsListField->Items->Strings[i]){
			isNew = false;
			break;
		}

	if(isNew){
		itemsListField->Items->Add(item);
	}
}


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
	if constexpr (is_same<T_MSG, HWND>::value)
		messageSpec = (int)message;
	else
		messageSpec = message;

	if(formMain->Visible == false){
		showMessageCustomWrp(messageSpec);
	}
	else{
		if(formMain->Memo1->Visible){
			formMain->Memo1->Lines->Add(messageSpec);
		}
		else if(formMain->enableDbgOut){
			showMessageCustomWrp(messageSpec);
		}
	}
}

template <typename T_MSG>
void DBG_MSG(vector<T_MSG> messages){
	for(int i = 0; i < messages.size(); i++)
		DBG_MSG(messages[i]);
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//															   	 MESSAGE DIALOGS
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

//******************************************************************************
