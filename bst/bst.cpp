#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
  int data;
  Node *lchild;
  Node *rchild;
  Node() {
    this->data = 0;
    this->lchild = NULL;
    this->rchild = NULL;
  }
  Node(int data) {
    this->data = data;
    this->lchild = NULL;
    this->rchild = NULL;
  }
};

class BST {
private:
  Node *root;

public:
  BST();
  ~BST();
  int insert(int data);
  int remove(int data);
  vector<int> inOrder();
  vector<int> preOrder();
  vector<int> postOrder();
  bool search(int data);
};

// Helper Functions
//
void freeBST(Node *root) {
  if (root == NULL)
    return;
  freeBST(root->lchild);
  freeBST(root->rchild);
  delete root;
}

Node *getSuccessor(Node *root) {
  Node *temp = root->rchild;
  while (temp->lchild) {
    temp = temp->lchild;
  }
  return temp;
}

// Class Methods
BST::BST() { this->root = NULL; }
BST::~BST() { freeBST(this->root); }

int BST::insert(int data) {
  Node *newNode = new Node(data);
  if (this->root == NULL) {
    this->root = newNode;
    return 0;
  }
  Node *temp = this->root;
  while (temp) {
    if (data < temp->data) {
      if (temp->lchild == NULL) {
        temp->lchild = newNode;
        return 0;
      } else {
        temp = temp->lchild;
      }
    } else if (data > temp->data) {
      if (temp->rchild == NULL) {
        temp->rchild = newNode;
        return 0;
      } else {
        temp = temp->rchild;
      }
    } else {
      return -1;
    }
  }
  return -1;
}

int BST::remove(int data) {
  if (this->root == NULL)
    return -1;
  Node *temp = this->root;
  Node *parent = NULL;
  while (temp) {
    if (data < temp->data) {
      parent = temp;
      temp = temp->lchild;
      continue;
    }
    if (data > temp->data) {
      parent = temp;
      temp = temp->rchild;
      continue;
    }
    if (temp->lchild == NULL && temp->rchild == NULL) {
      if (parent == NULL) {
        this->root = NULL;
      } else {
        if (parent->lchild == temp) {
          parent->lchild = NULL;
        } else {
          parent->rchild = NULL;
        }
      }
      delete temp;
      return 0;
    }
    if (temp->lchild == NULL && temp->rchild != NULL) {
      if (parent == NULL) {
        this->root = temp->rchild;
      } else {
        if (parent->lchild == temp) {
          parent->lchild = temp->rchild;
        } else {
          parent->rchild = temp->rchild;
        }
      }
      delete temp;
      return 0;
    }
    if (temp->lchild != NULL && temp->rchild == NULL) {
      if (parent == NULL) {
        this->root = temp->lchild;
      } else {
        if (parent->lchild == temp) {
          parent->lchild = temp->lchild;
        } else {
          parent->rchild = temp->lchild;
        }
      }
      delete temp;
      return 0;
    }
    Node *successor = getSuccessor(temp);
    temp->data = successor->data;
    remove(successor->data);
    return 0;
  }
  return -1;
}

vector<int> BST::inOrder() {
  vector<int> result;
  if (this->root == NULL)
    return result;
  Node *temp = this->root;
  vector<Node *> stack;
  while (temp || !stack.empty()) {
    while (temp) {
      stack.push_back(temp);
      temp = temp->lchild;
    }
    temp = stack.back();
    stack.pop_back();
    result.push_back(temp->data);
    temp = temp->rchild;
  }
  return result;
}

vector<int> BST::preOrder() {
  vector<int> result;
  if (this->root == NULL)
    return result;
  Node *temp = this->root;
  vector<Node *> stack;
  while (temp || !stack.empty()) {
    while (temp) {
      result.push_back(temp->data);
      stack.push_back(temp);
      temp = temp->lchild;
    }
    temp = stack.back();
    stack.pop_back();
    temp = temp->rchild;
  }
  return result;
}

vector<int> BST::postOrder() {
  vector<int> result;
  if (this->root == NULL)
    return result;
  Node *temp = this->root;
  vector<Node *> stack;
  Node *lastVisited = NULL;
  while (temp || !stack.empty()) {
    while (temp) {
      stack.push_back(temp);
      temp = temp->lchild;
    }
    temp = stack.back();
    if (temp->rchild == NULL || temp->rchild == lastVisited) {
      result.push_back(temp->data);
      stack.pop_back();
      lastVisited = temp;
      temp = NULL;
    } else {
      temp = temp->rchild;
    }
  }
  return result;
}

bool BST::search(int data)
{
  if (this->root == NULL)
    return false;
  Node *temp = this->root;
  while (temp) {
    if (data < temp->data) {
      temp = temp->lchild;
      continue;
    }
    if (data > temp->data) {
      temp = temp->rchild;
      continue;
    }
    return true;
  }
  return false;
}
