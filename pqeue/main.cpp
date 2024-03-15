#include "pqeue.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  PQeue pqeue;

  int data, priority, choice;

  do {
    cout << "1. Enqeue" << endl
         << "2. Deqeue" << endl
         << "3. Peek" << endl
         << "4. Display" << endl
         << "5. Exit" << endl
         << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1:
      cout << "Enter data: ";
      cin >> data;
      cout << "Enter priority: ";
      cin >> priority;
      pqeue.enqeue(data, priority);
      break;
    case 2:
      cout << "Deqeued: " << pqeue.deqeue() << endl;
      break;
    case 3:
      cout << "Peeked: " << pqeue.peek() << endl;
      break;
    case 4:
      pqeue.display();
      break;
    case 5:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice!" << endl;
      break;
    }
  } while (choice != 5);

  return 0;
}
