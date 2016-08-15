#include "sortable_list.h"

template <class Record>
void Sortable_list<Record> :: insertion_sort( )
/* Post: The entries of the Sortable_list have been rearranged so that the keys in
all the entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the contiguous List implementation of
Chapter 6 */
{
  int first_unsorted; // position of first unsorted entry
  int position; // searches sorted part of list
  Record current; // holds the entry temporarily removed from list
  for (first_unsorted = 1; first_unsorted < List<Record>::count; first_unsorted++) {
    if (List<Record>::entry[first_unsorted] < List<Record>::entry[first_unsorted - 1]) {
      position = first_unsorted;
      current = List<Record>::entry[first_unsorted]; // Pull unsorted entry out of the list.
      do { // Shift all entries until the proper position is found.
        List<Record>::entry[position] = List<Record>::entry[position - 1];
        position--; // position is empty.
      } while (position > 0 && List<Record>::entry[position - 1] > current);
      List<Record>::entry[position] = current;
    } //end if
  }
} //insertion_sort


template <class Record>
void Sortable_list<Record> :: selection_sort( )
/* Post: The entries of the Sortable_list have been rearranged so that the keys in
all the entries are sorted into nondecreasing order.
Uses: max_key, swap. */
{
  for (int position = List<Record>::count - 1; position > 0; position--) {
    int max = max_key(0, position);
    swap(max, position);
  }
} //selection_sort

template <class Record>
int Sortable_list<Record> :: max_key(int low, int high)
/* Pre: low and high are valid positions in the Sortable_list and low <= high.
Post: The position of the entry between low and high with the largest key is
returned.
Uses: The class Record. The contiguous List implementation of Chapter 6. */
{
  int largest, current;
  largest = low;
  for (current = low + 1; current <= high; current++)
    if (List<Record>::entry[largest] < List<Record>::entry[current])
      largest = current;
  return largest;
} //max_key

template <class Record>
void Sortable_list<Record> :: swap(int low, int high)
/* Pre: low and high are valid positions in the Sortable_list.
Post: The entry at position low is swapped with the entry at position high.
Uses: The contiguous List implementation of Chapter 6. */
{
  Record temp;
  temp = List<Record>::entry[low];
  List<Record>::entry[low] = List<Record>::entry[high];
  List<Record>::entry[high] = temp;
} //swap

template <class Record>
void Sortable_list<Record>::merge(int low, int high)
{
  Record *temp = new Record[high - low + 1];
  int index = 0;
  int index1 = low, mid = (low + high)/ 2, index2 = mid + 1;
  while (index1 <= mid && index2 <= high){
    if (List<Record>::entry[index1] < List<Record>::entry[index2])
      temp[index++] = List<Record>::entry[index1++];
    else
      temp[index++] = List<Record>::entry[index2++];
  }
  while (index1 <= mid)
    temp[index++] = List<Record>::entry[index1++];
  while (index2 <= high)
    temp[index++] = List<Record>::entry[index2++];
  for (index = low; index <= high; index++)
    List<Record>::entry[index] = temp[index -low];
  delete []temp;
} //merge

template <class Record>
void Sortable_list<Record>::recursive_merge_sort(int low, int high)
/*
Post: The entries of the sortable list between
index low and high have been rearranged so that
their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6.
*/
{
  if (high > low){
    recursive_merge_sort(low, (high + low)/ 2);
    recursive_merge_sort((high + low) / 2 + 1, high);
    merge(low, high);
  }
} //recursive_merge_sort

template <class Record>
void Sortable_list<Record>::merge_sort()
/*
Post: The entries of the sortable list have been rearranged so that
their keys are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6.
*/
{
  recursive_merge_sort(0, List<Record>::size()- 1);
} //merge_sort


template <class Record>
void Sortable_list<Record> :: quick_sort( )
/* Post: The entries of the Sortable_list have been rearranged so that their keys
are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6, recursive_quick_sort. */
{
  recursive_quick_sort(0, List<Record>::count - 1);
} //quick_sort

template <class Record>
void Sortable_list<Record> :: recursive_quick_sort(int low, int high)
/* Pre: low and high are valid positions in the Sortable_list.
Post: The entries of the Sortable_list have been rearranged so that their keys
are sorted into nondecreasing order.
Uses: The contiguous List implementation of Chapter 6, recursive_quick_sort,
and partition. */
{
  int pivot_position;
  if (low < high) { // Otherwise, no sorting is needed.
    pivot_position = partition(low, high);
    recursive_quick_sort(low, pivot_position - 1);
    recursive_quick_sort(pivot_position + 1, high);
  }
} //recursive_quick_sort

template <class Record>
int Sortable_list<Record> :: partition(int low, int high)
/* Pre: low and high are valid positions of the Sortable_list, with low <= high.
Post: The center (or left center) entry in the range between indices low and
high of the Sortable_list has been chosen as a pivot. All entries of the
Sortable_list between indices low and high, inclusive, have been rearranged
so that those with keys less than the pivot come before the pivot
and the remaining entries come after the pivot. The final position of the
pivot is returned.
Uses: swap(int i, int j) (interchanges entries in positions i and j of a Sortable_list),
the contiguous List implementation of Chapter 6, and methods for the
class Record. */
{
  Record pivot;
  int i, // used to scan through the list
  last_small; // position of the last key less than pivot
  swap(low, (low + high)/2);
  pivot = List<Record>::entry[low]; // First entry is now pivot.
  last_small = low;
  for (i = low + 1; i <= high; i++)
  /* At the beginning of each iteration of this loop, wehave the following conditions:
   *If low < j <= last_small then entry[j].key < pivot.
   *If last_small < j < i then entry[j].key >= pivot. */
    if (List<Record>::entry[i] < pivot) {
      last_small = last_small + 1;
      swap(last_small, i); // Move large entry to right and small to left.
    }
  swap(low, last_small); // Put the pivot into its proper position.
  return last_small;
} //partition


