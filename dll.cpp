#include<stdio.h>
#include<stdlib.h>

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Insert at beginning
void insbeg(Node*& head, int val) {
    Node* n = new Node(val);
    n->next = head;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Insert at specific position
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
    for (int i = 1; i < pos - 1 && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Position out of bounds\n");
        return;
    }
    Node* n = new Node(val);
    n->next = curr->next;
    n->prev = curr;
    if (curr->next != NULL) {
        curr->next->prev = n;
    }
    curr->next = n;
}

// Insert at end
void insend(Node*& head, int val) {
    if (head == NULL) {
        insbeg(head, val);
        return;
    }
    Node* n = new Node(val);
    Node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = n;
    n->prev = temp;
}

// Delete from beginning
void delbeg(Node*& head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* toDel = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete toDel;
}

// Delete from end
void delend(Node*& head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) { // Single element in the list
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}

// Delete at specific position
void delpos(Node*& head, int pos) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (pos < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 1) {
        delbeg(head);
        return;
    }
    Node* temp = head;
    int count = 1;

    while (temp != NULL && count != pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// Reverse display
void revdis(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

// Search for an element
bool search(Node* head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Menu-driven program
int main() {
    Node* head = NULL;
    int choice, value, pos, key;

    while (1) {
        printf("\nMenu\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete at position\n");
        printf("7. Display list\n");
        printf("8. Reverse display\n");
        printf("9. Search\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insbeg(head, value);
            display(head);
            break;
        case 2:
            printf("Enter value to insert: ");
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
            revdis(head);
            break;
        case 9:
            printf("Enter value to search: ");
            scanf("%d", &key);
            if (search(head, key)) {
                printf("Element found\n");
            } else {
                printf("Element not found\n");
            }
            break;
        case 10:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Retry.\n");
        }
    }
    return 0;
}