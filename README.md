### DSA-in-C-Cpp-
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

*Time complexity: O(1)*

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
*Time complexity: O(n)*

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

*Time complexity: O(n)*

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
*Time complexity: O(1)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

### 2. **Doubly linked list**
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
*Time complexity: O(1)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

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
*Time complexity: O(n)*

### 3. **Circular linked list**
A **circular linked list** is a variation of a linked list where the last element of the list is connected to the first element, forming a circular structure. Each element is divided into two parts: `Node` and `next`.

- The information held by a `Node` is called `data`. It may be of integer, character, or any other type.  
- The `next` pointer of a node points to the next element in the list. In the case of the last node, it points back to the first node instead of `NULL`.  

The **head** represents the starting node of the list, while the **tail** is the last node, which links back to the head.

A circular linked list is preferred over a singly linked list in scenarios where circular traversal is required. For example:
- Implementing buffers or queues in systems with continuous data flow.
- Simplifying traversal in certain algorithms since we can move seamlessly from the last node back to the first.

However, care must be taken to avoid infinite loops during traversal due to the circular nature of the list.

**Node structure**
```cpp
class Node {
public:
    int data;   // Stores the data
    Node* next; // Points to the next node in the circular list
    
    Node(int value) {
        data = value;
        next = this; // Points to itself by default, creating a circular reference
    }
};
```
a. **Insertion at beginning**
- Create new node with given value
```cpp
Node* n = new Node(val);
```
- check for empty list; if so, make the new node point at itself
```cpp
if (head == NULL) {
    n->next = n;
    head = n;
}
```
- traverse through the list to find the last node
```cpp
Node* temp = head;
while (temp->next != head) {
    temp = temp->next;
}
```
- make the last node point to the new node
```cpp
temp->next = n;
```
- make new node point to head
```cpp
n->next = head;
```
- update head to new node (this completes the list)
```cpp
head = n;
```
*Time complexity: O(n)*

b. **Insertion at end**
- Create new node with given value
```cpp
Node* n = new Node(val);
```
- Check for empty list
```cpp
if (head == NULL) {
    insbeg(head, val);
    return;
}
```
- Traverse to find last node
```cpp
Node* temp = head;
while (temp->next != head) {
    temp = temp->next;
}
```
- Make last node point to new node
```cpp
temp->next = n;
```
- Make new node point to head
```cpp
n->next = head;
```
*Time complexity: O(n)*

c. **Insertion at a certain position**
- Check for validity of the position
```cpp
if (pos < 1) {
    printf("Invalid position!\n");
    return;
}
```
- If `pos==1`, call `insbeg`
```cpp
if (pos == 1) {
    insbeg(head, val);
    return;
}
```
- Create a new node `n` and initialize `curr` to `head`
```cpp
Node* curr = head;
Node* n = new Node(val);
```
- Iterate to the desired position
```cpp
for (int i = 1; i < pos - 1 && curr->next != head; i++) {
    curr = curr->next;
}
```
- Insert at the desired position
```cpp
n->next = curr->next;
curr->next = n;
```
*Time complexity: O(n)*

d. **Deletion at beginning**
- Check for empty list
```cpp
if (head == NULL) {
    printf("List is empty\n");
    return;
}
```
- Traverse to last node
```cpp
Node* temp = head;
while (temp->next != head) {
    temp = temp->next;
}
```
- Store head to a temporary variable `toDel`
```cpp
Node* toDel = head;
```
- Point last node to second node
```cpp
temp->next = head->next;
```
- Update `head` pointer to second node
```cpp
head = head->next;
```
- Delete original head node
```cpp
delete toDel;
```
e. **Deletion at end**
- Check for empty list
```cpp
if (head == NULL) {
    printf("List is empty\n");
    return;
}
```
- Check for single-element list
```cpp
if (head->next == head) { // Single node
    delete head;
    head = NULL;
    return;
}
```
- Traverse to second-last node
```cpp
Node* temp = head;
while (temp->next->next != head) {
    temp = temp->next;
}
```
- Store last node to a temporary variable
```cpp
Node* toDel = temp->next;
```
- Make the node before the last node point to the head
```cpp
temp->next = head;
```
- Delete the last node
```cpp
delete toDel;
```
f. **Deletion at a certain position**
- Check for empty list
```cpp
if (head == NULL) {
    printf("List is empty\n");
    return;
}
```
- Check for single-element list
```cpp
if (pos == 1) {
    delbeg(head);
    return;
}
```
- Initialize `curr` to head
```cpp
Node* curr = head;
```
- Traverse to the node before the node to be deleted
```cpp
for (int i = 1; i < pos - 1 && curr->next != head; i++) {
    curr = curr->next;
}
```
- Check if the desired position is out of bounds
```cpp
if (curr->next == head) {
    printf("Position out of bounds\n");
    return;
}
```
- Node to be deleted is stored in a temporary variable
```cpp
Node* toDel = curr->next;
```
- Makes the node before the deleted node point to the node after the deleted node
```cpp
curr->next = curr->next->next;
```
- Deletes the node that was removed from the list
```cpp
delete toDel;
```
*Time complexity: O(n)*

