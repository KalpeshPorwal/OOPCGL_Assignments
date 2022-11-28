/*Write a C++ program that creates an output file, writes
information to it, closes the file, open it again as an input file and 
read the information from the file.*/

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
class Student
{
	public:
		char name[20];
		int roll;
		void getdata()
		{
			cout<<"\nEnter name and roll no : \n";
			cin.getline(name,19);
			cin>>roll;
			cin.ignore(1);
		}
		void putdata()
		{
			cout<<name<<" "<<roll<<endl;
		}
};
int main()

{
	fstream fobj;
	fobj.open("D:\\dev_cpp\\student.txt",ios::in|ios::out);
	
	if(fobj.fail()==1)
	{
		cout<<"\ncan't connect\n";
		exit(1);
	}
	Student obj;
	int i;
	for(i=0;i<2;i++)
	{
		obj.getdata();
		fobj.write((char*)&obj,sizeof(obj));
	}
	
	cout<<"Reading object from file\n";
	fobj.seekp(0,ios::beg);
	for(i=0;i<2;i++)
	{
			
	fobj.read((char*)&obj ,sizeof(obj));
	obj.putdata();
	}
	
	fobj.close();



	return 0;
}

