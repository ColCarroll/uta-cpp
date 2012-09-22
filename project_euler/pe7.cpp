//  This is project euler problem 7 - Find the 10,001 prime number
//  Start time: 7:10
//  Finish time: 7:49

#include <iostream>
#include <vector> 

using namespace std;

// returns 0 if n is not prime, else returns 1
int isPrime (long n,vector<long> l)
{
  for (vector<long>::size_type i = 0; i < l.size(); i++)
    {
      if (n % l[i] == 0)
	{
	  //n is composite
	  return 0;
	}
    } 
  // n is prime
  return 1;
}

// Finds the next prime after the number n.
long findPrime (long n, vector<long> l)
{
  n++;
  while(isPrime(n,l) != 1)
    {
      n++;
    }

  //n is prime
  return n;
}

int main ()
{
  vector<long> l;
  l.push_back(2);

  while(l.size() < 10001) 
  {
    vector<long>::size_type i;
    i = l.size() -1 ;
    l.push_back(findPrime(l[i],l));
  }

  cout << "The 10,001st prime is: " << l[l.size()-1] << endl;

  return 0;
}

