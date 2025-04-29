/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
    public:
      Node* segregate(Node* head) {
          if(head == NULL){
              return NULL;
          }
          
          Node *curr = head;
          int zeroCount = 0, oneCount = 0, twoCount = 0;
          
          while(curr != NULL){
              if(curr -> data == 0){
                  zeroCount++;
              }
              else if(curr -> data == 1){
                  oneCount++;
              }
              else{
                  twoCount++;
              }
              curr = curr -> next;
          }
          
          curr = head;
          
          while(curr != NULL){
              if(zeroCount){
                  curr -> data = 0;
                  zeroCount--;
              }
              else if(oneCount){
                  curr -> data = 1;
                  oneCount--;
              }
              else{
                  curr -> data =2;
                  twoCount--;
              }
              curr = curr -> next;
          }
          
          return head;
      }
  };