class Solution {
public:
    int longestSquareStreak(vector<int>& arr) {
        unordered_set<int> n(arr.begin(), arr.end());
        vector<int> nums;
        for (auto i=n.begin(); i!=n.end(); i++) nums.push_back(*i);
        sort(nums.begin(), nums.end());
        unordered_map<long, int> m;
        int ans=-1;
        for (int i=0; i!=nums.size(); i++)
        {
            long t=(long)nums[i]*nums[i];
            if (m.count(nums[i])>0) m[t]=m[nums[i]]+1;
            else m[t]=1;
            if (m[t]>1) ans=max(ans, m[t]);
            if (ans==5) return ans;
        }
        return ans;
    }
};