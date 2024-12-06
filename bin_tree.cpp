#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    Node* left;
    Node* right;
};

class BinTree{
    public:
    Node* root; //defining the root

    BinTree(){
        root=NULL; //empty tree
    }
    Node* createnewnode(int data){
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data=data; //storing number in the new node
        newNode->left=NULL; //left child not present
        newNode->right=NULL; //right child not present
        return newNode;
    }

    //insertion: smaller elements go to the left, larger to the right
    Node* insert(Node* root, int data){
        if(root==NULL){
            return createnewnode(data);
        }

        if(data<root->data){
            root->left=insert(root->left, data); //smaller->left
        }
        else{
            root->right=insert(root->right, data);
        }
        return root;
    }
    //wrapper function: calls the function
    void insert(int data){
        root = insert(root, data);
    }

    //preorder: root, left, right
    void preorder(Node* root){
        if(root!=NULL){
            printf("%d", root->data); //root
            preorder(root->left); //left
            preorder(root->right); //right
        }
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

    //inorder: left, root, right
    void inorder(Node*root){
        if(root!=NULL){
            inorder(root->left);
            printf("%d", root->data);
            inorder(root->right);
        }
    }

    //postorder: left, right, root
    void postorder(Node* root){
        if(root!=NULL){
            postorder(root->left); //left
            postorder(root->right); //right
            printf("%d", root->data); //root
        }
    }    

    //display
    void display(){
        printf("\nTree traversals\n");

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

    //recursively searching through the tree
    //if we reach null, number is not present
    //if we find key (root->data=key), number is present
    //if key is smaller than root, search left
    //if key is larger, search right
    bool search(Node*root, int key){
        if(root==NULL){
            return false;
        }
        if(root->data=key){
            return true;
        }
        else if(key<root->data){
            return search(root->left, key);
        }else{
            return search(root->right, key);
        }
    }

    //wrapper function
    bool search(int key){
        return search(root, key);
    }

};

int main(){
    BinTree tree;
    int data, choice;

    while(1){
            printf("\nMenu\n");
        printf("1. Insertion\n");
        printf("2. Preorder traversal\n");
        printf("3. Inorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Search\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
            //insertion
            printf("Insertion\n");
            printf("Enter number to insert: ");
            scanf("%d",&data);
            tree.insert(data);
            printf("%d has been successfully inserted\n",data);
            tree.display();
            break;

            case 2:
            //preorder
            printf("Preorder traversal");
            tree.printPreorder();
            break;

            case 3:
            //inorder
            printf("Inorder traversal\n");
            tree.printInorder();
            break;

            case 4:
            //postorder
            printf("Postorder traversal\n");
            tree.printPostorder();
            break;

            case 5:
            //search
            printf("Enter the element to be searched: ");
            scanf("%d",&data);
            if(tree.search(data)){
                printf("Element %d found in the tree\n",data);
            }else{
                printf("Element %d not found\n",data);
            }
            tree.display();
            break;

            case 6:
            printf("Exiting...\n");
            exit(0);

            default:
            printf("Invalid choice, retry!");
        }
    }
    return 0;
}