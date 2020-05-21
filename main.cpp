     /*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <place holder> with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
         the possible return values of the compare() function should give you a hint.
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
struct T
{
    T(float v, const char* n) :
    value(v),
    name(n)
    {}  //1
    float value;//2
    std::string name;//3
};

struct Comparator                                //4
{
    T* compare(T* a = nullptr, T* b = nullptr)//5
    {
        if (a != nullptr && b != nullptr)
        {
        if(a->value < b->value) return a;
        if(a->value > b->value) return b;
        }
        return nullptr;   
    }
};

struct U
{
    float f1 { 0 }, f2 { 0 };
    float multiply(float* newValue = nullptr)      //12
    {
        std::cout << "U's f1 value: " << f1 << std::endl;
        if (newValue != nullptr) f1 = *newValue;
        std::cout << "U's f1 updated value: " << f1 << std::endl;
        while(std::abs(f2 - f1) > 0.001f)
        {
            /*
             write something that makes the distance between f2 and f1 get smaller
             */
            if (f1 > f2) 
            {
                f2 += 0.001f;
            }
            else f2 -= 0.001f;
        }
        std::cout << "U's f2 updated value: " << f2 << std::endl;
        return f2 * f1;
    }
};

struct Mult
{
    static float multiply(U* that = nullptr, float* newValue = nullptr)    //10
    {
        std::cout << "U's f1 value: " << that->f1 << std::endl;
        if (that != nullptr && newValue != nullptr) that->f1 = *newValue;
        std::cout << "U's f1 updated value: " << that->f1 << std::endl;
        while( std::abs(that->f2 - that->f1) > 0.001f)
        {
            /*
             write something that makes the distance between that->f2 and that->f1 get smaller
             */
            if (that->f1 > that->f2) 
            {
                that->f2 += 0.001f;
            }
            else that->f2 -= 0.001f;
        }
        std::cout << "U's f2 updated value: " << that->f2 << std::endl;
        return that->f2 * that->f1;
    }
};
        
int main()
{
    T aTinstance(0.05f , "aTinstance");                                   //6
    T anotherTinstance(0.7f, "anotherTinstance");                       //6
    
    Comparator f;                                            //7
    
    auto* smaller = f.compare(&aTinstance, &anotherTinstance);          //8
    
    if (smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U aUinstance;
    float updatedValue = 5.f;
    std::cout << "[static func] aUinstance's multiplied values: " << Mult::multiply(&aUinstance, &updatedValue) << std::endl;                  //11
    
    U anotherUinstance;
    std::cout << "[member func] anotherUinstance's multiplied values: " << anotherUinstance.multiply(&updatedValue) << std::endl;
}

        
        
        
        
        
        
        
