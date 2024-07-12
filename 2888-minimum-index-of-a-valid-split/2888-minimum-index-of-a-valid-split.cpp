class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        vector<int> a=nums;
        sort(a.begin(), a.end());
        int d=a[nums.size()/2], count=0, j, i;
        for (i=0; i!=nums.size(); i++)
        {
            if (nums[i]==d) count++;
            if (count*2>i+1) break;
        }
        count=0;
        i++;
        for ( j=i; j!=nums.size(); j++)
        {
            if (nums[j]==d) count++;
        }
        if (count*2>nums.size()-i) return i-1;
        return -1;
    }
};