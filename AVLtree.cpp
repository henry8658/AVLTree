//
// Created by Henry Park on 12/12/19.
//

#include "AVLtree.h"

AVLtree::AVLtree()
{
  root = nullptr;
}

AVLtree::~AVLtree()
{

}

bool AVLtree::isEmpty()
{
  return root == nullptr;
}

bool AVLtree::Insert(int data)
{
  insertHelper(root, data);
  return true;
}

int AVLtree::balanceFactor(Node* node) const
{
  return getHeight(node->right) - getHeight(node->left);
}

void AVLtree::insertHelper(Node*& node, int data)
{
  if (node == nullptr)
  {
    node = new Node();
    node->data = data;
    node->height = 1;
    node->right = nullptr;
    node->left = nullptr;
  } else if (node->data < data)
  {
    insertHelper(node->right, data);
  } else if (node->data > data)
  {
    insertHelper(node->left, data);
  }

  updateHeight(node);

  if (balanceFactor(node) == 2)
  {
    leftRotation(node);
  }

  if (balanceFactor(node) == -2)
  {
    rightRotation(node);
  }

}

void AVLtree::Display()
{
  inOrder(root);
}

void AVLtree::inOrder(Node* node) const
{
  if (node->left != nullptr) inOrder(node->left);
  std::cout << node->data << " " << node->height << " " << balanceFactor(node) << std::endl;
  if (node->right != nullptr) inOrder(node->right);
}

void AVLtree::rightRotation(AVLtree::Node*& node)
{
  Node* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  updateHeight(node);
  node = temp;
  updateHeight(temp);
}

void AVLtree::leftRotation(AVLtree::Node *&node)
{
  std::cout << node->data << std::endl;
  Node* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  updateHeight(node);
  node = temp;
  updateHeight(temp);
}

int AVLtree::getHeight(AVLtree::Node* node) const
{
  if (node != nullptr) return node->height;
  else return 0;
}

void AVLtree::updateHeight(AVLtree::Node*& node)
{
  node->height = std::max(getHeight(node->right), getHeight(node->left)) + 1;
}





