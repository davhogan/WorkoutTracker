//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

//The purpose of this program is to represent a bunch of races to train for.
//A race has a name, previous fiish time, days until the race and how long since the last attempt.
//A race also has a LLL of eercises to help train.
//There are three different types of exercises to do to help train for the races.
//They are a stretching, weight lifting and cardio exercises.
//All exercises have a name of the class, a max, a min and amount of time to do per week.
//The program opens up a file and reads all of the data for each line.
//Where one line represents all info for a race.
//Formating for the text file: race name|days left|finish time|years since|number of exercises|type of exercise|exercise name|exercise type|exercise name|max|min|num times|

#include "tree.h"
using namespace std;

const int MAX = 144;
//Checks the user's response to make sure it is in range of the available options.
//Continues to make the user get enter a number until the one entered is in range.
//Takes in the user's response and returns the response that is in range.
int checkResponse(int user_resp)
{
  while(user_resp < 1 || user_resp > 3)
  { 
     cout<<"That isn't an acceptable command"<<endl;
     cout<<"[1] To display all races."<<endl;
     cout<<"[2] To display a specific race."<<endl;
     cout<<"[3] To add a race to train for."<<endl; 

     cin>>user_resp;
     cin.ignore(100,'\n');
  }
  
  return user_resp;
}

//Checks the user's response to make sure it is in range of the available options.
//Continues to make the user get enter a number until the one entered is in range.
//Takes in the user's response and returns the response that is in range.
int checkType(int user_resp)
{
   while(user_resp < 1 || user_resp > 3)
   {
     cout<<"Select which type of study material to add."<<endl;
     cout<<"[1] A new book."<<endl;
     cout<<"[2] A new location of slides."<<endl;
     cout<<"[3] A new set of questions."<<endl;

     cin>>user_resp;
     cin.ignore(100,'\n');
   }

  return user_resp;
}

