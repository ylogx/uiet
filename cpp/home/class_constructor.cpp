 // Demonstrates declaration of a constructors and
 // destructor for the Cat class
 #include <iostream>// for cout
 using namespace std;
 class Cat// begin declaration of the  
 {
 public://begin public section
 Cat(int initialAge);//constructor
 ~Cat();//destructor
 int GetAge();//accessor function
 void SetAge(int age);// accessor function
 void Meow();
 private:
 // begin private section
 int itsAge;
 // member variable
 };
 // constructor of Cat,
 Cat::Cat(int initialAge)
 {
 itsAge = initialAge;
 }
 Cat::~Cat()
 // destructor, takes no action
 {
 }
 // GetAge, Public accessor function
 // returns value of itsAge member
 int Cat::GetAge()
 {
 return itsAge;
 }
 // Definition of SetAge, public
 // accessor function
 void Cat::SetAge(int age)
 {
 // set member variable its age to
 // value passed in by parameter age
 itsAge = age;
 }
 // definition of Meow method
 // returns: void
 // parameters: None
 // action: Prints "meow" to screen
 void Cat::Meow()
 {
 cout << "Meow.\n";
 }
 // create a cat, set its age, have it
 // meow, tell us its age, then meow again.
 int main()
 {
 Cat Frisky(5);
 Frisky.Meow();
 cout << "Frisky is a cat who is " ;
 cout << Frisky.GetAge() << " years old.\n";
 Frisky.Meow();
 Frisky.SetAge(7);
 cout << "Now Frisky is " ;
 cout << Frisky.GetAge() << " years old.\n";
 return 0;
}

