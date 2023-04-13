#pragma once

int ID_PASSANGER = 1;

class Passanger {
private:
	int ID = ID_PASSANGER, age;
	string lastname, firstname, phonenumber, adresse, nationality;
public:
	// Constructor
	Passanger() {
		age = 0;
		lastname = "RANDOM";
		firstname = "RANDOM";
		phonenumber = "0000000000";
		adresse = "RANDOM";
		nationality = "RANDOM";
		ID_PASSANGER++;
	}
	Passanger(int a, string n, string p, string tel, string adr, string nat) {
		age = a;
		lastname = n;
		firstname = p;
		phonenumber = tel;
		adresse = adr;
		nationality = nat;
		ID_PASSANGER++;
	}

	// Setters
	void setID(int id) { ID = id; }
	void setAge(int a) { age = a; }
	void setLastName(string n) { lastname = n; }
	void setFirstName(string p) { firstname = p; }
	void setPhoneNumber(string tel) { phonenumber = tel; }
	void setAdresse(string adr) { adresse = adr; }
	void setNationality(string nat) { nationality = nat; }

	// Getters
	int getID() { return ID; }
	int getAge() { return age; }
	string getLastName() { return lastname; }
	string getFirstName() { return firstname; }
	string getPhoneNumber() { return phonenumber; }
	string getAdresse() { return adresse; }
	string getNationality() { return nationality; }

	// Other Functions
	void Fill_Info_Passanger() {
		cout << "Enter The Passanger First Name : "; cin >> firstname;
		cout << "Enter The Passanger Last Name : "; cin >> lastname;
		cout << "Enter The Passanger Age : "; cin >> age;
		cout << "Enter The Passanger Adresse : "; cin >> adresse;
		cout << "Enter The Passanger Phone Number : "; cin >> phonenumber;
		cout << "Enter The Passanger Nationality : "; cin >> nationality;
	}

	void Get_Info_Passanger() {
		cout << "Passanger ID : " << ID << endl;
		cout << "Passanger First Name : " << firstname << endl;
		cout << "Passanger Last Name : " << lastname << endl;
		cout << "Passanger Age : " << age << endl;
		cout << "Passanger Adresse : " << adresse << endl;
		cout << "Passanger Phone Number : " << phonenumber << endl;
		cout << "Passanger Nationality : " << nationality << endl;
	}

	// Destructor
	~Passanger() {}
};