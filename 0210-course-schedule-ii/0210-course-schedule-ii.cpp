class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        
        vector<int> in(n,0);
        vector<int> topo;
        
        vector<vector<int>> graph(n);
        for(auto p : pre){
            graph[p[1]].push_back(p[0]);
            
            in[p[0]]++;
        }
        queue<int> qu;
        for(int i = 0; i < n; i++){
            if(in[i] == 0){
                qu.push(i);
            }
        }
        
        while(!qu.empty()){
            
            int top = qu.front();
            qu.pop();
            
            topo.push_back(top);
            for(auto n : graph[top]){
                in[n]--;
                if(in[n] == 0){
                    qu.push(n);
                }
            }
        }
        
        if(topo.size() == n)return topo;
        else return {};
    }
};