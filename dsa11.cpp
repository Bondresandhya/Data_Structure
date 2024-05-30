Problem Statement - Design and implement a simple Student Management System using C++ that allows the user to perform various operations such as inserting,
 searching, displaying, and deleting student records. The records should be stored in a file for persistence.





#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct stud
{
	int roll;
	string name;
	char div;
	string add;
};
stud s[10];
int n;
void insert()
{

   ofstream f;
   f.open("student.txt",ios::app);
   cout<<"Enter the number of student ";
   cin>>n;
   for(int i=0;i<n;i++)
   {
   	cout<<"Enter th name of student ";
   	cin>>s[i].name;
   	cout<<"Enter the roll no of student";
   	cin>>s[i].roll;
   	cout<<"Enter the division of student";
   	cin>>s[i].div;
   	cout<<"Enter the address of student";
   	cin>>s[i].add;
   	f  <<"\t"<<s[i]. roll<<"\t"  <<s[i]. name<<"\t" << s[i].div<<"\t"  << s[i].add<<"\t" << endl;
   	//f.write((char *)&s[i],sizeof(s[i]));
   	cout<<"data insert succesfully"<<endl;
   }
   f.close();
}
void search()
{
	int r;
	cout<<"Enter the roll number to search"<<endl;
	cin>>r;
	for(int i=0;i<n;i++)
	{
		if(r==s[i].roll)
		{
			cout<<"record found"<<endl;
			cout<<"Name is: "<<s[i].name<<endl;
			cout<<"Division is: "<<s[i].div<<endl;
			cout<<"Address is: "<<s[i].add<<endl;
			return;
		}
	}
		cout<<"Record not found "<<endl;
}
void display()
{
	cout<<"-All records"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Roll number is :"<<s[i].roll<<endl;
		cout<<"name is:"<<s[i].name<<endl;
		cout<<"Division is :"<<s[i].div<<endl;
		cout<<"Address is :"<<s[i].add<<endl;
	}
}
void delete1()
{
	int r;
	cout<<"enter roll number to delete"<<endl;
	cin>>r;
	for(int i=0;i<n;i++)
	{
		if(r==s[i].roll)
		{
			for(int j=i;j<n;j++)
			{
				s[j].name=s[j+1].name;
				s[j].roll=s[j+1].roll;
				s[j].div=s[j+1].div;
				s[j].add=s[j+1].add;
			}
			cout<<"Data deleted successfully";
			return;
		}
	}
	cout<<"roll number not exist"<<endl;
}

int main()
{
	ofstream f("student.txt",ios::out);
	insert();
	search();
	display();
    delete1();
	display();
	return 0;
}
