#include <iostream>
#include <cmath>

using namespace std;


bool isprime(long n){
  int rt = pow(n,0.5);
  
  if (n <= 1||int(n) != n){
    return false;
  }
  
  if (n==2){
    return true;
  }
  if (n%2==0){
    return false;
  }
  
  for(long p = 3;p<=rt;p+=2){
    if (n%p == 0){
      return false;
    }
  }
  return true;
}

int main(){ // computes the (top) prime
  int count = 1; // starting at 1, and skipping 2, since it is already prime
  long top = 10001; 
  int n = 1;
  while (count<top){
    n+=2;
    if (isprime(n)){
      count++;
      }
  }
  cout << "Prime number "<<top<< " is, strangely enough, " <<n <<".\n";
  return n;
}


