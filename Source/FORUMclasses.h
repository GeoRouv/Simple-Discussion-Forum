#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "FORUMtext.h"
#define NUMOFPOSTS 5
#define NUMOFTHREADS 5

using namespace std;

//////////////////////////////////////////Posts Class////////////////////////////////////////////
class posts{
private:
	int    postid;	//Post ID
	string title;	//Post title
	string creator;	//Post creator
	string text;	//Post text
public:
	int    get_postid(void) {return postid;};
	string get_title(void)  {return title;};
	string get_creator(void){return creator;};
	string get_text(void)	{return text;};
	posts(int i=0,string j=" ",string k=" ",string p=" "):postid(i),creator(j),title(k),text(p){
		if(i!=0){		//Don't print empty array of posts
			cout<<"Post ID:"<<postid<<endl;
			creationdate.print_date();
			cout<<"Creator:"<<creator<<endl;
			cout<<"Title:"<<title<<endl;
			cout<<"Text:"<<text<<"\n"<<endl;
		}
	};
	~posts(){/*cout<<"Post number:"<<postid<<" is about to be destroyed!"<<"\n"<<endl;*/};

	//###DATE###
	class date{
	private:
		int day,month,year;
	public:
		date(){
			day=rand()%30+1;
			month=rand()%12+1;
			year=rand()%5+2011;	
		}; 
		~date(){};
		void print_date(void){
			cout << "Date created: "<<day<<"/"<<month<<"/"<<year<< endl;
		}
	};
	//##########
	
	private:	//creationdate is a private member of post class
		date creationdate;
	public:
		date get_date(void){
			return creationdate;
		}
	
	void print_post(void){	//Print elements of post
		int i=get_postid();
		cout<<"Post ID:"<<i<<endl;
		string k=get_creator();
		posts::date s=get_date();
		s.print_date();
		cout<<"Creator:"<<k<<endl;
		string j=get_title();
		cout<<"Title:"<<j<<endl;
		string l=get_text();
		cout<<"Text:"<<l<<"\n"<<endl;
	}	
};


///////////////////////////////////////////Thread Class////////////////////////////////////////////
class threads{
private:
	string creator;		//Thread creator
	int    numofposts;	//Thread's number of posts
	string subject;		//Thread subject
	posts* Ptr;		//Pointer to posts
	posts arrayposts[5];
public:
	threads(string i=" ",string j=" ",int k=0):subject(i),creator(j),numofposts(k)
	{	if(k!=0){  //Don't print empty array of threads
			cout<<"////////////////////////////////////////////////////////////////"<<"\n"<<endl;
			cout<<"Thread with subject:"<<subject<<" has just been created!"<<endl;
			creationdate.print_date();
			cout<<"Creator:"<<creator<<endl;
			cout<<"Number of posts:"<<numofposts<<"\n"<<endl;
			Ptr=NULL;
			if(creator=="UserA"){			//The first post about RULES&INFORMATION is from ADMIN:UserA
				Ptr=new posts(rand(),strCREATORS[0],strPOSTTITLES[(rand()%5+1)-1],strPOSTTEXTS[(rand()%5+1)-1]);
				arrayposts[0]=*Ptr;
				for(int n=1;n<numofposts;n++){		//Creating posts and making an array of them
				Ptr=new posts(rand(),strCREATORS[(rand()%12+1)-1],strPOSTTITLES[(rand()%5+1)-1],strPOSTTEXTS[(rand()%5+1)-1]);
				arrayposts[n]=*Ptr;
				}			
			}
			else{
				for(int n=0;n<numofposts;n++){		//Creating posts and making an array of them(NOT FOR RULES&INFORMATION)
				Ptr=new posts(rand(),strCREATORS[(rand()%12+1)-1],strPOSTTITLES[(rand()%5+1)-1],strPOSTTEXTS[(rand()%5+1)-1]);
					arrayposts[n]=*Ptr;
				}
			}
		}
	};
	~threads(){/*cout<<"Thread with subject:"<<subject<<" is about to be destroyed!"<<"\n"<<endl;*/};
	string get_subject(void){return subject;};
	string get_creator(void){return creator;};
	int    get_numofposts(void){return numofposts;};
	void   print_subject(void){cout<<subject<<endl;};
	posts* get_post_address(const int& i){ return &(arrayposts[i]); }	

