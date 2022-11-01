class Solution
{
    public:
        bool canFinish(int n, vector<vector < int>> &pre)
        {
            vector<int> in (n, 0);
            vector<vector < int>> graph(n);

            for(auto p : pre){
                graph[p[1]].push_back(p[0]);
                in[p[0]]++;
            }
            queue<int> qu;
            for (int i = 0; i < n; i++)
            {
                if (in[i] == 0) qu.push(i);
            }
            vector<int> topo;
            while (!qu.empty())
            {

                int top = qu.front();
                qu.pop();
                topo.push_back(top);
                for (auto nbr: graph[top])
                {
                    in[nbr]--;
                    if (in[nbr] == 0)
                    {
                        qu.push(nbr);
                    }
                }
            }

            return topo.size() == n;
        }
};