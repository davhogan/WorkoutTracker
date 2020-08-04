//David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include "tree.h"
using namespace std;

//T_NODE Class
//Default constrcutor
t_node::t_node():name(NULL),days_left(0),fin_time(0),years_pass(0),head(NULL),right(NULL),left(NULL)
{}

//Copy Constructor to do a deep copy
t_node::t_node(t_node* &t)
{
   int len=0;
 
   len=strlen(t->name);
   name=new char[len+1];
   strcpy(name,t->name);
    
   len=strlen(t->fin_time);
   fin_time=new char[len+1];
   strcpy(fin_time,t->fin_time);
 
   days_left=t->days_left;
   years_pass=t->years_pass;
  
   head=t->head;
   right=t->right;
   left=t->left;
}

//Constructor given a name, days left, previous finish time,and years since the last race
t_node::t_node(const char* a_name, int ds_left, char* f_time, float yrs_p)
{
   int len=0;
   
   len=strlen(a_name);
   name=new char[len+1];
   strcpy(name,a_name);
   
   len=strlen(f_time);
   fin_time=new char[len+1];
   strcpy(fin_time,f_time);
  
   days_left=ds_left;
   years_pass=yrs_p;
  
   head=NULL;
   right=NULL;
   left=NULL;

}

//Destructor
t_node::~t_node()
{
  delete name;
  name=NULL;
  delete head;
  head = NULL;
  delete right;
  right=NULL;
  delete left;
  left=NULL;
}

//Gets the left node of the tree node
t_node* t_node::go_left()
{
  return left;
}

//Gets the right node of the tree node
t_node* t_node::go_right()
{
  return right;
}

//Sets the left node 
bool t_node::setLeft(t_node* &dest)
{
  left=dest;
  return true;
}

//Set the right node
bool t_node::setRight(t_node* &dest)
{
  right=dest;
  return true;
}

//Copies the t_nodes name into a given name
bool t_node::copyName(char* a_name)
{
   int len=0;
   len=strlen(name);
   a_name=new char[len+1];
   strcpy(a_name,name);
   return true;

}
//Get the head of the list
bool t_node::getHead(l_node* &dest)
{
   dest=head;
   return true;
}

//Inserts a exercise into the front of the list.
//Takes in an exercise to add then adds it to the front of the list.
bool t_node::insert(l_node* &curr, l_node* &to_add)
{     
    l_node * next=curr;

    //Nothing to add
    if(to_add==NULL)
       return false;
    //Nothing in the list.
    if(head==NULL)
    {
       head=to_add;
       return true;
    }       
    //Add to the front of the list.
    else
    {
      to_add->setNext(head);//Put the node to add at the front.
      head=to_add;//Set head to new destination.
      return true;
    }
   curr->getNext(next);//get the next node in the list.
   insert(next,to_add);//Recursive step.
}

//Displays the entire list of exercises.
//Recurisvely goes through the list and displays the exercises.
bool t_node::displayList(l_node* &curr)
{
   l_node * next = NULL;
   if(curr==NULL)
    return false;

   curr->getNext(next);
   //Empty List
   if(head==NULL)
    return false;
   //Base Case at the end of the list
   if(next==NULL)
   {
     curr->display();
     return true;
   }
   curr->getNext(next);
   displayList(next);
   curr->display();
}

//Displays all information for a race
bool t_node::display()
{
  cout<<"Name of Race: "<<name<<endl;
  cout<<"Days until race: "<<days_left<<endl;
  cout<<"Previous finish time: "<<fin_time<<endl;
  cout<<"Years since last attempt: "<<years_pass<<endl;
  cout<<"Exercises to do: "<<endl;
  displayList(head); 
}

//Operatro overload > compares the caller's years since to the callee's year since.
//Returns true if the caller's years are more than the callee
bool t_node::operator > (const t_node& t)
{
    if(this->years_pass > t.years_pass)
      return true;
    else
      return false;
}

//Operatro overload >= compares the caller's years since to the callee's year since.
//Returns true if the caller's years are more or equal to the callees
bool t_node::operator >= (const t_node& t)
{
    if(this->years_pass >= t.years_pass)
      return true;
    else
      return false;
}

//Operatro overload > compares the caller's years since to the callee's year since.
//Returns true if the caller's years are less than the callee's.
bool t_node::operator < (const t_node& t)
{
    if(this->years_pass < t.years_pass)
      return true;
    else
      return false;
}

//Operatro overload <= compares the caller's years since to the callee's year since.
//Returns true if the caller's years are less than equal to the callee's.
bool t_node::operator <= (const t_node& t)
{
    if(this->years_pass <= t.years_pass)
      return true;
    else
      return false;
}

//BST CLASS
//Default constructor
bst::bst():root(NULL)
{}
//Copy constructor to make a deep copy
bst::bst(const bst& b)
{
  root=b.root;
}
//Destructor
bst::~bst()
{
  delete root;
  root=NULL;
}
//Get the root of the BST
bool bst::getRoot(t_node* &dest)
{
   dest=root;
   return true;
}
//Recursively go through and insert into the BST
t_node* bst::insert(t_node* &root, t_node* &to_add)
{
   t_node * right = NULL;
   t_node * left = NULL;
   //Empty Child
   if(root==NULL)
   {
      root= new t_node(to_add);
      return root;
   }
   left=root->go_left();//get the left
   right=root->go_right();//get the right

   //To add is newer than the root   
   if(to_add <= root)
   {
      left=insert(left,to_add);
      root->setLeft(left);
   }

   //To add is older than the root
   else if(to_add > root)
   {
      right=insert(right,to_add);
      root->setRight(right);
   }

   return root;
}
//Recursively go through the tree and display all information for a tree node.
bool bst::displayTree(t_node* root)
{
  if(root != NULL)
  {
    displayTree(root->go_left());//go to the left
    root->display();//display the current nodes data
    displayTree(root->go_right());//go to the right

  }
  return true;
}

//Recursively search the BST for the race given the name.
bool bst::displayRace(t_node* root, char * a_race)
{
   char * a_name = NULL;
   root->copyName(a_name);
   int check = strcmp(a_name,a_race);

   if(root==NULL) 
     return false;
   displayRace(root->go_right(),a_race);//Go right
  //At the race with the given name
    if(check==0)
      root->display();

   displayRace(root->go_left(),a_race);//Go Left

    return true;
}
