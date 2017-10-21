Node* Delete(Node *head, int position)
{
    Node *newNode = head;
    if(position == 0){
        return head->next;        
    }
    for(int i = 0 ; i < position-1; i++){
        newNode = newNode->next;              
    }
      newNode->next = newNode->next->next; // (n-1)th-> = (n-1)th->next->next;
      return head;
}
