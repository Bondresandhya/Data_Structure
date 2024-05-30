Problem Statement:-
Design and implement a system using C++ that allows the user to input marks of students and then determine the minimum and
maximum marks using heap data structures. The system should maintain two heaps: a min-heap for finding the minimum marks and a max-heap
for finding the maximum marks.






#include<iostream>
using namespace std;

class heap
{
	int n, k;
	int *minheap, *maxheap;
	public:
		void get()
		{
			cout<<"Enter the number of students";
			cin>>n;
			minheap=new int[n];
			maxheap=new int[n];
			cout<<"Enter the marks of student";
			for(int i=0;i<n;i++)
			{
				cin>>k;
				minheap[i]=k;
				upAdjust(0,i);
				maxheap[i]=k;
				upAdjust(1,i);
			}
		}
		void upAdjust(bool m, int l)
		{
			int s;
			if(!m)
			{
				while(minheap[(l-1)/2]>minheap[l])
				{
					s=minheap[l];
					minheap[(l-1)/2]=minheap[l];
				    minheap[(l-1)/2]=s;
				    l=(l-1)/2;
				    if(l==-1)
				     break;
				}
				while(maxheap[(l-1)/2]<maxheap[l])
				{
					s=maxheap[l];
					maxheap[(l-1)/2]=maxheap[l];
					maxheap[(l-1)/2]=s;
					l=(l-1)/2;
					if(l==-1)
					 break;
				}
			}
		}
		void displaymin()
		{
			cout<<"minimum marks are"<<minheap[0]<<endl;
		}
		void displaymax()
		{
			cout<<"maximum marks are "<<maxheap[0]<<endl;
		}
};
int main()
{
	heap h;
	h.get();
	h.displaymin();
	h.displaymax();
	return 0;
}

