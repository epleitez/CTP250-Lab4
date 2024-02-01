#include <iostream>
#include "Node.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void displayList(Node *);
void insertFront(Node **head, int value);
void insertBack(Node **ptrToHead, int value);
void insertAfter(Node *previous, int value);
void deleteAtN(Node **ptrToHead, int n);
void deleteNode(Node **ptrToHead, int searchVal);
void clearList(Node **ptrToHead);

//new methods
bool searchVal(Node *, int item);
int countFrequency(Node *, int item);
int size(Node *);
void displayFromFrontToN(Node *, int n);
void displayFromNToEnd(Node *, int n);
void insertInOrder(Node *, int n);
void fillListFromFile(Node *); // will need to keep track of nodes
void displayInRows(Node *);



int main() {

    Node *node1 = new Node();
    node1->setValue(10);
    Node *node2 = new Node();
    node2->setValue(20);
    Node *node3 = new Node();
    node3->setValue(30);
    Node *node4 = new Node();
    node4->setValue(40);

    node1->next = node2; //next is public, direct access
    node2->next = node3;
    node3->next = node4;

    Node *head = node1; // head is a reference to a Node object

    /*Methods created in class
    displayList(head);
    insertFront(&head, 5); //& passed ny address because head can change
    displayList(head);
    insertBack(&head, 45);
    displayList(head);
    insertAfter(node1,15); //works only with a named node
    displayList(head);
    deleteAtN(&head, 2); //second element (list is 1-based)
    displayList(head);
    deleteNode(&head, 45);
    displayList(head);
    clearList(&head);
    displayList(head);
    */

    //new methods
    displayList(head);
    searchVal(head, 10);
    countFrequency(head, 10);
    size(head);
    displayFromFrontToN(head, 2);
    displayFromNToEnd(head, 2);
    insertInOrder(head, 35);
    displayList(head);
    clearList(&head);
    fillListFromFile(head);
    displayList(head);
    //displayInRows(head);

    return 0;
}
/* Searches the linked list for an item. returns true if item is found, false otherwise
 * @param Node* head allows access to the linked list.
 * @param int item, is item that is being searched for in list.
 */
bool searchVal(Node* head, int item){

    bool found = false;

    cout << "Searching for: " << item << endl;

    Node* current = head;
    while (current != nullptr){
        if(current->getValue() == item){
            found = true;
        }
        current = current->next;
    }
    if (found == true)
        cout << "Yes, the item is found." << endl;
    else
        cout << "The item is not found..." << endl;

    return found;
}//end searchVal()

/* Searches the linked list for an item. returns count of the item in list if found.
 * @param Node* head allows access to the linked list.
 * @param int item, is item that is being searched for and counted in list.
 */
int countFrequency(Node *head, int item){

    int count = 0;

    cout << "Searching for: " << item << endl;

    Node* current = head;
    while (current != nullptr){
        if(current->getValue() == item){
            count ++;
        }
        current = current->next;
    }

    if (count > 0)
        cout << "Frequency of item: " << count << endl;
    else
        cout << "Item not found in list..." << endl;

    return count;
}//end countFrequency

/* Returns the number of items in the list.
 * @param Node* head allows access to the linked list.
 */
int size(Node *head){
    int count = 0;

    Node* current = head;
    while (current != nullptr){
        count ++;
        current = current->next;
    }

    cout << "Total number of items in list: " << count << endl;

    return count;
}//end size()

/* Displays the linked list from the head to the nth position.
 * @param Node* ptr allows access to the linked list.
 * @param int n is the position up to which the list will be displayed
 */
void displayFromFrontToN(Node *ptr, int n){

    if(ptr == nullptr){
        cout << "empty list" << endl;
    }//end if
    else{
        for (int i = 0; i < n; i ++){
            cout << ptr->getValue() << endl;
            ptr = ptr->next;
        }//end for

    }//end else
    cout << "-----------------------------" << endl;
}//end displayFromFrontToN()

/* Displays the linked list from the nth position to the end.
 * @param Node* ptr allows access to the linked list.
 * @param int n is the position the linked list will begin to display from
 */
void displayFromNToEnd(Node *head, int n){

    int count = 0;
    Node* current = head;
    Node* ptr = head;
    while (current != nullptr){
        count ++;
        current = current->next;
    }

    if(n <= count){
        for (int i = 0; i < count; i++){
            if(i < n)
                ptr = ptr->next;
            else if(i >= n){
                cout << ptr->getValue() << endl;
                ptr = ptr->next;
            }//end else if
        }//end for
    }//end if
    cout << "-----------------------------" << endl;
}//end displayFromNToEnd()

/* Inserts the parameter n into the linked list in its proper order
 * @param Node* previous allows access to the linked list.
 * @param int n is the element being added to the linked list
 */
