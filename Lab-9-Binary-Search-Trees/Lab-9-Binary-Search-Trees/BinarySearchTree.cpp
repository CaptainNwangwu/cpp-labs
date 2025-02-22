#include "CSZNode.h"
#include "BinarySearchTree.h"
#include <string>
#include <stack>
using std::stack;


void BinarySearchTree::add_iteratively(const CityStateZip& new_city)
{
    CSZNode* newNode = new CSZNode(new_city);
    if (root == nullptr)  { // If the tree is empty
        root = newNode;
      }
    else { // If there is already a root
        CSZNode* current = root;
        CSZNode* previous = nullptr;
        while (current != nullptr) {
          previous = current; 
            if (*newNode < *current) {  //Compares dereferenced pointers, not memory slots (Note the dereference operator).*/
                current = current->get_left();
            }
            else { // If newNode > current   
                current = current->get_right();
            }
        }
        if (*newNode < *previous) {
            previous->set_left(newNode);
        }
        else { // If newNode > previous
            previous->set_right(newNode);
        }
    }
}



bool CSZNode::operator<(const CSZNode& op2) const {
    if (this->payload.city().compare(op2.payload.city()) < 0) {
        return true;
    }
    else {
        return false;
    }
  }

    void BinarySearchTree::write_recursively( std::ostream& strm ) const {
        write_recursively(strm, this->root);
    }
    
    void BinarySearchTree::write_recursively ( std::ostream& strm, CSZNode* current_root ) const { // Public Version
          if (current_root != nullptr) {
            write_recursively(strm, current_root->get_left());

            current_root->write(strm);
            strm << '\n';

            write_recursively(strm, current_root->get_right());
          }
        }

// Public Version
void BinarySearchTree::add_recursively(const CityStateZip& new_city) {
CSZNode* newNode = new CSZNode(new_city);
  if (root == nullptr) {
      root = newNode;
  }
  else {
    add_recursively(newNode, root);
  }
}

// Private Version
void BinarySearchTree::add_recursively( CSZNode* new_node, CSZNode* current_root ) {
  if (*new_node < *current_root && current_root->get_left() == nullptr) {
   current_root->set_left(new_node);
  }
    
  else if (*new_node < *current_root && current_root->get_left() != nullptr ) {
    add_recursively(new_node,current_root->get_left());
  }

  if (*current_root < *new_node && current_root->get_right() == nullptr) {
    current_root->set_right(new_node);
  }
    
  else if (*current_root < *new_node && current_root->get_right() != nullptr) { // y tho
    add_recursively(new_node, current_root->get_right());
  } 
}

void BinarySearchTree::write_iteratively( std::ostream& strm ) const {
  CSZNode*  curr = root;
  stack<CSZNode*> tree;

  while (curr != nullptr || !tree.empty()) {
    if (curr != nullptr) {
      tree.push(curr);
      curr = curr->get_left();
    }
    else {
      curr = tree.top();
      tree.pop();
      curr->write(strm);
      strm << '\n';
      curr = curr->get_right();
    }
  }
}


void BinarySearchTree::erase_recursively() {
    erase_recursively(root);
}

void BinarySearchTree::erase_recursively(CSZNode* current_root) {
    if (current_root != nullptr) {
      erase_recursively(current_root->get_left());
      erase_recursively(current_root->get_right());

      cout << "\nDeleting node: "; current_root->write(cout); cout << endl;
      delete current_root;
      }
  root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
  erase_recursively();
}