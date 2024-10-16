class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int id1, idn;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==1) id1=i;
            if (nums[i]==nums.size()) idn=i;
        }
        if (id1<idn) return id1+nums.size()-idn-1;
        else return id1+nums.size()-idn-2;
    }
};