#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n = 3;
  int sum = 0;
  while (n<1000){
    if (n%3 == 0 || n%5 == 0){
      sum+=n;
    }
    n+=1;
  }
  cout << sum << '\n';
  return 0;
}