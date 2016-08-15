#ifndef BINARY_TREE_H
#define  BINARY_TREE_H
enum Error_code {success, fail, range_error, underflow, overflow, duplicate_error};


template <class Entry>
struct Binary_node {
	// data members:
	Entry data;
	Binary_node<Entry> *left;
	Binary_node<Entry> *right;
	// constructors:
	Binary_node( );
	Binary_node(const Entry &x);
};

template <class Entry>
class Binary_tree {
public:
  Binary_tree( );
  bool empty( ) const;
  void preorder(void (*visit)(Entry &));
  void inorder(void (*visit)(Entry &));
  void postorder(void (*visit)(Entry &));
  void clear( );
  int size( ) const;
  Error_code insert(const Entry &);
  Binary_tree (const Binary_tree<Entry> &original);
  Binary_tree & operator = (const Binary_tree<Entry> &original);
  ~Binary_tree( );
protected:
  // Add auxiliary function prototypes here.
  void recursive_inorder(Binary_node<Entry> *sub_root,
                              void (*visit)(Entry &));
  void recursive_preorder(Binary_node<Entry> *sub_root,
                              void (*visit)(Entry &));
  void recursive_postorder(Binary_node<Entry> *sub_root,
                              void (*visit)(Entry &));
  int recursive_size(Binary_node<Entry> *sub_root) const;
  void recursive_clear(Binary_node<Entry> * &sub_root);
  Binary_node<Entry> *recursive_copy(Binary_node<Entry> *sub_root);
  Error_code recursive_insert(Binary_node<Entry> * &sub_root, 
                               const Entry &new_data);
  
  Binary_node<Entry> *root;
};

#endif
