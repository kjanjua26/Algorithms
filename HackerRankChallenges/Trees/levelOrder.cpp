#include <queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void levelOrder(node * root) {
    if(root == NULL) return;
    queue<int> temp;
    temp.push(root->data);
    while(!temp.empty()){
        cout << temp.front() << " ";
        if(temp.front()->left != NULL)
            temp.push(temp.front()->left->data);
        if(temp.front()->right != NULL)
            temp.push(temp.front()->right->data);
        temp.pop();
    }
}
