class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum=0, one1=100000, two1=100001, one2=100000, two2=100001, delta1=100000, delta2=100001;
        for (int i=0; i!=nums.size(); i++)
        {
            sum+=nums[i];
            if (nums[i]%3==1)
            {
                if (one1>=one2) one1=min(one1, nums[i]);
                else one2=min(one2, nums[i]);
                delta1=min(delta1, min(one1, one2));
                delta2=min(delta2, one1+one2);
            }
            else if (nums[i]%3==2)
            {
                if (two1>=two2) two1=min(two1, nums[i]);
                else two2=min(two2, nums[i]);
                delta1=min(delta1, two1+two2);
                delta2=min(delta2, min(two1, two2));
            }
        }
        if (sum%3==0) return sum;
        else if (sum%3==1) return sum-delta1;
        else return sum-delta2;
    }
};