class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        vector<int> ans(q.size(), 0), arr(m, 0);
        for (int i=0; i<m; i++) arr[i] = i+1;
        for (int i=0; i!=q.size(); i++)
        {
            int k = q[i], t = arr[0];
            if (arr[0] == k)
            {
                ans[i] = 0;
            }
            else
            {
                arr[0] = k;
                for (int j=1; j<m; j++)
                {
                    int a = arr[j];
                    arr[j] = t;
                    t = a;
                    if (t == k)
                    {
                        ans[i] = j;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};