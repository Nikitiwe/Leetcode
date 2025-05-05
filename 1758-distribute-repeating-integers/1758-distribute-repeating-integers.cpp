class Solution {
public:
    bool f(vector<int>& arr, vector<int>& q, int l)
    {
        if (l >= q.size()) return 1;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i] >= q[l])
            {
                arr[i] -= q[l];
                if (f(arr, q, l+1) == 1) return 1;
                arr[i] += q[l];
            }
        }
        return 0;
    }

    bool canDistribute(vector<int>& nums, vector<int>& q) {
        vector<int> arr(1000, 0);
        for (int i=0; i!=nums.size(); i++) arr[nums[i]-1]++;
        vector<int> res;
        for (int i=0; i!=arr.size(); i++) if (arr[i] > 0) res.push_back(arr[i]);
        /*sort(res.rbegin(), res.rend());*/
        sort(q.rbegin(), q.rend());
        return f(res, q, 0);
    }
};