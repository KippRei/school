#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
};

// only for the 1st Node
void initNode(struct Node *head,int n){
	head->data = n;
	head->next = NULL;
}

// appending
void addNode(struct Node *head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node *cur = head;
	while(cur) {
		if(cur->next == NULL) {
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void insertFront(struct Node **head, int n) {
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

//Write searchNode() here
Node* searchNode(struct Node* nodePtr, int n) {
    while (nodePtr != NULL) {
        if (nodePtr->data == n) {
            return nodePtr;
        }
        nodePtr = nodePtr->next;
    }
    cout << "No node found with value of " << n << endl;
    return NULL;
}

//Write deleteNode() here
bool deleteNode(struct Node** head, struct Node* toDelete) {
    Node* prev = NULL;
    Node* current = *head;
    if (current->data == toDelete->data) {
        *head = (*head)->next;
        delete(current);
        return true;
    }
    else {
        while (current != NULL) {
            if (current->data == toDelete->data) {
                prev->next = current->next;
                delete(current);
                return true;
            }
            prev = current;
            current = current->next;
        }
    }
    return false;
}

/* Creating a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew)
{
	if(node != NULL) {
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copyLinkedList(node->next, &((*pNew)->next));
	}
}

/* Compare two linked list */
/* return value: same(1), different(0) */
int compareLinkedList(struct Node *node1, struct Node *node2)
{
	static int flag;

	/* both lists are NULL */
	if(node1 == NULL && node2 == NULL) {
		flag = 1;
	}
	else {
		if(node1 == NULL || node2 == NULL) 
			flag = 0;
		else if(node1->data != node2->data) 
			flag = 0;
		else
			compareLinkedList(node1->next, node2->next);
	}

	return flag;
}

void deleteLinkedList(struct Node **node)
{
	struct Node *tmpNode;
	while(*node) {
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

void display(struct Node *head) {
	Node *list = head;
	while(list) {
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
	cout << endl;
}

int main() 
{
	struct Node *newHead;
	struct Node *head = new Node;
	
	initNode(head,10);
	display(head);

	addNode(head,20);
	display(head);

	addNode(head,30);
	display(head);

	addNode(head,35);
	display(head);

	addNode(head, 40);
	display(head);

	insertFront(&head, 5);
	display(head);

	int numDel = 5;
	Node *ptrDelete = searchNode(head, numDel);
	if(deleteNode(&head, ptrDelete)) 
		cout << "Node "<< numDel << " deleted!\n";
	display(head);

	cout << "The list is copied\n";
	copyLinkedList(head,&newHead);
	display(newHead);

	cout << "Comparing the two lists...\n";
	cout << "Are the two lists same?\n";
	if(compareLinkedList(head,newHead)) 
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
	cout << endl;

	numDel = 35;
	ptrDelete = searchNode(newHead,numDel);
	if(deleteNode(&newHead, ptrDelete)) {
		cout << "Node "<< numDel << " deleted!\n";
		cout << "The new list after the delete is\n";
		display(newHead);
	}
	cout << "Comparing the two lists again...\n";
	cout << "Are the two lists same?\n";
	if(compareLinkedList(head,newHead)) 
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
    
	cout << endl;
	cout << "Deleting the copied list\n";
	deleteLinkedList(&newHead);
	display(newHead);
	return 0;
}