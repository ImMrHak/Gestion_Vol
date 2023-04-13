#pragma once
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4018)
#include <iostream>
#include <mysql.h>
#include <string>
#include <chrono>
#include <vector>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <codecvt>
#include <windows.h>

using namespace std;

time_t now = time(0);
tm *ltm = localtime(&now);

struct Date {
	int day = (ltm->tm_mday);
	int month = (ltm->tm_mon + 1);
	int year = (ltm->tm_mon + 1900);

	Date() {

	}

	Date(int d, int m, int y) {
		setYear(y);
		setMonth(m);
		setDay(d);
	}

	void setYear(int y) {
		year = y;
	}

	void setMonth(int m) {
		if (m > 12) {
			month = m % 12;
			if (month == 0) {
				month = 12;
			}
			year++;
		}
		else if (m < 1) {
			month = 12;
			year--;
		}
		else {
			month = m;
		}
	}

	void setDay(int d) {
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && d > 0 && d <= 31) {
			day = d;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && d > 0 && d <= 30) {
			day = d;
		}
		else if (month == 2 && d > 0 && d <= 28) {
			day = d;
		}
		else if (month == 2 && d > 0 && d <= 29 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
			day = d;
		}
		else {
			day = 1;
			setMonth(month + 1);
		}
	}

	void setDate() {
		int d, m, y;
		cout << " Enter The Day : "; cin >> d;
		cout << " Enter The Month : "; cin >> m;
		cout << " Enter The Year : "; cin >> y;
		setYear(y);
		setMonth(m);
		setDay(d);
	}

	bool LaterThan(const Date& otherDate) const {
		if (year > otherDate.year) {
			return true;
		}
		else if (year < otherDate.year) {
			return false;
		}
		else {
			if (month > otherDate.month) {
				return true;
			}
			else if (month < otherDate.month) {
				return false;
			}
			else {
				return (day > otherDate.day);
			}
		}
	}

	bool AreEqual(const Date& otherDate) const {
		if (year == otherDate.year) {
			return true;
		}
		else if (month == otherDate.month) {
			return true;
		}
		else if(day == otherDate.day){
			return true;
		}
		else {
			return false;
		}
	}

	string FullDate() {
		string FullDate = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
		return FullDate;
	}
	string FullDate_Insert_DB() {
		string FullDate = to_string(year) +"/" + to_string(month) + "/" + to_string(day);
		return FullDate;
	}
};

static string User_Id;
static string User_Full_Name;
static string User_Role;
static string User_Actions;
static string User_Side;
static int Last_Id_Table;

#include "Own_Functions.h"
#include "Menu_Account.h"
#include "Menu.h"