g. **Display**
- Check for empty list
```cpp
if (head == NULL) {
    printf("List is empty\n");
    return;
}
```
- Initialize `temp` pointer to the `head` of the list
```cpp
Node* temp = head;
```
- Use a `do-while` loop to iterate through the list (**We use a `do-while` loop here as it makes sure that the function is executed atleast once, even if the list is empty**)
```cpp
do {
    printf("%d ", temp->data);
    temp = temp->next;
} while (temp != head);
printf("\n");
```
*Time complexity: O(n)*

### 4. **Stacks using SLL**
A stack is a linear data structure that follows the **Last In, First Out (LIFO)** principle. Operations such as `push`, `pop`, `peek`, and `display` can be efficiently implemented using a singly linked list.

a. **Push**
- The `push` operation inserts an element at the top of the stack. This is equivalent to **inserting at the beginning of a singly linked list**, as it's efficient and maintains the LIFO order.
- A new node is created, and its `next` pointer is set to the current top of the stack (i.e., `head`). The head is updated to the new node.
```cpp
void push(Node*& head, int value) {
    Node* n = new Node(value); // Create a new node with the given value
    n->next = head;            // Link the new node to the current top
    head = n;                  // Update head to point to the new node
}
```
*Time complexity: O(1)*

b. **Pop**
- The `pop` operation removes the top element of the stack. This is equivalent to **deleting from the beginning of a singly linked list**.
- Check for empty stack
```cpp
if (head == NULL) { // Check if the stack is empty
        printf("Stack underflow\n");
        return;
    }
```
- The head (top element) is deleted, and the `head` pointer is updated to the next node
```cpp
Node* toDel = head; // Temporary pointer to the node to delete
    head = head->next;  // Move the head to the next node
    delete toDel;
```
*Time complexity: O(1)*

c. **Peek**
- The `peek` operation retrieves the value of the top element without modifying the stack.
- Check for empty stack
```cpp
if (head == NULL) { // Check if the stack is empty
        printf("Stack is empty\n");
        return -1;      // Return an invalid value for an empty stack
    }
```
- Simply return the `data` of the head node.
```cpp
return head->data;
```
*Time complexity: O(1)*

d. **Display**
- Check for empty stack
```cpp
if (head == NULL) { // Check if the stack is empty
        printf("Stack is empty\n");
        return;
    }
```

- Traverse through stack elements and print them
```cpp
Node* temp = head;
    while (temp != NULL) { // Traverse the list
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
```
*Time complexity: O(n)*

### 5. **Queues using SLL**
A queue is a linear data structure that follows the **First In, First Out (FIFO)** principle. Operations such as `enqueue`, `dequeue`, `peek`, and `display` can be efficiently implemented using a singly linked list.

a. **Enqueue**
- The `enqueue` operation adds an element to the rear of the queue. This is equivalent to **inserting at the end of a singly linked list**.
- A new node is created, and its `next` pointer is set to `NULL`. The current rear node's `next` pointer is updated to point to this new node, and the rear pointer is updated.
```cpp
Node* n = new Node(value); // Create a new node with the given value

    if (tail == NULL) {        // If the queue is empty
        head = tail = n;       // Both head and tail point to the new node
        return;
    }

    tail->next = n;            // Link the new node to the current tail
    tail = n;               // Update the tail to the new node
```
*Time complexity: O(1)*

