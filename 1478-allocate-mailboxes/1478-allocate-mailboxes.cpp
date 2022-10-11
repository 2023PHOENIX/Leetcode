class Solution {
public:
    int dp[101][101];
    int dfs(vector<int> &houses,int index,int k){

        if(index == houses.size())return 0;

        if(k == 0)return (int)1e9;
        
        if(dp[index][k] != -1)return dp[index][k];

        int ans = INT_MAX;
        for(int i = index;i<houses.size();i++){
            
            int median = houses[(index + i)/2];

            int cost = 0;

            for(int j = index;j<=i;j++){
                cost += abs(median - houses[j]);
            }

            ans = min(ans,cost + dfs(houses,i + 1,k - 1));
        }
        return dp[index][k] = ans;
    }
    int minDistance(vector<int>& houses, int k) {
        sort(houses.begin(),houses.end());
        memset(dp,-1,sizeof(dp));
        return dfs(houses,0,k);
    }
};