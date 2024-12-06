#include <stdio.h>
#include <stdlib.h>

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Enqueue operation
    void enqueue(int val) {
        Node* n = new Node(val);
        if (rear == NULL) {  // Empty queue
            front = rear = n;
            printf("Enqueued %d into the queue.\n", val);
            display();
            return;
        }
        rear->next = n;
        rear = n;
        printf("Enqueued %d into the queue.\n", val);
        display();
    }

    // Dequeue operation
    void dequeue() {
        if (front == NULL) {
            printf("Queue underflow! Cannot dequeue from an empty queue.\n");
            return;
        }
        Node* toDel = front;
        printf("Dequeued %d from the queue.\n", front->data);
        front = front->next;

        if (front == NULL) {  // Queue becomes empty
            rear = NULL;
        }

        delete toDel;  // Free memory
        display();
    }

    // Peek operation
    void peek() {
        if (front == NULL) {
            printf("Queue is empty! Nothing to peek.\n");
            return;
        }
        printf("Front element is: %d\n", front->data);
    }

    // Display the queue
    void display() {
        if (front == NULL) {
            printf("Queue is empty.\n");
            return;
        }

        printf("Queue elements are: ");
        Node* temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Free memory of the entire queue
    void clear() {
        while (front != NULL) {
            Node* toDel = front;
            front = front->next;
            delete toDel;  // Free memory
        }
        rear = NULL;
        printf("All queue memory has been freed.\n");
    }
};

// Menu-driven main function
int main() {
    Queue q;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            printf("Exiting...\n");
            q.clear();  // Free all allocated memory before exiting
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}