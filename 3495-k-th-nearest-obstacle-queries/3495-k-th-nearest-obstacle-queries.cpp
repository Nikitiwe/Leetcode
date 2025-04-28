class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& q, int k) {
        vector<int> ans(q.size(), -1);
        if (k > ans.size()) return ans;
        priority_queue<int> arr;
        for (int i=0; i<k; i++)
        {
            int t = abs(q[i][0]) + abs(q[i][1]);
            arr.push(t);
        }
        if (k-1 < ans.size()) ans[k-1] = arr.top();
        for (int i=k; i<q.size(); i++)
        {
            int t = abs(q[i][0]) + abs(q[i][1]);
            if (arr.top() > t)
            {
                arr.pop();
                arr.push(t);
            }
            ans[i] = arr.top();
        }
        return ans;
    }
};