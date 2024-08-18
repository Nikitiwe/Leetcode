class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long ans, sum=0, temp=0, n=nums.size(), id=0, summ;
        for (int i=0; i!=n; i++) sum+=nums[i];
        ans=99999999999;
        summ=sum;
        for (int i=0; i<n-1; i++)
        {
            temp+=nums[i];
            sum-=nums[i];
            if (ans>abs(temp/(i+1)-sum/(n-i-1))) {ans=abs(temp/(i+1)-sum/(n-i-1)); id=i;}
            if (ans==0) return id;
        }
        if (ans>abs(0-summ/n)) id=n-1;
        return id;
    }
};