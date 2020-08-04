//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828
#include "exercises.h"
using namespace std;



l_node::l_node():an_exercise(NULL),next(NULL)
{}

//Copy Constructor to make a deep copy of an l_node
l_node::l_node(const l_node* &a_node)
{
  an_exercise=a_node->an_exercise;
  next=a_node->next;
}

//Constructor given a question and a number for the question's number.
l_node::l_node(exercise * exercise_copy)
{
  an_exercise=exercise_copy;
  next=NULL;

}

l_node::~l_node()
{
  delete(an_exercise);
  an_exercise=NULL;
  
}

//Gets the next pointer in the list by copying next to a passed in variable.
bool l_node::getNext(l_node* &copy)
{
    copy=next;
    return true;
}

//Sets the next pointer for an l_node.
//Sets the next pointer to a given pointer.
bool l_node::setNext(l_node* &dest)
{
   next=dest;
   return true;
}

//Displays the exercise information
bool l_node::display()
{
  //cout<<an_exercise;
  an_exercise->display();
}
//Assigns all l_node info to another l_node
l_node& l_node::operator = (const l_node& l)
{
   this->an_exercise=l.an_exercise;
   this->next=l.next;
   return *this;
}
//Adds the second l_node operand after the first one.
//Returns the first node now pointing to the second
l_node l_node::operator + (const l_node& l) 
{
  l_node * temp = l.next;
  temp->next=this->next;
  this->next=temp;
  return *this;
}
//Adds the second l_node operand after the first one.
//Returns the first node now pointing to the second
l_node& l_node::operator += (const l_node& l)
{
  l_node * temp = l.next;
  temp->next=this->next;
  this->next=temp;
  return *this;

}
//Ostrea operator to display an exercises information
ostream& operator << (ostream& out, const l_node& l)
{
   l.an_exercise->display(); 
   return out;
}

//Abstract Base Class: Exercise class

//Constructors
//Default
exercise::exercise():name(NULL),max(0),min(0)
{}

//Copy Constructor to deep copy the exercises' name, max  and min
exercise::exercise(const exercise &an_exercise)
{
   
   int len =0;
 
   len=strlen(an_exercise.name);
   name=new char[len+1];
   strcpy(name,an_exercise.name);
   
   max=an_exercise.max;
   min=an_exercise.min;
}

//Destructors
exercise::~exercise()
{
  delete name;
  name=NULL;
}
//Displays nothing because it is the base class
bool exercise::display()
{
 return false;
}
//Compares the exercise's name to a given name.
//Returns tue of the names match else returns false.
bool exercise::cmpName(char * a_name)
{
   if(!strcmp(a_name,name))
    return true;
   else
    return false;
}

//Compares the exercises's min to a given min.
//Returns true if it matches else it returns false.
bool exercise::cmpMax(int a_max)
{
   if(a_max==max)
     return true;
   else
     return false;
}

//Compares the exercises's max to a given max.
//Returns true if it matches else it returns false.
bool exercise::cmpMin(int a_min)
{
   if(a_min==min)
     return true;
   else
     return false;
}

// != operator returns true if any of the information of the two exercises aren't the same.
bool exercise::operator != (const exercise& e)
{
   
   if(!strcmp(this->name,e.name) && this->min!=e.min && this->max!=e.max)
      return true;
   else
      return false;
}
// == operator retuns true if all of the information for two exercises are the same.
bool exercise::operator == (const exercise& e)const
{
   
   if(!strcmp(this->name,e.name) && this->min!=e.min && this->max!=e.max)
      return false;
   else
      return true;
}

// = operator to assign all information of a exercise to another exercise 
exercise& exercise::operator = (const exercise& e)
{
    int len=0;
    len=strlen(e.name);
    this->name=new char[len+1];
    strcpy(this->name,e.name);
    
    this->max=e.max;
    this->min=e.min;

  return *this;
}

//This overload shouldn't occur because there shouldn't be a plain exercise
ostream& operator << (ostream out, exercise& e)
{
   return out<<"There was an error exercise base class is being displayed"<<endl;
}


//Child Class of exercise class: stretch class

//Constructors
stretch::stretch():b_part(NULL)
{
   name=NULL;
   max=0;
   min=0;
}

//Copy constructor for a stretch exercise. Does a deep copy of the stretch's information
stretch::stretch(const stretch &a_stretch)
{
   int len =0;
   len=strlen(a_stretch.b_part);
   b_part=new char[len+1];
   strcpy(b_part,a_stretch.b_part);
 
}

//Constructor for a stretch exercise given a name, a max, a min and the name of the body part worked out.
stretch::stretch(const char* a_name, int a_max, int a_min, int n_times, const char* a_bpart)
{
   int len =0;
    
   len=strlen(a_name);
   name=new char[len+1];
   strcpy(name,a_name);
     
   max=a_max;
   min=a_min;
   num_times=n_times;

   len=strlen(a_bpart);
   b_part= new char[len+1];
   strcpy(b_part,a_bpart);
   
}


