/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
#include <limits.h>
bool helper(Node* root, int min, int max){
    if(root == NULL) return true;
    return (root->data > min && root->data < max && helper(root->left, min, root->data) && helper(root->right, root->data, max));
}
bool checkBST(Node* root) {
    return helper(root, 0, INT_MAX);
} 
