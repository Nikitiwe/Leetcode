class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& nums, string s) {
        vector<priority_queue<int>> m(26, priority_queue<int> ());
        for (int i=0; i!=s.size(); i++)
        {
            int t=-(max(abs(nums[i][0]), abs(nums[i][1])));
            m[s[i]-'a'].push(t);
        }
        int ans=0, g=-2000000000;
        for (int i=0; i!=26; i++)
        {
            if (m[i].size()>1)
            {
                int a=m[i].top();
                m[i].pop();
                int b=m[i].top();
                g=max(b+1, g);
                m[i].push(a);
            }
        }
        for (int i=0; i!=26; i++)
        {
            if (m[i].size()>0&&m[i].top()>=g) ans++;
        }
        return ans;
    }
};