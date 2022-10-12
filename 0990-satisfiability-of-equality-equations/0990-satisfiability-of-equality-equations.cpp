class Solution {
public:
    vector<int> link;
    vector<int> size;
    int find(int u){
        while(u != link[u])u = link[u];
        
        return u;
    }
    bool unite(int a,int b){
        a = find(a);
        b = find(b);
        
        if(a == b)return false;
        
        if(size[a] > size[b]){
            link[b] = a;
        }else if(size[b] > size[a]){
            link[a] = b;
        }else{
            link[a] = b;
            size[b]++;
        }
        return true;
    }
    bool equationsPossible(vector<string>& equations) {
        
        link = size = vector<int>(26);
        for(int i = 0; i < 26;i++){
            link[i] = i;
            size[i] = 1;
        }
        for(auto e : equations){
            
            if(e[1] == '='){
                unite(e[0] - 'a',e[3] - 'a');
            }
        }
        
        for(auto e : equations){
            if(e[1] == '!' and find(e[0] - 'a') == find(e[3] - 'a')){
                return false;
            }
        }
       
        return true;
    }
};