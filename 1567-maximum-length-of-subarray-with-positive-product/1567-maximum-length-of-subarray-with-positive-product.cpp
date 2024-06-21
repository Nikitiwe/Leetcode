class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]!=0) nums[i]=nums[i]/abs(nums[i]);
        }
        nums.push_back(0);
        vector<int> numspaired;
        int a=0;
        while (a<nums.size())
        {
            if (nums[a]!=1) {numspaired.push_back(nums[a]); a++;}
            else
            {
            int t=0;
            while ((a+t<nums.size())&&(nums[a+t]==1))
            {
                t++;
            }
            numspaired.push_back(t);
            a=a+t;
            }
        }        
        int ans=0;
        for (int i=0; i!=numspaired.size(); i++)
        {
            int count=0, locans=0, r=0;
            for (int k=i; numspaired[k]!=0; k++)
            {
                if (numspaired[k]==-1) {count++;}
            }
            if (count%2==0)
            {
                for (int k=i; numspaired[k]!=0; k++)
                {
                    locans=locans+abs(numspaired[k]);
                    r++;
                }
            }
            if (locans>ans) ans=locans;
            i=i+r;
            count=0, locans=0;
            for (int j=i; numspaired[j]!=0; j++)
            {
                if (numspaired[j]>=1) {locans=locans+numspaired[j];}
                else if (numspaired[j]==-1) {locans++; count++;}
                if ((count%2==0)&&(locans>ans)) ans=locans;
            }
        }
        return ans;
    }
};