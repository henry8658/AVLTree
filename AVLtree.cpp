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
  bool isInserted = false;
  insertHelper(root, data, isInserted);
  return isInserted;
}

int AVLtree::balanceFactor(Node* node) const
{
  return getHeight(node->right) - getHeight(node->left);
}

void AVLtree::insertHelper(Node*& node, int data, bool& status)
{
  if (node == nullptr)
  {
    node = new Node();
    node->data = data;
    node->height = 1;
    node->right = nullptr;
    node->left = nullptr;
    status = true;
  } else if (node->data < data)
  {
    insertHelper(node->right, data);
  } else if (node->data > data)
  {
    insertHelper(node->left, data);
  } else if (node->data == data)
  {
    return ;
  }

<<<<<<< HEAD
  updateHeight(node);
  balance(node);
=======
  if (balanceFactor(node) == -2)
  {
    //If left subtree is right-heavy, then perform left-right rotation.
    if (balanceFactor(node->left) > 0) leftRotation(node->left);
    rightRotation(node);
  }
>>>>>>> 761d24bf40ab9663659f1425dca5b95a5cd3e67a
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
  if (node == nullptr) return ;
  node->height = std::max(getHeight(node->right), getHeight(node->left)) + 1;
}

void AVLtree::removeHelper(AVLtree::Node*& node, int data, bool& status)
{
  if (node == nullptr)
  {
    return ;
  } else if (node->data == data)
  {
    if (node->right == nullptr)
    {
      Node* temp = node;
      node = node->left;
      delete temp;
    } else
    {
      findAndDeleteMinNode(node->right, node->data);
    }
    status = true;
  } else if (node->data < data)
  {
    removeHelper(node->right, data, status);
  } else if (node->data > data)
  {
    removeHelper(node->left, data, status);
  }

  updateHeight(node);
  balance(node);
}

void AVLtree::findAndDeleteMinNode(Node*& node, int& data)
{
  if (node->left == nullptr)
  {
    Node* temp = node;
    node = node->right;
    data = temp->data;
    delete temp;
  } else
  {
    findAndDeleteMinNode(node->left, data);
  }
  updateHeight(node);
  balance(node);
}

bool AVLtree::Remove(int data)
{
  bool isRemoved = false;
  removeHelper(root, data, isRemoved);
  return isRemoved;
}

void AVLtree::balance(Node*& node)
{
  if (balanceFactor(node) == 2)
  {
    //If right subtree is left-heavy, then perform right-left rotation.
    if (balanceFactor(node->right) < 0) rightRotation(node->right);
    leftRotation(node);
  }

  if (balanceFactor(node) == -2)
  {
    //If left subtree is right-heavy, then perform left-right rotation.
    if (balanceFactor(node->left) > 0) rightRotation(node->left);
    rightRotation(node);
  }
}
