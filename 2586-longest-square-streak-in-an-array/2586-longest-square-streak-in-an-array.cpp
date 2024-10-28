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
            if (m.count(nums[i])>0) m[(long)nums[i]*nums[i]]=m[nums[i]]+1;
            else m[(long)nums[i]*nums[i]]=1;
            if (m[(long)nums[i]*nums[i]]>1) ans=max(ans, m[(long)nums[i]*nums[i]]);
            if (ans==5) return ans;
        }
        return ans;
    }
};