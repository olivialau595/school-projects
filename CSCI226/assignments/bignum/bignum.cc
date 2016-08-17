//Name: Olivia Lau
//File: bignum.cc
//Date: September 5, 2014
//Class: CSCI226
//Assignment: BigNum
//Purpose: To perform basic arithmetic for large positive numbers
//Input: 2 large numbers and an operation
//Output: The outcome of the operation
//_____________________________________________________________________

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

void read (int []);
void add (int[], int[], int[]);
void sub (int[], int[], int[]);
void mod (int[], int[], int[]);
void mult (int[], int[], int[]);
void digitmult (int [], int, int[]);
bool check (int[], int[]);
void print (int []);

//constant variables
//__________________________________
//number of "places" in each bignum
const int N = 30;
//each place in a bignum must be >0 and <R
const int R = 1000;
//width of each place for printing
const int W = 3;


int main()
{
  int a[N] = {};                 // array to hold x
  int b[N] = {};                 // array to hold y
  int ans[N] = {};               // array to hold answer
  char operation = ' ';          // char to hold the operation

  //reads in x, y values and operation
  read (a);
  cin >> operation;
  read (b);

  //checks if operation is valid
  if (operation == '+' || '-' || '%' || '*' || '/')
  {
    //first part of output
    print (a);
    cout << operation << endl;
    print(b);
    cout << "=" << endl;

    //switch statement dependant on operation
    switch (operation)
      {
      case '+':
	add (a, b, ans);
	break;
	//end of +

      case '-':
	//checks to make sure a > b
	if (check (a, b))
	  sub (a, b, ans);
	else 
	  cout << "warning: y is greater than x" << endl;	
	break;
	//end of -

      case '%':
	//checks to make sure a > b
	if (check(a, b))
	    mod (a, b, ans);
	else
	  //if b < a, then the answer is just b[]
	  {
	    for (int j = 0; j < N; j++)
	      ans[j] = a[j];
	  }
	break;

      case '*':
	mult (a, b, ans);
	break;

      }

    print (ans);
  }
  else
    //warning if operation is not +, -, *, %, /
    cout << "warning: operation invalid. exiting program" << endl;

  return 11;
}

//reads the digits and places them in the correct format
void read (int x[])
{
  int digit;
  int i = 0;

  while (cin >> digit)
    {
      //this loop repeats as long as a number for big digit is inputed
      if (digit < 0 || digit >= R)
	{
	  cout << "warning: invalid big digit: " << digit << endl;
	}
      else
	{
	  //shifts the digits of x over by one place to the left
	  for(int k = i; k >= 0; k--)
	    {
	      x[k + 1] = x[k];
	    }

	  //the newest digit is placed in the zero position
	  x[0] = digit;
	}
      i++;
    }

  cin.clear();
  cin.unget();

}

//addition function
void add (int a[], int b[], int ans[])
{
  int carry;                  //variable for the number carried
  int c[N] = {};             //array to store carried number

  for (int i = 0; i < N; i++)
    {
      carry = 0;

      //checks if sum is > 999
      if(a[i] + b[i] + c[i]> (R - 1))
	{
	  //check to make sure i+1 wont run off the array
	  if (i != (N - 1))
	    {
	      carry = R;
	      c [i + 1] += 1;
	    }
	  else
	    cout << "warning: overflow" << endl;
	}

      //answer < 1000 that gets stored in the array
      ans[i] = a[i] + b[i] +c[i] - carry;
    }
}

//subtraction function
void sub (int a[], int b[], int ans[])
{
  for (int i = 0; i < N; i++)
    {
      //borrows from previous array spot
      if (a[i] - b[i] < 0)
	{
	  a[i + 1] -= 1;
	  a[i] += R;
	}

      ans[i] = a[i] - b[i];
    }
}

//modulo function
void mod (int a[], int b[], int ans[])
{
  //do while loop continues until a < b
  do
    {
      //subtracts and switches arrays
      sub (a, b, ans);
      for (int i = 0; i < N; i++)
	a[i] = ans[i];
    }
  while (check(a, b));

  //switches ans and a array
  for (int i = 0; i < N; i++)
    ans[i] = a[i];
}

//multiplication function
void mult (int a[], int b[], int ans[])
{
  int ans1[N] = {};            //temporary array to hold an answer
  int tempans[N] = {};         //temporary array to hold another answer

  for(int i = (N - 1); i >= 0; i--)
    {
      //calls digitmult function
      digitmult (a, b[i], ans1);

      //shifts the tempans in preparation of adding ans1
      if (tempans[N - 1] != 0)
	cout <<" warning: overflow" << endl;
      for (int j = (N - 2); j >= 0; j--)
	{
	  tempans[j + 1] = tempans[j];
	}
      tempans[0] = 0;

      //resets ans array
      for (int k = 0; k < N ; k++)
	ans[k] = 0;

      //calls add function
      add (ans1, tempans, ans);

      //copies ans to tempans
      for (int k = 0; k < N; k++)
	{
	  tempans[k] = ans[k];
	}
    }

}

//function to multiply an array by a constant
void digitmult (int a[], int x, int ans[])
{
  int carry = 0;             //variable for carried numbers
  int tempans = 0;           //variable for temporary answer

  for (int i = 0; i < N; i++)
    {
      tempans = (a[i] * x) + carry;

      //makes sure what is stored in ans[i] is < 1000
      ans[i] = tempans % R;
      //carried number stored in carried variable
      carry = tempans / R;
    }

  //if there is still a number being carried after 29 slots, overflow
  if (carry != 0)
    cout << "warning: overflow" << endl;
}

//checks if array a > array b
bool check (int a[], int b[])
{
  //runs through the array and compares each position from N - 1 to 0
  for (int i = (N - 1); i >= 0; i--)
    {
      if (a[i] > b[i])
	return true;
      if (a[i] < b[i])
	return false;
    }

  // if out of for loop, then a = b
  return true;
}

//function to print array
void print (int x[])
{

  const char FILL = ' ';

  int i = N - 1;

  //leaves spaces for the zeros in the array
  while (i > 0 && x[i] == 0)
    {
      cout << " " << setw(W) << setfill(FILL) << "";
      i--;
    }

  //prints the first non-zero big digit with a space
  //still uses FILL in case the big digit starts with a zero
  cout << " " << setw(W) << setfill(FILL) << x[i];
  i--;

  //prints remaining big digits 
  while (i >= 0)
    {
      cout << " " << setw(W) << setfill('0') << x[i];
      i--;
    }
  cout << endl;

}

