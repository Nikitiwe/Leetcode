class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        nums[nums.size()-1]+=k;
        int d=0;
        for (int i=nums.size()-1; i>=0; i--)
        {
            nums[i]+=d;
            if (nums[i]>9)
            {
                d=nums[i]/10;
                nums[i]%=10;
            }
            else d=0;
            if (d==0) break;
        }
        if (d>0)
        {
            vector<int> arr;
            while (d>0)
            {
                arr.push_back(d%10);
                d/=10;
            }
            reverse(arr.begin(), arr.end());
            for (int i=0; i!=nums.size(); i++) arr.push_back(nums[i]);
            return arr;
        }
        else return nums;
    }
};