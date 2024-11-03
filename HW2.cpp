//Aidan Ahmad
//HW2.cpp
//Desc: Program to demonstrate understanding of sets in programming

#include<iostream>
using namespace std;

int main()
{
  int setA, setB = 0;
  int userInput = 0;
  int intersection = 0;
  int unionsum = 0;
  int difference = 0;
  cout << endl;
  cout << "Welcome to HW 2: Programming. With the help of code, we" << endl;
  cout << "will be showing how subsets work with a universal set of" << endl;
  cout << "0-9 or {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}. We will be finding" << endl;
  cout << "A U B, A ∩ B, and A - B with bit strings. Please populate" << endl;
  cout << "the set with any amount of numbers." << endl << endl;

  while(userInput != -1){
    cout << "Please enter a number for set A (enter -1 to finish): ";
    cin >> userInput;
    if(userInput != -1){
      setA |= (1 << userInput);
    }
  }

  userInput = 0;
  cout << endl;

  while(userInput != -1){
    cout << "Please enter a number for set B (enter -1 to finish): ";
    cin >> userInput;
    if(userInput != -1){
      setB |= (1 << userInput);
    }
  }

  intersection = setA & setB;
  unionsum = setA | setB;
  difference = setA & ~(setA & setB);

  cout << endl;
  cout << "Set A: " << setA << endl;
  cout << "Set B: " << setB << endl << endl;
  cout << "Intersection: " << intersection << endl;
  cout << "Union: " << unionsum << endl;
  cout << "Difference: " << difference << endl;

  cout << endl;
  return 0;
}