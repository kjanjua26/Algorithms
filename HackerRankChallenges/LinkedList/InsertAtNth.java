/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  class Node {
     int data;
     Node next;
  }
*/
    

Node InsertNth(Node head, int data, int position) {
    Node node = head;
    if(position == 0){
        node = new Node();
        node.data = data;
        node.next = head;
        return node;
    }
    else{
        while(--position != 0){
            node = node.next;
        }
        Node temp = node.next;
        node.next = new Node();
        node.next.data = data;
        node.next.next = temp;
        return head;
    }
}

