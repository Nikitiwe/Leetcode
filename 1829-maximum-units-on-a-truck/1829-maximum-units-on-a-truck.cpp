class Solution {
public:
    int maximumUnits(vector<vector<int>>& b, int t) {
        priority_queue<int> q;
        for (int i=0; i!=b.size(); i++)
        {
            for (int j=0; j!=b[i][0]; j++) q.push(b[i][1]);
        }
        int ans=0;
        while (t>0&&q.size()>0)
        {
            ans+=q.top();
            q.pop();
            t--;
        }
        return ans;
    }
};