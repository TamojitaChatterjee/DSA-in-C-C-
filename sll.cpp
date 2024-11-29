//singly linked list
#include<stdio.h>
#include<stdlib.h>

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};

void insbeg(Node*&head, int value){
    Node* n = new Node(value);
    n->next=head;
    head=n;
}

void insend(Node*&head, int value){
    Node* n = new Node(value);
    //empty list
    if(head==NULL){
        head=n;
        return;
    }
    //iterate
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //main logic
    temp->next=n;
}

void inspos(Node*& head, int value, int pos) {
    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        insbeg(head, value);
        return;
    }
    Node* n = new Node(value);
    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of bounds\n");
        delete n;
        return;
    }
    n->next = temp->next;
    temp->next = n;
}

void delbeg(Node*&head){
    if(head==NULL) return;

    Node* toDel = head;
    head=head->next;
    delete toDel;
}

void delend(Node*&head){
    if(head==NULL) return;

    if(head->next==NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp= head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}

void delpos(Node*& head, int pos) {
    if (!head) {  // If list is empty
        printf("List is empty\n");
        return;
    }
    
    if (pos < 1) {  // Invalid position (positions start from 1)
        printf("Invalid position!\n");
        return;
    }
    
    if (pos == 1) {  // Deleting the first node
        Node* toDel = head;
        head = head->next;
        delete toDel;
        return;
    }
    
    Node* prev = head;
    for (int i = 1; prev && i < pos - 1; i++) {  // Find the node before the position to delete
        prev = prev->next;
    }
    
    if (!prev || !prev->next) {  // Position out of bounds
        printf("Position out of bounds\n");
        return;
    }
    
    Node* toDel = prev->next;
    prev->next = prev->next->next;  // Update the link to skip over the node to delete
    delete toDel;
}

void display(Node*&head){
    Node* temp=head;
    //iterate
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void revit(Node*&head){
    if(head==NULL){
        return;
    }
    revit(head->next);
    printf("%d ",head->data);
    return;
}

bool search(Node*& head, int key) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// free memory
void freeList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){
    Node* head = NULL;
    int choice, value, pos, key;

    while(1){
        printf("\nMenu\n");
        printf("1. Insbeg\n");
        printf("2. Insend\n");
        printf("3. Inspos\n");
        printf("4. Delbeg\n");
        printf("5. Delend\n");
        printf("6. Delpos\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Reverse display\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter value to be inserted: ");
            scanf("%d",&value);
            insbeg(head, value);
            display(head);
            break;

            case 2:
            printf("Enter value to be inserted: ");
            scanf("%d",&value);
            insend(head, value);
            display(head);
            break;

            case 3:
            printf("Enter value to be inserted: ");
            scanf("%d",&value);
            printf("Enter position: ");
            scanf("%d",&pos);
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
            printf("Enter position from which element is to be deleted: ");
            scanf("%d",&pos);
            delpos(head, pos);
            display(head);
            break;

            case 7:
            printf("Enter value to be searched: ");
            scanf("%d",&key);
            if(search(head, key)){
                printf("Element has been found\n");
            }else{
                printf("Element has not been found\n");
            }
            break;

            case 8:
            display(head);
            break;

            case 9:
            revit(head);
            printf("\n");
            break;

            case 10:
            printf("Exiting...\n");
            freeList(head);
            exit(0);

            default:
            printf("Invalid choice!  Retry\n");
        }
    }
    return 0;
}