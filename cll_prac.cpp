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

void insbeg(Node*& head, int val) {
    Node* n = new Node(val);
    Node* temp = head;

    if (head == NULL) {
        n->next = n;
        head = n;
        return;
    }

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insend(Node*& head, int val) {
    if (head == NULL) {
        insbeg(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void inspos(Node*& head, int val, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }

    if (pos == 1) {
        insbeg(head, val);
        return;
    }

    Node* curr = head;
    Node* n = new Node(val);
    for (int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }

    n->next = curr->next;
    curr->next = n;
}

void delbeg(Node*& head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    Node* toDel = head;
    temp->next = head->next;
    head = head->next;

    delete toDel;
}

void delend(Node*& head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) { // Single node
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }

    Node* toDel = temp->next;
    temp->next = head;

    delete toDel;
}

void delpos(Node*& head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        delbeg(head);
        return;
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr->next != head; i++) {
        curr = curr->next;
    }

    if (curr->next == head) {
        printf("Position out of bounds\n");
        return;
    }

    Node* toDel = curr->next;
    curr->next = curr->next->next;

    delete toDel;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Menu-driven program
int main() {
    Node* head = NULL;
    int choice, value, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert at beginning: ");
            scanf("%d", &value);
            insbeg(head, value);
            display(head);
            break;

        case 2:
            printf("Enter value to insert at end: ");
            scanf("%d", &value);
            insend(head, value);
            display(head);
            break;

        case 3:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Enter position: ");
            scanf("%d", &pos);
            inspos(head, value, pos);
            display(head);
            break;

        case 4:
            delbeg(head);
            display(head);
            break;

        case 5:
            delend(head);
            display(head);
            break;

        case 6:
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            delpos(head, pos);
            display(head);
            break;

        case 7:
            display(head);
            break;

        case 8:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
