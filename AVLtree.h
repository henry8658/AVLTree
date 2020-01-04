#include <iostream>
#ifndef AVLTREE_H_
#define AVLTREE_H_

class AVLtree
{
 public:
  AVLtree();
  ~AVLtree();

  bool Insert(int data);
  bool Remove(int data);
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
  void insertHelper(Node*& node, int data, bool& status);
  void rightRotation(Node*& node);
  void leftRotation(Node*& node);
  void inOrder(Node* node) const;
  int getHeight(Node* node) const;
  void updateHeight(Node*& node);
  void removeHelper(Node*& node, int data, bool& status);
  void findAndDeleteMinNode(Node*& node, int& data);
  void balance(Node*& node);
};

#endif //AVLTREE_H_
