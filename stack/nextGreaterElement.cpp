#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      // Function to find the next greater element for each element of the array.
      vector<int> nextLargerElement(vector<int>& arr) {
          int n = arr.size();
          // int j;
          // vector<int> ans;
          // for(int i = 0; i < n; i++){
          //     for(j = i + 1; j < n; j++){
          //         if(arr[j] > arr[i]){
          //             ans.push_back(arr[j]);
          //             break;
          //         }
          //     }
              
          //     if(j == n){
          //         ans.push_back(-1);
          //     }
              
          // }
          
          // return ans;
          
          stack<int> st;
          vector<int> ans;
          
          for(int i = n - 1; i >= 0; i--){
              while(!st.empty() && st.top() <= arr[i]){
                  st.pop();
              }
              
              if(st.empty()){
                  ans.push_back(-1);
              }
              else{
                  ans.push_back(st.top());
              }
              
              st.push(arr[i]);
          }
          
          reverse(ans.begin(), ans.end());
          
          return ans;
      }
  };