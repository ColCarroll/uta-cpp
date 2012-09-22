//  This is project euler problem 11:
//  What is the greatest product of four adjacent numbers in any 
//  direction (up, down, left, right, or diagonally) in the 20×20 grid?
//  
//  Start time: 4:28
//  Finish time: 4:53

#include <iostream>  // I/O 
#include <fstream>   // file I/O
#include <iomanip>   // format manipulation
#include <string>
using namespace std;

int grid [20][20];

void readFile();
int horizontal(int old_biggest);
int vertical(int old_biggest);
int diagdown(int old_biggest);
int diagup(int old_biggest);

int main ()
{
  readFile();

  int biggest = 0;

  biggest = horizontal(biggest);
  biggest = vertical(biggest);
  biggest = diagdown(biggest);
  biggest = diagup(biggest);

  cout << "The biggest 4 adjacent guys are: " << biggest << endl;

  /* Old: reads out the grid ina pretty crude way:
  for (int i = 0;i < 400; i++)
    { 
      cout << grid[i/20][i%20]<< endl;
    }
  */

  return 0;
}

// Reads in the file and puts it into grid.
void readFile ()
{
  ifstream fp_in; // declare input stream
  fp_in.open("pe11.txt", ios::in);    // open the stream

  for (int i = 0; i < 400; i++)
    {
      int n;
      fp_in >> n;
      grid[i/20][i%20] = n;
    }

  fp_in.close();   // close the streams when done
  return;
}

// returns the larger of old_biggest or the largest horizontal 
// product of 4 entries in the grid. 
int horizontal(int old_biggest)
{
  int biggest = old_biggest;
  int product = 1;

  for (int i=0;i< 400;i++)
    {
      // first, skip this part if we're too close to the end of the line
      if (i%20 >16)
	continue;
      
      // we have enough room so build a sum to the right
      product = 1;
      for (int j = 0;j < 4;j++)
	{
	  product *= grid[i/20][(i%20) + j];
	}

      // we have our product for this i, check if it's bigger than biggest
      if (product > biggest)
	biggest = product;
    }
  return biggest;
}

// returns the larger of old_biggest or the largest vertical 
// product of 4 entries in the grid. 
int vertical(int old_biggest)
{
  int biggest = old_biggest;
  int product = 1;

  for (int i=0;i< 400;i++)
    {
      // first, skip this part if we're too close to the end of the line
      if (i/20 >16)
	continue;
      
      // we have enough room so build a product downward
      product = 1;
      for (int j = 0;j < 4;j++)
	{
	  product *= grid[i/20+j][(i%20)];
	}

      // we have our product for this i, check if it's bigger than biggest
      if (product > biggest)
	biggest = product;
    }
  return biggest;
}

// returns the larger of old_biggest or the largest product
// of 4 entries diagonally down and right in the grid. 
int diagdown(int old_biggest)
{
  int biggest = old_biggest;
  int product = 1;

  for (int i=0;i< 400;i++)
    {
      // first, skip this part if we're too close to the end of the line
      if (i/20 >16 || i%20 > 16)
	continue;
      
      // we have enough room so build a product
      product = 1;
      for (int j = 0;j < 4;j++)
	{
	  product *= grid[i/20+j][(i%20)+j];
	}

      // we have our product for this i, check if it's bigger than biggest
      if (product > biggest)
	biggest = product;
    }
  return biggest;
}

// returns the larger of old_biggest or the largest product
// of 4 entries diagonally up and right in the grid. 
int diagup(int old_biggest)
{
  int biggest = old_biggest;
  int product = 1;

  for (int i=0;i< 400;i++)
    {
      // first, skip this part if we're too close to the end of the line
      if (i/20 < 3 || i%20 > 16)
	continue;
      
      // we have enough room so build a product
      product = 1;
      for (int j = 0;j < 4;j++)
	{
	  product *= grid[i/20-j][(i%20)+j];
	}

      // we have our product for this i, check if it's bigger than biggest
      if (product > biggest)
	biggest = product;
    }
  return biggest;
}
