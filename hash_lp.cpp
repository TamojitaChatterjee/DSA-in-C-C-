//hash-linear probing

#include<stdio.h>
#include<stdlib.h>

class HashTable{
    int* arr; //stores elements
    int size; //size of table

//computes the index
    int hash(int x){
        return x % size;
    }

public:
    //constructor
    HashTable(int n){
        size = n;
        arr = new int[n]; //create a dynamic array of size n

        for(int i=0;i<n;i++){
            arr[i]=-1; //initialize all slots to -1
        }
    }

    //insertion
    void insert(int x){
        int idx = hash(x); //find index
        while(arr[idx] != -1){
            idx = (idx+1)%size;
        }
        arr[idx] = x;
    }

    //deletion
    void del(int x){
        int idx = hash(x);
        while(arr[idx] !=x && arr[idx] != -1){
            idx=(idx+1)%size;
        }
        if(arr[idx]==x){
            arr[idx]=-1;
        }
    }

    //search
    bool Search(int x){
        int idx = hash(x);
        while(arr[idx] != -1){
            if(arr[idx] == x){
                return true;
            }
            idx = (idx+1)%size;
        }
        return false;
    }

    //display
    void display(){
        for(int i=0;i<size;i++){
            if(arr[i] != -1){
                printf("[%d]: %d\n",i, arr[i]);
            }
        }
    }
};

int main(){
    HashTable ht(10); //add size of table
    int choice, val;

    while(1){
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d",&val);
            ht.insert(val);
            ht.display();
            break;

            case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d",&val);
            ht.del(val);
            ht.display();
            break;

            case 3:
            printf("Enter the value to be searched: ");
            scanf("%d",&val);

            if(ht.Search(val)){
                printf("%d is present in the table",val);
            }else{
                printf("%d is absent",val);
            }
            break;

            case 4:
            ht.display();
            break;

            case 5:
            printf("Exiting...\n");
            exit(0);

            default:
            printf("Invalid choice! Retry");
        }
    }
    return 0;
}