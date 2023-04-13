#pragma once

bool Login_User(string username, string password) {
	try {
		if (Open_Connection()) {
			int query_state;
			string query = "SELECT id_user, nom, prenom, libellerole FROM users U, roles R WHERE U.id_role=R.id_role AND U.username='" + username + "' AND U.password ='" + password + "'";
			const char* q = query.c_str();
			query_state = mysql_query(conn, q);
			res = mysql_store_result(conn);
			while (row = mysql_fetch_row(res))
			{
				User_Id = string(row[0]);
				User_Full_Name = string(row[2]) + " " + string(row[1]);
				User_Role = string(row[3]);
				return true;
			}
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