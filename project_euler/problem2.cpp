#include <iostream>

using namespace std;

int main(){
  int a = 1;
  int b = 1;
  int tot = 0;
  while (a < 4000000){
    if (a%2 == 0){
      tot += a;
    }
    a = a+b;
    b = a-b;
  }
  cout << tot << '\n';
  return 0;
}