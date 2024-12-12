class Solution {
public:
    long long pickGifts(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans=0;
        for (int i=1; i<=k; i++)
        {
            int t=q.top();
            q.pop();
            t=sqrt(t);
            q.push(t);
        }
        for (int i=0; i!=nums.size(); i++)
        {
            ans+=q.top();
            q.pop();
        }
        return ans;
    }
};