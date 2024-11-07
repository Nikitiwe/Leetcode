class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i=0; i!=nums.size(); i++) m[nums[i]]++;
        int ans=0;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            int t=i->second;
            if (m.count(i->first+1)>0) ans=max(ans, t+m[i->first+1]);
            if (m.count(i->first-1)>0) ans=max(ans, t+m[i->first-1]);
        }
        return ans;
    }
};