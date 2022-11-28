/*Imagine a publishing company which does marketing for book and audio cassette versions. 
Create a class publication that stores the title (a string) and price (type float) of publications. 
From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). 
Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. 
If an exception is caught, replace all the data member values with zero values.*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class publication
{
	protected:
		char title[30];
		float price ;
	public:
		publication()
		{
			strcpy(title,"All about Satellites");
			price = 0.0;
		}
		publication(float p)
		{
			strcpy(title,"All about Satellites");
			price = p;
		}
		
		
};
class book : public publication
{
	int pagecount;
	public:
		book():publication()
		{
			pagecount = 0;
		}
		book( float p , int pgcnt):publication(p)
		{
			pagecount = pgcnt;
		}
		void getdata()
		{
				cin.ignore(1);
			cout<<"\n Enter name of the book : ";
			cin.getline(title,29);
			cout<<"\n Enter price of the book : ";
			cin>>price;
			cout<<"\n Enter pages of book : ";
			cin>>pagecount;
		}
		void display()
		{
			cout<<"\n	*****************	\n";
			cout<<" Title of the book is ==> "<<title<<endl;
			cout<<" Price of the book is ==> "<<price<<endl;
			cout<<" Total pages in book are ==> "<<pagecount<<endl;
			cout<<"\n	*****************	\n";
		}
};
class Tape : public publication
{
	float time ;
	public:
		Tape():publication()
		{
			time = 0;
		}
		Tape( float p , float t):publication(p)
		{
			time = t;
		}
		void getdata()
		{
			cin.ignore(1);
			cout<<"\n Enter name of the book : ";
			cin.getline(title,29);
			cout<<"\n Enter price of the book : ";
			cin>>price;
			cout<<"\n Enter the time in min : ";
			cin>>time;
		}
		void show()
		{
			cout<<"\n	*****************	\n";
			cout<<" Title of the book is ==> "<<title<<endl;
			cout<<" Price of the book is ==> "<<price<<endl;
			cout<<" Total time in minutes ==> "<<time<<endl;
			cout<<"\n	*****************	\n";
		}
};
int main()
{
	cout<<"\n			BOOK DATA			\n"<<endl;
	book B2( 450 , 1020);
	B2.display();
	cout<<"\n			TAPE DATA			\n"<<endl;
	Tape T1(150,200.45);
	T1.show();

	book *B;
	Tape *T;
	int n;
	int ch;
	char ans;
	cout<<"\nEnter count of Books : ";
	cin>>n;
	cout<<"\n	*****************	\n";

	do
	{
		cout<<"\n  1 -> Create Datebase for Books \n";
		cout<<"\n  2 -> Create Datebase for Tapes \n";
		cout<<"\n  3 -> Display Database of Books \n";
		cout<<"\n  4 -> Display Database of Tapes \n";
		cout<<"\n  5 -> Exit\n";
		cout<<"\n Enter your choice \n ";
		cin>>ch;
		switch(ch)
		{
			case 1 : 
			{
				for(int i=0;i<n;i++)
				{
					B = new book[n];
					B->getdata();
				}
				break;
			}
			
			case 2 : 
			{
				for(int i=0;i<n;i++)
				{
					T = new Tape[n];
					T->getdata();
				}
				break;
			}
			
			case 3 : 
			{
				for(int i=0;i<n;i++)
				{
					B->display();
				}
				break;
			}
					 
			case 4 : 
			{
				for(int i=0;i<n;i++)
				{
					T->show();
				}
				break;
			}
			case 5 : exit(0);
			
			default : cout<<"\nYou have entered an Invalid Choice ! ";
		}
		cout<<"\nDo you want to continue ? \n";
		cin>>ans;
	}while(ans=='y');


	return 0;
}

