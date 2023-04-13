#pragma once

class Airplane {
private:
	string apcode, pilot, model;
	int stock;
	Date Manufacture_Date;
public:
	// Constructor
	Airplane() {
		apcode = "RANDOM";
		pilot = "RANDOM";
		model = "RANDOM";
		stock = 0;
	}
	Airplane(string ca, string pil, string mod, int stk, Date df) {
		apcode = ca;
		pilot = pil;
		model = mod;
		stock = stk;
		Manufacture_Date = df;
	}

	// Setters
	void setapcode(string ca) { apcode = ca; }
	void setPilot(string pil) { pilot = pil; }
	void setModel(string mod) { model = mod; }
	void setStock(int stk) { stock = stk; }
	void setDateManufacturen(Date df) { Manufacture_Date = df; }

	// Getters
	string getapcode() { return apcode; }
	string getPilot() { return pilot; }
	string getModel() { return model; }
	int getStock() { return stock; }
	Date& getDateManufacturen() { return Manufacture_Date; }

	// Other Functions
	void Fill_Info_Airplane() {
		cout << "Enter The Code Of The Airplane : "; cin >> apcode;
		cout << "Enter The Pilot : "; cin >> pilot;
		cout << "Enter The Model Of The Airplane : "; cin >> model;
		cout << "Enter Stock Capacity : "; cin >> stock;
		cout << "Enter The Date Of Manufacturing : "; Manufacture_Date.setDate();
	}

	void Get_Info_Airplane() {
		cout << "Airplane Code : " << apcode << endl;
		cout << "Airplane Pilot : " << pilot << endl;
		cout << "Airplane Model : " << model << endl;
		cout << "Airplane Stock Capacity : " << stock << endl;
		cout << "Airplane Date Of Manufacturing : " << Manufacture_Date.FullDate() << endl;
	}

	// Destructor
	~Airplane() {}
};