class Solution
{
public:
    int dp[1001][1001];
    int solve(int i, int j, string &s1, string &s2, int m, int n)
    {
        // Base case
        if (i >= m || j >= n)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        if (s1[i] == s2[j])
        {
            return dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, m, n);
        }

        return dp[i][j] = max(solve(i + 1, j, s1, s2, m, n), solve(i, j + 1, s1, s2, m, n));
    }
    int lcs(string &s1, string &s2)
    {
        memset(dp, -1, sizeof(dp));
        int m = s1.length();
        int n = s2.length();

        return solve(0, 0, s1, s2, m, n);
    }
};