	//###DATE###
	class date{
	private:
		int day,month,year;
	public:
		date(){
			day=rand()%30+1;
			month=rand()%12+1;
			year=rand()%5+2011;	
		};
		~date(){};
		void print_date(void){
			cout << "Date created: "<<day<<"/"<<month<<"/"<<year<< endl;
		}
	};
	//##########

	private:
		date creationdate;
	public:
		date get_date(void){
			return creationdate;
		}

	void print_thread(void){	//Print elements of thread
		string k=get_subject();
		cout<<"Thread with subject:"<<k<<endl;
		threads::date s=get_date();
		s.print_date();
		string p=get_creator();
		cout<<"Creator:"<<p<<endl;
		int v=get_numofposts();
		cout<<"Number of posts:"<<v<<endl;
		cout<<"\n"<<endl;	
	}
};
///////////////////////////////////List Class///////////////////////////////////////

class List {
		struct Node {
			posts data;	//Data in list nodes(Posts)
			Node* next;	//Pointer to next list node

			Node(const posts& p, Node* n = NULL) : data(p), next(n) {				
				//cout << "New Node"<<"\n"<< endl;
			}
		};
		Node* start;
		unsigned int size_;

	public:

		List() : start(NULL), size_(0) {
			//cout << "List creation" << endl;
		}
	
		~List() {
			Node* t1 = start;
			while (t1 != NULL) {	//Deleting every list node...
				Node* t2 = t1;
				t1 = t1->next;
				delete t2;
			}
			//cout << "List destruction" << endl;
		}
	
		unsigned int size() const { return size_; }
	
		void pushFront(const posts& p) {	//Insertion of item in the list
			start = new Node(p, start);	
			size_++;
		}

		posts pop_post(unsigned int index){	//Returning item-post from the list,index is the location of the item
			Node* t=start;
			for(int i=0;i<index;i++){	//Move until you find index-location of item
				t=t->next;
			}
			return t->data;
		}
			
		void print() const {
			Node* t = start;
			while (t != NULL) {
				t->data.print_post();
				t = t->next;
			}
		}

};


/////////////////////////////Tree Class/////////////////////////////////////////
 struct TreeNode {
	List l;			//List of posts
	string data;    	// The data in this node(Creators of posts-Users).
	posts* newnode; 	//Pointer to new node
         TreeNode* left;    	// Pointer to left subtree.
         TreeNode* right;   	// Pointer to right subtree.
		
         TreeNode(posts y) {	// Constructor of tree nodes.  Initializing it with a thread post.
	    l.pushFront(y);	//Inserting post to node list
            left = NULL;
            right = NULL;
         }

	void treeInsertpost(TreeNode* &root, posts* newnode) {
                if(root==NULL){ //Enter to empty tree,insert new node
			root=new TreeNode(*newnode);
			root->data=newnode->get_creator();
			root->left=NULL;
			root->right=NULL;	
		}
		else {		//Non-empty tree
			if(newnode->get_creator()<root->data)	//Go to left subtree
				treeInsertpost(root->left,newnode);
			else{
				if(newnode->get_creator()>root->data)	//Go to right subtree
					treeInsertpost(root->right,newnode);
				else	
					if(newnode->get_creator()==root->data){
						root->l.pushFront(*newnode);
					}	
			}
		}
       }  // end treeInsert()

	void Inorder(TreeNode* &root){	//Inorder print of nodes
    		if(root != NULL){
      	 	 Inorder(root->left);
		 cout<<"~~~~~~~~~~~~"<<endl;
        	 cout << root->data <<endl;
		 root->l.print();
       		 Inorder(root->right);
		}
	} //end Inorder()

	void merge(TreeNode* &root,TreeNode* &targetroot){
		if(root != NULL){
			int k=root->l.size();		//Getting the size of the list in this node
			for(int i=0;i<k;i++){		//Run until the end of the list
				posts p=root->l.pop_post(i);			//Get post from list
				targetroot->treeInsertpost(targetroot,&p);	//and insert it to target tree
			}
			merge(root->left,targetroot);
			merge(root->right,targetroot);			  	 	 	
		}				
	} //end merge()


	void delete_tree(TreeNode *root){	//Recursive deletion of tree
    		if(root!=NULL){
        		delete_tree(root->left);
       			delete_tree(root->right);
        		delete(root);
        		if(root->left!=NULL) root->left=NULL;
        		if(root->right!=NULL) root->right=NULL;
        		root=NULL;
   		}
	} //end delete_tree()


};  // end struct Treenode



