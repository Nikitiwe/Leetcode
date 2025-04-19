class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int k) {
        vector<vector<int>> arr(nums.size(), vector<int>(2, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        sort(arr.begin(), arr.end());
        vector<vector<int>> d;
        int l = arr[0][0];
        vector<int> t;
        for (int i=0; i<arr.size(); i++)
        {
            if ( arr[i][0] <= l + k )
            {
                t.push_back(arr[i][1]);
                l = arr[i][0];
            }
            else
            {
                if (t.size() > 0)
                {
                    d.push_back(t);
                    t.clear();
                }
                t.push_back(arr[i][1]);
                l = arr[i][0];
            }
            if (i == arr.size() - 1) d.push_back(t);
        }
        for (int i = 0; i<d.size(); i++)
        {
            vector<int> t(d[i].size(), 0);
            sort(d[i].begin(), d[i].end());
            for (int j=0; j!=d[i].size(); j++)
            {
                t[j] = nums[d[i][j]];
            }
            sort(t.begin(), t.end());
            for (int j=0; j!=d[i].size(); j++)
            {
                nums[d[i][j]] = t[j];
            }
        }
        return nums;
    }
};