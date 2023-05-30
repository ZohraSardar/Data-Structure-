#include <iostream>

#define MAX_SIZE 100

struct Queue {
    int data[MAX_SIZE];
    int front, rear;
};

void init(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isFull(Queue* q) {
    return (q->rear == MAX_SIZE - 1);
}

bool isEmpty(Queue* q) {
    return (q->front == -1 || q->front > q->rear);
}

void enqueue(Queue* q, int val) {
    if (isFull(q)) {
        std::cout << "Queue overflow" << std::endl;
        return;
    }

    if (isEmpty(q)) {
        q->front = 0;
    }

    q->rear++;
    q->data[q->rear] = val;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue underflow" << std::endl;
        return;
    }

    q->front++;
}

void reverseIntegersAtEvenPositions(Queue* q) {
    if (isEmpty(q) || (q->rear - q->front) < 2) {
        return;  // No need to reverse if queue is empty or has less than 2 elements
    }

    int evenSize = ((q->rear - q->front + 1) / 2) * 2;  // Number of even positions
    int oddSize = q->rear - q->front + 1 - evenSize;   // Number of odd positions

    int* temp = new int[evenSize];
    int tempIndex = 0;

    // Extract even positioned elements and store them in a temporary array
    for (int i = q->front + 1; i <= q->rear; i += 2) {
        temp[tempIndex++] = q->data[i];
    }

    // Reverse the order of elements in the temporary array
    for (int i = 0; i < evenSize / 2; i++) {
        int j = evenSize - i - 1;
        int swap = temp[i];
        temp[i] = temp[j];
        temp[j] = swap;
    }

    // Put the reversed even positioned elements back into the queue
    tempIndex = 0;
    for (int i = q->front + 1; i <= q->rear; i += 2) {
        q->data[i] = temp[tempIndex++];
    }

    delete[] temp;
}

void displayQueue(Queue* q) {
    if (isEmpty(q)) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }

    for (int i = q->front + 1; i <= q->rear; i++) {
        std::cout << q->data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Queue myQueue;
    init(&myQueue);

    enqueue(&myQueue, 1);
    enqueue(&myQueue, 2);
    enqueue(&myQueue, 3);
    enqueue(&myQueue, 4);
    enqueue(&myQueue, 5);
    enqueue(&myQueue, 6);
    enqueue(&myQueue, 7);
    enqueue(&myQueue, 8);

    std::cout << "Original Queue: ";
    displayQueue(&myQueue);

    reverseIntegersAtEvenPositions(&myQueue);

    std::cout;
}
