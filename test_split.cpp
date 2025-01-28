/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"

int main(int argc, char* argv[])
{
  Node* node1 = new Node(1, nullptr); 
  Node* node2 = new Node(2, nullptr);
  Node* node3 = new Node(3, nullptr);
  Node* node4 = new Node(4, nullptr); 


  node1->next = node2;
  node2->next = node3;
  node3->next = node4; 

  Node* evenNode = nullptr; 
  Node* oddNode = nullptr; 


  split(node1, oddNode, evenNode);
  delete evenNode;
  delete oddNode;  
  return 1; 

}
