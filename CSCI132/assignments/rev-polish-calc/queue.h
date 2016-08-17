/****************************************************
 * File Name: queue.h
 * Author: Robert Kruse and Alexander Ryba
 *         from "Data Structures and Program Design in C++"
 * Modified by: CSCI 132 Instructor
 * Course: CSCI132
 * Modification Date: February 14, 2011
 * Purpose: specification of Queue class
 *****************************************************/


const int maxqueue = 100; //  small value for testing
enum Error_code { success, fail, underflow, overflow };
typedef char Queue_entry;

class Queue {
 public:
  Queue();
  bool empty() const;
  Error_code serve();
  Error_code append(const Queue_entry &item);
  Error_code retrieve(Queue_entry &item) const;

 protected:
  int count;
  int front, rear;
  Queue_entry entry[maxqueue];
};

