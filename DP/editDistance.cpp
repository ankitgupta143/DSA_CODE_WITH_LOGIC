class Solution {
    public:
      int m, n;
      int dp[1001][1001];
      int solve(string& s1, string& s2, int i, int j){
          if(i >= m){
              return n - j;
          }
          
          if(j >= n){
              return m - i;
          }
          
          if(dp[i][j] != -1){
              return dp[i][j];
          }
          
          int ans = 0;
          if(s1[i] == s2[j]){
              ans = solve(s1, s2, i + 1, j + 1);
          }
          else{
              int insert = 1 + solve(s1, s2, i, j + 1);
              int removes = 1 + solve(s1, s2, i + 1, j);
              int replace = 1 + solve(s1, s2, i + 1, j + 1);
              ans = min({insert, removes, replace});
          }
          
          return dp[i][j] = ans;
          
      }
      int editDistance(string& s1, string& s2) {
          memset(dp, -1, sizeof(dp));
          m = s1.length();
          n = s2.length();
          
          return solve(s1, s2, 0, 0);
      }
  };