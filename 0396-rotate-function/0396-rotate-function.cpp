class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int sum=0, ans=0, temp=0;
        for (int i=nums.size()-1; i>=0; i--)
        {
            sum+=nums[i];
            temp+=sum;
        }
        temp-=sum;
        ans=temp;
        for (int i=nums.size()-1; i>=0; i--)
        {
            temp+=sum;
            temp-=nums[i]*nums.size();
            ans=max(ans, temp);
        }
        return ans;
    }
};