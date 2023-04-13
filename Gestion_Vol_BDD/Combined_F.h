#pragma once
                                                         // FUNCTIONS TO CHECK MULTIPLE THINGS \\

														         // CHEKCING INFORMATION \\

bool Check_Passanger_Exists_Flight(Passanger& passanger, Flight& flight) {
	for (int i = 0; i < flight.getPassangers().size(); i++) {
		if (flight.getPassangers()[i].getID() == passanger.getID()) {
			return true;
		}
	}
	return false;
}

bool Check_Flights_Exists(vector<Flight>& flights,int idvol) {
	for (int i = 0; i < flights.size(); i++) {
		if (flights[i].getID() == idvol) {
			return true;
		}
	}
	return false;
}

bool Check_Airplane_Exists_Flight(Airplane& airplane, Flight& flight) {
	if (flight.getAirplane().getapcode() == airplane.getapcode()) {
		return true;
	}
	return false;
}

bool Check_Passanger_Exists_Passangers(Passanger& passanger, vector<Passanger> passangers) {
	for (int i = 0; i < passangers.size(); i++) {
		if (passangers[i].getID() == passanger.getID() &&
			passangers[i].getPhoneNumber() == passanger.getPhoneNumber()
			) {
			return true;
		}
	}
	return false;
}

bool Check_Flight_Flights(Flight& fight, vector<Flight>& flights) {
	for (int i = 0;i < flights.size();i++) {
		if (
			flights[i].getAirplane().getapcode() == fight.getAirplane().getapcode() &&
			flights[i].getDepartureDate().AreEqual(fight.getDepartureDate())&&
			flights[i].getArrivalDate().AreEqual(fight.getArrivalDate())
			) {
			return true;
		}
	}
	return false;
}

bool Check_Passanger_Flights(Passanger& passanger, vector<Flight>& flights) {
	for (int i = 0;i < flights.size();i++) {
		if (Check_Passanger_Exists_Flight(passanger, flights[i])) {
			return true;
		}
	}
	return false;
}

                                                   // FUNCTIONS TO BE ABLE TO PERFORM MULTIPLE THINGS \\

                                                                 // ADDING INFORMATION \\

void Add_Passanger_Flight(Passanger& passanger, Flight& flight) {
	if (!Check_Passanger_Exists_Flight(passanger, flight)) {
		flight.getPassangers().push_back(passanger);
		cout << "" << endl;
		cout << "Passanger Added Successfully" << endl;
		cout << "" << endl;
	}
}

void Add_Airplane_Flight(Airplane& airplane, Flight& flight) {
	if (!Check_Airplane_Exists_Flight(airplane, flight)) {
		flight.setAirplane(airplane);
		cout << "" << endl;
		cout << "Airplane Added Successfully" << endl;
		cout << "" << endl;
	}
}

void Add_Passanger_Passangers(Passanger& passanger, vector<Passanger>& passangers) {
	if (!Check_Passanger_Exists_Passangers(passanger, passangers)) {
		passangers.push_back(passanger);
		cout << "" << endl;
		cout << "Passanger Have Been Added Successfully To THe Passangers Array" << endl;
		cout << "" << endl;
	}
}

void Add_Passangers_Flight(vector<Passanger>& passangers, Flight& flight) {
	for (int i = 0;i < passangers.size();i++) {
		if (!Check_Passanger_Exists_Flight(passangers[i], flight)) {
			flight.getPassangers().push_back(passangers[i]);
		}
	}
}

void Add_Flight_Flights(Flight& flight, vector<Flight>& flights) {
	if (!Check_Flight_Flights(flight, flights)) {
		flights.push_back(flight);
		cout << "" << endl;
		cout << "Flight Have Been Added To The Array Flights" << endl;
		cout << "" << endl;
	}
}

void Add_Passanger_Flights(Passanger& passanger, int idvol, vector<Flight>& flights) {
	if (Check_Flights_Exists(flights, idvol)) {
		for (int i = 0;i < flights.size();i++) {
			if (flights[i].getID() == idvol) {
				flights[i].getPassangers().push_back(passanger);
				cout << "" << endl;
				cout << "Passanger Have Been Added Successfully" << idvol << endl;
				cout << "" << endl;
			}
		}
	}
}

                                                                 // EDITING INFORMATION \\

