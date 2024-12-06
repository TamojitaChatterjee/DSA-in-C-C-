//bst
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BST{
    public:
    Node* root;
    BST(){
        root=NULL;
    }

    Node* createnewNode(int data){
        Node* newNode=(Node*)malloc(sizeof(Node));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
    }

    //insert
    Node* insert(Node* root, int data){
        if(root==NULL){
            return createnewNode(data);
        }
        if(data<root->data){
            root->left=insert(root->left, data);
        }else{
            root->right=insert(root->right, data);
        }
        return root;
    }

    void insert(int data){
        root=insert(root,data);
    }

    void preorder(Node* root){
        //root, left, right
        if(root!=NULL){
            printf("%d",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void printPreorder(){
        preorder(root);
        printf("\n");
    }

    void inorder(Node* root){
        //left,root,right
        if(root!=NULL){
            inorder(root->left);
            printf("%d",root->data);
            inorder(root->right);
        }
    }

    void printInorder(){
        inorder(root);
        printf("\n");
    }

    void postorder(Node* root){
        //left, right, root
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            printf("%d",root->data);
        }
    }

    void printPostorder(){
        postorder(root);
        printf("\n");
    }

    void display(){
        printf("Tree traversals\n");
        printf("Preorder: ");
        preorder(root);
        printf("\n");

        printf("Inorder: ");
        inorder(root);
        printf("\n");

        printf("Postorder: ");
        postorder(root);
        printf("\n");
    }

    bool Search(Node* root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data == key){
            return true;
        }
        else if(key<root->data){
            return Search(root->left, key);
        }else{
            return Search(root->right, key);
        }
    }

    bool Search(int key){
        return Search(root, key);
    }
};

int main(){
    BST bst;
    int choice, data;

    printf("Menu\n");
    printf("1. Insertion\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Postorder\n");
    printf("5. Search\n");
    printf("6. Exit\n");

    printf("Enter the choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
        printf("Enter the number to be inserted: ");
        scanf("%d",&data);
        bst.insert(data);
        printf("Element %d has been inserted successfully!",data);
        bst.display();
        break;

        case 2:
        bst.printPreorder();
        break;

        case 3:
        bst.printInorder();
        break;

        case 4:
        bst.printPostorder();
        break;

        case 5:
        printf("Enter the number to be searched: ");
        scanf("&d",&data);
        if(bst.Search(data)){
            printf("Element %d is present!", data);
        }else{
            printf("Element absent!");
        }
        break;

        case 6:
        printf("Exiting...\n");
        exit(0);
    }
    return 0;
}