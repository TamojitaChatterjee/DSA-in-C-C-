//separate chaining
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10 // Define the size of the hash table

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Hash table with separate chaining
class HashTable {
private:
    Node* table[TABLE_SIZE]; // Array of pointers to linked lists

    // Hash function
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL; // Initialize all table slots to NULL
        }
    }

    // Insert operation
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);

        // Insert at the beginning of the linked list
        newNode->next = table[index];
        table[index] = newNode;

        printf("Inserted %d into hash table.\n", key);
    }

    // Search operation
    bool search(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];

        while (temp != NULL) {
            if (temp->data == key) {
                return true; // Key found
            }
            temp = temp->next;
        }
        return false; // Key not found
    }

    // Delete operation
    void remove(int key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Key %d not found in the hash table.\n", key);
            return;
        }

        // Remove the node
        if (prev == NULL) { // If the key is at the head
            table[index] = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        printf("Removed %d from the hash table.\n", key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            printf("Slot %d: ", i);
            Node* temp = table[i];
            while (temp != NULL) {
                printf("%d -> ", temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }

    // Free all memory
    void freeTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            Node* temp = table[i];
            while (temp != NULL) {
                Node* toDel = temp;
                temp = temp->next;
                delete toDel;
            }
            table[i] = NULL;
        }
        printf("Freed all hash table memory.\n");
    }
};

// Menu-driven main function
int main() {
    HashTable ht;
    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Remove\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            ht.insert(value);
            break;

        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (ht.search(value)) {
                printf("%d found in the hash table.\n", value);
            } else {
                printf("%d not found in the hash table.\n", value);
            }
            break;

        case 3:
            printf("Enter value to remove: ");
            scanf("%d", &value);
            ht.remove(value);
            break;

        case 4:
            ht.display();
            break;

        case 5:
            ht.freeTable(); // Free all memory before exiting
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}