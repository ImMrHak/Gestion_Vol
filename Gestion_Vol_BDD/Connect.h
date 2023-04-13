#pragma once
#define GESTION_VOL_CONFIG "config/Gestion_Vol_DB.config"

MYSQL* conn;
MYSQL_ROW row;
MYSQL_ROW rows;
MYSQL_RES *res;
MYSQL_RES *ress;

string server_ip = "localhost";
string server_username = "root";
string server_password = "";
string server_db = "Gestion_VolDB";
int server_port = 3006;
char* server_unix_socket = NULL;
int server_client_flag = 0;

bool Open_Connection() {
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, server_ip.c_str(), server_username.c_str(), server_password.c_str(), server_db.c_str(), 3006, server_unix_socket, 0);
	if (conn) {
		return true;
	}
	else {
		cout << "The Program Will Turn Off Automatically After Pressing Any Key" << endl;
		cout << "ERROR : CONNECTION WITH DATABASE NOT ETABLISHED" << endl;
		system("pause");
		exit(0);
		return false;
	}
}

bool ExecuteQuery_Log() {
	try {
		if (Open_Connection()) {
			Date today(ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900);
			string query = "INSERT INTO logs(motif, datelog, id_user) VALUES('" + User_Actions + "','" + today.FullDate_Insert_DB() + "','" + User_Id + "')";
			mysql_query(conn, query.c_str());
			mysql_commit(conn);
			return true;
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing EU Function" << endl;
		system("pause");
		system("cls");
	}
	return false;
}

void Get_DB_Info() {
	ifstream file("config/Gestion_Vol_DB.config");
	string line;
	vector<string> fields;
	while (std::getline(file, line)) {
		stringstream ss(line);
		string field;
		while (std::getline(ss, field, ':')) {
			fields.push_back(field);
		}
	}
	file.close();

	server_ip = fields[1];
	server_username = fields[3];
	server_password = fields[5];
	server_db = fields[7];
	server_port = stoi(fields[9]);
}
