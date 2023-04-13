#pragma once
#include "Header.h"
#include "Passanger.h"
#include "Airplane.h"

class Flight {
private:
	int ID = Last_Id_Table + 1;
	vector<Passanger> Passangers;
	Airplane Ap;
	Date Departure_Date, Arrival_Date;
	string Departure_City, Arrival_City;
public:
	// Constructor
	Flight() {
		ID++;
	}

	// Setters
	void setID(int id) { ID = id; }
	void setPassangers(vector<Passanger> allpassangers) { Passangers = allpassangers; }
	void setAirplane(Airplane ap) { Ap = ap; }
	void setDepartureDate(Date dp) { Departure_Date = dp; }
	void setArrivalDate(Date da) { Arrival_Date = da; }
	void setDepartureCity(string vd) { Departure_City = vd; }
	void setArrivalCity(string va) { Arrival_City = va; }

	// Getters
	int getID() { return ID; }
	vector<Passanger>& getPassangers() { return Passangers; }
	Airplane& getAirplane() { return Ap; }
	Date& getDepartureDate() { return Departure_Date; }
	Date& getArrivalDate() { return Arrival_Date; }
	string getDepartureCity() { return Departure_City; }
	string getArrivalCity() { return Arrival_City; }

	// Other Functions
	void Fill_Info_Flight() {
		cout << "" << endl;
		cout << "Enter The Airplane Informations : " << endl;
		cout << "" << endl;
		Ap.Fill_Info_Airplane();
		int nb_p;
		cout << "" << endl;
		cout << "Enter The Numbers Of Passengers You Want To Enter : "; cin >> nb_p;
		for (int i = 0;i<nb_p;i++) {
			Passanger P;
			cout << "Enter Passenger Information Number : " << i + 1 << endl;
			P.Fill_Info_Passanger();
			Passangers.push_back(P);
		}
		cout << "" << endl;
		cout << "Enter Departure Date : " << endl;
		Departure_Date.setDate();
		cout << "" << endl;
		cout << "Enter Arrival Date : " << endl;
		Arrival_Date.setDate();
		cout << "" << endl;
		string vp, va;
		cout << "Enter Departure City : "; cin >> vp;
		setDepartureCity(vp);
		cout << "" << endl;
		cout << "Enter Arrival City : "; cin >> va;
		setArrivalCity(va);
	}

	void Get_Info_Flight() {
		cout << "" << endl;
		cout << "The Flight ID : " << ID << endl;
		cout << "" << endl;
		cout << "Airplane Informations " << endl;
		Ap.Get_Info_Airplane();
		cout << "" << endl;
		char show_p;
		cout << "Do You Want To Display Passengers Informations ?y/n : "; cin >> show_p;
		if (show_p == 'y' || show_p == 'Y') {
			for (int i = 0;i<Passangers.size();i++) {
				cout << "Voici Les Informations Du Passager Numero : " << i + 1 << endl;
				Passangers[i].Get_Info_Passanger();
			}
		}
		cout << "" << endl;
		cout << "Departure Date : " << Departure_Date.FullDate() << endl;
		cout << "" << endl;
		cout << "Arrival Date : " << Arrival_Date.FullDate() << endl;
		cout << "" << endl;
		cout << "Departure City : " << Departure_City << endl;
		cout << "" << endl;
		cout << "Arrival City : " << Arrival_City << endl;
	}

	// Destructor
	~Flight() {}
};