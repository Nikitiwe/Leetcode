class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> ans(q.size(), -1);
        priority_queue<int> arr;
        for (int i=0; i!=q.size(); i++)
        {
            int t = abs(q[i][0]) + abs(q[i][1]);
            if (i < k) arr.push(t);
            if (arr.size() == k)
            {
                if (i >= k && arr.top() > t)
                {
                    arr.pop();
                    arr.push(t);
                }
                ans[i] = arr.top();
            }
        }
        return ans;
    }
};