//============================================================================
// Name        : DynamicMemoryExamples.cpp
// Author      : Nancy Eisenmenger

// This program demonstrates how to dynamically allocate memory, using arrays as an example.
// It also shows how to pass arrays in functions. If you want to have an N-D array,
// it is better to use a single large array, or an array of pointers. Passing N-D arrays doesn't work well.
//============================================================================

#include <iostream>
using namespace std;

int printArray(int* Array1, int k);


int main() {


	int i, n;
	n = 10; //

	cout << "What do you want n to be: " << endl;
	cin >> n;

	int Arr[n]; // declaring an array

	int *DArr; // declaring a dynamic array Step 1
	DArr = new (nothrow) int [n]; // declaring a dynamic array Step 2
	// check to make sure the memory was actually allocated
	if (DArr == 0)
	    cout << "Error: memory could not be allocated";
	else

	for(i=0; i<n; i++)
	{
		//You access both arrays in the same way
		Arr[i] = i;
		DArr[i] = 2*i;
	}

	//You treat both types of arrays the same way when you use them in functions
	cout << "Printing the static array:" << endl;
	printArray(Arr, n);
	cout << "Printing the dynamic array:" << endl;
	printArray(DArr, n);

	//now if we need more memory and we know that we are done with the dynamic array, we can delete it
	delete [] DArr;
	//delete [] Arr; // This doesn't work.
	//but we are stuck with the static array. that memory is all tied up until the program terminates

	//Now we have a different problem. The memory is freed so it can be re-allocated, but DArr still points there.
	//If we try to print DArr, it still prints like before, at least for now. And we can still edit DArr.
	cout << "Printing the dynamic array after it has been deleted:" << endl;
	printArray(DArr, n);
	DArr[0] = 5;
	printArray(DArr, n);
	//But once the memory is assigned to something else, it can be overwritten.
	// It can also still be accessed with DArr. This is bad! VERY VERY BAD!
	//After you delete a variable, you must ALWAYS set its pointer to 0 (null).
	//Then you will get an error if you try to use it and it will prevent you from doing very bad things with your program.
	DArr = 0;

	cout << "Printing the dynamic array after the pointer is set to zero:" << endl;
	DArr[0] = 15;
	printArray(DArr, n);
	//Also remember never to set your pointer to zero until you are done with it.
	//If you do this, you will lose access to that memory and you will not be able to free it.
	//You will never be able to use it again until your program stops running. Memory leaks are bad.

	return 0;
}

// How Hendrik and Nick wanted to do it:
//int printArray(int Array1[n], int k)

// How you should do it:
int printArray(int* Array1, int k)
{
	int i;
	for(i=0; i<k; i++)
	{

			cout << Array1[i] << ", ";
	}
	cout << endl;
	return 0;
}

/* Sample Output:
What do you want n to be: 
7
Printing the static array:
0, 1, 2, 3, 4, 5, 6, 
Printing the dynamic array:
0, 2, 4, 6, 8, 10, 12, 
Printing the dynamic array after it has been deleted:
0, 2, 4, 6, 8, 10, 12, 
5, 2, 4, 6, 8, 10, 12, 
Printing the dynamic array after the pointer is set to zero:
     99 [main] DynamicMemoryExamples 4492 exception::handle: Exception: STATUS_ACCESS_VIOLATION
   1080 [main] DynamicMemoryExamples 4492 open_stackdumpfile: Dumping stack trace to DynamicMemoryExamples.exe.stackdump
 */

