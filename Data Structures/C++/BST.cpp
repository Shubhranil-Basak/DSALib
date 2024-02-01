#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left, *right;
};

typedef struct node Node;

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout<< root->data << " ";
    printInOrder(root->right);
}

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

bool SearchUTL(Node *node, int val){
    if(node == NULL){
        return false;
    }
    else if (node->data == val){
        return true;
    }
    else if (val < node->data){
        return SearchUTL(node->left, val);
    }
    else{
        return SearchUTL(node->right, val);
    }
}

void Search(Node *node, int val){
    if(SearchUTL(node, val)){
        cout<<"Found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
}

int findMin(Node *node){
    if(node == NULL){
        printf("Tree is empty");
        return -1;
    }
    else if (node->left == NULL){
        return node->data;
    }
    else{
        return findMin(node->left);
    }
}

int findMax(Node *node){
    if(node == NULL){
        printf("Tree is empty");
        return -1;
    }
    else if (node->left == NULL){
        return node->data;
    }
    else{
        return findMax(node->right);
    } 
}

int heigthOfTree(Node *root){
    if(root == NULL){
        return 0;
    }
    int leftHeigth = heigthOfTree(root->left);
    int rightHeigth = heigthOfTree(root->left);
    return max(leftHeigth, rightHeigth) + 1;
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
}