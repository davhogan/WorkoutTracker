//David Hogan
//email: davhogan@pdx.edu
//Student ID: 989671828

#include "exercises.h"

//The purpose of this file is to represent a binary search tree that holds all information for all the races to train for. 
//This information includes the name of the race, days left until the race,the finish time from a previous attempt of the race and the date of that attempt.
//The race also has a pointer to the head of a LLL of exercises to do to train for the race.
//New races to train for can be added to the BST, as well as displaying all of the races or all information for a given race.

//The purpose of this class is to represent a node in a binary search tree.
///A node in the tree represents a race to train for.
//The information for a race includes the name of the race, days left until the race,the finish time from a previous attempt of the race and the date of that attempt.
//The race also has a pointer to the head of a LLL of exercises to do to train for the race.
//There are also pointer to the right and left nodes of the tree node 
class t_node
{
   public:
          //Constructors
          t_node();
          t_node(t_node*&);
          t_node(const char* a_name, int ds_left, char* f_time, float f_date);
          ~t_node();//Destructor

          t_node* go_left();//Get left
          t_node* go_right();//Get right
          bool setLeft(t_node* &dest);//Set left node
          bool setRight(t_node* &dest);//Set right node
          bool copyName(char* a_name);
          bool getHead(l_node* &dest);
 
          bool insert(l_node* &curr, l_node* &to_add);//Insert an exercise into the LLL
          bool display();//Display all info for the race 
          bool displayList(l_node* &curr);//Display the LLL of exercises

          bool operator > (const t_node&);
          bool operator >=(const t_node&);
          bool operator < (const t_node&);
          bool operator <=(const t_node&);
          
   protected:
          char * name;//Name of the race
          float days_left;//Days left until the race
          char* fin_time;//Finish time from previous attempt
          float  years_pass;//Years since the race
          l_node * head;//Head of LLL of exercises
          t_node * right;//Right tree node
          t_node * left;//Left tree node
};

//The purpose of this class is to represent a binary tree of all races to train for.
//The class only has a root pointer to the tree.
//A new race can be added
class bst
{
   public:
          //Constructor
          bst();
          bst(const bst&);
          ~bst();//Destructor

          bool getRoot(t_node* &dest);         
          t_node* insert(t_node* &root, t_node* &to_add);//Add a race to BST
          bool displayTree(t_node* root);//Display the entire tree
          bool displayRace(t_node* root,char * name);//Display a race by a given name

   protected:
           t_node * root;//Root of the BST

};
