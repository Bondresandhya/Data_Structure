Problem Statement:-Design and implement a C++ program that allows the user to input the names of cities and the distances between each pair of cities. 
The program should store these distances in an adjacency matrix and display the matrix in a tabular format.



#include<iostream>
using namespace std;
int adj_mat[30][30];
string cities[30];
int i, j, n;
void display_mat()
{
	for(i=0;i<n;i++)
	{
		cout<<"\t"<<cities[i]<<"\t"; //column
	}
	for(i=0;i<n;i++)
	{
		cout<<"\n"<<cities[i];
		for(j=0;j<n;j++)
		{
			cout<<"\t"<<adj_mat[i][j]<<"\t"; //row
		}
	}
};
int main()
{
	cout<<"Enter the number of cities"<<"\t";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter city"<<"\t";
		cin>>cities[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			cout<<"distance between two cities are "<<cities[i]<<"and"<<cities[j]<<":";
			cin>>adj_mat[i][j];
			adj_mat[j][i]=adj_mat[i][j];
		}
	}
    cout<<endl;
display_mat();
return 0;
}