//This is where the user interacts with the program.
//Main prompts the user to fill and interact with the CLL of study materials.
int main()
{

  int user_resp=0;//The user's response
  char cont='y';//Whether or not the user wants to continue
  char resp[MAX]={'\0'};//user resp
  char r_name[MAX]={'\0'};//name of race
  char e_name[MAX]={'\0'};//name of exercise
  char f_time[MAX]={'\0'};//finish time
  char b_part[MAX]={'\0'};//body part
  char e_type,c_type='\0';//types 
  l_node * head=NULL;//head
  
  int d_left,n_exercises,max,min,n_times,weight=0;//misc ints
  float yrs_snce=0;//years since
  t_node * root=NULL;//root of tree
  FILE* file;
  bst obj;

  cout<<"Enter the name of file to look up"<<endl;
  cin.getline(resp,MAX-1,'\n');
  cin.ignore(100,'\n');
  
  file=fopen(resp,"r");

  if(!file)
  {
    cout<<"File could not be found\n";
    return -1;
  }
  //While file is open go through and read each line
  while(!feof(file))
  {
   fscanf(file,"%s|",&r_name);
   fscanf(file,"%d|",d_left);
   fscanf(file,"%s|",f_time);
   fscanf(file,"%f|",yrs_snce);
   t_node* a_tnode = new t_node(r_name,d_left,f_time,yrs_snce);
   fscanf(file,"%d|",n_exercises);

   for(int i=0; i<n_exercises; ++i)
   {
     l_node * a_lnode = NULL;
     a_tnode->getHead(head);
     fscanf(file,"%c|",e_type);
     //Type of exercise is a stretch     
     if(e_type=='s')
     {
       fscanf(file,"%s|",e_name);
       fscanf(file,"%d|",max);
       fscanf(file,"%d|",min);
       fscanf(file,"%d|",n_times);
       fscanf(file,"%s|",b_part);
       exercise* s = new stretch(e_name,max,min,n_times,b_part);  
       a_lnode = new l_node(s);
     }
     //Type of exercise is weight lifting
     else if(e_type=='w')
     {
       fscanf(file,"%s|",e_name);
       fscanf(file,"%d|",max);
       fscanf(file,"%d|",min);
       fscanf(file,"%d|",n_times);
       fscanf(file,"%s|",b_part);
       fscanf(file,"%d|",weight);
       exercise* w = new lift(e_name,max,min,n_times,b_part,weight);
       a_lnode = new l_node(w); 
     }
     //Type of execise is cardio
     else if(e_type=='c')
     {
       fscanf(file,"%s|",e_name);
       fscanf(file,"%d|",max);
       fscanf(file,"%d|",min);
       fscanf(file,"%d|",n_times);
       fscanf(file,"%c|",c_type);
       exercise* c = new cardio(e_name,max,min,n_times,c_type);
       a_lnode = new l_node(c);
     }
      a_tnode->insert(head,a_lnode);//insert to the LLL of exercises
   }
  
    root=obj.insert(root,a_tnode); //insert into the BST.
  }
  


   //While the user wants to continue interacting with the CLL of study materials
   while(cont=='y' || cont=='Y')
   {
     cout<<"[1] To display all races."<<endl;
     cout<<"[2] To display a specific race."<<endl;
     cout<<"[3] To add a race to train for."<<endl; 

         
      cin>>user_resp;
      cin.ignore(100,'\n');

      user_resp=checkResponse(user_resp);//check in range
      //Display All of the races to train for
      if(user_resp==1)
      {
          t_node * root = NULL;
          obj.getRoot(root);
          obj.displayTree(root);

      } 
      //Display information for a given race
      else if(user_resp==2)
      {
          t_node * root = NULL;
          obj.getRoot(root);
          cout<<"Enter the name of the race to look: ";
          cin.getline(r_name,143,'\n');
          obj.displayRace(root,r_name);

      }

      //Add a race to train for
      else if(user_resp==3)
      {
         cout<<"Enter the name of the race you are training for."<<endl;
         cin.getline(r_name,MAX-1,'\n'); 
         cin.ignore(100,'\n');
       
         cout<<"How many days until the race?"<<endl;
         cin>>d_left;
         cin.ignore(100,'\n');

         cout<<"How long since the last time you attempted this race?"<<endl;   
         cin>>yrs_snce;
         cin.ignore(100,'\n');

         cout<<"What was the finish time of the last attenpt?"<<endl;
         cin.getline(f_time,MAX-1,'\n');
         cin.ignore(100,'\n');

         cout<<"What is the number of the question to remove?"<<endl;
         cin>>user_resp;
         cin.ignore(100,'\n');

         t_node* a_tnode = new t_node(r_name,d_left,f_time,yrs_snce);
         
         cout<<"Would you like to add an exercise?(y/n)"<<endl;
         cin>>cont;
         cin.ignore(100,'\n');

         while(cont=='Y' || cont =='y')
         {
           l_node * a_lnode = NULL;
           cout<<"[1] Add a stretching exercise"<<endl;
           cout<<"[2] Add a weight lifting exercise"<<endl;
           cout<<"[3] Add a cardio exercise"<<endl;
            
           //Type of exercise is streyching
	    if(user_resp==1)
	     {
	       cin.getline(e_name,MAX-1,'\n');
               cin.ignore(100,'\n');

	       cin>>max;
               cin.ignore(100,'\n');
               
               cin>>min;
               cin.ignore(100,'\n');

               cin>>n_times;
               cin.ignore(100,'\n');

               cin.getline(b_part,MAX-1,'\n');
               cin.ignore(100,'\n');

               exercise* s = new stretch(e_name,max,min,n_times,b_part);  
	       a_lnode = new l_node(s);
	     }
	     //Type of exercise is weight lifting
	     else if(user_resp==2)
	     {
	       cin.getline(e_name,MAX-1,'\n');
               cin.ignore(100,'\n');

	       cin>>max;
               cin.ignore(100,'\n');
               
               cin>>min;
               cin.ignore(100,'\n');

               cin>>n_times;
               cin.ignore(100,'\n');

               cin.getline(b_part,MAX-1,'\n');
               cin.ignore(100,'\n');

	       cin>>weight;
               cin.ignore(100,'\n');

	       exercise* w = new lift(e_name,max,min,n_times,b_part,weight);
	       a_lnode = new l_node(w); 
	     }
	     //Type of execise is cardio
	     else if(user_resp==3)
	     {
	       cin.getline(e_name,MAX-1,'\n');
               cin.ignore(100,'\n');

	       cin>>max;
               cin.ignore(100,'\n');
               
               cin>>min;
               cin.ignore(100,'\n');

               cin>>n_times;
               cin.ignore(100,'\n');

               cin>>c_type;
               cin.ignore(100,'\n');
               
               exercise* c = new cardio(e_name,max,min,n_times,c_type);
	       a_lnode = new l_node(c);
	     }
          
          a_tnode->insert(head,a_lnode);//insert to the LLL of exercises
          root=obj.insert(root,a_tnode); //insert into the BST.
     
          cout<<"Would you like to add another exercise?(y/n): ";
          cin>>cont;
          cin.ignore(100,'\n');
 
         }
      }
      
      
       cout<<"Would you like to do anything else?(y/n): ";
       cin>>cont;
       cin.ignore(100,'\n');
  }
   
 
 return 0;
}

