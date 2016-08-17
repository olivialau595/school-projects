/****************************************************
 * File Name: queue.cc
 * Author: Olivia Lau
 * Adapted from: Robert Kruse and Alexander Ryba
 *         from "Data Structures and Program Design in C++"
 * Course: CSCI 132
 * Purpose: Implementation of Queue class
 * Date: March 12, 2014
 *****************************************************/

#include "queue.h"

Queue :: Queue(const Queue &original) // copy constructor
/**********************************************************************
* Pre: None
* Post: The Queue is initialized as a copy of Queue original.
**********************************************************************/
{
  Node *newcopy, *originalnode;   //pointers for marking position on list
  originalnode = original.front;

  //front is null if original is null
  if(originalnode == NULL)
    front = NULL;
  else 
    {
      //sets the front of linked list
      front = newcopy = new Node (originalnode -> entry);

      //duplicates rest of linked list
      while (originalnode -> next != NULL)
	{
	  originalnode = originalnode ->next;
	  newcopy -> next = new Node (originalnode -> entry);
	  newcopy = newcopy -> next; 
	}
    }
}//end of copy constructor

void Queue :: operator = (const Queue &original) //overloaded assignment
/**********************************************************************
* Pre: None
* Post: The Queue is reset as a copy of Queue original.
**********************************************************************/
{

  Node *newfront, *newcopy, *originalnode;  //pointers for marking pos on list
  originalnode = original.front;

  if(originalnode == NULL)
    newfront = NULL;
  else
    {
      //sets front of new list as front of original list
      newfront = new Node (originalnode ->entry);
      newcopy = newfront;

      //copies rest of the list
      while (originalnode -> next != NULL)
	{
	  originalnode = originalnode -> next;
	  newcopy -> next = new Node (originalnode -> entry);
	  newcopy = newcopy -> next;
	}
    }

  //deletes old linked list
  while (!empty())
    serve();

  //sets copied list from original to the queue
  front = newfront;

}//end of operator=

Queue :: ~Queue() //deconstructor
/**********************************************************************
* Pre: None
* Post: The Queue is cleared and the memory returned to the heap.
**********************************************************************/
{
   while(!empty())
    {
      serve();      //pop() deletes nodes, doesn't need error check
    }
}//end of deconstructor


Term :: Term(int exponent, double scalar)
/**********************************************************************
* Pre: None
* Post: The Term is initialized with the given coefficient 
*       and exponent, or with default parameter values of 0.
**********************************************************************/
{
  degree = exponent;
  coefficient = scalar;
} //end Term()

Node ::Node()
/**********************************************************************
* Pre: None
* Post: An empty node with a NULL pointer to next is created.
**********************************************************************/
{
  next =NULL ;
} //end Node()

Node ::Node(Node_entry item ,Node *add_on)
/**********************************************************************
* Pre: None
* Post: A Node is created with data entry  of item and next pointer 
*       given by add_on (default is NULL)
**********************************************************************/
{
  entry =item ;
  next =add_on ;
} //end Node(Node_entry, Node)

int Extended_queue::size( ) const
/**********************************************************************
* Pre: None
* Post: Return the number of entries in the Extended_queue. 
**********************************************************************/
{
  Node *window = front;
  int count = 0;
  while (window != NULL) {
    window = window->next;
    count++;
  } // end while
  return count;
} //end size()

bool Extended_queue :: full() const
/**********************************************************************
* Pre: None
* Post: Return true if no room in queue.
**********************************************************************/
{
  Node *new_node = new Node();
  return new_node == NULL;
} //end full()

void Extended_queue::clear() 
/**********************************************************************
* Pre: None
* Post: Delete all the entries of the queue.
**********************************************************************/
{
  while (!empty()) {
    serve();
  } //end while
} //end clear()

Error_code Extended_queue :: serve_and_retrieve(Queue_entry &item)
/**********************************************************************
* Pre: None
* Post: Return entry at front of queue in item, then delete front node
**********************************************************************/
{
  if( retrieve(item) == underflow) {
    return underflow;
  } //end if
  return serve();
} //end serve_and_retrieve( )

Queue::Queue()
/**********************************************************************
* Pre: None
* Post: The Queue is initialized to be empty.
**********************************************************************/
{
  front = rear = NULL;
} //end Queue()


bool Queue::empty() const
/**********************************************************************
* Pre: None
* Post: Return true if the Queue is empty, otherwise return false.
**********************************************************************/
{
  return front == NULL;
} //end empty()


Error_code Queue::append(const Queue_entry &item)
/**********************************************************************
* Pre: None
* Post: item is added to the rear of the Queue. If the Queue is full
*       return an Error_code of overflow and leave the Queue unchanged.
**********************************************************************/
{
  Node *new_rear = new Node(item);
  if (new_rear == NULL) {
    return overflow;
  } //end if
  if (rear == NULL) {
    front = rear = new_rear;
  } else {
    rear->next = new_rear;
    rear = new_rear;
  } //end if-else
  return success;
} //end append()


Error_code Queue::serve()
/**********************************************************************
* Pre: None
* Post: The front of the Queue is removed. If the Queue
*       is empty return an Error_code of underflow.
**********************************************************************/
{
  Node *old_front;
  if (front == NULL) {
    return underflow;
  } //end if
  old_front = front;
  front = old_front->next;
  if (front == NULL) {
    rear = NULL;
  } //end if
  delete old_front;
  return success;
} //end serve()


Error_code Queue::retrieve(Queue_entry &item) const
/**********************************************************************
* Pre: None
* Post: The front of the Queue retrieved to the output
*       parameter item. If the Queue is empty return an Error_code of underflow.
**********************************************************************/
{
  if (front == NULL) {
    return underflow;
  } //end if
  item = front->entry;
  return success;
} //end retrieve()




