class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int r=nums.size()-1, l=r-1, ans=0, ans1=0;
        vector<bool> up(nums.size(), 0), down=up;
        sort(nums.begin(), nums.end());
        while (l>=0)
        {
            if (nums[l]*2<=nums[r])
            {
                up[r]=1;
                down[l]=1;
                r--;
                l--;
            }
            else l--;
        }
        int t=nums.size()-1;
        for (int i=nums.size()-1; i>=0; i--)
        {
            t=min(i-1, t);
            if (up[i]==1&&down[i]==1)
            {
                while (t>=0)
                {
                    if (down[t]==0)
                    {
                        down[t]=1;
                        down[i]=0;
                        break;
                    }
                    t--;
                }
            }
        }
        for (int i=0; i!=nums.size(); i++)
        {
            if (up[i]==1&&down[i]==0) ans++;
            if (up[i]==0&&down[i]==1) ans1++;
        }
        for (int i=0; i!=nums.size(); i++)
        {
            if (up[i]==1&&down[i]==1) {if (ans<ans1) ans++; else ans1++;}
        }
        ans=min(ans, ans1);
        return 2*ans;
    }
};