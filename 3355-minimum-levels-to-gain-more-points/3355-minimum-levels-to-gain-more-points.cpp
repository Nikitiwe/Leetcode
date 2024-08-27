class Solution {
public:
    int minimumLevels(vector<int>& nums) {
        int sum=0, temp=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]==1) sum++;
            else sum--;
        }
        for (int i=0; i!=nums.size()-1; i++)
        {
            if (nums[i]==1) temp++;
            else temp--;
            if (temp>sum-temp) return i+1;
        }
        return -1;
    }
};