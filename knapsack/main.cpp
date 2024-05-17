#include <iostream>

using namespace std;

class Item {
public:
  int w;
  int v;

  Item() {
    w = 0;
    v = 0;
  }

  Item(int weight, int value) {
    w = weight;
    v = value;
  }

  float valuePerWeight() { return (float)v / w; }
};

Item items[] = {
    Item(10, 20),
    Item(15, 40),
    Item(35, 10),
    Item(54, 15),
};
int n = 4;

void sortItems(Item *items, int n) {
  for (int i = 0; i < n; i++) {
    bool sorted = true;
    for (int j = 0; j < n - i - 1; j++) {
      if (items[j].valuePerWeight() < items[j + 1].valuePerWeight()) {
        Item temp = items[j];
        items[j] = items[j + 1];
        items[j + 1] = temp;
        sorted = false;
      }
    }
    if (sorted)
      break;
  }
}
void knapsack(Item *items, int n, int c) {
  sortItems(items, n);
  float *frac = new float[n];
  float totalCost = 0;
  int i = 0;

  while (c > 0 && i < n) {
    Item it = items[i];
    if (it.w <= c) {
      frac[i] = 1;
      c -= it.w;
      i++;
    } else {
       
    }
  }
}
