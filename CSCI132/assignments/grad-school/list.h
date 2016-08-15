#ifndef LIST_H
#define LIST_H
enum Error_code { success, fail, range_error, underflow, overflow, fatal,
not_present, duplicate_error, entry_inserted, entry_found,
internal_error };

const int max_list= 100;

template<class List_entry>
class List {
 public:
  // methods of the List ADT
  List( );
  int size( ) const;
  bool full( ) const;
  bool empty( ) const;
  void clear( );
  void traverse(void (*visit)(List_entry &));
  Error_code retrieve(int position, List_entry &x) const;
  Error_code replace(int position, const List_entry &x);
  Error_code remove(int position, List_entry &x);
  Error_code insert(int position, const List_entry &x);
 protected:
  // data members for a contiguous list implementation
  int count;
  List_entry entry[max_list];
};


#endif
