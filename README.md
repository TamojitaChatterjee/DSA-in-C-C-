# DSA-in-C-Cpp-
This repository provides us with codes for basic Data Structures implemented in C++ but using header files #include&lt;stdio.h> and #include&lt;stdlib.h>

The logics for individual data structures have been added as well for clearer understanding

### 1. **Singly linked list**
A `singly linked list` is a list of elements where each element is connected to the next element. Each element is divided into two parts- `Node` and `next`. The information held by a `Node` is called `data`. It may be of integer or character type. `Next` is the part of the node which contains the pointer which points to the next element of the list. `Head` is the first element of the list, while `tail` is the last. The `next` of `tail` points towards the `null pointer`.

A singly linked list is preferred over an array as it has a flexible size and allows efficient insertions and deletions.

a. **Insertion at beginning**
- A new node is created. It is initiated by assigning the data the value (here, of type `int`) and `next` is pointed towards `NULL`

```cpp
class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};
```
- The next of new node is made the head.

```cpp
void insbeg(Node*&head, int value){
    Node* n = new Node(value);
    n->next=head;
    head=n;
}
```

**Note:** Here we use `Node*&head` here as head is not a fixed location, it may vary.

**Time complexity: O(1)*

b. **Insertion at end**
- The first step is to create a new node with the given value. This new node is initialized with the next pointer pointing to NULL, indicating that it is the last   node in the list.
```cpp
void insend(Node*& head, int value) {
    Node* n = new Node(value);
```

- If `head==NULL`, it indicates an empty list and the head pointer is updated to point at the new node
```cpp
if (head == NULL) {
        head = n;
        return;
    }
```
- A new node `temp` is created which helps us traverse through the list
```cpp
Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
```
- Once we reach the last node, the `next` pointer is set to the `new node` and then the list is updated
```cpp
temp->next = n;
```
**Time complexity: O(n)*

c. **Insertion at a certain position**
- Creating a new node:
```cpp
void inspos(Node*& head, int value, int pos) {
  Node* n = new Node(value);
```
- Checking for insertion at the beginning:
```cpp
if (pos == 1) {
    n->next = head;
    head = n;        
    return;
}
```
- Traversing to the correct position:
```cpp
Node* temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
}
```
- Handling out-of-bounds position:
```cpp
if (temp == NULL) {
    printf("Position out of bounds!\n");
    delete n;
    return;
}
```
- Inserting the new node:
```cpp
n->next = temp->next;
temp->next = n;
```

**Time complexity: O(n)*

d. **Deletion at beginning**
- Check for an empty list
```cpp
if (head == NULL) {
    printf("List is empty! Cannot delete.\n");
    return;
}
```
- Update the head
```cpp
Node* toDel = head;
head = head->next;
```
- Delete the old head
```cpp
delete toDel;
```
**Time complexity: O(1)*

e. **Deletion at end**
- Handling list with a single node
If the list contains only one node, the `head` is set to `NULL` after deleting the node.
```cpp
if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
}
```
- Traversing to the second-last node
```cpp
Node* temp = head;
while (temp->next->next != NULL) {
    temp = temp->next;
}
```
- Updating and deleting the last node
```cpp
Node* toDel = temp->next;
temp->next = NULL;
delete toDel;
```
**Time complexity: O(n)*

f. **Deletion at a certain position**
- Check for empty list condition (**do this to prevent segmentation faults**)
```cpp
if (head == NULL) {
        printf("List is empty! Cannot delete.\n");
        return;
    }
```
- Handle deletion at beginning
```cpp
if (pos == 1) {
    delbeg(head);
    return;
}
```
- Traverse to node before the desired position
```cpp
Node* temp = head;
for (int i = 1; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
}
```
- Check out of bound positions
```cpp
if (temp == NULL || temp->next == NULL) {
    printf("Position out of bounds! Cannot delete.\n");
    return;
}
```
- Update pointers and delete target node
```cpp
Node* toDel = temp->next;
temp->next = temp->next->next;
delete toDel;
```
**Time complexity: O(n)*

g. **Search**
- Iterate through the list
- Check each node's `data`
- If value is found, return `position`
  else, continue traversal till `temp!=NULL`
```cpp
while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Value %d not found in the list.\n", value);
```
**Time complexity: O(n)*

h. **Display**
- Check for an empty list
```cpp
if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
```
- Iterate through the list
- Print each node
```
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}
```
**Time complexity: O(n)*

i. **Reverse display**
- Recursively traverse through the list
- Have a base case
```cpp
if (head == NULL) {
    return;
}
```
- Call the recursive function
```cpp
reverseDisplay(head->next);
printf("%d ", head->data);
```
**Time complexity: O(n)*

2. **Doubly linked list**
A `doubly linked list` is a list of elements where each element is connected to both the previous and the next elements. Each element is divided into three parts: `prev`, `Node`, and `next`.

- The information held by a `Node` is called `data`. It may be of integer, character, or any other type.  
- `Prev` is a pointer that points to the previous node in the list.  
- `Next` is a pointer that points to the next node in the list.  

The first element of the list is called the `head`, and its `prev` pointer is set to `NULL`. Similarly, the last element is called the `tail`, and its `next` pointer is set to `NULL`.

