#include <iostream>
#include <vector>

class Heap
{
  std::vector<int> v;
  int size = 0;

public:
  bool isEmpty();
  bool insert(int data);
  int remove();
  void print();
};

bool Heap::isEmpty() { return size == 0; }

bool Heap::insert(int data)
{
  v.push_back(data);
  int i = size;
  int p = (i - 1) / 2;

  while (p >= 0 && v[i] < v[p])
  {
    std::swap(v[i], v[p]);
    i = p;
    p = (i - 1) / 2;
  }

  size++;
  return true;
}

int Heap::remove()
{
  std::swap(v[size - 1], v[0]);
  int i = 0;

  while (true)
  {
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (c1 >= size)
      break;

    int smaller = c2 >= size || v[c1] < v[c2] ? c1 : c2;

    if (v[i] > v[smaller])
      break;

    std::swap(v[i], v[smaller]);
    i = smaller;
  }

  return v[--size];
}

void Heap::print()
{
  for (auto i : v)
  {
    std::cout << i << ' ';
  }

  std::cout << std::endl;
}