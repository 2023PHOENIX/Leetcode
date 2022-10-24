typedef long long ll;
class Solution {
public:
    ll getCost(vector<int> &nums,vector<int> &cost,int value){
        ll result = 0;
        for(int i = 0; i<nums.size();i++){
            result += 1L * abs(nums[i] - value) * cost[i];
        }
        
        return result;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int l = 1;
        int r = 1e7;
        ll res = getCost(nums,cost,1);
        
        
        while(l < r){
            int x = (l +  r)>>1;
            
            ll a = getCost(nums,cost,x);
            ll b = getCost(nums,cost,x + 1);
            res = min(a,b);
            if(a < b){
                r = x;
            }else{
                l = x + 1;
            }
        }
        
        
        return res;
    }
};