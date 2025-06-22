class Solution {
public:
    vector<int> findCoins(vector<int>& nums) {
        vector<int> arr;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i] > 1) return arr;
            else if (nums[i] == 1)
            {
                arr.push_back(i+1);
                break;
            }
        }
        while (1)
        {
            vector<int> t(nums.size(), 0);
            for (int j=0; j<arr.size(); j++)
            {
                t[arr[j]-1]++;
                for (int i=0; i<t.size(); i++)
                {
                    if (i + arr[j] < t.size()) t[i + arr[j]] += t[i];
                }
            }
            if (t == nums) return arr;
            for (int i=0; i!=nums.size(); i++)
            {
                if (nums[i] - t[i] > 1 || nums[i] - t[i] < 0) return {};
                else if (nums[i] - t[i] == 1)
                {
                    arr.push_back(i+1);
                    break;
                }
            }
        }
        return arr;
    }
};