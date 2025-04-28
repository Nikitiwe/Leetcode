class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        vector<pair<int, int>> arr;
        for (int i=0; i!=nums.size(); i++)
        {
            arr.push_back({abs(x - nums[i]), nums[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int> ans(k, 0);
        for (int i=0; i!=ans.size(); i++) ans[i] = arr[i].second;
        sort(ans.begin(), ans.end());
        return ans;
    }
};