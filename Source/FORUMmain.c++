#include <string.h>
#include <iostream>
#include "FORUMclasses.h"
#include "FORUMtext.h"
#include <stdlib.h>
#include <time.h>
#define NUMOFTHREADS 5

const string z="Αντικειμενοστραφής Προγραμματισμός";

using namespace std;

int main(){
	int x=-1;
	srand(time(NULL));
	cout<<"Create forum??"<<endl;
	cout<<"Type 1 for yes , or 0 for no."<<endl;
	cin>>x;
	if(x==0){
		cout<<"Exiting program..."<<endl;
		return 0;
	}
	forum f(z,NUMOFTHREADS);	//Creating forum...
	int c=-1;
	while(c!=0){
		cout<<"Choose Command:"<<endl<<"0.Exit"<<endl
		                             /*<<"1.Print forum"<<endl
					     <<"2.Print rules of forum"<<endl
					     <<"3.Print random posts"<<endl*/
					     <<"4.Print sorted"<<"\n"<<endl;	
		cin>>c;
		switch(c){
			case 0:
				cout<<"Exiting program..."<<endl;
				break;
			/*case 1:{
				f.print_forum();
				break;
			}
			case 2:{
				f.print_rules();
				break;
			}
			case 3:{
				f.print_random();
				break;
			}*/
			case 4:{
				f.print_sorted();
				c=0;
				break;
			}
			default:
				cout<<"Invalid Command"<<endl;
		}
		cout<<endl;
	}
	
return 0;
}




