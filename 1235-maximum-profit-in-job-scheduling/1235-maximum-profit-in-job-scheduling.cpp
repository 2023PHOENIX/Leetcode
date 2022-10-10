class Solution
{
    public:

        int bSearch(vector<vector < int>> &job, int i)
        {

            int lo = 0;
            int hi = i - 1;
            int ans = -1;
            while (lo <= hi)
            {
                int m = lo + (hi - lo) / 2;

                if (job[m][1] > job[i][0])
                {
                    hi = m - 1;
                }
                else
                {
                    ans = m;
                    lo = m + 1;
                }
            }

            return ans;
        }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector< int > &profit)
    {

        vector<vector < int>> jobs(profit.size());

        vector<int> dp(profit.size(), 0);

        for (int i = 0; i < jobs.size(); i++)
        {
            jobs[i] = { startTime[i],
                endTime[i],
                profit[i]
            };
        }
        sort(jobs.begin(), jobs.end(), [& ](vector<int> a, vector<int> b)
        {
            return a[1] < b[1];
	});
        dp[0] = jobs[0][2];	// for first value

        for (int i = 1; i < profit.size(); i++)
        {

            int ix = bSearch(jobs, i);
            int include = jobs[i][2];
           	//choose 
            if (ix != -1)
            {
                include += dp[ix];
            }

            dp[i] = max(dp[i - 1], include);
        }
        return dp[profit.size() - 1];
    }
};