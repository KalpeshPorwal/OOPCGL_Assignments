/*Implement a class Complex which represents the Complex Number data type. Implement the following 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
2. Overload operator+ to add two complex numbers. 
3. Overload operator* to multiply two complex numbers. 
4. Overload operators << and >> to print and read Complex Numbers.*/

#include<iostream> 
using namespace std;
class Complex  //Class for complex operations
{
  private:
    int r;	// r = real part
    int i;	// i = imaginary part
  public:
    Complex()	//Constructor
    {
      r=0;
      i=0;
    }
    Complex(int r1,int i1)
    {
      r=r1;
      i=i1;
    }
    ~Complex()//Destructor
    {
      cout<<endl;
    }
    void input()	//function to accept inputs 
    {
      cout<<" Enter real part : "<<endl;
      cin>>r;
      cout<<" Enter imaginary part : "<<endl;
      cin>>i;
    }
    void display()	//function to print complex numbers
    {
    cout<<"\n Complex number is : "<<r<<"+"<<i<<"j"<<endl;
    }
    Complex operator + (Complex & p)	//overloading + operator
    {
    	Complex result;
    	result.r = r + p.r;
    	result.i = i + p.i;
    	return result;
	}
	 Complex operator * (Complex & p)		//overloaded * operator
    {
    	Complex result;
    	result.r = (p.r * r)-(p.i * i);
    	result.i = (p.r * i)+(p.i * r);
    	return result;
	}
	Complex operator -(Complex  &p)	//overloaded - operator
    {
      Complex diff;
      diff.r=r-p.r;
      diff.i=i-p.i;
      return diff;
    }
	friend ostream& operator << (ostream &output, Complex &p);	//Insertion oprator prototype
       
	friend istream& operator >> (istream &input, Complex &p);	//Extraction operator prototype
};
ostream & operator << (ostream &output, Complex & p)	//Insertion operator function
{
  output << " Real Part  is: "<< p.r<<endl;
  output << " Imaginary Part is: "<< p.i<<endl;
}
istream & operator >> (istream & input, Complex &p)	//Extraction operator function
{
    cout<< " Enter real and imaginary part : "<<endl;
    input>>p.r>>p.i;
}

int main()
{
Complex c1,c2,c3,c4,c7;
c1.display();
c1.input();
c1.display();

c2.input();
c2.display();

Complex c5(50,60);
cout<<c5;

Complex c6;
cin>>c6;
cout<<c6;

int i = 0;
int choice;
while(1)
{
	cout<<"\n Enter 1 to display Addition \nEnter 2 to display multiplication  \nEnter 3 to display Substration  \nEnter 0 to exit";
	cout<<"\n Enter your choice : ";
	cin>>choice;
	switch(choice)
{
	case 1 : 	c3 = c1 + c2;
				cout<<"\n After addtion by operator overloading :\n";
				c3.display();
				break;
	case 2 :  	c4 = c1 * c2;
				cout<<"\n After multiplication  by operator overloading :\n";
				c4.display();
				break;
	case 3 : 	c7 = c1 - c2;
				cout<<"\n After substraction by operator overloading:\n";
				c7.display();
				break;
	case 0 :    exit(0);
	default : cout<<"\n Invalid Input"<<endl;
	
}
i++;
}


return 0;
}
