class Solution {
public:
    
    // Disjoint set 
    vector<int> Rank;
    vector<int> Parent;
    
    int findParent(int u){
        
        if(u == Parent[u]){
            return u;
        }
        
        return Parent[u] = findParent(Parent[u]);
    }
    void Union(int u,int v){
        int U = findParent(u);
        int V = findParent(v);
        
        if(Rank[U] == Rank[V]){
            Parent[U] = V;
            Rank[V]++;
        }else if(Rank[U] > Rank[V]){
            Parent[V] = U;
        }else if(Rank[V] > Rank[U]){
            Parent[U] = V;
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 1001;
        Rank = vector<int>(n);
        Parent = vector<int>(n);
        for(int i = 0; i<n;i++){
            Parent[i] = i;
            Rank[i] = 1;
        }
        
        for(auto e : edges){
            if(findParent(e[0]) == findParent(e[1])){
                return {e[0],e[1]};
            }
            
            Union(e[0],e[1]);
        }
        return {-1,-1};
    }
};