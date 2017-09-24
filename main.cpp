/*
 * Building a LinkedList.
 */

#include <iostream>
using namespace std;

struct node {
    int value;
    node *next;
};

/*
 *  Function declarations.
 */
bool isEmpty(node *head);
char panel();
void insertFirst(node *&head, node *&tail, int value);
void insert(node *&head, node *&tail, int value);
void remove(node *&head, node *&tail);
void printList(node *head);

/*
 *  Function Definitions.
 */
bool isEmpty(node *head){
    return head == NULL; //Returns true if list is empty else returns false.
}
char panel(){
    char cho;
    cout << "\nPanel" << endl;
    cout << "1. Add an item." << endl;
    cout << "2. Remove an item." << endl;
    cout << "3. Show the list." << endl;
    cout << "4. Exit." << endl;
    cin >> cho;
    return cho;
}
void insertFirst(node *&head, node *&tail, int value){
    node *temp = new node;
    temp->value = value;
    temp->next = NULL;
    head = temp; //Since there is only one value, we set head and tail to temp.
    tail = temp;
}
void insert(node *&head, node *&tail, int value){
    if(isEmpty(head))
        insertFirst(head, tail, value);

    else{
        node *temp = new node;
        temp->value = value;
        temp->next = NULL; //Because this is newest value.
        tail->next = temp; //Joins the last node to next node.
        tail = temp;
    }
}
void remove(node *&head, node *&tail){ //Removes the first element in the list.
    if(isEmpty(head))
        cout << "\nThe list is already empty." << endl;
    else if (head == tail){
        delete head;
        head = NULL;
        tail = NULL;
    }
    else{
        node *temp = head;
        head = head->next;
        delete temp;
    }
}
void printList(node *head){
    if(isEmpty(head))
        cout << "\nThe list is already empty." << endl;
    else{
        cout << "The values in the list are: " << endl;
        while(head != NULL){
            cout << head->value << ", " << "";
            head = head->next;
        }
    }
}
int main() {
    node *head = NULL;
    node *tail = NULL;
    char cho;
    int value;
    do{
        cho = panel();
        switch(cho){
            case '1':
                cout << "Enter a number: ";
                cin >> value;
                insert(head, tail, value);
                break;
            case '2':
                remove(head, tail);
                break;
            case '3':
                printList(head);
                break;
            default:
                cout << "Exiting.";
        }
    } while(cho != '4');

    return 0;
}