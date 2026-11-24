#include "header.h"

int main(){
	// var -------------------------------------
	addrParent parent_first;
	addrParent parent_temp1, parent_temp2;
	addrChild child;
	dataParent data_sales;
	dataChild data_properti;
	
	string NIP_search;
	string NIP_target;
	string type;
	
	int num;
	int menu;
	
	// body ------------------------------------
	inisialisasi(&parent_first);

	while (1) {
		menu = mainMenu();

		switch (menu) {
			default: {
				CLEAR
				
				ERROR printf("menu invalid"); NEW_LINE

				PAUSE
				return 0;
			}

			case 0: {
				CLEAR

				if (!isEmpty(parent_first)) {
					deleteAllParent(&parent_first);
				}
				NEW_LEFT_MARGIN LEFT_MARGIN printf(BACK_BRIGHT_WHITE"250713212 - 250713196 - 250713173 - 250713184"END);
				
				NEW_LINE
				PAUSE
				return 0;
			}
		}
	}

	return 0;
}
