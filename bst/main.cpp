#include<iostream>
#include<vector>
#include "bst.cpp"

using namespace std;

// Make a menu driven program for BST
int main() {
  BST bst;
  int choice, data;
  while (1) {
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Inorder" << endl;
    cout << "4. Preorder" << endl;
    cout << "5. Postorder" << endl;
    cout << "6. Search" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      bst.insert(data);
      break;
    case 2:
      cout << "Enter data: ";
      cin >> data;
      bst.remove(data);
      break;
    case 3:
      cout << "Inorder: ";
      for (int i : bst.inOrder())
        cout << i << " ";
      cout << endl;
      break;
    case 4:
      cout << "Preorder: ";
      for (int i : bst.preOrder())
        cout << i << " ";
      cout << endl;
      break;
    case 5:
      cout << "Postorder: ";
      for (int i : bst.postOrder())
        cout << i << " ";
      cout << endl;
      break;
    case 6:
      cout << "Enter data: ";
      cin >> data;
      cout << "Search: " << bst.search(data) << endl;
      break;
    case 7:
      exit(0);
    default:
      cout << "Invalid choice" << endl;
    }
  }
  return 0;
}