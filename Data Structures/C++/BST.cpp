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

Node *Search(Node *root, int val){
    if(root == NULL || root->data == val){
        return root;
    }
    
    if (val < root->data){
        return Search(root->left, val);
    }
    else{
        return Search(root->right, val);
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

Node* Successor(Node* root, int X) {
    // Find the node with value X in the BST
    Node* currentNode = Search(root, X);
    
    if (currentNode == nullptr)
        return nullptr;
    
    // Case 1: If currentNode has a right subtree
    if (currentNode->right != nullptr) {
        // Find the leftmost node in the right subtree (smallest value in the right subtree)
        Node* successor = currentNode->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        return successor;
    }
    
    // Case 2: If currentNode does not have a right subtree
    // Traverse from root to currentNode to find the inorder successor
    Node* successor = nullptr;
    Node* ancestor = root;
    while (ancestor != currentNode) {
        if (currentNode->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            ancestor = ancestor->right;
        }
    }
    
    return successor;
}

Node* inorderPredecessor(Node* root, int X) {
    // Find the node with value X in the BST
    Node* currentNode = Search(root, X);

    if (currentNode == nullptr)
        return nullptr;

    // Case 1: If currentNode has a left subtree
    if (currentNode->left != nullptr) {
        // Find the rightmost node in the left subtree (largest value in the left subtree)
        Node* predecessor = currentNode->left;
        while (predecessor->right != nullptr) {
            predecessor = predecessor->right;
        }
        return predecessor;
    }

    // Case 2: If currentNode does not have a left subtree
    // Traverse from root to currentNode to find the inorder predecessor
    Node* predecessor = nullptr;
    Node* ancestor = root;
    while (ancestor != currentNode) {
        if (currentNode->data > ancestor->data) {
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    return predecessor;
}

Node* LCA(Node* root, int A, int B) {
    if (root == nullptr)
        return nullptr;

    if (root->data > A && root->data > B)
        return LCA(root->left, A, B);
    else if (root->data < A && root->data < B)
        return LCA(root->right, A, B);
    else
        return root;
}


/*Driver Code*/
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