#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST
{
public:
  int value;
  BST *left;
  BST *right;

  BST(int value)
  {
    value = value;
    left = NULL;
    right = NULL;
  }

  BST &insert(int val)
  {
    if (this->value > val)
    {
      if (this->left)
        this->left->insert(val);
      else
        this->left = new BST(val);
    }
    else if (this->value < val)
    {
      if (this->right)
        this->right->insert(val);
      else
        this->right = new BST(val);
    }
    return *this;
  }

  bool contains(int val)
  {
    if (this->value == val)
      return true;
    if (this->value > val && this->left)
      return this->left->contains(val);
    else if (this->value < val && this->right)
      return this->right->contains(val);
    return false;
  }

  BST &remove(int val, BST *parent = NULL)
  {
    if (this->value == val)
    {
      if (this->left && this->right)
      {
        int minVal = GetMinInTree(this->right);
        this->value = minVal;
        this->right->remove(minVal, this);
      }
      else if (parent == NULL)
      {
        if (this->left)
          copyTree(this, this->left);
        if (this->right)
          copyTree(this, this->right);
      }
      else if (parent->left == this)
        parent->left = left != NULL ? left : right;
      else if (parent->right == this)
        parent->right = left != NULL ? left : right;
    }
    else if (this->value > val && this->left)
      this->left->remove(val, this);
    else if (this->value < val && this->right)
      this->right->remove(val, this);
    return *this;
  }
  int GetMinInTree(BST *root)
  {
    while (root->left)
      root = root->left;
    return root->value;
  }

  void copyTree(BST *src, BST *dest)
  {
    dest->value = src->value;
    dest->left = src->left;
    dest->right = src->right;
  }
};
