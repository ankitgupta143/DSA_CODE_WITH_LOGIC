// ✅ Time Complexity: O(n² log n + k log n)
// ✅ Space Complexity: O(n²)


class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        
        priority_queue<int> pq;
        
        for(int i = 0;  i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                
                pq.push(sum);
            }
        }
        
        while(k > 1){
            pq.pop();
            k--;
        }
        
        return pq.top();
    }
};


// ✅ Time Complexity: O(n^2 log k)
// ✅ Space Complexity: O(log k)

class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        int n = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = i; j < n; j++){
                sum += arr[j];
                
                if(pq.size() < k){
                    pq.push(sum);
                }
                else if(sum > pq.top()){
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
        
        
        
        return pq.top();
    }
};