//Destructor
stretch::~stretch()
{
   delete b_part;
   b_part=NULL;
}

//Displays the information of a textbook.
bool stretch::display()
{
   cout<<"Name: "<<name<<endl;
   cout<<"Body Part to stretch: "<<b_part<<endl;
   cout<<"Max time to hold stretch: "<<max<<" seconds"<<endl;
   cout<<"Min time to hold stretch: "<<min<<" seconds"<<endl<<endl;
   
   return true;
}
// != operator returns true if any of the information of the two stretches aren't the same.
bool stretch::operator != (const stretch& s)
{
   
   if(!strcmp(this->name,s.name) && this->min!=s.min && this->max!=s.max && !strcmp(this->b_part,s.b_part))
      return true;
   else
      return false;
}
// == operator retuns true if all of the information for two stretches are the same.
bool stretch::operator == (const stretch& s)const
{
   
   if(!strcmp(this->name,s.name) && this->min!=s.min && this->max!=s.max && !strcmp(this->b_part,s.b_part))
      return false;
   else
      return true;
}
// = operator to assign all information of a stretch to another stretch 
stretch& stretch::operator = (const stretch& s)
{
    int len=0;
    len=strlen(s.name);
    this->name=new char[len+1];
    strcpy(this->name,s.name);
   
    len=strlen(s.name);
    b_part=new char[len+1];
    strcpy(this->b_part,s.b_part);
   

    this->max=s.max;
    this-> min=s.min;

  return *this;
}

//Operator overload << displays all information for a stretch
ostream& operator << (ostream& out, stretch& s)
{ 
   s.display();
   return out;

}

//Child Class of stretch class: lift class

//Constructors
lift::lift():weight(0)
{
}

//Copy Constructor for slides.
//Does a deep copy of the slide.
lift::lift(const lift &a_lift)
{
   weight=a_lift.weight; 
}

//Constructor for a weight lifting exercise given a name, a max, a min, the name of the body part worked out, and a suggested weight.
lift::lift(const char* a_name, int a_max, int a_min, int n_times, const char* a_bpart, int a_weight)
{
   int len =0;
    
   len=strlen(a_name);
   name=new char[len+1];
   strcpy(name,a_name);
     
   max=a_max;
   min=a_min;
   num_times=n_times;

   len=strlen(a_bpart);
   b_part= new char[len+1];
   strcpy(b_part,a_bpart);
   
   weight=a_weight;
}


//Destructor
lift::~lift()
{}

//Display all lifting information
bool lift::display()
{
   cout<<"Name: "<<name<<endl;
   cout<<"Recommened weight: "<<weight<<endl;
   cout<<"Max Reps: "<<max<<endl;
   cout<<"Min Reps: "<<min<<endl<<endl;

   return true;
}

// != operator returns true if any of the information of the two lifts aren't the same.
bool lift::operator != (const lift& l)
{
    if(!strcmp(this->name,l.name) || this->min!=l.min || this->max!=l.max || !strcmp(this->b_part,l.b_part) || this->weight != l.weight)
     return true;
   else
      return false;
}
// == operator retuns true if all of the information for two lifts are the same.
bool lift::operator == (const lift& l)const
{
   
   if(!strcmp(this->name,l.name) && this->min!=l.min && this->max!=l.max && !strcmp(this->b_part,l.b_part) && this->weight != l.weight)
      return false;
   else
      return true;
}

// = operator to assign all information of a lift to another lift 
lift& lift::operator = (const lift& l)
{
    int len=0;
    len=strlen(l.name);
    this->name=new char[len+1];
    strcpy(this->name,l.name);
   
    len=strlen(l.b_part);
    this->b_part=new char[len+1];
    strcpy(this->b_part,l.b_part);
   
    this->max=l.max;
    this->min=l.min;
    this->weight=l.weight; 

  return *this;
}

//Ostream operator to display all info of a lift
ostream& operator << (ostream& out, lift& l)
{ 
    l.display();
    return out;

}

//Child Class of exercise class: cardio class

//Constructors
cardio::cardio():type('\0')
{}

//Copy Constructor for a cardio exercise.
//Does a deep copy of the given cardio exercise.
cardio::cardio(const cardio &a_cardio)
{
   type=a_cardio.type;
}

//Constructor for a cardio exercise given a type
cardio::cardio(char a_type)
{
   type=a_type;
}

//Destructor
cardio::~cardio()
{}

