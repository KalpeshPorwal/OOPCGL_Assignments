/*Wrie a program in C++ to use map associative container. The keys will be the names of states and 
the values will be the populations of the states. When the program runs, 
the user is prompted to type the name of a state.   
The program then looks in the map, 
using the state name as an index and returns the population of the state.*/
	
#include<map>
#include<string>
#include<iterator>
#include<iostream>
#include<fstream>
using namespace std;
//void print();
//void search();
int main()
{
	 // empty map container 
    map<string, int> map_pop; 
  	map<string, int>::iterator itr; 
    // insert elements in random order 
    map_pop.insert(pair<string, int>("Maharashtra",112374333)); 
    map_pop.insert(pair<string, int>("Gujrat",60439692)); 
    map_pop.insert(pair<string, int>("Rajasthan",68548437)); 
    map_pop.insert(pair<string, int>("Panjab",27743338)); 
    map_pop.insert(pair<string, int>("Haryana",25351462)); 
    map_pop.insert(pair<string, int>("Jammu & Kashmir",12267032)); 
    map_pop.insert(pair<string, int>("Uttarakhand",10086292)); 
    map_pop.insert(pair<string, int>("Uttar-Pradesh",199812341)); 
    map_pop.insert(pair<string, int>("Himachal-Pradesh",6864602)); 
    map_pop.insert(pair<string, int>("Sikkim",610577)); 
    map_pop.insert(pair<string, int>("Meghalaya",2966889)); 
    map_pop.insert(pair<string, int>("Nagaland",1978502)); 
    map_pop.insert(pair<string, int>("Assam",31205576)); 
    map_pop.insert(pair<string, int>("Arunachal-Pradesh",1383727)); 
    map_pop.insert(pair<string, int>("Tripura",3673971)); 
    map_pop.insert(pair<string, int>("Mizoram",1097206)); 
    map_pop.insert(pair<string, int>("West-Bengal",91276115)); 
    map_pop.insert(pair<string, int>("Chattisgarh",25545198)); 
    map_pop.insert(pair<string, int>("Manipur",2570390)); 
    map_pop.insert(pair<string, int>("Odisha",41974219)); 
    map_pop.insert(pair<string, int>("Telangana",35003674)); 
    map_pop.insert(pair<string, int>("Andhra-Pradesh",49577103)); 
    map_pop.insert(pair<string, int>("Madhya-Pradesh",72626809)); 
    map_pop.insert(pair<string, int>("Bihar",104099452)); 
    map_pop.insert(pair<string, int>("Jharkhand",32998134)); 
    map_pop.insert(pair<string, int>("Karnataka",61095297)); 
    map_pop.insert(pair<string, int>("Tamilnadu",72147030)); 
    map_pop.insert(pair<string, int>("Kerala",33406061)); 
    map_pop.insert(pair<string, int>("Goa",1458545)); 
    
	int ch;
      do
    {  
        cout<<"\n\t\t\t***** Main Menu *****";
        cout<<"\n\t\t1.Display Population of all States";
        cout<<"\n\t\t2.Search State";
        cout<<"\n\t\t3.Exit";
        cout<<"\n\t\t\tEnter your choice:";
        cin>>ch;
       
        switch(ch)
        {
                   
               case 1:
                          // printing map 
    
					    cout << "\nThe map  is : \n"; 
					    
					    for (itr = map_pop.begin(); itr != map_pop.end(); itr++) { 
					        cout <<"\t"<< itr->first 
					             <<"\t\t\t"<< itr->second << '\n'; 
					    } 
    					cout << endl; 
    					break;
                   
               case 2:
                          	
						 
						    cout<<"\nEnter State Name to search:";
						    string state ;
						    cin>>state;
						    itr = map_pop.find(state);
						    if(itr == map_pop.end())
						    {
						         cout<<"\n Search Not found.";
						    }
						    else
						    {
						         cout<<"\n Search Found\n";
						         cout<<itr->first<<" -> "<<itr->second<<"\n";
						         
						    }
						    
						    cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;       
                         break;
                                  
              
        }
   
    }while(ch!=3);
	cout<<"\n----------- End of Program -----------\n";



	return 0;
}

