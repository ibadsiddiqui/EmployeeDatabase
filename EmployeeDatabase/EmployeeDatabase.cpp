#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void input();
void search();
void edit();
void displayAll();

int main()
{
	system("cls");
	system("Title Ibad Database program");
	system("color 0");
	cout << "Enter choice from below " << endl;
	cout << "1.Input new Employee " << endl;
	cout << "2.Search for employee by ID number " << endl;
	cout << "3.Edit an existing account " << endl;
	cout << "4.Display all employee" << endl;
	cout << "5.Exit " << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		input();
		break;
	case 2:
		search();
		break;
	case 3:
		edit();
		break;
	case 4:
		displayAll();
		break;
	default:
		break;
	}
}

void input()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string filename;
	double salary;
	int empId;
	int age;

	cout << "Enter First Name: ";
	cin >> fname;
	cout << "Enter Middle Name: ";
	cin >> mname;
	cout << "Enter Last Name: ";
	cin >> lname;
	cout << "Enter Employee Age: ";
	cin >> age;
	cout << "Enter Employee Salary: ";
	cin >> salary;
	cout << "Enter Employee ID: ";
	cin >> empId;

	string empId2 = to_string(empId);
	empId2.append(".txt");

	ofstream newemployee(empId2);
	newemployee << fname << " " << mname << " " << lname << " " << empId << " " << salary << " " << age << endl;
	newemployee.close();
	ofstream dir("Directory.txt", ios::app);
	dir << fname << " " << mname << " " << lname << " " << empId << " " << salary << " " << age << endl;
	dir.close();
	main();
}
void search()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string filename;
	double salary;
	int empId;
	int age;
	//	int thrw;
	cout << "Enter Employee ID number: ";
	cin >> empId;
	string empId2 = to_string(empId);
	empId2.append(".txt");
	ifstream employee(empId2);
	while (employee >> fname >> mname >> lname >> empId >> salary >> age)
	{
		int mnameLength = mname.size();
		int lnameLength = lname.size();
		int fnameLength = fname.size();
		int TotalLength = fnameLength + mnameLength + lnameLength;

		string answer;
		cout << "Is this correct Employee[y/n] " << endl;
		cout << fname << " " << mname << " " << lname << " " << empId << " " << salary << " " << age << endl;
		cin >> answer;

		if (answer == "y")
		{
			system("cls");
			cout << "Name";
			for (int y = 1; y < TotalLength; y++)
			{
				cout << " ";
			}

			cout << "Age ";
			for (int z = 1; z < 2; z++)
			{
				cout << " ";
			}

			cout << "Salary ";
			cout << "ID# " << endl;
			for (int y = 1; y < TotalLength + 20; y++)
			{
				cout << "-";
			}
			cout << " " << endl;
			cout << fname << " " << mname << " " << lname << " " << age << "   " << salary << "  " << empId << endl;
		}
	}

}
void edit()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	string newfname;
	string newmname;
	string newlname;
	string decision;
	string filename;
	double salary, newsalary;
	int empId;
	int age, newage;
	//int thrw;

	cout << "Enter the Employee Number, whose data you want to edit: ";
	cin >> empId;

	string empId2 = to_string(empId);
	empId2.append(".txt");

	ifstream employee1(empId2);
	while (employee1 >> fname >> mname >> lname >> empId >> salary >> age)
	{
		cout << "Is this the Employee that you wish to edit? [y/n]: " << endl;
		cout << fname << " " << mname << " " << lname << endl;
		cin >> decision;

		if (decision == "y")
		{
			system("cls");
			cout << "Current Information: " << endl;

			int mnameLength = mname.size();
			int lnameLength = lname.size();
			int fnameLength = fname.size();
			int TotalLength = fnameLength + mnameLength + lnameLength;

			cout << "Name";
			for (int y = 1; y < TotalLength; y++)
			{
				cout << " ";
			}

			cout << "Age ";
			for (int z = 1; z < 2; z++)
			{
				cout << " ";
			}

			cout << "Salary ";
			cout << "ID# " << endl;
			for (int y = 1; y < TotalLength + 20; y++)
			{
				cout << "-";
			}
			cout << " " << endl;
			cout << fname << " " << mname << " " << lname << " " << age << "   " << salary << "  " << empId << endl;

			cout << "Enter new First Name:";
			cin >> newfname;
			cout << "Enter new Middle Name:";
			cin >> newmname;
			cout << "Enter new last Name:";
			cin >> newlname;
			cout << "Enter new Age:";
			cin >> newage;
			cout << "Enter new Salary:";
			cin >> newsalary;
			main();
		}
		if (decision == "n")
			main();

		employee1.close();
		ofstream employee2(empId2);
		employee2 << newfname << newmname << newlname << empId << newsalary << newage << endl;
		employee2.close();
	}
	main();
}
void displayAll()
{
	system("cls");
	string fname;
	string mname;
	string lname;
	int age;
	double salary;
	int empId;

	cout << "Entire Employee Database " << endl;
	cout << "------------------------ " << endl;
	ifstream dir("Directory.txt");
	while (dir >> fname >> mname >> lname >> age >> empId >> salary)
	{
		cout << fname << " " << mname << " " << lname << " " << age << " " << salary << " " << empId << endl;
	}
	system("Pause");
	main();

}
