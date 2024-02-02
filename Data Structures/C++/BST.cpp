#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

typedef struct node Node;


Node *createNode(int val){
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *node, int val){
    if(node == NULL){
        node =  createNode(val);
    }
    else if(val <= node->data){
        node->left = insert(node->left ,val);
    }
    else{
        node->right = insert(node->right, val);
    }
    return node;

}

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<< root->data << " ";
    printInOrder(root->right);
}

void printPreOrder(Node *root){
    if(root == NULL){
        return;
    }
    cout<< root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(Node *root){
    if(root == NULL){
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<< root->data << " ";
}

bool SearchUTL(Node *root, int val){
    if(root == NULL){
        return false;
    }
    else if (root->data == val){
        return true;
    }
    else if (val < root->data){
        return SearchUTL(root->left, val);
    }
    else{
        return SearchUTL(root->right, val);
    }
}

void Search(Node *root, int val){
    if(SearchUTL(root, val)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}

int findMin(Node *root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    else if (root->left == NULL){
        return root->data;
    }
    else{
        return findMin(root->left);
    }
}

int findMax(Node *root){
    if(root == NULL){
        printf("Tree is empty");
        return -1;
    }
    else if (root->right == NULL){
        return root->data;
    }
    else{
        return findMax(root->right);
    } 
}

int heigthOfTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHeigth = heigthOfTree(root->left);
    int rightHeigth = heigthOfTree(root->right);
    return max(leftHeigth, rightHeigth) + 1;
}

void printCurrentLevel(Node* root, int level){
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void printLevelOrder(Node* root){
    int h = heigthOfTree(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}

int main(){
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 90);
    root = insert(root, 70);
    root = insert(root, 80);
    root = insert(root, 100);
    return 0;
}