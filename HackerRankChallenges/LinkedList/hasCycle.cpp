/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
The algorithm is Floyd Cycle Detection Algorithm which is used to detect the cycle in LinkedLists.
*/

bool has_cycle(Node* head) {
    Node* temp1 = head;
    Node* temp2 = head;
    while(temp1 && temp1->next){
        temp2 = temp2->next;
        temp1 = temp1->next->next;
        if(temp2 == temp1){
            return true;
        }
    }
    return false;
}
