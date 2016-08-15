/*************************************************
 * File name: stack.h
 * Purpose: Specification of Stack class
 *          Stack represented as an array
 *          Has all basic stack functions, plus size()
 *          Created for use in CSCI 132
 * Author: CSCI 132 Instructor
 * Date modified: January 1, 2011
 ************************************************/

#include <iostream>
#include "polynomial.h"

using namespace std;

#ifndef STACK_H
#define STACK_H

typedef Polynomial Stack_entry;

const int maxstack = 52;   //  small value for testing
enum Error_code {success, fail, underflow, overflow};

class Stack {
 public:
  Stack();
  bool empty() const;
  int size() const;
  Error_code pop();
  Error_code top(Stack_entry &item) const;
  Error_code push(const Stack_entry &item);

 protected:
  int count;
  Stack_entry entry[maxstack];
};

#endif