void insertInOrder(Node *head, int n){

    if(head == nullptr){
        cout << "Cannot be inserted... value is null" << endl;
    }
    else{
        Node *current = head;
        Node *newNode = new Node();
        newNode->setValue(n);
        while(current != nullptr && (current->getValue() < newNode->getValue())){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }//end else

}//end insertInOrder

/* Reads a file and creates a linked list using nodes.
 * @param Node* head is the address of the first item in the list
 */
void fillListFromFile(Node *head){

    ifstream infile("linkedListData1.txt");
    if(!infile.is_open()){
        cout << "file not open for input...program terminating" << endl;
        exit(0);
    }//end if

    Node *first = head;
    Node *current = head;
    Node *newNode = new Node;
    string line;

    while(getline(infile, line)){
        current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }

    infile.close();
}//end fillListFromFile()

/* Displays the linked list in rows of 10 elements
 * @param Node* head is the address of the first item in the list
 */
void displayInRows(Node *ptr){
    if(ptr == nullptr){
        cout << "empty list" << endl;
    }//end if
    else {
        while(ptr != nullptr) {
            for (int i = 10; i > 0 ; i--) {
                cout << ptr->getValue() << " ";
                ptr = ptr->next;
                if (i == 1) {
                    cout << "\n" << endl;
                    i = 10;
                }
            }//end for
        }//end while
    }//end else
    cout << "-----------------------------" << endl;
}//end displayInRows()

void displayList(Node *ptr){
    if(ptr == nullptr){
        cout << "empty list" << endl;
    }//end if
    else {
        while(ptr != nullptr){
            cout << ptr->getValue() << endl;
            ptr = ptr->next;
        }//end while
    }//end else
    cout << "-----------------------------" << endl;
}//end displayList

void insertFront(Node **head, int value)
{
    Node *newNode = new Node();

    newNode->setValue(value);

    //cout<< newNode->getValue() << endl;

    newNode->next = *head; //*head is a pointer to a Node, next is a pointer to a Node so these can be assigned

    *head = newNode;  //*head is a pointer to a Node, newNode is a pointer to a Node

}

void insertBack(Node **ptrToHead, int value){
    //prepare the new node
    Node *newNode = new Node();
    newNode->setValue(value);
    newNode->next = nullptr; // didn't need to do this since it is done in the constructor

    //if it's am empty list
    if (*ptrToHead == nullptr)
    {
        *ptrToHead = newNode;
    }//end if
        //find the last node of the list
    else
    {
        Node *last = *ptrToHead;
        while(last->next != nullptr)
        {
            last = last->next; //traversal, gets us to the end of the list
        }
        last->next = newNode;

    }//end else
}//end insertBack()insertBack

void insertAfter(Node *previous, int value){
    //check if previous node is nullptr
    if (previous == nullptr)
    {
        cout << "previous cannot be null" << endl;

    }
    else
    {
        //prepare the new node

        Node *newNode = new Node();
        newNode->setValue(value);

        newNode->next = previous->next;
        previous->next = newNode;
    }

}//end insertAfter()

void deleteAtN(Node **ptrToHead, int n){
    Node *temp = *ptrToHead;

    if (n == 1){
        *ptrToHead = temp->next;
        delete temp;
    }
    else {
        for (int i = 1; i <= n - 2; ++i){
            temp = temp->next;
        }
        Node *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
    }
}

void deleteNode(Node **ptrToHead, int searchVal){

    if (*ptrToHead == nullptr){
        cout << "can't delete from empty list" << endl;
    }
    else{
        Node *current = *ptrToHead;
        Node *trailing = nullptr;

        //now we traverse to find the match
        while (current != nullptr){
            if (current->getValue() == searchVal){
                if (current == *ptrToHead){
                    *ptrToHead = (*ptrToHead)->next;  //parens necessary because of operator precedence -> comes before *
                }
                    //somewhere beyond head
                else {
                    trailing->next = current->next;
                }

                delete current;  //delete the current pointer
                current = nullptr; //make it point to null

            }
            else {
                trailing = current;
                current = current->next;
            }


        }//end while

        if (current == nullptr){
            cout << searchVal << " removed " << endl; //reporting that element was deleted
        }
    }//end else

}

void clearList(Node **ptrTohead){


    Node *current, *temp;


    current = *ptrTohead;
    while(current != nullptr){
        temp = current;
        current = current->next;
        delete temp;
    }

    *ptrTohead = nullptr; // this is the head pointer

    cout <<"end of clearList()"<<endl;


}//end clearList()

/*
 cout << "head: " << head << endl;
 cout << "Node1: " << node1 << endl;
 cout << "Node1 next: " << node1->next << endl;
 cout << "Node2: " << node2 << endl;
 cout << "Node2 next: " << node2->next << endl;
 cout << "Node3: " << node3 << endl;
 cout << "Node3 next: " << node3->next << endl;
 */
