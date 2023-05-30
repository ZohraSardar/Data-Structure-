#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head =NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void remove(int data) {
        if (head == NULL) {
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        while (curr->next != NULL) {
            if (curr->next->data == data) {
                Node* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }

    bool search(int data) {
        Node* curr = head;
        while (curr != NULL) {
            if (curr->data == data) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    void display() {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

class HashTable {
private:
    int capacity;
    LinkedList* table;

public:
    HashTable(int V) {
        this->capacity = V;
        table = new LinkedList[capacity];
    }

    int hashFunction(int key) {
        return (key % capacity);
    }

    void insertItem(int data) {
        int index = hashFunction(data);
        table[index].insert(data);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHash() {
        for (int i = 0; i < capacity; i++) {
            cout << "table[" << i << "] ";
            table[i].display();
        }
    }

    void searchItem(int key) {
        int index = hashFunction(key);
        if (table[index].search(key)) {
            cout << "Record Found at [" << index << "] for key " << key << endl;
        } else {
            cout << "Record Not Found for key " << key << endl;
        }
    }
};

int main() {
    int data[] = {1, 9, 23, 4, 5, 6, 7};
    int size = sizeof(data) / sizeof(data[0]);
    HashTable h(size);

    for (int i = 0; i < size; i++) {
        h.insertItem(data[i]);
    }

    h.deleteItem(7);
    h.displayHash();
    h.searchItem(23);

    return 0;
}
