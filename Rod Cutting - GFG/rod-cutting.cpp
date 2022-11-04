//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  
    unordered_map<int,int> cost;
    int dp[1001];
    int rodCutting(int n){
    
        if(dp[n] != -1)return dp[n];
    	int maxValue = 0;
    	for(int i = 1; i <= n; i++){
    		maxValue = max(maxValue,cost[i] + rodCutting(n - i));
    	}
    
    	return dp[n] = maxValue;
    }
    int cutRod(int price[], int n) {
        
        for(int i = 0; i < n; i++){
            cost[i + 1] = price[i];
        }
        
        memset(dp,-1,sizeof(dp));
        return rodCutting(n);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends