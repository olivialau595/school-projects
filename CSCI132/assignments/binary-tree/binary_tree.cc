//Name: Olivia Lau
//Date: April 29, 2014
//Assignment: Assignment 9
//Program file: binary_tree.cc
//Purpose: implementation of binary tree functions to find the size, clear,
//         find the preorder, inorder, and postorder of a binary tree
//Precondition: Binary_tree object has been initialized
//Postcondition: varies by function
//-------------------------------------------------------------------------

template <class Entry>
Binary_tree<Entry> :: Binary_tree( )
/* Post: An empty binary tree has been created. */
{
  root = NULL;
}// default constructor


template <class Entry>
bool Binary_tree<Entry> :: empty( ) const
/* Post: A result of true is returned if the binary tree is 
     empty. Otherwise, false is returned. */
{
  return root == NULL;
} //empty

template <class Entry>
int Binary_tree<Entry> :: size() const
/* Post: Returns the number of nodes in the tree
   Uses: The function recursive_size */
{
  return recursive_size(root);
} //size

template <class Entry>
int Binary_tree<Entry> :: recursive_size(Binary_node<Entry> *sub_root) const
/* Post: Returns the number of nodes in the tree or subtree pointed to by sub_root*/
{
  int count = 0;     //variable to store the number of nodes

  //if statement to continue looking down the tree
  if(sub_root != NULL)
    {
      //count is the count of left and right subtree and the node itself
      count += recursive_size(sub_root -> left) + 
	recursive_size(sub_root ->right) + 1;
    }
  return count;

} //recursive_size

template <class Entry>
void Binary_tree<Entry> :: clear( )
/* Post: All entries of the binary tree are removed. */
{
  //calls recursive_clear with correct parameter
  recursive_clear(root);
} //clear


template <class Entry>
void Binary_tree<Entry> :: recursive_clear(Binary_node<Entry> * &sub_root)
/* Post: The subtree rooted at sub_root is cleared. */
{
  //continues to clear if subroot is not at the end of tree
  if(sub_root != NULL)
    {
      //recursivelt clears left and right sides
      recursive_clear(sub_root -> left);
      recursive_clear(sub_root -> right);

      //deletes the subroot after clearing children nodes
      delete sub_root;

      //sets subroot to null for future use
      sub_root = NULL;
    }

} //recursive_clear

template <class Entry>
void Binary_tree<Entry> :: inorder(void (*visit)(Entry &))
/* Post: The tree has been been traversed in inorder sequence.
   Uses: The function recursive_inorder */
{
  recursive_inorder(root, visit);
} //inorder

template <class Entry>
void Binary_tree<Entry> :: recursive_inorder(Binary_node<Entry> *sub_root,
                                              void (*visit)(Entry &))
/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
   Post: The subtree has been been traversed in inorder sequence.
   Uses: The function recursive_inorder recursively */
{
  if (sub_root != NULL) {
     recursive_inorder(sub_root->left, visit);
     (*visit)(sub_root->data);
     recursive_inorder(sub_root->right, visit);
  } //not NULL
} //recursive_inorder

template <class Entry>
void Binary_tree<Entry> :: preorder(void (*visit)(Entry &))
/* Post: The tree has been been traversed in inorder sequence.
   Uses: The function recursive_inorder */
{
  recursive_preorder(root, visit);
} //preorder

template <class Entry>
void Binary_tree<Entry> :: recursive_preorder(Binary_node<Entry> *sub_root,
                                              void (*visit)(Entry &))
/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
   Post: The subtree has been been traversed in preorder sequence.
   Uses: The function recursive_preorder recursively */
{
  if (sub_root != NULL) {
    (*visit)(sub_root->data);
    recursive_preorder(sub_root->left, visit);
    recursive_preorder(sub_root->right, visit);
  } //not NULL
} //recursive preorder

template <class Entry>
void Binary_tree<Entry> :: postorder(void (*visit)(Entry &))
/* Post: The tree has been been traversed in inorder sequence.
   Uses: The function recursive_postorder */
{
  recursive_postorder(root, visit);
} //postorder

template <class Entry>
void Binary_tree<Entry> :: recursive_postorder(Binary_node<Entry> *sub_root,
                                                void (*visit)(Entry &))
/* Pre: sub_root is either NULL or points to a subtree of the Binary_tree.
   Post: The subtree has been been traversed in postorder sequence.
   Uses: The function recursive_postorder recursively */
{
  if (sub_root != NULL) {
    recursive_postorder(sub_root->left, visit);
    recursive_postorder(sub_root->right, visit);
    (*visit)(sub_root->data);
  } //not NULL
} //recursive_postorder

template <class Entry>
Binary_tree<Entry> :: ~Binary_tree( )
/* Post: All entries of the binary tree are removed. 
     All dynamically allocated memory in the
     structure is deleted. */
{
  clear( );
} //destructor

template <class Entry>
Binary_tree<Entry> :: Binary_tree (const Binary_tree<Entry> &original)
/* Post: A new binary tree is initialized to copy original. */
{
  root = recursive_copy(original.root);
} //copy constructor

template <class Entry>
Binary_node<Entry> *Binary_tree<Entry> :: recursive_copy(Binary_node<Entry> *sub_root)
/* Post: The subtree rooted at sub_root is copied, 
     and a pointer to the root of the new copy is
     returned. */
{
  if (sub_root == NULL) return NULL;
  Binary_node<Entry> *temp = new Binary_node<Entry>(sub_root->data);
  temp->left = recursive_copy(sub_root->left);
  temp->right = recursive_copy(sub_root->right);
  return temp;
} //recursive copy

template <class Entry>
Binary_tree<Entry> &Binary_tree<Entry> :: operator = (const Binary_tree<Entry> &original)
/* Post: The binary tree is reset to copy original. */
{
  Binary_tree<Entry> new_copy(original);
  clear( );
  root = new_copy.root;
  new_copy.root = NULL;
  return *this;
} //overloaded assignment

template <class Entry>
Error_code Binary_tree<Entry> :: insert(const Entry &new_data) {
	return recursive_insert(root, new_data);
} //insert

template <class Entry>
Error_code Binary_tree<Entry> :: recursive_insert(Binary_node<Entry> * &sub_root, 
                                                   const Entry &new_data)
{
  if (sub_root == NULL) {
     sub_root = new Binary_node<Entry>(new_data);
     return success;
  } else if (new_data < sub_root->data)
      return recursive_insert(sub_root->left, new_data);
  else if (new_data > sub_root->data)
      return recursive_insert(sub_root->right, new_data);
  else return duplicate_error;
} //recursive insert

template <class Entry>
Binary_node<Entry>::Binary_node( ) {
	left = NULL;
	right = NULL;
} //default constructor
	
template <class Entry>
Binary_node<Entry>::Binary_node(const Entry &x) {
	left = NULL;
	right = NULL;
	data = x;
} //constructor

