#include <iostream>
#include "heap.cpp"

using namespace std;

int main()
{
    Heap heap;
    int choice, data;

    do
    {
        cout << "1. Insert element\n";
        cout << "2. Remove element\n";
        cout << "3. Print heap\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter element to insert: ";
                cin >> data;
                heap.insert(data);
                break;

            case 2:
                if (heap.isEmpty())
                {
                    cout << "Heap is empty\n";
                }
                else
                {
                    cout << "Removed element: " << heap.remove() << endl;
                }
                break;

            case 3:
                cout << "Heap: ";
                heap.print();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice\n";
                break;
        }

        cout << endl;

    } while (choice != 4);

    return 0;
}