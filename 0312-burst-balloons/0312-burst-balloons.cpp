class Solution {
public:
    int dp[301][301];
    int f(int i,int j,vector<int> &nums){
        if(i > j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = INT_MIN;
        for(int x = i ; x <=j ; x++){
            
            int cost = f(i,x - 1,nums) + f(x + 1,j,nums) + nums[x] * nums[i-1] * nums[j + 1];
            ans = max(cost,ans);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return f(1,nums.size() - 2,nums);
    }
};