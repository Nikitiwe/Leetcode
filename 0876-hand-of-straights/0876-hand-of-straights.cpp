class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int s) {
        if (nums.size()%s!=0) return 0;
        sort(nums.begin(), nums.end());
        int c=0;
        while(c<nums.size())
        {
            int b, i=0, l=1;
            for (i; i!=nums.size(); i++)
            {
                if (nums[i]>=0)
                {
                    b=nums[i];
                    nums[i]=-1;
                    break;
                }
            }
            while (l<s)
            {
                i++;
                if (i==nums.size()) return 0;
                if (nums[i]==b+l)
                {
                    l++;
                    nums[i]=-1;
                }
            }
            c+=s;
        }
        return 1;
    }
};