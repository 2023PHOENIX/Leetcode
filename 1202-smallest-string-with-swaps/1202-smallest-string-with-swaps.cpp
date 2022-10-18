class Solution
{
    public:

        int find(int u, vector<int> &ds)
        {
            return ds[u] < 0 ? u : ds[u] = find(ds[u],ds);
        }

    string smallestStringWithSwaps(string s, vector<vector < int>> &pairs)
    {

        vector<int> ds(s.length(), -1);
        vector<vector < int>> m(s.length());

        for (auto &a: pairs)
        {

            int x = find(a[0], ds), y = find(a[1], ds);

            if (x != y)
            {
                ds[y] = x;	// y parent -> x
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            m[find(i, ds)].push_back(i);
        }

        for (auto &p: m)
        {

            string ss = "";

            for (auto c: p)
            {
                ss += s[c];
            }

            sort(ss.begin(), ss.end());

            for (int i = 0; i < p.size(); i++)
            {
                s[p[i]] = ss[i];
            }
        }
        return s;
    }
};