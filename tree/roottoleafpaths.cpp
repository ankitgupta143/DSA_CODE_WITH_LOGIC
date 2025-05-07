/*

Definition for Binary Tree Node
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
      void solve(Node *root, vector<vector<int>> &ans, vector<int> path){
          if(!root){
              return;
          }
          
          
          path.push_back(root -> data);
          
          if(root -> left == NULL and root -> right == NULL){
              ans.push_back(path);
              return;
          }
          
          
          solve(root -> left, ans, path);
          solve(root -> right, ans, path);
      }
      vector<vector<int>> Paths(Node* root) {
          
          
          vector<vector<int>> ans;
          vector<int> path;
          
          solve(root, ans, path);
          return ans;
          
      }
  };