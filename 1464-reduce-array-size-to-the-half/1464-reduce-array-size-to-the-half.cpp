class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++) m[arr[i]]++;
        vector<int> nums;
        for (auto i=m.begin(); i!=m.end(); i++) nums.push_back(i->second);
        sort(nums.rbegin(), nums.rend());
        int t=0, n=arr.size()/2;
        for (int i=0; i!=nums.size(); i++)
        {
            t+=nums[i];
            if (t>=n) return i+1;
        }
        return -1;
    }
};