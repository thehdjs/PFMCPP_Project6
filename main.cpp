/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
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
    T compare(T& a, T& b)//5
    {
        if(a.value < b.value) return a;
        if(a.value > b.value) return b;
        T noneOfThem(0, "none of them");
        return noneOfThem;
    }
};

struct U
{
    float f1 { 0 }, f2 { 0 };
    float multiply(const float& newValue)      //12
    {
        std::cout << "U's f1 value: " << f1 << std::endl;
        f1 = newValue;
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
    static float multiply(U& that, const float& newValue)    //10
    {
        std::cout << "U's f1 value: " << that.f1 << std::endl;
        that.f1 = newValue;
        std::cout << "U's f1 updated value: " << that.f1 << std::endl;
        while( std::abs(that.f2 - that.f1) > 0.001f)
        {
            /*
             write something that makes the distance between that->f2 and that->f1 get smaller
             */
            if (that.f1 > that.f2) 
            {
                that.f2 += 0.001f;
            }
            else that.f2 -= 0.001f;
        }
        std::cout << "U's f2 updated value: " << that.f2 << std::endl;
        return that.f2 * that.f1;
    }
};
        
int main()
{
    T aTinstance(0.05f , "aTinstance");                                   //6
    T anotherTinstance(0.7f, "anotherTinstance");                      //6
    
    Comparator f;                                            //7
    
    auto smaller = f.compare(aTinstance, anotherTinstance);          //8
    
    std::cout << "the smaller one is << " << smaller.name << std::endl; //9

    U aUinstance;
    float updatedValue = 5.f;
    std::cout << "[static func] aUinstance's multiplied values: " << Mult::multiply(aUinstance, updatedValue) << std::endl;                  //11
    
    U anotherUinstance;
    std::cout << "[member func] anotherUinstance's multiplied values: " << anotherUinstance.multiply(updatedValue) << std::endl;
}