////////////////////////////////////////////////Forum Class//////////////////////////////////////
class forum{
private:
	TreeNode* root0,*root1,*root2,*root3,*root4;	//Tree roots-pointers
	string title;			//Title of forum
	int    numofthreads;		//Forum's number of threads
	threads* ptr;			//Pointer to the array of threads
	threads  arraythreads[5];	//Array of threads
public:
	forum(string i,int j):title(i),numofthreads(j)
	{	
		cout<<"Forum with title:"<<title<<" has just been created!It contains 5 threads and each of them 5 posts!"<<"\n"<<endl;
		ptr=NULL;
		cout<<"////////////////////////////////////////////////////////////////"<<endl;	//Creating thread:Rules of forum
		ptr=new threads(strTHREADTITLES[0],strCREATORS[0],NUMOFPOSTS);
		arraythreads[0]=*ptr;	
		for(int n=1;n<numofthreads;n++){		//Creating threads & making an array for them
			cout<<"////////////////////////////////////////////////////////////////"<<endl;
			ptr=new threads(strTHREADTITLES[rand()%(5+1-1)+1],strCREATORS[(rand() % (11 + 1 - 1) + 1)],NUMOFPOSTS);
			arraythreads[n]=*ptr;
		} 
	};
	~forum(){	cout<<"/////////////////////////////////////////////////////////////"<<"\n"<<endl;
			/*cout<<"Forum with title:"<<title<<" is about to be destroyed!"<<endl;*/};	
	void print_forum(void);			
	void print_rules(void);
	void print_random(void);
	void print_threads(void){			//Print all thread titles
		for(int i=0;i<numofthreads;i++){
			arraythreads[i].print_subject();
		}
	}
	void print_specthread(void){			//Print a specified thread
		string g;				//g,k,v=temporary variables
		cin>>g;
		string k;
		for(int i=0;i<numofthreads;i++){
			k=arraythreads[i].get_subject();
			if(g==k){			//If input thread title matches to thread then print all of its contents
				arraythreads[i].print_thread();				
				int v=arraythreads[i].get_numofposts();
				for(int j=0;j<v;j++){
					arraythreads[i].get_post_address(j)->print_post();
				}
		
			}
		}
	}
	void print_sorted(void){
		for(int j=0;j<5;j++){	 //Creating trees...one for each thread...
			root0->treeInsertpost(root0,arraythreads[0].get_post_address(j));
			root1->treeInsertpost(root1,arraythreads[1].get_post_address(j));
			root2->treeInsertpost(root2,arraythreads[2].get_post_address(j));
			root3->treeInsertpost(root3,arraythreads[3].get_post_address(j));
			root4->treeInsertpost(root4,arraythreads[4].get_post_address(j));
		}
		cout<<"\n"<<endl;
		root0->merge(root1,root0);	//Merging all trees with the first one...
		root0->merge(root2,root0);
		root0->merge(root3,root0);
		root0->merge(root4,root0);

		root0->Inorder(root0);		//Inorder print of tree0...

		root0->delete_tree(root0);	//Deleting trees...
		root1->delete_tree(root1);
		root2->delete_tree(root2);
		root3->delete_tree(root3);
		root4->delete_tree(root4);
	};

};









		
	
