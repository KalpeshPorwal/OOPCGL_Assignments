/*Write C++ program using STL for sorting and searching user defined records such as personal records 
(Name, DOB, Telephone number etc) using vector container.
OR
Write C++ program using STL for sorting and searching user	
defined records such as Item records (Item code, name, cost, quantity etc) using vector container.*/

#include <iostream>    
#include <algorithm>   
#include <vector>    

using namespace std;
class product     
{
      public:   
        char name[10];
        int quantity;
        int cost;
        int code;

        bool operator==(const product& p1)         
    {
        if(code==p1.code)                                           
        return 1;
        return 0;
    }

    bool operator<(const product& p1)
    {
        if(code<p1.code)                                      
        return 1;
        return 0;
    }

};

vector<product> o1; //vector of type item = o1
void print(product &p1);
void display();
void insert();
void search();
void delete_p(); // to delete records

bool compare(const product &p1, const product &p2)
{
   return p1.code < p2.code;
}

int main()
{
    int ch;
      do
    {  
        cout<<"\n***** Main Menu *****";
        cout<<"\n1.Insert Entry";
        cout<<"\n2.Display Entries";
        cout<<"\n3.Search Product";
        cout<<"\n4.Sort Products";
        cout<<"\n5.Delete Entries";
        cout<<"\n6.Exit";
        cout<<"\nEnter your choice:";
        cin>>ch;
       
        switch(ch)
        {
               case 1:
                          insert();
                          break;
                   
               case 2:
                          display();
                          break;
                   
               case 3:
                         search();
                         break;
                              
               case 4:
                        sort(o1.begin(),o1.end(),compare);
                        cout<<"\n\n Sorted on Code";
                        display();
                        break;
                  
               case 5:
                       delete_p();
                        break;
                     
               case 6:
                        exit(0);
        }
   
    }while(ch!=7);

      return 0;
}

void insert()
{
    product p1;
    cout<<"\nEnter Product Name:";
    cin>>p1.name;
    cout<<"\nEnter Product Quantity:";
    cin>>p1.quantity;
    cout<<"\nEnter Product Cost:";
    cin>>p1.cost;
    cout<<"\nEnter Product Code:";
    cin>>p1.code;
    o1.push_back(p1);
}

void display()
{
    for_each(o1.begin(),o1.end(),print);
}

void print(product &p1) // to display entries
{
     cout<<"\n";
     cout<<"\nItem Name:"<<p1.name;
     cout<<"\nItem Quantity:"<<p1.quantity;
     cout<<"\nItem Cost:"<<p1.cost;
     cout<<"\nItem Code:"<<p1.code;
}

void search() // to search among entries
{
    vector<product>::iterator p;
    product p1;
    cout<<"\nEnter Item Code to search:";
    cin>>p1.code;
    p=find(o1.begin(),o1.end(),p1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         cout<<"\nFound.";
    }
}

void delete_p() // to delete entries
{
     vector<product>::iterator p;
    product p1;
    cout<<"\nEnter Item Code to delete:";
    cin>>p1.code;
    p=find(o1.begin(),o1.end(),p1);
    if(p==o1.end())
    {
         cout<<"\nNot found.";
    }
    else
    {
         o1.erase(p);
         cout<<"\nDeleted.";
    }
}
