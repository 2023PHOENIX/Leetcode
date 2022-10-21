class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        long long badIndex = -1,lastMin = -1,lastMax = -1;
        long long ans = 0;
        for(int i = 0; i<nums.size();i++){
            if(nums[i] < minK || nums[i] > maxK)badIndex = i;
            
            if(nums[i] == minK)lastMin = i;
            if(nums[i] == maxK)lastMax = i;
            long long v = min(lastMin,lastMax) - badIndex;
            if(v > 0)ans += v;
        }
        
        return ans;
    }
};