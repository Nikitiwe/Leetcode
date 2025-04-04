class Solution {
public:
    long long mod = 1000000007;

    long long g(vector<int>& nums, queue<vector<int>> &q, vector<int>& ll, vector<int>& rr)
    {
        long long ans = 1, l = 0, r = 0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i] < nums[0])
            {
                l++;
                ll.push_back(nums[i]);
            }
            else
            {
                r++;
                rr.push_back(nums[i]);
            }
        }
        for (int i=1; i<=r+l; i++)
        {
            ans *= i;
            ans %= mod;
        }
        for (int i=1; i<=r; i++)
        {
            long long mn = 1;
            while ((mn) % i != 0) mn += mod;
            mn /= i;
            ans *= mn;
            ans %= mod;
        }
        for (int i=1; i<=l; i++)
        {
            long long mn = 1;
            while ((mn) % i != 0) mn += mod;
            mn /= i;
            ans *= mn;
            ans %= mod;
        }
        return ans;
    }

    long long f(vector<int>& nums, queue<vector<int>> &q)
    {
        long long ans = 1;
        q.push(nums);
        while (q.size() > 0)
        {
            vector<int> arr = q.front();
            vector<int> l, r;
            q.pop();
            ans *= g(arr, q, l, r);
            if (l.size() > 2) q.push(l);
            if (r.size() > 2) q.push(r);
            ans %= mod;
        }
        return ans;
    }

    int numOfWays(vector<int>& nums) {
        long long res = 1;
        queue<vector<int>> q;
        res = f(nums, q);
        res--;
        return res;
    }
}; // хз