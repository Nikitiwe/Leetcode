class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++) m[arr[i]]++;
        vector<int> nums;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            nums.push_back(i->second);
        }
        sort(nums.begin(), nums.end());
        int sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            if (sum>k) return nums.size()-i;
        }
        return 0;
    }
};