//character binary tree
#include<stdio.h>
#include<stdlib.h>

struct Node{
    char data;
    Node* left;
    Node* right;
};

class charBinTree{
    public:
    Node* root;

    charBinTree(){
        root=NULL;
    }

    Node* createnewNode(char data){
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data=data;
        newNode->left=NULL;
        newNode->right=NULL;
        return newNode;
    }

    Node* insert(Node* root, char data){
        if(root==NULL){
            return createnewNode(data);
        }

        if(data<root->data){
            root->left = insert(root->left, data);
        }else{
            root->right =insert(root->right, data);
        }
        return root;
    }

    void insert(char data){
        root = insert(root,data);
    }

    void preorder(Node*root){
        //root,left,right
        if(root!=NULL){
            printf("%c",root->data);
            preorder(root->left);
            preorder(root->right);
        }
    }

    void inorder(Node*root){
        //left, root, right
        if(root!=NULL){
            inorder(root->left);
            printf("%c",root->data);
            inorder(root->right);
        }
    }

    void postorder(Node*root){
        //left,right,root
        if(root!=NULL){
            postorder(root->left);
            postorder(root->right);
            printf("%c",root->data);
        }
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

    void printPreorder(){
        preorder(root);
        printf("\n");
    }

    void printInorder(){
        inorder(root);
        printf("\n");
    }

    void printPostorder(){
        postorder(root);
        printf("\n");
    }

    bool Search(Node* root, char key){
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

    bool Search(char key){
        return Search(root, key);
    }
};

int main(){
    charBinTree tree;
    char data; 
    int choice;

    printf("\nMenu\n");
    printf("1. Insertion\n");
    printf("2. Preorder\n");
    printf("3. Inorder\n");
    printf("4. Postorder\n");
    printf("5. Search\n");
    printf("6. Exit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            //insertion
            printf("Enter character to be inserted: ");
            scanf(" %c", &data);
            tree.insert(data);
            printf("Element %c has been inserted successfully!\n",data);
            tree.display();
            break;

            case 2:
            //preorder
            tree.printPreorder();
            break;

            case 3:
            //inorder
            tree.printInorder();
            break;

            case 4:
            tree.printPostorder();
            break;

            case 5:
            printf("Enter character to search: ");
            scanf(" %c", &data);
            if(tree.Search(data)){
                printf("Character found!");
            }else{
                printf("Character not found!");
            }
            break;

            case 6:
            printf("Exiting...\n");
            exit(0);

            default:
            printf("Invalid choice! Retry");
        }
    }
    return 0;
}