//  This is project euler problem 1 - Find the sum of all the 
//  multiples of 3 or 5 below 1000..  
//  You run it by using the compiler command g++
//  Start time: 4:03
//  Finish time: 4:16

// Editing here online (at uta-cpp) to see how to pull down and merge locally

#include <iostream>
using namespace std;

int main ()
{
  int s = 0;
  
  for (int i=1; i < 1000; i++)
  {
    if (i % 3 == 0 || i % 5 == 0)
      {	
        s = s + i;
      }
  }

  cout << s << endl;

  return 0;
}
