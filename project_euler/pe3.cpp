//  This is project euler problem 3:
//  What is the largest prime factor of the number 600851475143?
//  Start time: 4:28
//  Finish time: 4:53

#include <iostream>
using namespace std;

//  Returns the smallest (prime) factor of number, including 
//  returning number if number is prime
int findPrime(int long number)
{
  int factor = 2 ;
  while (factor < number)
    {
      if (number%factor == 0)	
	  return factor;
      factor++;
    }
  return number;
}

int main ()
{
  int largestPrime = 1;
  int long remaining = 600851475143;

  while (remaining > 1)
    {
      int factor = findPrime(remaining);
      if (factor > largestPrime)
	largestPrime = factor;
      remaining /= factor;
    }   

  cout << "Largest prime is " << largestPrime <<endl;

  return 0;
}


