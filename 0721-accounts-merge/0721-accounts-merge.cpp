class Solution
{
    public:
        string find(string s, unordered_map<string, string> &p)
        {
            return p[s] == s ? s : find(p[s], p);
        }
    vector<vector < string>> accountsMerge(vector<vector < string>> &accounts)
    {
        unordered_map<string, string> owner;
        unordered_map<string, string> parent;
        unordered_map<string, set < string>> unions;

        for (int i = 0; i < accounts.size(); i++)
        {
            string o = accounts[i][0];

            for (int j = 1; j < accounts[i].size(); j++)
            {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }

        for (int i = 0; i < accounts.size(); i++)
        {
            string p = find(accounts[i][1], parent);
            for (int j = 2; j < accounts[i].size(); j++)
            {
                parent[find(accounts[i][j], parent)] = p;
            }
        }

        for (int i = 0; i < accounts.size(); i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
            }
        }

        vector<vector < string>> result;

        for (auto p: unions)
        {
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            result.push_back(emails);
        }

        return result;
    }
};