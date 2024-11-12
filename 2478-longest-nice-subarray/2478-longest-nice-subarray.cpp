class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> arr(30, 0);
        int l=0, r=0, ans=1;
        int t=nums[r], k=0;
        while (t>0)
        {
            arr[k]+=t%2;
            k++;
            t/=2;
        }
        while (r<nums.size())
        {
            bool isit=1;
            for (int i=0; i!=arr.size(); i++) if (arr[i]>1)
            {
                isit=0;
                break;
            }
            if (isit==1)
            {
                ans=max(ans, r-l+1);
                if (ans==30) return ans;
                r++;
                if (r==nums.size()) break;
                int t=nums[r], k=0;
                while (t>0)
                {
                    arr[k]+=t%2;
                    k++;
                    t/=2;
                }
            }
            else
            {
                int t=nums[l], k=0;
                while (t>0)
                {
                    arr[k]-=t%2;
                    k++;
                    t/=2;
                }
                l++;
            }
        }
        return ans;
    }
};