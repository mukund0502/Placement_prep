**if you have tons of time or for high level preparation : go to [here](https://whimsical.com/object-oriented-programming-cheatsheet-by-love-babbar-YbSgLatbWQ4R5paV7EgqFw)** 

*by love babbar*

for Short notes and fast revision [link](https://www.youtube.com/watch?v=3fLvC4cofcg&t=170s)

# topics to be covered: 
1. ### OOP vs POP (object oriented programming vs procedure oriented programming)
    - Expand 
    - Approach (class based vs function based)
    - Features (four pillars like *Polymorphism, inheritance, Abstraction and encapsulation* vs no concepts of pillars )

2. ### Classes and objects - definition 

3. ### features of oops - **EPID** => Encapsulation Polymorphism Inheritence Data abstraction

4. ### Types of Polymorphism 
    - compile time => *Function overloading* - same name of two functions but different number of parameters or types of parameter -
    ```cpp
    int area(int a, int b){
        return a*b;
    }
    int area(int a){ // this is called 
        return a*a;
    }
    int a = 10;
    cout << area(a);
    ```
    - run time polymorphism => *Function overriding* - when two functions present one derived class function and another the function which is inherited by parent class, in this case derived class function is called -
    
    ```cpp
    class A{
        public : int area(){};
    };
    class B:public A{
        public : int area(){}; // this is called 
        // area() A's
    };
    B ob;
    ob.area();
    ```

5. ### Types of inheritence
    - Single level inheritence => one base and one derived class
    - Multiple inheritence => multiple base and one derived class 
    - Multi level inheritence => multiple level of derivation of class 
    - Hierarchical inheritence => one base class and multiple derived class 
    - Hybrid inheritence => collection of two or more inheritence 

6. ### Modes of inheritence 
    - public 
    - private
    - protected 

7. ### Static variable - single copy of variable shared by all objects of this class 
    ```cpp
    class A{
        public : 
        int x;
        static int y;
    };
    A ob1, ob2; 
    // different objects have their own x but y is same and shared by all objects of that particular class
    ```

8. ### Friend function - can access private and protected member of class in which it is declared 
    friend function is declared as: 
    ```cpp
    class box{
        private:
        int length;
        friend int printlength(box); //declaration
    };
    ```

9. ### Call by value Call by reference 
    declared as 
    ```cpp
    void func1(int a){
        a = 20;
    }
    void func2(int &a){
        a = 20;
    }
    int a = 40;
    func1(a); // this doesn't change the value 
    func2(a); // this will change the value 
    ```

10. ### Constructor and destructor 
    - types of constructor: (no return type, autometically called, same name as class name, can overload)
        - Default 
        - Parameterised 
        - copy 
    - types of destructed:
        - default 

11. ### Reference and pointer 
    Reference :
        - Can't be NULL
        - Never be void
        - concept of single level indirection only
        - once created, can't be later made to reference another variable/object.
    Pointer : 
        - Can be NULL
        - Can never be NULL
        - concept of n-level indirection of pointers like single, double, triple level pointer.
        - once created, can't be later made to reference another variable/object.
    Reference means alias, pointer means pointing the address of variable
    understand by code: 
    ```cpp
    // REFERENCE
    int x = 20;
    int &ref = x;
    ref = 19;
    cout << x << endl; //19

    // POINTER 
    int a = 2;
    int *x = &a;
    cout << x << endl; // address of a
    cout << *x << endl; // value of variable at address x
    ```

12. ### Virtual function
    - used to ensure that the function is overridden. this especially applies to case where pointer of base class points to the object of a derived class.

    understand by code: 
    ```cpp
    class base{
        public:
        /*virtual*/ void print(){} // if virtual is used then derived function will be called not the base 
    };
    class derived: public base{
        public:void print(){}
    };
    derived d1;
    base* b1 = &d1;
    b1->print(); // base function is called
    ```
13. ### Type conversion 
    -   Types of data conversion : 
        - Implicit type conversion 
            done by compiler autometically if needed. small=>big
        - explicit type conversion 
            done by programmer. big=>small
    understand by code: 
    ```cpp
    int num1 = 24;
    float num2;
    num2 = num1; // implicit

    float num2;
    int num1 = 25;
    num2 = (float)num1; // explicit
    ```

14. ### Default parameter : 
    
    understand by code: 
    ```cpp
    int func(int x, int y, int z = 10){
        return x+y+z;
    }
    cout << func(10, 12); // 32
    ```

15. ### Inline  function : when this function is called while line of that function substituted at the place where function is called 

    understand by code :
    ```cpp
    inline int add(int a, int b){
        return a+b;
    }
    cout << add(10, 20) << endl;
    ```
16. ### Macros : 
    understand by code : 
    ```cpp
    #define LIMIT 10 
    int a = 5;
    if(a<LIMIT) cout << "YES"; // this will execute
    else cout <<"NO";
    ```






