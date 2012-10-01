//============================================================================
// Name        : pointere_example.cpp
// Author      : Nancy Eisenmenger
//============================================================================

#include <iostream>
using namespace std;

int SwitchBad(int a, int b);
int Switch(int *a, int*b);
int Switch2(int **a, int **b);
int Switch3(int* a, int* b);

int main()
{
  // declares integer variables x and y
	int x;
	int y;

	// initializes x and y to different values
	x = 5;
	y = 7;

	// prints out initial values of x and y
	cout << "Initialize x and y." << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;

	// attempts to switch x and y, but fails because it only passes by value instead of using points
	SwitchBad(x, y);
	cout << endl;
	cout << "SwitchBad(x, y)" << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;

	// switches values of x and y by calling the function with pointers to x and y
	Switch(&x, &y);
	cout << endl;
	cout << "Switch(&x, &y)" << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;

	// attempts to switch x and y, but fails
	Switch3(&x, &y);
	cout << endl;
	cout << "Switch3(&x, &y)" << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;
	// declares pointers xP and yP
	int *xP;
	int *yP;

	// sets pointers xP and yP to point to x and y, respectively
	xP = &x;
	yP = &y;

	// demonstrates another way to use Switch() by calling it with xP and yP instead of &x and &y
	Switch(xP, yP);
	cout << endl;
	cout << "Switch(xP, yP)" << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;

	// calls another function with pointers to pointers to x and y
	Switch2(&xP, &yP);
	// Switch2() does not switch x and y, but it does switch xP and yP so that xP points to y and vice versa
	cout << endl;
	cout << "Switch2(&xP, &yP)" << endl;
	cout << "x = " << x << ", y = " << y << "." << endl;
	cout << "xP points to " << *xP << ", yP points to " << *yP << "." << endl;

	// Prints sample memory addresses (pointer values)
	cout << endl;
	cout << "Sample output for pointer memory address" << endl;
	cout << "xP is " << xP << " yP is " << yP << endl;

	return 0;
}

/*
Sample output from Main()

Initialize x and y.
x = 5, y = 7.

SwitchBad(x, y)
x = 5, y = 7.

Switch(&x, &y)
x = 7, y = 5.

Switch3(&x, &y)
x = 7, y = 5.

Switch(xP, yP)
x = 5, y = 7.

Switch2(&xP, &yP)
x = 5, y = 7.
xP points to 7, yP points to 5.

Sample output for pointer memory address
xP is 0x22ccb4 yP is 0x22ccb8
 */

//Takes integer arguments a and b and switches them. The switch fails because pointers are not used.
int SwitchBad(int a, int b)
{
	int c;
	c = a;
	a = b;
	b = c;
	return 0;
}

//Takes integer pointer arguments a and b and switches the values at those memory addresses.
int Switch(int* a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	return 0;
}

//Takes pointers to pointers, a and b, as arguments switches them. The values at a and b are not switched,
//but the pointers *a and *b are switched.
int Switch2(int **a, int **b)// does not work - only switches pointers
{
	int *c;
	c = *a;
	*a = *b;
	*b = c;
	return 0;
}

//Takes integer pointer arguments a and b and switches where the pointers point, but only within the function.
//When the function returns, the changes are lost.
// Essentially this function fails for the same reason that SwitchBad() fails.
int Switch3(int* a, int* b) // does not work - only switches pointers inside the function
{
	int* c;
	c = a;
	a = b;
	b = c;
	return 0;
}
