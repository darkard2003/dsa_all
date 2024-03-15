#define NULL 0

class Node {
public:
  int key;
  Node *left;
  Node *right;
  int height;

  Node(int key) {
    this->key = key;
    left = right = NULL;
    height = 1;
  }

  Node() {
    key = 0;
    left = right = NULL;
    height = 1;
  }
};

int _height(Node *root) {
  if (root == NULL)
    return 0;
  return root->height;
}

int _balance(Node *root) {
  if (root == NULL)
    return 0;
  return _height(root->left) - _height(root->right);
}

int max(int a, int b) { return (a > b) ? a : b; }

Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = 1 + max(_height(y->left), _height(y->right));
  x->height = 1 + max(_height(x->left), _height(x->right));
  return x;
}

Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = 1 + max(_height(x->left), _height(x->right));
  y->height = 1 + max(_height(y->left), _height(y->right));
  return y;
}

class AVL {
  Node *root;

public:
  AVL() { root = NULL; }

  void insert(int key);
};

Node *_insert(Node *root, int key) {

  Node *newNode = new Node(key);

  if (root == NULL) {
    root = newNode;
    return root;
  }

  if (key < root->key)
    root->left = _insert(root->left, key);
  else if (key > root->key)
    root->right = _insert(root->right, key);
  else
    return root;

  root->height = 1 + max(_height(root->left), _height(root->right));

  int balance = _balance(root);

  if (balance > 1 && key < root->left->key)
    return rightRotate(root);

  if (balance < -1 && key > root->right->key)
    return leftRotate(root);

  if (balance > 1 && key > root->left->key) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && key < root->right->key) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}
