//priority queue using max heaps
#include <stdio.h>
#include <stdlib.h>

class MaxHeap {
private:
    int* heap; // Array to store heap elements
    int capacity; // Maximum capacity of the heap
    int size; // Current size of the heap

    // Helper function to heapify up
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                // Swap with parent if current is greater
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    // Helper function to heapify down
    void heapifyDown(int index) {
        while (true) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                // Swap with the largest child
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    MaxHeap(int cap) {
        capacity = cap;
        size = 0;
        heap = (int*)malloc(capacity * sizeof(int));
    }

    // Insert an element into the heap
    void insert(int val) {
        if (size == capacity) {
            printf("Heap overflow! Cannot insert.\n");
            return;
        }
        heap[size] = val;
        size++;
        heapifyUp(size - 1);
        printf("Inserted %d into the priority queue.\n", val);
    }

    // Extract the maximum element
    void extractMax() {
        if (size == 0) {
            printf("Heap underflow! No elements to extract.\n");
            return;
        }
        printf("Extracted maximum: %d\n", heap[0]);
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    // Peek at the maximum element
    void getMax() {
        if (size == 0) {
            printf("Priority queue is empty!\n");
            return;
        }
        printf("Maximum element: %d\n", heap[0]);
    }

    // Display the elements in the heap (level order)
    void display() {
        if (size == 0) {
            printf("Priority queue is empty!\n");
            return;
        }
        printf("Priority queue elements: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", heap[i]);
        }
        printf("\n");
    }
};

// Menu-driven main function
int main() {
    int capacity, choice, value;
    printf("Enter the maximum capacity of the priority queue: ");
    scanf("%d", &capacity);

    MaxHeap pq(capacity);

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Extract Max\n");
        printf("3. Get Max\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            pq.insert(value);
            break;

        case 2:
            pq.extractMax();
            break;

        case 3:
            pq.getMax();
            break;

        case 4:
            pq.display();
            break;

        case 5:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}