A `doubly linked list` is preferred over a singly linked list as it allows bidirectional traversal, making it more efficient for operations like reverse traversal. However, it requires more memory as each node stores two pointers (`prev` and `next`).

**Node structure**
```cpp
class Node {
public:
    int data;   // Stores the data
    Node* next; // Points to the next node
    Node* prev; // Points to the previous node

    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};
```

a. **Insertion at Beginning**
- A new node is created with the given value. The `next` pointer of the new node is set to point to the current head, making it the new first node in the list.  
```cpp
Node* n = new Node(val);
n->next = head;
```
- If the list is not empty (`head != NULL`), the `prev` pointer of the current head is updated to point to the new node.
```cpp
if (head != NULL) {
    head->prev = n;
}
```
- Finally, the head pointer is updated to point to the new node.
```cpp
head = n;
```
**Time complexity: O(1)*

b. **Insertion at end**
- A new node is created with the given value. If the list is empty (`head == NULL`), the new node becomes the head of the list.
```cpp
if (head == NULL) {
    insbeg(head, val);
    return;
}
```
- Otherwise, a temporary pointer is used to traverse to the last node of the list.
```cpp
Node* temp = head;
while (temp->next != NULL) {
    temp = temp->next;
}
```
- The `next` pointer of the last node is updated to point to the new node, and the `prev` pointer of the new node is set to the last node.
```cpp
temp->next = n;
n->prev = temp;
```
**Time complexity: O(n)*

c. **Insertion at a position**
- If the position is 1, the function delegates to `insbeg` as it's equivalent to inserting at the beginning.
```cpp
if (pos == 1) {
    insbeg(head, val);
    return;
}
```
- A temporary pointer is used to traverse the list to the node at position `pos - 1`. If the position is out of bounds, an error message is displayed.
```cpp
for (int i = 1; i < pos - 1 && curr != NULL; i++) {
    curr = curr->next;
}
if (curr == NULL) {
    printf("Position out of bounds\n");
    return;
}
```
- A new node is created and inserted between the current node and its next node. The `prev` and `next` pointers are adjusted accordingly.
```cpp
Node* n = new Node(val);
n->next = curr->next;
n->prev = curr;
if (curr->next != NULL) {
    curr->next->prev = n;
}
curr->next = n;
```
**Time complexity: O(n)*

d. **Deletion at beginning**
- If the list is empty (`head == NULL`), an error message is displayed.
```cpp
if (head == NULL) {
    printf("List is empty\n");
    return;
}
```
- The head pointer is updated to the next node. If the new head is not NULL, its `prev` pointer is set to NULL.
```cpp
Node* toDel = head;
head = head->next;
if (head != NULL) {
    head->prev = NULL;
}
```
- The deleted node is deallocated.
```cpp
delete toDel;
```

e. **Deletion at end**
- If the list is empty, an error message is displayed. If there is only one node, it is deleted, and the head is set to NULL.
```cpp
if (head->next == NULL) {
    delete head;
    head = NULL;
    return;
}
```
- A temporary pointer is used to traverse to the last node. The `next` pointer of the second last node is set to NULL.
```cpp
Node* temp = head;
while (temp->next != NULL) {
    temp = temp->next;
}
temp->prev->next = NULL;
```
- The last node is deallocated.
```cpp
delete temp;
```
**Time complexity: O(n)*

f. **Deletion at a specific position**
- If the position is 1, the function delegates to `delbeg`.
```cpp
if (pos == 1) {
    delbeg(head);
    return;
}
```
- A temporary pointer is used to traverse to the node at the given position. If the position is out of bounds, an error message is displayed.
```cpp
while (temp != NULL && count != pos) {
    temp = temp->next;
    count++;
}
if (temp == NULL) {
    printf("Position out of bounds\n");
    return;
}
```
- The node is removed by updating the `next` pointer of the previous node and the `prev` pointer of the next node.
```
temp->prev->next = temp->next;
if (temp->next != NULL) {
    temp->next->prev = temp->prev;
}
```
- The deleted node is deallocated.
```cpp
delete temp;
```
**Time complexity: O(n)*

g. **Display**
- A temporary pointer is used to traverse the list and print the `data` of each node
```cpp
Node* temp = head;
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
}
printf("\n");
```
**Time complexity: O(n)*

h. **Reverse display**
- A temporary pointer is used to traverse to the last node. Starting from the last node, the list is printed in reverse order by following the `prev` pointers.
```cpp
Node* temp = head;
while (temp->next != NULL) {
    temp = temp->next;
}
while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
}
printf("\n");
```
**Time complexity: O(n)*

i. **Search**
- A temporary pointer is used to traverse the list. If the `data` of any node matches the key, the function returns `true`. If the end of the list is reached without finding the key, the function returns `false`.
```cpp
Node* temp = head;
while (temp != NULL) {
    if (temp->data == key) {
        return true;
    }
    temp = temp->next;
}
return false;
```
**Time complexity: O(n)*

3. **Circular linked list**
4. **Stacks using SLL**
5. **Queues using SLL**
6. **Binary trees**
7. **Character binary tree**
8. **Binary search tree**
9. **Priority queues using max heap**
10. **Hashing using linear probing**
11. **Hashing using quadratic probing**
12. **Hashing using separate chaining**
13. **Graphs using adjacency matrix**
14. **Graphs using adjacency lists**
