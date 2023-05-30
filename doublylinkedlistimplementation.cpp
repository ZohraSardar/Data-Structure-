#include<iostream>
using namespace std;

class Node {
public:
    int info;
    Node* next;
    Node* prev;

    Node(int val) {
        info = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    int length;

    DoublyLinkedList() {
        head = NULL;
        length = 0;
    }

    void insert(int val, int pos) {
        if (pos > (length + 1) || pos < 1) {
            cout << "Invalid position";
            return;
        }

        Node* newNode = new Node(val);

        if (pos == 1) {
            newNode->next = head;
            if (head != NULL)
                head->prev = newNode;
            head = newNode;
        } else {
            Node* curr = head;
            for (int i = 1; i < (pos - 1); i++) {
                curr = curr->next;
            }

            newNode->next = curr->next;
            newNode->prev = curr;
            if (curr->next != NULL)
                curr->next->prev = newNode;
            curr->next = newNode;
        }

        length++;
    }

    void convertToCircular() {
        if (head == NULL)
            return;

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = head;
        head->prev = curr;
    }

  int countNodesRecursive(Node* node) {
        if (node == NULL) 
            return 0;
        

       return 1 + countNodesRecursive(node->next);
    }

    void printCircular() {
        if (head == NULL) {
            cout << "List is empty.";
            return;
        }

        Node* curr = head;
        do {
            cout << curr->info << "--->";
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (head == NULL) {
            cout << "List is empty.";
            return;
        }

        Node* curr = head;
        while (curr != NULL) {
            cout << curr->info << "---->";
            curr = curr->next;
        }
    }
};

int main() {
    DoublyLinkedList d1;

    d1.insert(2, 1);
    d1.insert(3, 2);
    d1.insert(4, 3);
    d1.insert(5, 4);
    d1.insert(6, 5);
    d1.insert(7, 6);

    cout << "List is: ";
    d1.printList();
    cout << endl;
//
//    d1.convertToCircular();
//
//    cout << "List after converting to circular: ";
//    d1.printCircular();
//    cout << endl;

    
    cout << "Number of nodes: " << d1.countNodesRecursive(d1.head);
    return 0;
}
