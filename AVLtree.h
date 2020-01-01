#include <iostream>
#ifndef ALGORITHMS__AVLTREE_H_
#define ALGORITHMS__AVLTREE_H_

class AVLtree
{
 public:
  AVLtree();
  ~AVLtree();

  bool Insert(int data);
  void Display();
  bool isEmpty();

 private:
  struct Node
  {
    Node* left;
    Node* right;
    int data;
    int height;
  };
  Node *root;

  int balanceFactor(Node* node) const;
  void insertHelper(Node*& node, int data);
  void rightRotation(Node*& node);
  void leftRotation(Node*& node);
  void inOrder(Node* node) const;
  int getHeight(Node* node) const;
  void updateHeight(Node*& node);

};

#endif //ALGORITHMS__AVLTREE_H_
