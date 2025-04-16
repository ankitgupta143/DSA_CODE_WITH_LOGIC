class Solution {
    public:
      int getSecondLargest(vector<int> &arr) {
          // First approach
          
          int n = arr.size();
          
          // sort(arr.begin(), arr.end());
          
          // for(int i = n - 1; i>= 1; i--){
          //     if(arr[i] != arr[i - 1]){
          //         return arr[i - 1];
          //     }
          // }
          // return -1;
          
          
          // second approach
          // int secondLargest = -1;
          // int largest = -1;
          
          // for(int i = 0; i< n; i++){
          //     if(arr[i] > largest){
          //         secondLargest = largest;
          //         largest = arr[i];
          //     }
          //     else if(arr[i] < largest && arr[i] > secondLargest){
          //         secondLargest = arr[i];
          //     }
          // }
          
          // return secondLargest;
          
          
          // Third approach
          priority_queue<int> pq(arr.begin(), arr.end());
          int first = pq.top();
          pq.pop();
          
          while(!pq.empty()){
              int next = pq.top();
              pq.pop();
              
              if(next != first){
                  return next;
              }
          }
          
          return -1;
          
      }
  };