class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int t) {
        int c=0, a=0;
        for (int i=0; i!=nums.size(); i++) if (nums[i]<t) c++; else if (nums[i]==t) a++;
        vector<int> ans(a, 0);
        for (int i=0; i!=ans.size(); i++)
        {
            ans[i]=c;
            c++;
        }
        return ans;
    }
};