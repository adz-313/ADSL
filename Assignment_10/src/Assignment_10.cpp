//============================================================================
// Name        : Assignment_10.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;

class Student
{
	int roll_no;
	string name;
	string temp,address;
	char division;
public:
	void create();
	void insert();
	void display();
	void delet();
	void find();
};

void Student::create()
{
	int n;
	cout << "Enter number of entries: ";
	cin >> n;
	ofstream fout;
	fout.open("Student.txt", ios::out|ios::app);
	for(int i=0;i<n;i++)
	{
		cout << "Enter roll number: ";
		cin >> roll_no;
		cin.ignore(1);
		cout << "Enter name: ";
		getline(cin,name);
		cout << "Enter division: ";
		cin >> division;
		cin.ignore(1);
		cout << "Enter address: ";
		getline(cin,address);
		fout << name << "\t" << roll_no << "\t" << division << "\t" << address << "\n";
	}
	fout.close();
}

void Student::insert()
{
	cout << "Enter roll number: ";
	cin >> roll_no;
	cin.ignore(1);
	cout << "Enter name: ";
	getline(cin,name);
	cout << "Enter division: ";
	cin >> division;
	cin.ignore(1);
	cout << "Enter address: ";
	getline(cin,address);
	ofstream fout;
	fout.open("Student.txt", ios::out|ios::app);
	fout << name << "\t" << roll_no << "\t" << division << "\t" << address << "\n";
	fout.close();
}

void Student::display()
{
	ifstream fin;
	fin.open("Student.txt",ios::in|ios::app);
	cout << "Name\tRollNo\tDiv\tAddress";
	string temp;
	fin.seekg(0,ios::beg);
	while(fin.eof() == 0)
	{
		getline(fin,temp);
		cout << "\n" << temp;
	}
	fin.close();
}

void Student::delet()
{
	ifstream fin;
	fin.open("Student.txt",ios::in|ios::app);
	string temp,name,temp2,temp3;
	cout << "\nEnter name of student whose record is to be deleted: ";
	getline(cin,name);
	fin.seekg(0,ios::beg);
	int flag = 0;
	ofstream fout;
	fout.open("yolo.txt", ios::out);
	int cnt = 0;
	while(fin.eof() == 0 && fin.tellg() != -1)
	{
		fin >> temp;
		if(temp == name)
		{
			flag = 1;
		}
		if(flag == 1)
		{
			for(int i=0;i<4;i++)
			{
				fin >> temp;
			}
			flag = 0;
            cnt = 0;
		}
		fout << temp;
		if(cnt == 3)
        {
            cnt = 0;
            fout << "\n";
        }
        else
        {
            cnt++;
            fout << "\t";
        }
	}
	fout.close();
	fin.close();
	cnt = 0;
	fin.open("yolo.txt",ios::in|ios::app);
	fout.open("Student.txt",ios::out | ios::trunc);
	while(fin.eof() == 0)
	{
		fin >> temp2;
		if(temp2 != temp3)
		{
			fout << temp2;
			if(cnt == 3)
			{
			    cnt = 0;
			    fout << "\n";
			}
			else
			{
			    cnt++;
			    fout << "\t";
			}
		}
		temp3 = temp2;
	}
	fin.close();
	fout.close();
}

void Student::find()
{
    ifstream fin;
	fin.open("Student.txt",ios::in|ios::app);
	string temp,name;
	cout << "\nEnter name of student whose record is to be searched: ";
	getline(cin,name);
	fin.seekg(0,ios::beg);
	int flag = 0;
	while(!fin.eof())
	{
		fin >> temp;
		if(temp == name)
		{
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
        for(int i=0;i<4;i++)
		{
		    cout << temp << "\t";
			fin >> temp;
		}
		fin.close();
		return;
	}
	cout << "Record not found.\n";
}

int main()
{
	Student a;
	cout << "1. Create Database.\n";
	cout << "2. Display Database.\n";
	cout << "3. Insert into Database.\n";
	cout << "4. Search from Database.\n";
	cout << "5. Delete from Database.\n";
	cout << "6. Exit.\n";
	int ch;
	while(1)
	{
		cout << "Enter choice: ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				a.create();
				break;

			case 2:
				a.display();
				break;

			case 3:
				a.insert();
				break;

			case 4:
				cin.ignore(1);
				a.find();
				break;

			case 5:
				cin.ignore(1);
				a.delet();
				break;

			case 6:
				return 0;

			default:
				cout << "Invalid choice.\n";
		}
	}
	return 0;
}
