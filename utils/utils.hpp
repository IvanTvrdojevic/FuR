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

//******************************************************************************
