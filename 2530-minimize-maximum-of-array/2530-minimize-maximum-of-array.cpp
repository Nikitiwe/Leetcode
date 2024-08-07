class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        double ans=0, sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            ans=max(ans, ceil(sum/(i+1)));
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int temp, f=1;
        while (f==1)
        {
            for (int i=nums.size()-1; i>0; i--)
            {
                f=0;
                if (nums[i-1]<nums[i])
                {
                    f=1;
                    temp=(nums[i]-nums[i-1])/2;
                    nums[i-1]+=temp;
                    nums[i]-=temp;
                    if (nums[i-1]<nums[i])
                    {
                        nums[i-1]++;
                        nums[i]--;
                    }
                }
            }
        }
        return *max_element(nums.begin(), nums.end());
    }
};
*/