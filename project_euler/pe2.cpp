//  This is project euler problem 2:
//  By considering the terms in the Fibonacci 
//  sequence whose values do not exceed four million, 
//  find the sum of the even-valued terms.
//  Start time: 4:19
//  Finish time: 4:27

#include <iostream>
using namespace std;

int main ()
{
  int sum = 0;
  int low = 1;
  int high = 2;

  while (high < 4000000)
  {
    if (high %2 == 0) 
      sum += high;
    high += low;
    low = high - low;
    //    cout << "high: " << high << " low: " << low << " sum: " << sum << endl;  
    cout << sum << endl;
  }

  return 0;
}
