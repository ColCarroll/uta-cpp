// This program runs a collection of sorts on an array

#include <iostream>
using namespace std;

void shuffle (char list[26]);
void sort (char list[26]);
void printlist (char list[26]);
void qsort (char list[26], int start, int end);
void bubsort (char list[26]);
void swap(char list[26], int first, int second);
void insort (char list[26]);
struct leaf
{
  char value;
  leaf *child1;
  leaf *child2;


  leaf(char new_value) : value(new_value), child1(NULL),child2(NULL) { }
  
  /*
    leaf(char new_value)
    {
    // constructor.  make a leaf containing new_value
    value = new_value;
    child1 = NULL;
    child2 = NULL;
    }*/
};
void treesort (char list[26]);

int main ()
{
  char list[26];

  shuffle(list);

  cout << "This is a before and after of Quicksort:" << endl;
  printlist(list);
  qsort(list,0,25);
  printlist(list);

  shuffle(list);

  cout << "This is a before and after of Bubblesort:" << endl;
  printlist(list);
  bubsort(list);
  printlist(list);

  shuffle(list);

  cout << "This is a before and after of Insertionsort:" << endl;
  printlist(list);
  insort(list);
  printlist(list);

  shuffle(list);

  cout << "This is a before and after of Treesort:" << endl;
  printlist(list);
  treesort(list);
  printlist(list);


}

// Performs a really stupid shuffle.  I should really be more sophisticated about this.
void shuffle(char list[26])
{
  list[0] = 'c';

  for(int i = 0; i < 23; i++)
    {
      list[i+1] = list[i]+1;
    }
  list[24] = 'a';
  list[25] = 'b';
}

void printlist(char list[26])
{
  for (int i = 0; i < 26; i++)
    {
      cout << list[i];
    }
  cout << endl;
}

// Performs a QuickSort. 
// start is the index to begin sorting,
// end is the index to end sorting
// end functions as the pivot 
void qsort(char list[26], int start, int end)
{
  if (start >= end)
    return;

  char newlist[26];
  int lesser = start;
  int greater = end;
  //copystuff from outside lists??

  for (int i = start; i < end; i++)
    {
      if (list[i] < list[end])
	{
	  newlist[lesser] = list[i];
	  lesser++;
	}
      else
	{
	  newlist[greater] = list[i];
	  greater--;
	}
    }
  newlist[lesser]=list[end];
  
  for (int i = start;i <= end; i++)
    {
      list[i]= newlist[i];
    }

  //recursively call qsort of the lesser and greater halves
  qsort(list,start,lesser-1);
  qsort(list,greater+1,end);
}

// swaps the entries first and second in list
void swap(char list[26], int first, int second)
{
  char temp = list[first];
  list[first] = list[second];
  list[second] = temp;
}

// performs a Bubblesort on list
void bubsort(char list[26]) 
{
  int cursor = 26; //the earliest correctly sorted number

  while (cursor > 0) 
    {
      for (int i = 0; i < cursor - 1; i++)
	{
	  if (list[i]>list[i+1])
	    swap(list,i,i+1);
	}

      //  To see the step-by-step, delete the comments on this:
      //      printlist(list);
      cursor--;
    }
}

// performs an Insertionsort on list
void insort(char list[26])
{
  int least; //marks the smallest element of the list on each pass

  for (int i = 0; i < 25; i++)
    {
      least = i;

      // find the least term among the unsorted section of the list
      for (int j = i+1; j < 26; j++)
	{
	  if (list[least] > list[j])
	    least = j;
	}

      swap(list,i,least);
      //  To see the step-by-step, delete the comments on this:
      //      printlist(list);
    }
}

// Finds the pointer to parent of the leaf that element should be the value of.
// When calling, one should send call with the root as current_leaf 
leaf* findPlace (char element, leaf* current)
{
  //leaf current = *current_leaf;
  if (current->value > element)
    {
      // debug code:
      //cout << current->value << " is greater than " << element << endl;

      if (current->child1 == NULL)
	{
	  // debug code:
	  // cout << current->value << " doesn't have a left child." << endl; 
	  return current;
	}
      return findPlace(element,current->child1);
    }
  else 
    {
      // debug code:
      // cout << current->value << " is less than " << element << endl;

      if (current->child2 == NULL)
	{
	  // debug code:
	  // cout << current->value << " doesn't have a right child." << endl; 
	  return current;
	}
      return findPlace(element,current->child2);
    }
}

// traverses the tree, adding the elements to list as they are found
void traverse_tree (char list[26], leaf* current, int* index)
{
  //leaf current = *current_leaf;
  if (current->child1 == NULL) 
    {
      list[*index] = current->value; // found it!
      (*index)++;
    }
  else 
    {
      traverse_tree(list,current->child1, index); // take care of the left subtree
      list[*index] = current->value;
      (*index)++;
    }
    
  if (current->child2 != NULL)
    traverse_tree(list,current->child2, index); // take care of the right subtree
}

// performs a Treesort on list
void treesort(char list[26])
{
  // build the first leaf, to start:
  leaf *root; 
  root = new leaf(list[0]); // WTF WHY DO I NOT NEED *root HERE I'M PISSED

  // first, build the tree:
  for (int i = 1; i<26; i++)
    {
      // build a new leaf:
      leaf *new_leaf;
      new_leaf = new leaf(list[i]);  // STILL PISSED.

      // find the parent of the leaf you want to be, and place yourself there:
      leaf *parent = findPlace(list[i],root);

      // Debug code:
      // cout << "the parent " << parent->value << " is receiving the child " << list[i] << endl;

      if (parent->value > new_leaf->value)
	{
	  parent->child1 = new_leaf;
	}
      else
	{
	  parent->child2 = new_leaf;
	}
    }

  // now sort the array by running through the list:
  int k = 0;
  traverse_tree(list,root,&k);
}

