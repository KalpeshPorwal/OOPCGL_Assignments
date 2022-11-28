/*Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.*/

#include<iostream>
using namespace std;
#define size 10
int n;

template<class T>
void selection_sort(T A[size])
{
    int i,j,min;
    T temp;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            min=j;
        }
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
    cout<<"\nSorted array:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<" "<<A[i];
    }
}

int main()
{
    int A[size];
    float B[size];
    int i;
    int  ch;
    char ans;
    
   
    do
    {
    	cout<<"\n\t1)to sort integer elements";
    	cout<<"\n\t2)to sort float elements\n";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1 : cout<<"\nEnter total no of int elements : ";
    					cin>>n;
   					 cout<<"\nEnter int elements : \n";
    				for(i=0;i<n;i++)
    				{
        				cin>>A[i];
    				}
    				selection_sort(A);
    				
    				break;
    		case 2 :  cout<<"\nEnter total no of float elements : ";
    				cin>>n;
    				cout<<"\nEnter float elements : \n";
    				for(i=0;i<n;i++)
    				{
        				cin>>B[i];
    				}	
    				selection_sort(B);
    				break;
    			
    		case 0 : exit(0);
    		default : cout<<"\nIncorrect choice \n";
    	}
    	cout<<"\nWant to continue ? \n";
    	cin>>ans;
	}while(ans=='y');
}
