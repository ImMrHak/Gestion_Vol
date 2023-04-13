#include "Header.h"

int main()
{
	Create_Config_File();
	Get_DB_Info();
	while (true) {
		if (LR_Account() == 1) {
			if (!All_Menu()) {
				system("cls");
				main();
			}
		}
		else if (LR_Account() == 2) {
			system("cls");
			main();
		}
	}
	return 0;
}