//Constructor for a cardio given a name, a max, a min, the type of cardio work out.
cardio::cardio(const char* a_name, int a_max, int a_min, int n_times, char a_type)
{
   int len =0;
    
   len=strlen(a_name);
   name=new char[len+1];
   strcpy(name,a_name);
     
   max=a_max;
   min=a_min;
   num_times=n_times;
   type=a_type;
    
}

//Display information of the cardio exercise.
bool cardio::display()
{
   cout<<"Name: "<<name<<endl;
   cout<<"Max Time to work out: "<<max<<" minutes"<<endl;
   cout<<"Min Time to work out: "<<min<<" minutes"<<endl<<endl;

   if(type=='s')
     cout<<"Short cardio work out"<<endl;

   if(type=='m')
     cout<<"Medium cardio work out."<<endl;
  
   if(type=='l')
     cout<<"Long cardio work out"<<endl; 

  return true;
}

// != operator returns true if any of the information of the two cardios aren't the same.
bool cardio::operator != (const cardio& c)
{
   
   if(!strcmp(this->name,c.name) && this->min!=c.min && this->max!=c.max && this->type!=c.type)
      return true;
   else
      return false;
}
// == operator retuns true if all of the information for two cardios are the same.
bool cardio::operator == (const cardio& c)const
{
   
   if(!strcmp(this->name,c.name) && this->min!=c.min && this->max!=c.max && this->type!=c.type)
      return false;
   else
      return true;
}
// = operator to assign all information of a lift to another lift 

cardio& cardio::operator = (const cardio& c)
{
    int len=0;
    len=strlen(c.name);
    this->name=new char[len+1];
    strcpy(this->name,c.name);
    
    this->max=c.max;
    this->min=c.min;
    this->type=c.type;

  return *this;
}
//Ostream operator to display all info of a cario work out
ostream& operator << (ostream& out,  cardio& c)
{ 
     c.display();
     return out;
}

/*
//Inserts a question into the front of the list.
//Takes in a question to add then adds it to the front of the list.
bool questions::insert(l_node* &curr, l_node* &to_add)
{     
    l_node * next=curr;

    //Nothing to add
    if(to_add==NULL)
       return false;
    //Nothing in the list.
    if(head==NULL)
    {
       head=to_add;
       tail=to_add;
       ++num_q;
       return true;
    }       
    //Add to the front of the list.
    else
    {
      to_add->setNext(head);//Put the node to add at the front.
      head=to_add;//Set head to new destination.
      ++num_q;//Increment the amount of questions in the list.
      return true;
    }
   curr->getNext(next);//get the next node in the list.
   insert(next,to_add);//Recursive step.
}

//Remove a question from the LLL.
//Recursively goes through and finds the question with the give number.
//It then removes that question from the LLL.
bool questions::remove(l_node* &curr, int to_remove)
{  
   l_node* h_next = NULL;
   l_node* c_next = NULL;
   l_node* c_next2 = NULL;
   //Nothing to remove
   if(head==NULL)
     return false;

   //Only 1 item in the list to remove
   if(h_next==tail)
   {
     delete head;
     head=NULL;
     tail=NULL;
     num_q=0;
     return true;
   }

   //Make sure not to  dereference a NULL pointer.
   if(curr==NULL)
   {
    return false;
   }
   
   curr->getNext(c_next);
   
   //Question to remove is at the front
   if(head->cmpNum(to_remove) && curr==head)
   {
     head=c_next;
     delete curr; 
     curr=NULL;
     --num_q;
     return true;
   }
   //Question to remove is at the end
   else if(c_next==tail && tail->cmpNum(to_remove))
   {
     delete c_next;
     c_next=NULL;
     tail=curr;
     --num_q;
     return true;

   }
   //Question is in the middle of the list 
   else if(c_next->cmpNum(to_remove))
   {
      c_next->getNext(c_next2);
      curr->setNext(c_next2);
      delete c_next;
      c_next=NULL;
      --num_q;
      return true;
   }

   remove(c_next,to_remove);
   return false;
}
//Displays the information of questions.
//Doesn't display the list of question though.
bool questions::display()
{
   cout<<"Category: "<<category<<endl;
   cout<<"Class Name: "<<c_name<<endl;
   cout<<"Number of questions to avaliable to review: "<<num_q<<endl<<endl;
   
   return true;
}

//Displays the entire list of the questions.
//Recurisvely goes through the list and displays the question.
bool questions::displayList(l_node* &curr)
{
   l_node * next = NULL;
   //Empty List
   if(head==NULL)
    return false;
   //Base Case at the end of the list
   if(curr==tail)
   {
     curr->display();
     return true;
   }
   curr->getNext(next);
   displayList(next);
   curr->display();
}

//Gets the number of questions in the LLL
bool questions::getNumQ(int &copy)
{
  copy=num_q;
  return true;
}

//Gets the head of the LLL
bool questions::getHead(l_node* &copy)
{
   copy=head;
   return true;
}
*/
