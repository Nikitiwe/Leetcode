class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum=0, c=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%6==0)
            {
                sum+=nums[i];
                c++;
            }
        }
        if (c!=0) return sum/c;
        else return 0;
    }
};