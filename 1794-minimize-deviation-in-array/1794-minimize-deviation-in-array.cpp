class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> q;
        int mi = 1000000000;
        for (int i=0; i!=nums.size(); i++)
        {
            int t = nums[i];
            if (t%2 == 1) t *= 2;
            mi = min(mi, t);
            q.push(t);
        }
        int ans = q.top() - mi;
        while (q.top() %2 == 0)
        {
            int t = q.top();
            q.pop();
            t /= 2;
            q.push(t);
            mi = min(mi, t);
            ans = min(ans, q.top() - mi);
        }
        return ans;
    }
};