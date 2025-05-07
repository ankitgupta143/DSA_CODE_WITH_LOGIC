/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

 class Solution {
    public:
      vector<int> leftView(Node *root) {
          
      queue<Node *> que;
      que.push(root);
      vector<int> ans;
      
      if(root == NULL){
          return ans;
      }
          
      while(!que.empty()){
         int size = que.size();
         for(int i = 0; i < size; i++){
             Node *curr = que.front();
             que.pop();
             
             if(i == 0){
                 ans.push_back(curr -> data); 
             }
             
             if(curr -> left != NULL){
                 que.push(curr -> left);
             }
             
             if(curr -> right != NULL){
                 que.push(curr -> right);
             }
         }
      }
      
      
      return ans;
      }
  };