class Solution
{

    public:
        int mod = (int) 1e9 + 7;
    int func(vector<vector < int>> &grid, vector< vector< vector< int>>> &dp, int r, int c, int sum, int k)
    {
        if (r == grid.size() || c == grid[0].size()) return 0;

        sum += grid[r][c];

        if (r == grid.size() - 1 and c == grid[0].size() - 1)
        {
            if (sum % k == 0)
            {
                return 1;
            }
            return 0;
        }

        int rem = sum % k;
        if (dp[r][c][rem] != -1) return dp[r][c][rem] % mod;
        return dp[r][c][rem] = (func(grid, dp, r + 1, c, sum, k) % mod + func(grid, dp, r, c + 1, sum, k) % mod) % mod;
    }
    int numberOfPaths(vector<vector < int>> &grid, int k)
    {

        vector<vector<vector< int>>> dp(grid.size(), vector<vector < int>> (grid[0].size(), vector<int> (k, -1)));
        return func(grid, dp, 0, 0, 0, k);
    }
};