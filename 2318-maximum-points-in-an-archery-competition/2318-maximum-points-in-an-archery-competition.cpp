class Solution {
public:
    vector<int> maximumBobPoints(int n, vector<int>& nums) {
        int a=2047, c=0;
        vector<int> ans(12, 0), zero=ans;
        for (int k=1; k<=a; k++)
        {
            int t=k, l=1, sum=0, score=0;
            vector<int> arr(12, 0);
            while (t>0)
            {
                arr[l]=t%2;
                t/=2;
                l++;
            }
            for (int i=1; i!=12; i++)
            {
                if (arr[i]==1)
                {
                    sum+=nums[i]+1;
                    score+=i;
                }
            }
            if (sum<=n&&score>c)
            {
                c=score;
                ans=zero;
                ans[0]=n-sum;
                for (int i=1; i!=12; i++) if (arr[i]==1) ans[i]=nums[i]+1;
            }
        }
        return ans;
    }
};