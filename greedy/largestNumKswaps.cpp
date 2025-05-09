class Solution
{
    public:
    string ans = "";
    void solve(int idx, int n, string str, int k){
        if(k == 0 || idx >= n){
            ans = max(ans, str);
            return;
        }
        
        
        for(int i = idx + 1; i<n; i++){
            if(str[i] > str[idx]){
                swap(str[i], str[idx]);
                solve(idx + 1, n, str, k - 1);
                swap(str[i], str[idx]);
            }
        }
        
        solve(idx + 1, n, str, k);
        
    }
    string findMaximumNum(string str, int k)
    {
        int n = str.length();
        solve(0, n, str, k);
        return ans;
         
    }
};