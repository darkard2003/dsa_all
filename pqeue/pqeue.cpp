#include <iostream>

using namespace std;

class Node {
public:
  int data;
  int priority;
  Node *next;

  Node() { next = NULL; }

  Node(int data, int priority) {
    this->data = data;
    this->priority = priority;
    next = NULL;
  }
};

class PQeue {
private:
  Node *front;
  Node *rear;

public:
  PQeue() { front = rear = NULL; }
  ~PQeue() {
    Node *temp = front;
    while (temp != NULL) {
      front = front->next;
      delete temp;
      temp = front;
    }
  };
  void enqeue(int, int);
  int deqeue();
  int peek();
  void display();
  bool isEmpty();
};

bool PQeue::isEmpty() { return front == NULL; }

void PQeue::enqeue(int data, int priority) {
  Node *temp = new Node(data, priority);

  if (isEmpty()) {
    front = rear = temp;
    return;
  }

  if (front->priority < priority) {
    temp->next = front;
    front = temp;
    return;
  }

  if (rear->priority >= priority) {
    rear->next = temp;
    rear = temp;
    return;
  }

  Node *p = front;

  while (p->next->priority >= priority) {
    p = p->next;
  }

  temp->next = p->next;
  p->next = temp;
}

int PQeue::deqeue() {

  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }

  Node *temp = front;

  int data = temp->data;
  front = front->next;

  delete temp;
  return data;
}

int PQeue::peek() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  return front->data;
}

void PQeue::display() {
  if (isEmpty()) {
    cout << "Queue is empty" << endl;
    return;
  }
  Node *temp = front;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}
