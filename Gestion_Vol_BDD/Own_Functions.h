#pragma once

void Center_Text(string output) {
	// Determine the width of the console window
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	// Calculate the number of spaces to print before the output
	int numSpaces = (consoleWidth / 2) - (output.length() / 2);

	// Print the spaces before the output
	for (int i = 0; i < numSpaces; i++) {
		std::cout << " ";
	}
	// Print the output
	std::cout << output << std::endl;
}

bool Check_Integer(string input)
{
	bool isNeg = false;
	int itr = 0;
	if (input.size() == 0)
		return false;
	if (input[0] == '-')
	{
		isNeg = true;
		itr = 1;
	}

	for (int i = itr;i<input.size();i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}

void Center_Multiple_Strings(vector<string> ln) {
	for (int i = 0; i < ln.size(); i++)
	{
		Center_Text(ln[i]);
	}
}

vector<string> split(string& str, char delimiter) {
	// Vector to store the output
	vector<string> output;

	// Use strtok to split the string by the delimiter
	char* p = strtok(&str[0], &delimiter);
	while (p) {
		// Push the token onto the vector
		output.push_back(p);

		// Get the next token
		p = strtok(nullptr, &delimiter);
	}

	return output;
}

void Create_Config_File() {
	ifstream file("config/Gestion_Vol_DB.config");
	if (!file) {
		std::string dir_name = "config";
		wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
		wstring dir_name_wide = converter.from_bytes(dir_name);
		BOOL status = CreateDirectory(dir_name_wide.c_str(), NULL);
		std::ofstream file("config/Gestion_Vol_DB.config");
		ofstream foutput;
		ifstream finput;
		string file_name = "config/Gestion_Vol_DB.config";
		finput.open(file_name);
		foutput.open(file_name, ios::app);
		foutput << "server_ip:" << "localhost" << endl << "server_username:" << "root" << endl << "server_password:" << "testpassword" << endl << "server_db:" << "Gestion_VolDB" << endl << "server_port:" << "3006" << endl;
		finput.close();
		foutput.close();
	}
}