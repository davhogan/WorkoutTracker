//By David Hogan
//Email:davhogan@pdx.edu
//Student ID: 989671828

#include <iostream>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//The purpose of this file is to represent an exercise to do for training.
//An exercise can be either a stretch a weight lift or a cardio work outi. Because these exercises act differently there is an abstract base class of the exercises the basics that every piece of exercise has. 


//This class is the abstract base class for the different types of exercises.
//Every piece of exercise has a name, a max rep/time a min rep/time and the amount of time to do the exercise.
//This class doesn't do much and instead invokes the work onto it's childeren.
class exercise
{
   public:
         exercise();//Constructor
         exercise(const exercise &an_exercise);//Copy Constructor
         virtual ~exercise();//Destructor
         virtual bool display();//Pure virtual function. 

         bool cmpName(char * a_name);//Compares a name of the exercise to a goven name.
         bool cmpMax(int a_max);//Compares the max reps.
         bool cmpMin(int a_min);//Compares the min reps.

         exercise& operator = (const exercise&);
         bool operator != (const exercise&);
         bool operator == (const exercise&)const;
         friend std::ostream& operator << (std::ostream&, exercise&);

   protected:
         char * name;//Indicator for which type of study material the object is
         int max;//Max amount of reps or time to do for the exercise 
         int min;//Min amount of reps or time to do for the exercise  
         int num_times;//Amount of times to do the workout

};

//Child class of the abstract base class: exercise
//The purpose of this class is to represent a stretching exercise
//A stretching exercise has a specfic body part it works out
class stretch: public exercise
{
   public:
         //Constructors
         stretch();//Default
         stretch(const stretch &a_stretch);//Copy Constructor
        // book(const char* a_name, const char * a_category, const char* a_title);//Constructor for a book when given a name,category and title
         stretch(const char* a_name, int a_max, int a_min, int n_times,const char* a_bpart);//Constructor given a name, a max, a min, and  a body part to work out
         //Destructor
         ~stretch();
        
         bool display();//Displays the title of the book,the name of the class the book is for and the realted category
         stretch& operator = (const stretch&);
         bool operator != (const stretch&);
         bool operator == (const stretch&)const;
         friend std::ostream& operator << (std::ostream&, stretch&);

   protected:
        char * b_part;//Part of the body to work out.

}; 

//Child class of the class: stretch
//The purpose of this class is to represent a weight lifting exercise
//A weight lifting exercise has a suggested weight to use
class lift: public stretch
{
   public:
         //Constructors
         lift();//Default
         lift(const lift &a_lift);//Copy Constructor
       //  slides(const char* a_name, const char* a_category, const char* location);//Constructor when given a name, category and location of the slides
        lift(const char* a_name, int a_max, int a_min, int n_times, const char* a_bpart, int a_weight);//Constructor given a name, a max, a min, a body part to work out and a suggested weight
        //Destructor
        ~lift();

         bool display();//Displays the location of the slides 
  
         lift& operator = (const lift&);
         bool operator != (const lift&);
         bool operator == (const lift&)const;
         friend std::ostream& operator << (std::ostream&, lift&);

   protected:
         int weight;//File location for the slides      
};

//Child class of the abstract base class: exercise
//The purpose of this class is to represent a cardio exercise
//A cardio exercise has a char type of cardio workout: short(s), meduim(m) or long(l)
class cardio: public exercise
{
   public:
         //Constructors
         cardio();//Default
         cardio(const cardio &a_cardio);//Copy constructor.
         cardio(char type);//Constructor that takes in a type.
         cardio(const char* a_name, int a_max, int a_min, int n_times, char a_type);//Constructor given a name, a max, a min and a type
        
         //Destructor
         ~cardio();

   //      bool insert(l_node* &curr, l_node* &to_add);//Adds a question to the front of the list
     //    bool remove(l_node* &curr, int to_remove);//Removes the given question from the list. 
         bool display();//Displays the class,category and number of questions. 
       //  bool displayList(l_node* &curr);//Displays all of the questions for a given category.
       //  bool getNumQ(int &copy);//Get the number of questions in the LLL.
        // bool getHead(l_node* &copy);//Get the head of the LLL.
         cardio& operator = (const cardio&);
         bool operator != (const cardio&);
         bool operator == (const cardio&)const;
         friend std::ostream& operator << (std::ostream&, cardio&);
 
   protected:
 
        char type;//Type of cardio work out: s for short, m for medium, l for long.

};

//The class is used to represent a node in a linear linked list.
//An l_node has a question, a number and a pointer to the next node in the LLL.
class l_node
{
  public:
      //Constructors
      l_node();//Default.
      l_node(const l_node* &a_node);//Copy Constructor.
      l_node(exercise * exercise_copy);//Constructor given a question and a number of the question.
      //Destructor
      ~l_node();

      bool getNext(l_node* &copy);//Gets the next pointer in the list.
      bool setNext(l_node* &dest);//Sets the next pointer in the list.
     
      bool display();//Display the question and its number. 
      
      l_node& operator = (const l_node&);
      l_node operator + (const l_node&);
      l_node& operator += (const l_node&);
      friend std::ostream& operator << (std::ostream&, const l_node&);

  protected:
      exercise * an_exercise;//An exercise.
      l_node * next;//The next pointer in the list.
};


