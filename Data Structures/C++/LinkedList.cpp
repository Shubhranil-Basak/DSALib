#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

typedef struct node Node;

Node* createNode(int val) {
    Node* newnode = new Node();
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

Node* insert(Node* head, int val) {
    if (head == NULL) {
        head = createNode(val);
        return head;
    } else {
        Node* l = head;
        while (l->next != NULL) {
            l = l->next;
        }
        l->next = createNode(val);
        return head;
    }
}

void printValLL(struct node* head) {
    struct node* l;
    for (l = head; l != NULL; l = l->next)
        printf("%d ", l->data);
}

int lengthLL(struct node* head){
	struct node* l;
	int i = 0;
	for(l=head; l!=NULL; l = l->next)
		i++;
	return i;
}

void printValReverseLL(struct node* head){
	if(!head)
		return;
	printValReverseLL(head->next);
	printf("%d ", head->data);
}

int getValAtHeadLL(struct node* head){
	if (!head){
		printf("Error");
		return 0;
	}
	return head->data;
}

int getValAtTailLL(struct node* head){
	if (!head){
		printf("Error");
		return 0;
	}
	struct node* l;
	for(l=head; l->next!=NULL; l=l->next);
	return (l->data);
}

int getValAtPosLL(struct node* head, int pos){
	struct node* l;
	int i=0;
	for(l=head; l!=NULL && i!=pos; l = l->next)
		i++;
	if(l==NULL)
		return (int) NULL;
	else
		return l->data;
}

struct node* addNodeToHeadLL(struct node* head, struct node* temp){
	temp->next = head;
	return temp;
}

struct node * addNodeToTailLL(struct node* head, struct node* temp){
	struct node* l;
	for(l=head; l->next!=NULL; l=l->next);
	l->next = temp;
	temp->next = NULL;
	return head;
}

struct node* addNodeToPosLL(struct node* head, int pos, struct node* temp){
	struct node* h;
	struct node* l;
	int i;
	for(i=0, h=head, l=NULL; h!=NULL && i!=pos; i++, h=h->next)
		l=h;
	if(l==NULL){
		temp->next = head;
		return temp;
	}
	l->next = temp;
	temp->next = h;
	return head;
}

struct node* deleteNodeAtPosFromLL(struct node* head, int pos){
	struct node* h;
	struct node* l;
	int i;
	for(i=0, h=head, l=NULL; h!=NULL && i!=pos; i++, h=h->next)
		l=h;
	if(l==NULL)
		return (head ? h->next: NULL);
	l->next = h ? h->next: NULL;
	return head;
}

struct node* deleteMatchingNodesFromLL(struct node* head, int val){
	struct node* h;
	struct node* l;
	for(h=head, l=NULL; h!=NULL; h=h->next){
		if(h->data==val){
			if(l==NULL)
				head = head ? h->next: NULL;
			else
				l->next = h ? h->next: NULL;
		}
		l=h;
	}
	return head;
}

struct node* reverseLL(struct node* head){
	struct node *current, *prev, *next;
	prev = NULL;
	current = head;
	next = NULL;
	while(current!=NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

struct node* joinLL(struct node* head1, struct node* head2){
	struct node* l;
	for(l=head1; l->next!=NULL; l=l->next);
	l->next = head2;
	return head1;
}

int main(){
    Node* head = NULL;
    for(int i = 0; i < 10; i++){
        head = insert(head, 10*i);
    }
    printValLL(head);
}