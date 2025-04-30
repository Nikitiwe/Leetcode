class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long> q;
        for (int i=0; i!=nums.size(); i++) q.push(-nums[i]);
        int ans = 0;
        while (q.top() > -k)
        {
            long a = -q.top(); q.pop();
            long b = -q.top(); q.pop();
            q.push( -(min(a, b)*2 + max(a, b)) );
            ans++;
        }
        return ans;
    }
};