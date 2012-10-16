/*
 *  headerfiles.h
 *  
 *
 *  Created by Shorty Knudson on 10/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

//Example 0:  This won't work, because we're calling add before we've declared

#include <iostream>

int main(){
cout << "Hey you!  Give me a number and I'll add 4 to it! '/n";
int x;
cin >> x;
cout << x <<" plus 4 is: " << add(x,4) << endl ;
return 0;
}

int add(int x, int y){
    return x + y;
}



//Example 1:  Here, we defined the function add before calling it in main.

#include <iostream>
using namespace std;

int add(int x, int y){
    return x + y;
}


int main(){
    cout << "Hey you!  Give me a number and I'll add 4 to it! '/n";
    int x;
    cin >> x;
    cout << x <<" plus 4 is: " << add(x,4) << endl ;
    return 0;
}


//Example 2: Or, we can include a forward declaration of the function, and give 
// the code for what it does later on.

#include <iostream>
using namespace std;

int add(int x, int y);

int main(){
    cout << "Hey you!  Give me a number and I'll add 4 to it! '\n";
    int x;
    cin >> x;
    cout << x <<" plus 4 is: " << add(x,4) << endl ;
    return 0;
}

int add(int x, int y){
    return x + y;
}

//Example 3:  This even works if "add" is defined in a different file.  I just need that forward declaraion again

//To compile two files with the terminal just write both of their names
//(e.g to compile add.cpp and math3.cpp, I'd enter ' g++ add.cpp math3.cpp ' into the terminal

//add.cpp :

int add (int x, int y) {
    return x + y;
}

//math3.cpp:

#include <iostream>
using namespace std;

int add(int x, int y);

int main(){
    cout << "Hey you!  Give me a number and I'll add 4 to it! \n";
    int x;
    cin >> x;
    cout << x <<" plus 4 is: " << add(x,4) << endl ;
    return 0;
}


//Example 4; Or, I can use header file for all my declarations, and #include that file
//Now I'll need to compile 3 source files


//add.h:

//add.cpp: (as above)

//math4.cpp
#include <iostream>
#include "add.h" 

int main(){
    cout << "Hey you!  Give me a number and I'll add 4 to it! '/n";
    int x;
    cin >> x;
    cout << x <<" plus 4 is: " << add(x,4) << endl ;
    return 0;
}