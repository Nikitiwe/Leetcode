class Solution {
public:
    int countTestedDevices(vector<int>& nums) {
        int decr=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]>decr)
            {
                decr++;
            }
        }
        return decr;
    }
};