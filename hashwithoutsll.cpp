#include <iostream>
#include <list>
using namespace std;

class HashTable {
    int capacity;
    list<int>* table;

public:
    HashTable(int V);
    void insertItem(int data);
    void deleteItem(int key);
    void displayHash();
    void searchItem(int key);
    int hashFunction(int key);
};

HashTable::HashTable(int c) {
    this->capacity = c;
    table = new list<int>[capacity];
}

void HashTable::insertItem(int data) {
    int index = hashFunction(data);
    table[index].push_back(data);
}

void HashTable::searchItem(int key) {
    int index = hashFunction(key);
    list<int>::iterator i;
    int y = 0;
    bool flag = false;

    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key) {
            cout << "Record Found at [" << index << "][" << y << "] ---> " << key << endl;
            flag = true;
            break;
        }
        y++;
    }

    if (!flag)
        cout << "Record Not Found" << endl;
}

void HashTable::deleteItem(int key) {
    int index = hashFunction(key);
    list<int>::iterator i;

    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (*i == key)
            break;
    }

    if (i != table[index].end())
        table[index].erase(i);
}

void HashTable::displayHash() {
    for (int i = 0; i < capacity; i++) {
        cout << "table[" << i << "]";
        for (list<int>::iterator it = table[i].begin(); it != table[i].end(); ++it)
            cout << " --> " << *it;
        cout << endl;
    }
}

int HashTable::hashFunction(int key) {
    return (key % capacity);
}

int main() {
    int data[] = {1, 9, 23, 4, 5, 6, 7};
    int size = sizeof(data) / sizeof(data[0]);
    HashTable h(size);

    for (int i = 0; i < size; i++)
        h.insertItem(data[i]);

    h.deleteItem(7);
    h.displayHash();
    h.searchItem(6);

    return 0;
}

