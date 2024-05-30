 Problem Statement:- Design and implement a simple Employee Management System using C++ that allows the user to perform various operations such as inserting, searching,
 displaying, and deleting employee records. The records should be stored in a file for persistence.


#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct employee
{
	long int emp_id;
	string name;
	string designation;
	int salary;
};
employee e[10];
int n , i;
void insert()
{
	ofstream f;
	f.open("employee.txt", ios::app);
	cout<<"Enter the number of employee data "<<endl;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the employee id"<<endl;
		cin>>e[i].emp_id;
		cout<<"Enter the name of employee"<<endl;
		cin>>e[i].name;
		cout<<"Enter the employee designation"<<endl;
		cin>>e[i].designation;
		cout<<"Enter the employee salary"<<endl;
		cin>>e[i].salary;
		f<<"\t"<< e[i].emp_id<<" \t"<< e[i].name<<"\t"<<  e[i].designation<<"\t"<<e[i].salary<<endl;
		cout<<"data inserted successfully"<<endl;
	}
	f.close();
}
void search()
{
	int id;
	cout<<"search employee id"<<endl;
	cout<<"enter the employee id"<<endl;
	cin>>id;
	for(i=0;i<n;i++)
	{
		if(id==e[i].emp_id)
		{
			cout<<"found the employee details"<<endl;
			cout<<"Name of employee"<<e[i].name<<endl;
			cout<<"designation of employee"<<e[i].designation<<endl;
			cout<<"Salary of employee"<<e[i].salary<<endl;
		}
	}
	cout<<"Record not found";
}
void display()
{
	for(i=0;i<n;i++)
	{
		cout<<"All data of employee"<<endl;
		cout<<"Name of the student: "<<e[i].name<<endl;
		cout<<"id of employee: "<<e[i].emp_id<<endl;
		cout<<"designation of employee: "<<e[i].designation<<endl;
		cout<<"salary of employee: "<<e[i].salary<<endl;		
	}
}
void delete1()
{
	int id;
	cout<<"Enter the emp_id";
	cin>>id;
	for(i=0;i<n;i++)
	{
		if(id==e[i].emp_id)
		{
			for(int j=i;j<n;j++)
			{
				e[j].name=e[j+1].name;
				e[j].emp_id=e[j+1].emp_id;
				e[j].designation=e[j+1].designation;
				e[j].salary=e[j+1].salary;
			}
		}
	}
	cout<<"delete succesfully";
	return;
}
int main()
{
	ofstream f("employee.txt", ios::out);
	insert();
	search();
	display();
	delete1();
	display();
	return 0;
}
