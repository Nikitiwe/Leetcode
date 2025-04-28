class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        vector<vector<int>> arr(b.size(), vector<int>());
        for (int i=0; i!=b.size(); i++)
        {
            long ri2 = (long)b[i][2] * b[i][2];
            for (int j=0; j!=b.size(); j++)
            {
                if (j != i)
                {
                    if ( ((long)b[i][0] - b[j][0])*((long)b[i][0] - b[j][0]) + ((long)b[i][1] - b[j][1])*((long)b[i][1] - b[j][1]) <= ri2 ) arr[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for (int i=0; i!=b.size(); i++)
        {
            int count = 1;
            vector<bool> isit(arr.size(), 1);
            queue<int> q;
            q.push(i);
            isit[i] = 0;
            while (q.size() > 0)
            {
                int id = q.front();
                q.pop();
                for (int j=0; j<arr[id].size(); j++)
                {
                    if (isit[arr[id][j]] == 1)
                    {
                        q.push(arr[id][j]);
                        isit[arr[id][j]] = 0;
                        count++;
                    }
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }
};