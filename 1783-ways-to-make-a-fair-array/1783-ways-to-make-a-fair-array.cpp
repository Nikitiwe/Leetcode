class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> so, se;
        int o=0, e=0, ans=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (i%2==0) {e+=nums[i]; se.push_back(e); so.push_back(o);}
            else {o+=nums[i]; so.push_back(o); se.push_back(e);}
        }
        if (so[nums.size()-1]-so[0]==se[nums.size()-1]-se[0]) ans++;
        for (int i=1; i!=nums.size(); i++)
        {
            if (so[nums.size()-1]-so[i]+se[i-1]==se[nums.size()-1]-se[i]+so[i-1]) ans++;
        }
        return ans;
    }
};