#pragma once

bool Register_User(string nom, string prenom, string adresse_mail, string username, string password, Date birthdate) {
	try {
		if (Open_Connection()) {
			string query = "INSERT INTO users(nom, prenom, adresse_mail, username, password, birthdate, id_role) VALUES('" + nom + "','" + prenom + "','" + adresse_mail + "','" + username + "','" + password + "', '" + birthdate.FullDate_Insert_DB() + "', 2)";
			int query_state = mysql_query(conn, query.c_str());
			if (query_state != 0) {
				return false;
			}
			int commit_state = mysql_commit(conn);
			if (commit_state != 0) {
				return false;
			}
			return true;
		}
	}
	catch (...) {
		system("cls");
		cout << "Error When Executing LU Function" << endl;
		system("pause");
		system("cls");
	}
	return false;
}