b. **Dequeue**
- The `dequeue` operation removes an element from the front of the queue. This is equivalent to deleting from the beginning of a singly linked list.
- Check for empty queue condition
```cpp
if (head == NULL) {        // Check if the queue is empty
        printf("Queue underflow\n");
        return;
    }
```
- The head node is removed, and the head pointer is updated to the next node. If the queue becomes empty, the tail is also set to NULL.
```cpp
 Node* toDel = head;        // Temporary pointer to the node to delete
    head = head->next;         // Update head to the next node

    if (head == NULL) {        // If the queue is now empty
        tail = NULL;           // Update tail to NULL
    }

    delete toDel;          //delete the node
```
*Time complexity: O(1)*

c. **Peek**
- The `peek` operation retrieves the value of the front element without modifying the queue.
- Check for empty queue condition
```cpp
if (head == NULL) {        // Check if the queue is empty
        printf("Queue is empty\n");
        return -1;             // Return an invalid value for an empty queue
    }
```
- Simply return the data of the head node.
```cpp
return head->data;
```
*Time complexity: O(1)*

d. **Display**
- The `display` operation prints all the elements of the queue from front to rear.
- Check for empty queue condition
```cpp
if (head == NULL) {        // Check if the queue is empty
        printf("Queue is empty\n");
        return;
    }
```
- Traverse through the queue and print all elements
```cpp
Node* temp = head;
    while (temp != NULL) {     // Traverse the list
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
```
*Time complexity: O(n)*

### 6. **Binary trees**
A binary tree is a hierarchical data structure where each node has at most two children, referred to as the left and right child. This implementation uses a dynamic structure where nodes are created as needed and linked together.

a. **Insert**
- Check for empty tree
```cpp
if (root == NULL) {
        return createnewnode(data);  // If the current position is NULL, create a new node
    }
```
- The `insert` function adds a node to the tree. In a **Binary Search Tree (BST)**:
  - Values smaller than the current node go to the left subtree.
    ```cpp
    if (data < root->data) {
        root->left = insert(root->left, data);  // Recursively insert in the left subtree
    }
    ```
  - Values greater than or equal to the current node go to the right subtree.
    ```cpp
    else {
        root->right = insert(root->right, data);  // Recursively insert in the right subtree
    }
    ```
*Time complexity: O(log n)*

b. **Preorder traversal**
Preorder traversal visits nodes in the order:
- Root
- Left Subtree
- Right Subtree
```cpp
if (root != NULL) {
        printf("%d ", root->data);   // Visit root
        preorder(root->left);       // Visit left subtree
        preorder(root->right);      // Visit right subtree
    }
```
*Time complexity: O(n)*

c. **Inorder traversal**
Inorder traversal visits nodes in the order:
- Left Subtree
- Root
- Right Subtree
```cpp
if (root != NULL) {
        inorder(root->left);        // Visit left subtree
        printf("%d ", root->data); // Visit root
        inorder(root->right);       // Visit right subtree
    }
```
*Time complexity: O(n)*

d. **Postorder traversal**
Postorder traversal visits nodes in the order:
- Left Subtree
- Right Subtree
- Root
```cpp
if (root != NULL){
    preorder(root->left);    //visit left subtree
    preorder(root->right);     //visit right subtree
    printf("%d", root->data);    //visit root
}
```
*Time complexity: O(n)*

e. **Search**
- The search operation locates a value in the binary tree. In a Binary Search Tree:
    - If value is not found
      ```cpp
      if (root == NULL) {       // Base case: value not found
        return false;
        }
      ```
    - If the value is equal to the current node, return true.
      ```cpp
      if (root->data == key) {  // Value found
        return true;
        }
      ```
    - If smaller, search in the left subtree.
      ```cpp
      else if (key < root->data) {
        return search(root->left, key);  // Search left subtree
        }
      ```
    - If larger, search in the right subtree.
      ```cpp
      else {
        return search(root->right, key); // Search right subtree
        }
      ```
*Time complexity: O(n)*

### 7. **Character binary tree**
The logic remains the same for `character binary trees`. We compare the values with the help of ASCII values. The **time complexity** of all operations remain the same

### 8. **Binary search tree**
A Binary Search Tree (BST) is a binary tree with the following properties:

- The left child of a node contains characters smaller than the node.
- The right child of a node contains characters greater than or equal to the node.

The logic remains the same as binary trees for all operations, but insertion
Insertion follows the above mentioned logic
The **time complexities** are O(n) for all operations *(worst case)*