void Edit_Passanger_Flight(Passanger& passanger, Flight& flight) {
	if (Check_Passanger_Exists_Flight(passanger, flight)) {
		vector<Passanger> passangers = flight.getPassangers();
		for (int i = 0; i < passangers.size(); i++) {
			if (passangers[i].getID() == passanger.getID()) {
				flight.getPassangers()[i] = passanger;
				cout << "" << endl;
				cout << "Passanger Modified Successfully" << endl;
				cout << "" << endl;
			}
		}
	}
}

void Edit_Passanger_Flights(Passanger& passanger, vector<Flight>& flights) {
	for (int i = 0; i < flights.size(); i++) {
		Edit_Passanger_Flight(passanger, flights[i]);
	}
}

void Edit_Date_Flight(Flight& flight) {
	Date newDateDepart;
	Date newDateArrive;
	cout << "" << endl;
	cout << "Departure Date : " << endl;
	cout << "" << endl;
	newDateDepart.setDate();
	cout << "" << endl;
	cout << "Arrival Date : " << endl;
	cout << "" << endl;
	newDateArrive.setDate();
	Date today(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
	if (newDateDepart.LaterThan(today)) {
		flight.setDepartureDate(newDateDepart);
		flight.setArrivalDate(newDateArrive);
		cout << "" << endl;
		cout << "Departure And Arrival Date Have Been Edited Successfully" << endl;
		cout << "" << endl;
	}
}

void Edit_Date_Flight_Flights(vector<Flight>& flights, int idvol) {
	if (Check_Flights_Exists(flights, idvol)) {
		for (int i = 0;i < flights.size();i++) {
			if (flights[i].getID() == idvol) {
				Edit_Date_Flight(flights[i]);
			}
		}
	}
}

void Edit_City_Flight(Flight& flight) {
	string villeDepart, villeArrive;
	cout << "Enter Departure City : "; cin >> villeDepart;
	cout << "Enter Arrival City : "; cin >> villeArrive;
	flight.setDepartureCity(villeDepart);
	flight.setArrivalCity(villeArrive);
	cout << "" << endl;
	cout << "Departure And Arrival City Have Been Edited Successfully" << endl;
	cout << "" << endl;
}

void Edit_City_Flight_Flights(vector<Flight>& flights, int idvol) {
	if (Check_Flights_Exists(flights, idvol)) {
		for (int i = 0;i < flights.size();i++) {
			if (flights[i].getID() == idvol) {
				Edit_City_Flight(flights[i]);
			}
		}
	}
}

                                                                  // SHOWING INFORMATION \\

void Show_Passanger_Informations(Passanger& passanger) {
	passanger.Get_Info_Passanger();
}

void Show_Airplane_Informations(Airplane& airplane) {
	airplane.Get_Info_Airplane();
}

void Show_Flight_Informations(Flight& flight) {
	flight.Get_Info_Flight();
}

void Show_Flight_Info_Flights(vector<Flight>& flights) {
	for (int i = 0;i < flights.size();i++) {
		cout << "" << endl;
		flights[i].Get_Info_Flight();
		cout << "" << endl;
	}
}

void Show_Only_Passanger_Info_Flights(vector<Flight>& flights) {
	for (int i = 0;i < flights.size();i++) {
		for (int y = 0; y < flights[i].getPassangers().size();i++) {
			cout << "Flight Number : " << flights[i].getID() << endl;
			cout << "" << endl;
			Show_Passanger_Informations(flights[i].getPassangers()[y]);
			cout << "" << endl;
		}
	}
}

void Show_Passanger_Flight_Flights(Passanger& passanger, vector<Flight>& flights) {
	for (int i = 0; i < flights.size(); i++) {
		if (Check_Passanger_Exists_Flight(passanger, flights[i])) {
			cout << "" << endl;
			flights[i].Get_Info_Flight();
			cout << "" << endl;
		}
	}
}

void Show_Flights_Passanger_10_yrs(vector<Flight>& flights) {
	cout << "Those Are The Passangers Less Than 10 Years Old : " << endl;
	for (int i = 0; i < flights.size(); i++) {
		for (int j = 0; j < flights[i].getPassangers().size(); j++) {
			if (flights[i].getPassangers()[j].getAge() <= 10) {
				cout << "" << endl;
				cout << "Flight ID : " << flights[i].getID() << endl;
				cout << "" << endl;
				flights[i].getPassangers()[j].Get_Info_Passanger();
				cout << "" << endl;
			}
		}
	}
}

void Show_Passangers(vector<Passanger>& passagers) {
	cout << "Those Are All Passangers In Array Passanger : " << endl;
	for (int i = 0;i < passagers.size();i++) {
		cout << "" << endl;
		cout << "Passanger Number " << i + 1 << endl;
		passagers[i].Get_Info_Passanger();
		cout << "" << endl;
	}
}

                                                                 // DELETING INFORMATION \\

void Delete_Flights(vector<Flight>& flights) {
	for (int i = flights.size() - 1; i >= 0; i--) {
		flights.erase(flights.begin() + i);
	}
	cout << "All Flights Have Been Deleted Successfully" << std::endl;
}

void Delete_Flight_From_Flights(int idv, vector<Flight>& flights) {
	bool found = false;
	for (int i = 0; i < flights.size(); i++) {
		if (flights[i].getID() == idv) {
			flights.erase(flights.begin() + i);
			found = true;
		}
	}
	if (found) {
		cout << "Flight ID " << idv << " have been deleted successfully." << endl;
	}
	else {
		cout << "No flights were found with ID " << idv << "." << endl;
	}
}

                                                              // PRINTING FLIGHTS INTO A FILE \\

void Print_Flights(vector<Flight>& flights) {
	for (int i = 0;i < flights.size();i++) {
		vector<Passanger> passangers = flights[i].getPassangers();
		ofstream foutput;
		ifstream finput;
		string namefile = "Flight_" + to_string(i + 1) + ".docx"; // Document Word : docx // Document Text : txt // Document : pdf
		if (!finput.is_open()) {
			finput.open(namefile);
			foutput.open(namefile, ios::app);
			foutput << "Flight Number : " << i + 1 << endl;
			foutput << "" << endl;
			foutput << "Flight ID : " << flights[i].getID() << endl;
			foutput << "Flight Departure Date : " << flights[i].getDepartureDate().FullDate() << endl;
			foutput << "Flight Arrival Date : " << flights[i].getArrivalDate().FullDate() << endl;
			foutput << "Flight Departure City : " << flights[i].getDepartureCity() << endl;
			foutput << "Flight Arrival City : " << flights[i].getArrivalCity() << endl;
			foutput << "" << endl;
			for (int j = 0;j < passangers.size();j++) {
				foutput << "Passanger Number : " << j + 1 << endl;
				foutput << "Passanger ID : " << passangers[j].getID() << endl;
				foutput << "Passanger Last Name : " << passangers[j].getLastName() << endl;
				foutput << "Passanger First Name : " << passangers[j].getFirstName() << endl;
				foutput << "Passanger Age : " << passangers[j].getAge() << endl;
				foutput << "Passanger Phone Number : " << passangers[j].getPhoneNumber() << endl;
				foutput << "Passanger Adresse : " << passangers[j].getAdresse() << endl;
				foutput << "Passanger Nationality : " << passangers[j].getNationality() << endl;
			}
			foutput << "" << endl;
			foutput << "Airplane Code : " << flights[i].getAirplane().getapcode() << endl;
			foutput << "Airplane Pilot : " << flights[i].getAirplane().getPilot() << endl;
			foutput << "Airplane Model : " << flights[i].getAirplane().getModel() << endl;
			foutput << "Airplane Stock : " << flights[i].getAirplane().getPilot() << endl;
			foutput << "Airplane Manufacture Date : " << flights[i].getAirplane().getDateManufacturen().FullDate() << endl;
			foutput << "" << endl;
			finput.close();
			foutput.close();
		}
	}
	cout << "" << endl;
	cout << "Printing Flights To A TXT/DOC File Was Successful" << endl;
	cout << "" << endl;
}


                                                  // ADDING TO DATABASE + EVERYTHING RELATED TO DATABASE USAGE \\

int Last_Flight_Id() {
	int ID = 0;
	string query = "SELECT id_flight FROM flights ORDER BY id_flight DESC LIMIT 1";
	const char* q = query.c_str();
	mysql_query(conn, q);
	res = mysql_store_result(conn);
	while (row = mysql_fetch_row(res))
	{
		ID = stoi(string(row[0]));
	}
	return ID;
}

bool Insert_Flights_To_Db(vector<Flight>& flights) {
	try {
		if (Open_Connection()) {
			for (int i = 0;i < flights.size();i++) {
				Airplane VAP = flights[i].getAirplane();
				string query = "INSERT INTO flights(apcode, pilot, model, stock, Manufacture_Date, Departure_Date, Arrival_Date, Departure_City, Arrival_City) VALUES('" + VAP.getapcode() + "','" + VAP.getPilot() + "','" + VAP.getModel() + "','" + to_string(VAP.getStock()) + "','" + VAP.getDateManufacturen().FullDate_Insert_DB() + "','" + flights[i].getDepartureDate().FullDate_Insert_DB() + "','" + flights[i].getArrivalDate().FullDate_Insert_DB() + "','" + flights[i].getDepartureCity() + "','" + flights[i].getArrivalCity() + "')";
				mysql_query(conn, query.c_str());
				mysql_commit(conn);
				for (int y = 0;y < flights[i].getPassangers().size();y++) {
					Passanger VP = flights[i].getPassangers()[y];
					string query1 = "INSERT INTO passangers(lastname, firstname, age, phonenumber, adresse, nationality, id_flight) VALUES('" + VP.getLastName() + "','" + VP.getFirstName() + "','" + to_string(VP.getAge()) + "','" + VP.getPhoneNumber() + "','" + VP.getAdresse() + "','" + VP.getNationality() + "','" + to_string(Last_Flight_Id()) + "')";
					mysql_query(conn, query1.c_str());
					mysql_commit(conn);
				}
			}
			return true;
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing IFD Function" << endl;
		system("pause");
		system("cls");
	}
	return false;
}

void Get_Flights_DB(vector<Flight>& flights) {
	try {
		if (Open_Connection()) {
			string query = "SELECT id_flight, apcode, pilot, model, stock, Manufacture_Date, Departure_Date, Arrival_Date, Departure_City, Arrival_City FROM flights";
			const char* q = query.c_str();
			mysql_query(conn, q);
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				Flight flight;
				flight.setID(stoi(row[0]));
				flight.getAirplane().setapcode(string(row[1]));
				flight.getAirplane().setPilot(string(row[2]));
				flight.getAirplane().setModel(string(row[3]));
				flight.getAirplane().setStock(stoi(row[4]));

				vector<string> splited_date_manufactor = split(string(row[5]), '-');
				flight.getAirplane().getDateManufacturen().setYear(stoi(splited_date_manufactor[0]));
				flight.getAirplane().getDateManufacturen().setMonth(stoi(splited_date_manufactor[1]));
				flight.getAirplane().getDateManufacturen().setDay(stoi(splited_date_manufactor[2]));

				vector<string> splited_date_departure = split(string(row[6]), '-');
				flight.getDepartureDate().setYear(stoi(splited_date_departure[0]));
				flight.getDepartureDate().setMonth(stoi(splited_date_departure[1]));
				flight.getDepartureDate().setDay(stoi(splited_date_departure[2]));

				vector<string> splited_date_arrival = split(string(row[7]), '-');
				flight.getArrivalDate().setYear(stoi(splited_date_arrival[0]));
				flight.getArrivalDate().setMonth(stoi(splited_date_arrival[1]));
				flight.getArrivalDate().setDay(stoi(splited_date_arrival[2]));

				flight.setDepartureCity(string(row[8]));
				flight.setArrivalCity(string(row[9]));

				string query1 = "SELECT id_passanger, lastname, firstname, age, phonenumber, adresse, nationality FROM passangers WHERE id_flight='" + to_string(flight.getID()) + "'";
				const char* q1 = query1.c_str();
				mysql_query(conn, q1);
				ress = mysql_store_result(conn);
				while (rows = mysql_fetch_row(ress)) {
					Passanger passanger;
					passanger.setID(stoi(rows[0]));
					passanger.setLastName(string(rows[1]));
					passanger.setFirstName(string(rows[2]));
					passanger.setAge(stoi(rows[3]));
					passanger.setPhoneNumber(string(rows[4]));
					passanger.setAdresse(string(rows[5]));
					passanger.setNationality(string(rows[6]));
					flight.getPassangers().push_back(passanger);
				}
				flights.push_back(flight);
			}

		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing GFDB Function" << endl;
		system("pause");
		system("cls");
	}
}