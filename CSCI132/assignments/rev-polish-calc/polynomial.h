#include "queue_array.h"

/*
Once you have your queue.cc methods implemented
you should change to include the dynamic queue
implementation and use the following include
       #include "queue.h"
instead of the array header and implementation
*/

#ifndef POLY_H
#define POLY_H
class Polynomial: private Extended_queue { // Use private inheritance.
public:
  void read( );
  void print( );
  void equals_sum(Polynomial p, Polynomial q);
  void equals_difference(Polynomial p, Polynomial q);
  void equals_product(Polynomial p, Polynomial q);
  double evaluate(double number);
  Error_code equals_quotient(Polynomial p, Polynomial q);
  int degree( ) const;
 private:
  void mult_term(Polynomial p, Term t);
};
#endif