### 9. **Priority queues using max heap**
A `max heap` is a specialized binary tree-based data structure where the value of each node is greater than or equal to the values of its children. This property ensures that the *maximum element is always at the root of the heap*.   
**Key Properties of a Max Heap**:
- *Complete Binary Tree*: Every level of the tree is completely filled, except possibly the last level, which is filled from left to right.
- *Heap Property*: The value of each node is greater than or equal to the values of its children.
Max heaps are often implemented using an array. The root node is at index 0, and the children of a node at index `i` are at indices `2i+1` (left child) and `2i+2` (right child).

A `priority queue` is a data structure that operates like a queue, but elements are served based on their priority rather than their arrival order. It's a versatile tool used in various algorithms and applications.
**Key Characteristics**:
- *Priority*: Each element in the queue has an associated priority value.
- *Order of Service*: Elements with higher priority are served before elements with lower priority.
- *Dynamic Operations*: Elements can be inserted and removed at any time.

Priority queues can be implemented using various data structures, with heaps being the most common choice due to their efficient performance:
- *Max Heap*: Used when you want to extract the maximum element.
- *Min Heap*: Used when you want to extract the minimum element.

a. **Insert**
- Check for `heap overflow`
```cpp
if (size == capacity) {
        printf("Heap overflow! Cannot insert.\n");
        return;
    }
```
- Insert the new value at the end of the heap array.
```cpp
heap[size] = val;  // Place the value at the end
    size++;
```
- Restore the max-heap property by repeatedly swapping the value with its parent until it is no longer greater than its parent (heapify up).
```cpp
heapifyUp(size - 1);
```
*Time complexity: O(log n)*

b. **Extract max**
- Check for `heap underflow`
```cpp
if (size == 0) {
        printf("Heap underflow! No elements to extract.\n");
        return;
    }
```
- Remove the root element (maximum value).
```cpp
printf("Extracted maximum: %d\n", heap[0]);
```
- Replace it with the last element in the heap array.
```cpp
heap[0] = heap[size - 1];  // Move the last element to the root
size--;  // Reduce heap size
```
- Restore the max-heap property by heapifying down from the root.
```cpp
heapifyDown(0);
```
*Time complexity: O(log n)*

c. **Get max**
- Check for empty queue
```cpp
if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }
```
- Return the root element of the heap, which is the maximum value.
```cpp
printf("Maximum element: %d\n", heap[0]);
```

d. **Display**
- Check for empty queue
```cpp
if (size == 0) {
        printf("Priority queue is empty!\n");
        return;
    }
```
- Print all elements of the heap array in level-order format.
```cpp
for (int i = 0; i < size; i++) {
        printf("%d ", heap[i]);
    }
```
*Time complexity: O(n)*

**HeapifyUp**
- Start from the index of the newly added element.
- Compare the element with its parent:
    - If the element is greater than its parent, swap them.
    - Continue moving up the tree until the element is no longer greater than its parent or it becomes the root.
- Stop when the heap property is restored.

*Psuedocode*
```cpp
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] > heap[parent]) {
            // Swap if the current value is greater than the parent
            swap(heap[index], heap[parent]);
            index = parent; // Move up to the parent's index
        } else {
            break; // Max-heap property is satisfied
        }
    }
}
```
*Time complexity: O(log n)*

**HeapifyDown**
- Start from the root index (0).
- Compare the element with its children:
    - Swap with the larger child if it is greater than the current element.
    - Continue moving down the tree until the element is greater than its children or it becomes a leaf node.
- Stop when the heap property is restored.

*Pseudocde*
```cpp
void heapifyDown(int index) {
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        // Check if left child is larger
        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        // Check if right child is larger
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            // Swap with the largest child
            swap(heap[index], heap[largest]);
            index = largest; // Move down to the largest child's index
        } else {
            break; // Max-heap property is satisfied
        }
    }
}
```
*Time complexity: O(log n)*

|                     HeapifyUp                         |            HeapifyDown           |
|-------------------------------------------------------|----------------------------------|
|              Adjusts heap after insertion             | Adjusts heap after extraction    |
|                 Moves elements upwards                | Moves elements downwards         |
| Starting point is the index of newly inserted element | Starting point is the root index |
|                 Compares with parent                  | Compares with children           |

### 10. **Hashing using linear probing**
### 11. **Hashing using quadratic probing**
### 12. **Hashing using separate chaining**
### 13. **Graphs using adjacency matrix**
### 14. **Graphs using adjacency lists**
