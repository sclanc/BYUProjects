#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#ifndef AVLTREESET_H
#define AVLTREESET_H

template <typename ItemType>

class AVLTreeSet {

private:

  struct Node {
    ItemType item;
    int height;
    Node* left;
    Node* right;
  };


  Node* root;

public:

  AVLTreeSet(){
    root= NULL;
    size=0;
  }

  /*The add command adds 'item' to the set if the item is not already in the set. If the set already 
   the item, the add command leaves the set unchanged. However the command is still output and processing continues 
   with the next command. The 'item' parameter is a string of non-whitespace characters. The'item' parameter cannot 
   contain any whitespace characters (space, tab, newline) because these characters are used to separate parameters. */
 
  void add(const ItemType& item) {

    if(n==null)
    {
      n = new Node(item)
    }
    else if(item< n->item)
    {
      add(n->left,item)
    }
    else if(item>n->item)
    {
      add(n->right,item)
    }

  }

/*The remove command removes 'item' from the set if the item is present in the set. If the set does not contain the item, 
the remove command leaves the set unchanged. However the command is still output and processing continues with the next 
command. The 'item' parameter is a string of non-whitespace characters.*/

  void remove(const ItemType& item) {



  }

  bool find(const ItemType& item) {

    return false;

  }

  ~AVLTreeSet()
  {
    ClearTree(root);
  }

};

#endif 