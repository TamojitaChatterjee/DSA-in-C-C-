//hashing-quadratic probing
#include<stdio.h>
#include<stdlib.h>

class HashTable{
    int *arr; //dynamic array
    int size; //size of the table

    int hash(int x){
        return x % size;
    }

public:
    HashTable(int n){
        size = n;
        arr = new int[n]; //dynamic array of size n
        for(int i=0; i<n; i++){
            arr[i] = -1;
        }
    }

    void insert(int x){
        int idx = hash(x);
        int i = 0;

        while(arr[(idx+ i*i)%size] != -1){
            i++;
            if(i == size){
                printf("Table is full");
                return;
            }
        }

        arr[(idx+ i*i)%size] = x;
        printf("Insertion successful");
    } 

    void del(int x){
        int idx = hash(x);
        int i = 0;

        while(arr[(idx+ i*i)%size] != x && arr[(idx+i*i)%size] != -1){
            i++;
            if(i==size){
                printf("Element not found");
                return;
            }
        }
        if (arr[(idx + i * i) % size] == x) {
            arr[(idx + i * i) % size] = -1;
            printf("Element %d removed.\n", x);
        } else {
            printf("Element %d not found.\n", x);
        }
    }

    bool search(int x) {
        int idx = hash(x);
        int i = 0;

        while (arr[(idx + i * i) % size] != -1) {
            if (arr[(idx + i * i) % size] == x) { // Value found
                return true;
            }
            i++;
            if (i == size) { 
                return false;
            }
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            if (arr[i] != -1) {
                printf("[%d]: %d\n", i, arr[i]); // Display element at index i
            } else {
                printf("[%d]: Empty\n", i); // Display empty slot
            }
        }
    }
};

int main(){
    HashTable ht(10);
    int choice;
    int val;

    printf("\nMenu\n");
    printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        //insert
        printf("Value: ");
        scanf("%d",&val);
        ht.insert(val);
        ht.display();
        break;

        case 2:
        //delete
        printf("Value: ");
        scanf("%d",&val);
        ht.del(val);
        ht.display();

        case 3:
        //search
        printf("Value: ");
        scanf("%d",&val);
        if(ht.search(val)){
            printf("Element found!\n");
        }else{
            printf("Element not found\n");
        }
        break;

        case 4:
        ht.display();
        break;

        case 5:
        printf("Exiting...\n");
        exit(0);
        break;

        default:
        printf("Invalid choice! Retry");
    }
    return 0;
}