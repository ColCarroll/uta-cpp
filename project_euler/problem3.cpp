#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
  long N = 1241987098632;
  long n = N;
  long p = 3;
  float rt = pow(n,0.5);
  vector<long> factors;
  
  while (n%2 == 0) {
    factors.push_back(2);
    n = n/2;
    }
  while ((n>1) && (p <= rt)){
    while (n%p==0){
      factors.push_back(p);
      n = n/p;
    }
    p+=2;
  }
  if (n>1){
    factors.push_back(n);
  }
  cout << "Factors of "<<N<<": \n\t";
  for (vector<int>::size_type i = 0; i<factors.size()-1;i++){
    cout << factors[i]<<", ";
  }
  cout << "and " << factors[factors.size()-1] << ".\n";
  
}
