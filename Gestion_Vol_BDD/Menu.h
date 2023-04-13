#pragma once
#include "Passanger.h"
#include "Airplane.h"
#include "Flight.h"
#include "Combined_F.h"

Passanger P;
Airplane AP;
Flight F;

vector<Flight> LFlights;
vector<Passanger> LPassangers;

// ss stand for static side used or not
bool ss = false;

// idd stand for insert data into the database
bool idd = true;

void User_Connected() {
	try {
		vector<string> lines = {
			" ______________________________________________",
			"                                               ",
			"   Connected User : " + User_Full_Name,
			"   User Role : " + User_Role,
			" ______________________________________________"
		};
		Center_Multiple_Strings(lines);
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing UC Function" << endl;
		system("pause");
		system("cls");
	}
}

void Used_Side() {
	try {
		cout << "" << endl;
		cout << "" << endl;
		vector<string> lines = {
			" ______________________________________________",
			"                                               ",
			"   User Side Using Now : " + User_Side,
			" ______________________________________________"
		};
		Center_Multiple_Strings(lines);
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing US Function" << endl;
		system("pause");
		system("cls");
	}
}



bool Add_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|                     [1] => Create Passanger                |",
				"|------------------------------------------------------------|",
				"|                     [2] => Create Airplane                 |",
				"|------------------------------------------------------------|",
				"|                      [3] => Create Flight                  |",
				"|------------------------------------------------------------|",
				"|                [4] => Add Passanger To A Flight            |",
				"|------------------------------------------------------------|",
				"|               [5] => Add An Airplane To A Flight           |",
				"|------------------------------------------------------------|",
				"|            [6] => Add Passanger To Array Passangers        |",
				"|------------------------------------------------------------|",
				"|           [7] => Add Array Passangers To To A Flight       |",
				"|------------------------------------------------------------|",
				"|             [8] => Add Flight To An Array Flights          |",
				"|------------------------------------------------------------|",
				"|                     [9] => Back To Menu                    |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			string message;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Create Passanger
					system("cls");
					message = "Enter The Passanger Informations";
					Center_Text(message);
					P.Fill_Info_Passanger();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Create Airplane
					system("cls");
					message = "Enter The Airplane Informations";
					Center_Text(message);
					AP.Fill_Info_Airplane();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Create Flight
					system("cls");
					message = "Enter The Flight Informations";
					Center_Text(message);
					F.Fill_Info_Flight();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 4) {
					// [4] => Add Passanger To A Flight
					system("cls");
					Add_Passanger_Flight(P, F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 5) {
					// [5] => Add An Airplane To A Flight
					system("cls");
					Add_Airplane_Flight(AP, F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 6) {
					// [6] => Add Passanger To Array Passangers
					system("cls");
					Add_Passanger_Passangers(P, LPassangers);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 7) {
					// [7] => Add Array Passangers To To A Flight
					system("cls");
					Add_Passangers_Flight(LPassangers, F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 8) {
					// [8] => Add Flight To An Array Flights
					system("cls");
					Add_Flight_Flights(F, LFlights);
					ss = true;
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 9) {
					// [9] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing AM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Edit_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> lines = {
				" _____________________________________________________________ ",
				"|-------------------------------------------------------------|",
				"|              [1] => Edit A Passanger In A Flight            |",
				"|-------------------------------------------------------------|",
				"|             [2] => Edit Departure And Arrival Date          |",
				"|-------------------------------------------------------------|",
				"|             [3] => Edit Departure And Arrival City          |",
				"|-------------------------------------------------------------|",
				"|                     [4] => Back To Menu                     |",
				"|-------------------------------------------------------------|",
				"|_____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Edit A Passanger In A Flight
					Passanger VP;
					system("cls");
					cout << "" << endl;
					int ID;
					cout << "Enter Passanger ID : "; cin >> ID;
					VP.setID(ID);
					if (Check_Passanger_Exists_Flight(VP, F)) {
						VP.Fill_Info_Passanger();
						Edit_Passanger_Flight(VP, F);
					}
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Edit Departure And Arrival Date
					system("cls");
					Edit_Date_Flight(F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Edit Arrival And Arrival City
					system("cls");
					Edit_City_Flight(F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 4) {
					// [4] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing EM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Show_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|              [1] => Show Passanger Informations            |",
				"|------------------------------------------------------------|",
				"|               [2] => Show Airplane Informations            |",
				"|------------------------------------------------------------|",
				"|                [3] => Show Flight Informations             |",
				"|------------------------------------------------------------|",
				"|                     [4] => Back To Menu                    |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Show Passanger Informations
					system("cls");
					Show_Passanger_Informations(P);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Show Airplane Informations
					system("cls");
					Show_Airplane_Informations(AP);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Show Flight Informations
					system("cls");
					Show_Flight_Informations(F);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 4) {
					// [4] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing SM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Static_Side() {
	try {
		User_Side = "Static Side";
		system("cls");
		User_Connected();
		Used_Side();
		cout << "" << endl;
		string ch = "0";
		vector<string> static_lines = {
			" ____________________________________________________________ ",
			"|------------------------------------------------------------|",
			"|                         [1] => Add                         |",
			"|------------------------------------------------------------|",
			"|                         [2] => Edit                        |",
			"|------------------------------------------------------------|",
			"|                         [3] => Show                        |",
			"|------------------------------------------------------------|",
			"|                     [4] => Back To Menu                    |",
			"|------------------------------------------------------------|",
			"|____________________________________________________________|"
		};
		Center_Multiple_Strings(static_lines);
		cout << "Enter Your Choice : "; cin >> ch;
		if (!Check_Integer(ch)) {
			system("cls");
			cout << "Enter A Number!!!" << endl;
			system("pause");
			system("cls");
		}
		else {
			if (stoi(ch) == 1) {
				if (!Add_Menu()) {
					Static_Side();
				}
			}
			else if (stoi(ch) == 2) {
				if (!Edit_Menu()) {
					Static_Side();
				}
			}
			else if (stoi(ch) == 3) {
				if (!Show_Menu()) {
					Static_Side();
				}
			}
			else if (stoi(ch) == 4) {
				return false;
			}
			else {
				return false;
			}
		}
		return false;
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing SS Function" << endl;
		system("pause");
		system("cls");
	}
}



bool Add_Dynamic_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|     [1] => Add Passanger To A Flight In Array Flights      |",
				"|------------------------------------------------------------|",
				"|             [2] => Add Flight To Array Flights             |",
				"|------------------------------------------------------------|",
				"|                     [3] => Back To Menu                    |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Add Passanger To A Flight In Array Flights
					system("cls");
					Passanger VP;
					int idv;
					VP.Fill_Info_Passanger();
					cout << "Enter The Flight ID : "; cin >> idv;
					Add_Passanger_Flights(VP, idv, LFlights);
					User_Actions = User_Full_Name + " Added A Passanger To An Array Flight";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Add Flight To Array Flights
					system("cls");
					Flight VF;
					VF.Fill_Info_Flight();
					Add_Flight_Flights(VF, LFlights);
					User_Actions = User_Full_Name + " Added A Flight To An Array Flight";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing ADM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Edit_Dynamic_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|            [1] => Edit Passanger In Array Flights          |",
				"|------------------------------------------------------------|",
				"|           [2] => Edit Flight Date In Array Flights         |",
				"|------------------------------------------------------------|",
				"|           [3] => Edit Flight City In Array Flights         |",
				"|------------------------------------------------------------|",
				"|                    [4] => Back To Menu                     |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Edit Passanger In Array Flights
					Passanger VP;
					system("cls");
					int ID;
					cout << "Enter Passanger ID : "; cin >> ID;
					VP.setID(ID);
					VP.Fill_Info_Passanger();
					Edit_Passanger_Flights(VP, LFlights);
					User_Actions = User_Full_Name + " Edited A Passanger In Array Flight";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Edit Flight Date In Array Flights
					system("cls");
					int ID;
					cout << "Enter Flight ID : "; cin >> ID;
					Edit_Date_Flight_Flights(LFlights, ID);
					User_Actions = User_Full_Name + " Edited A Flight Date In An Array Flight";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Edit Flight City In Array Flights
					system("cls");
					int ID;
					cout << "Enter Flight ID : "; cin >> ID;
					Edit_City_Flight_Flights(LFlights, ID);
					User_Actions = User_Full_Name + " Edited A Flight City In Array Flight";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 4) {
					// [4] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing EDM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Show_Dynamic_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			string ch = "0";
			cout << "" << endl;
			vector<string> lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|                   [1] => Show All Flights                  |",
				"|------------------------------------------------------------|",
				"|              [2] => Show All Flights Passangers            |",
				"|------------------------------------------------------------|",
				"|              [3] => Show All Passanger Flights             |",
				"|------------------------------------------------------------|",
				"|  [4] => Show All Passangers Under 10 Years Old In Flights  |",
				"|------------------------------------------------------------|",
				"|       [5] => Show All Passangers In Array Passangers       |",
				"|------------------------------------------------------------|",
				"|                    [6] => Back To Menu                     |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Show All Flights
					system("cls");
					Show_Flight_Info_Flights(LFlights);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] = > Show All Flights Passangers
					system("cls");
					Show_Only_Passanger_Info_Flights(LFlights);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Show All Passanger Flights
					Passanger VP;
					system("cls");
					int idp;
					VP.Fill_Info_Passanger();
					cout << "Enter The Passanger ID : "; cin >> idp;
					Show_Passanger_Flight_Flights(VP, LFlights);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 4) {
					// [4] => Show All Passangers Under 10 Years Old In Flights
					system("cls");
					Show_Flights_Passanger_10_yrs(LFlights);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 5) {
					// [5] => Show All Passangers In Array Passangers
					system("cls");
					Show_Passangers(LPassangers);
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 6) {
					// [5] => Back To Menu
					return false;
					break;
				}
				else {
					return false;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing SDM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Delete_Menu() {
	try {
		while (true) {
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> dynamic_lines = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|      [1] => Delete Specific Flight From Array Flights      |",
				"|------------------------------------------------------------|",
				"|                  [2] => Delete All Flights                 |",
				"|------------------------------------------------------------|",
				"|                     [3] => Back To Menu                    |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(dynamic_lines);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					// [1] => Delete Specific Flight From Array Flights
					system("cls");
					int ID;
					cout << "Enter Flight ID : "; cin >> ID;
					Delete_Flight_From_Flights(ID, LFlights);
					User_Actions = User_Full_Name + " Deleted A Specific Flight From Array Flights";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 2) {
					// [2] => Delete All Flights
					system("cls");
					Delete_Flights(LFlights);
					User_Actions = User_Full_Name + " Deleted All Flight From Array Flights";
					ExecuteQuery_Log();
					system("pause");
					system("cls");
				}
				else if (stoi(ch) == 3) {
					// [3] => Back To Menu
					return false;
					break;
				}
			}
			return false;

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing DM Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Dynamic_Side() {
	try {
		User_Side = "Dynamic Side";
		system("cls");
		User_Connected();
		Used_Side();
		cout << "" << endl;
		string ch = "0";
		vector<string> dynamic_lines = {
			" ____________________________________________________________ ",
			"|------------------------------------------------------------|",
			"|                         [1] => Add                         |",
			"|------------------------------------------------------------|",
			"|                         [2] => Edit                        |",
			"|------------------------------------------------------------|",
			"|                         [3] => Show                        |",
			"|------------------------------------------------------------|",
			"|                        [4] => Delete                       |",
			"|------------------------------------------------------------|",
			"|                     [5] => Back To Menu                    |",
			"|------------------------------------------------------------|",
			"|____________________________________________________________|"
		};
		Center_Multiple_Strings(dynamic_lines);
		cout << "Enter Your Choice : "; cin >> ch;
		if (!Check_Integer(ch)) {
			system("cls");
			cout << "Enter A Number!!!" << endl;
			system("pause");
			system("cls");
		}
		else {
			if (stoi(ch) == 1) {
				if (!Add_Dynamic_Menu()) {
					Dynamic_Side();
				}
			}
			else if (stoi(ch) == 2) {
				if (!Edit_Dynamic_Menu()) {
					Dynamic_Side();
				}
			}
			else if (stoi(ch) == 3) {
				if (!Show_Dynamic_Menu()) {
					Dynamic_Side();
				}
			}
			else if (stoi(ch) == 4) {
				if (!Delete_Menu()) {
					Dynamic_Side();
				}
			}
			else if (stoi(ch) == 5) {
				return false;
			}
			else {
				return false;
			}
		}
		return false;
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing DS Function" << endl;
		system("pause");
		system("cls");
	}
}

bool Admin_Menu() {
	try {
		while (true) {
			ss = true;
			system("cls");
			User_Connected();
			cout << "" << endl;
			string ch = "0";
			vector<string> admin_lignes = {
				" ____________________________________________________________ ",
				"|------------------------------------------------------------|",
				"|               [1] => Insert All Flights To DB              |",
				"|------------------------------------------------------------|",
				"|        [2] => Fill Program Array With Flights From DB      |",
				"|------------------------------------------------------------|",
				"|                     [3] => Back To Menu                    |",
				"|------------------------------------------------------------|",
				"|____________________________________________________________|"
			};
			Center_Multiple_Strings(admin_lignes);
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1 && idd == true) {
					// [1] => Insert All Flights To DB
					if (Insert_Flights_To_Db(LFlights)) {
						cout << "Data Inserted Successfully" << endl;
						User_Actions = User_Full_Name + " Inserted Data From The Array Flights Into The DB";
						ExecuteQuery_Log();
					}
				}
				else if (stoi(ch) == 2) {
					// [2] => Fill Program Array With Flights From DB
					Get_Flights_DB(LFlights);
					if (LFlights.size() > 0) {
						cout << "Array Flights Have Been Filled Successfully" << endl;
						User_Actions = User_Full_Name + " Filled The Array Flights From The DB";
						ExecuteQuery_Log();
						idd = false;
					}
				}
				else if (stoi(ch) == 3) {
					// [3] => Back To Menu
					return false;
				}
				else {
					return false;
				}
			}
			return false;
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing AM Function" << endl;
		system("pause");
		system("cls");
	}
}



bool All_Menu() {
	try {
		Last_Id_Table = Last_Flight_Id() + 1;
		system("cls");
		User_Connected();
		cout << "" << endl;
		string ch = "0";
		vector<string> lines = {
			" ____________________________________________________________ ",
			"|     First Use The Static Side Before The Dynamic Side      |",
			"|____________________________________________________________|",
			"|                     [1] => Static Side                     |",
			"|------------------------------------------------------------|",
			"|                     [2] => Dynamic Side                    |",
			"|------------------------------------------------------------|",
			"|            [4] => Print All Flights Into A File            |",
			"|------------------------------------------------------------|",
			"|                     [5] => Disconnect                      |",
			"|------------------------------------------------------------|",
			"|____________________________________________________________|"
		};
		if (User_Role == "ADMIN") {
			lines.insert(lines.begin() + 6, "|------------------------------------------------------------|");
			lines.insert(lines.begin() + 7, "|                    [3] => ADMIN SETTINGS                   |");
		}
		Center_Multiple_Strings(lines);
		cout << "Enter Your Choice : "; cin >> ch;
		if (!Check_Integer(ch)) {
			system("cls");
			cout << "Enter A Number!!!" << endl;
			system("pause");
			system("cls");
		}
		else {
			if (stoi(ch) == 1) {
				// [1] => Static Side
				if (!Static_Side()) {
					All_Menu();
				}
			}
			else if (stoi(ch) == 2) {
				// [2] => Dynamic Side
				if (ss == true) {
					if (!Dynamic_Side()) {
						All_Menu();
					}
					else {
						All_Menu();
					}
				}
				All_Menu();
			}
			else if (stoi(ch) == 3) {
				// [3] => ADMIN SETTINGS
				if (User_Role == "ADMIN") {
					if (!Admin_Menu()) {
						All_Menu();
					}
				}
				else {
					system("cls");
					cout << "Insufficient Privilege" << endl;
					system("pause");
					system("cls");
				}
			}
			else if (stoi(ch) == 4) {
				// [4] => Print All Flights Into A File
				Print_Flights(LFlights);
				User_Actions = User_Full_Name + " Printed All The Flights Into Files";
				ExecuteQuery_Log();
				return false;
			}
			else if (stoi(ch) == 5) {
				// [5] => Disconnect
				return false;
			}
			else {
				return false;
			}
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing AM Function" << endl;
		system("pause");
		system("cls");
	}
}