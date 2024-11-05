class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> m;
        int ma=0, ans=nums.size();
        for (int i=0; i!=nums.size(); i++)
        {
            m[nums[i]]++;
            ma=max(ma, m[nums[i]]);
        }
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            if (i->second==ma)
            {
                int l=0, r=nums.size()-1;
                while (nums[l]!=i->first) l++;
                while (nums[r]!=i->first) r--;
                ans=min(ans, r-l+1);
            }
        }
        return ans;
    }
};