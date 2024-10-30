class Solution {
public:
    int minStoneSum(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i=0; i!=k; i++)
        {
            int t=q.top();
            q.pop();
            t-=t/2;
            q.push(t);
        }
        int ans=0;
        while (q.size()>0)
        {
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};