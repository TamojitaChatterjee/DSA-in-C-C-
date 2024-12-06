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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push operation
    void push(int val) {
        Node* n = new Node(val);
        n->next = top;
        top = n;
        printf("Pushed %d onto the stack.\n", val);
        display(); // Display stack after each push
    }

    // Pop operation
    void pop() {
        if (top == NULL) {
            printf("Stack underflow! Cannot pop from an empty stack.\n");
            return;
        }

        Node* toDel = top;
        printf("Popped %d from the stack.\n", top->data);
        top = top->next;
        delete toDel;  // Free memory
        display(); // Display stack after each pop
    }

    // Peek operation
    void peek() {
        if (top == NULL) {
            printf("Stack is empty! Nothing to peek.\n");
            return;
        }

        printf("Top element is: %d\n", top->data);
    }

    // Display stack
    void display() {
        if (top == NULL) {
            printf("Stack is empty.\n");
            return;
        }

        printf("Stack elements are: ");
        Node* temp = top;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    // Free memory of the entire stack
    void remove() {
        while (top != NULL) {
            Node* toDel = top;
            top = top->next;
            delete toDel;  // Free memory
        }
        printf("All stack memory has been freed.\n");
    }
};

// Menu-driven main function
int main() {
    Stack s;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            printf("Exiting...\n");
            s.remove();  // Free all allocated memory before exiting
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
