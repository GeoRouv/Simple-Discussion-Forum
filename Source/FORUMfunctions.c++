#include <string.h>
#include <iostream>
#include "FORUMclasses.h"
#include "FORUMtext.h"
#include <stdlib.h>
#include <time.h>


using namespace std;


////////////FORUM FUNCTIONS///////////////

void forum::print_forum(void){						//Printing forum and its elements...
	cout<<"Forum title:"<<title<<"\n"<<endl;
	for(int i=0;i<numofthreads;i++){				//Printing all threads...
		arraythreads[i].print_thread();		
		int v=arraythreads[i].get_numofposts();
		for(int j=0;j<v;j++){					//Printing all their posts...
			arraythreads[i].get_post_address(j)->print_post();				
		}
		cout<<"//////////////////////////////////////////////"<<"\n"<<endl;
	}
}

void forum::print_rules(void){		//Printing rules of forum...
	string g="Κανόνες και χρήσιμες πληροφορίες";
	string k;
	for(int i=0;i<numofthreads;i++){
		k=arraythreads[i].get_subject();
		if(g==k){					//If input thread title matches to thread then print all of its contents
			arraythreads[i].print_thread();			
			int v=arraythreads[i].get_numofposts();
			for(int j=0;j<v;j++){
				arraythreads[i].get_post_address(j)->print_post();
			}
		
		}
	}
	cout<<"///////////////////////////////////////////////////////////////"<<"\n"<<endl;
}

void forum::print_random(void){		//Printing random posts...
	string k;
	for(int i=0;i<numofthreads;i++){
		int y=rand() % (4 + 1 - 0) + 0;			//Printing a random post from each thread...
		arraythreads[i].get_post_address(y)->print_post();
	}
}

	



















	
	
