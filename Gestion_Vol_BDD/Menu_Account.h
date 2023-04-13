#pragma once
#include "Connect.h"
#include "Login.h"
#include "Register.h"

int LR_Account() {
	try {
		system("cls");
		bool cc = false;
		while (!cc) {
			string ch = "0";
			string nom, prenom, adresse_mail, username, password;
			Date birthdate;
			vector<string> menu_connect = {
				" ____________________________ ",
				"|       MENU CONNECION       |",
				"|____________________________|",
				"|         1 =>Login          |",
				"|                            |",
				"|        2 =>Register        |",
				"|                            |",
				"|         3 =>Exit           |",
				"|____________________________|"
			};
			Center_Multiple_Strings(menu_connect);
			cout << "" << endl;
			cout << "Enter Your Choice : "; cin >> ch;
			if (!Check_Integer(ch)) {
				system("cls");
				cout << "Enter A Number!!!" << endl;
				system("pause");
				system("cls");
			}
			else {
				if (stoi(ch) == 1) {
					system("cls");
					cout << " _______________________ " << endl;
					cout << "| Login To Your Account |" << endl;
					cout << "|_______________________|" << endl;
					cout << "|   =>Username : ======> "; cin >> username;
					cout << "|                       |" << endl;
					cout << "|   =>Password : ======> "; cin >> password;
					cout << "|_______________________|" << endl;
					if (Login_User(username, password)) {
						return 1;
					}
					system("cls");
				}
				else if (stoi(ch) == 2) {
					system("cls");
					cout << " _______________________ " << endl;
					cout << "| Register Your Account |" << endl;
					cout << "|_______________________|" << endl;
					cout << "|   =>First Name ======> "; cin >> prenom;
					cout << "|                       |" << endl;
					cout << "|   =>Last Name =======> "; cin >> nom;
					cout << "|                       |" << endl;
					cout << "|   =>Email Adresse ===> "; cin >> adresse_mail;
					cout << "|                       |" << endl;
					cout << "|   =>Username ========> "; cin >> username;
					cout << "|                       |" << endl;
					cout << "|   =>Password ========> "; cin >> password;
					cout << "|                       |" << endl;
					cout << "|   =>Date Of Birth ===> " << endl; birthdate.setDate();
					cout << "|_______________________|" << endl;
					if (Register_User(nom, prenom, adresse_mail, username, password, birthdate)) {
						return 2;
						break;
					}
					system("cls");
				}
				else if (stoi(ch) == 3) {
					exit(0);
				}
				else {
					system("cls");
					cout << "Incorrecte Choice" << endl;
					system("pause");
					system("cls");
				}
				break;
			}
			break;
		}
	}
	catch (...){
		system("cls");
		cout << "Error When Executing LRA Function" << endl;
		system("pause");
		system("cls");
	}
}