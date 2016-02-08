#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
using namespace std;

void Input();
void Search();
void Edit();
void DisplayAll();
void Delete();

int main()
{
	system("cls");
	system("Title Employee Database program");
	system("color 0");
	cout << "\n\t\t\tEnter choices from below: " << endl;
	cout << "1.Input new Employee " << endl;
	cout << "2.View an Employee Data by ID number " << endl;
	cout << "3.Edit an existing Employee Data " << endl;
	cout << "4.Display all Employee." << endl;
	cout << "5.Delete an existing Employee Data. " << endl;
	cout << "6.Exit \n" << endl;

	int choice;
	cout << "\tChoice :";
	cin >> choice;
	switch (choice)
	{
		case 1:
			Input();
			break;
		case 2:
			Search();
			break;
		case 3:
			Edit();
			break;
		case 4:
			DisplayAll();
			break;
		case 5:
			Delete();
			break;
		default:
			break;
	}
}

void Input()
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
void Search()
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
void Edit()
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
void DisplayAll()
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
void Delete()
{
	
	int File;
	cout << "Enter Employee ID to delete the Data: ";
	cin >> File;
	
	string empId = to_string(File);
	empId.append(".txt");
	const char *mycharp = empId.c_str();

	if (remove(mycharp) != 0)
		cout << "Remove operation failed" << endl;
	else
	{
		_sleep(2000);
		cout << File << " has been removed." << endl;
	}

}