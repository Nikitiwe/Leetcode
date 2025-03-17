class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int l=0, r=q.size(), m, ans = q.size() + 1;
        while (l<=r)
        {
            m = (l+r)/2;
            bool isit = 1;
            for (int i=0; i!=nums.size(); i++)
            {
                vector<int> arr(nums[i]+1, 0);
                arr[nums[i]] = 1;
                for (int j=0; j<m; j++)
                {
                    if (q[j][0] <= i && q[j][1] >= i)
                    {
                        for (int k = 0; k <= nums[i] - q[j][2]; k++)
                        {
                            if (arr[k+q[j][2]] == 1) arr[k] = 1;
                        }
                        if (arr[0] == 1) break;
                    }
                }
                if (arr[0] == 0)
                {
                    isit = 0;
                    break;
                }
            }
            if (isit == 1)
            {
                ans = min(ans, m);
                r = m-1;
            }
            else l = m+1;
        }
        if (ans <= q.size()) return ans;
        else return -1;
    }
};