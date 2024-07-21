class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        vector<int> s(nums.size(), 0);
        long long ans=0;
        int dp=0, dm=0;
        for (int i=0; i!=nums.size(); i++)
        {
            s[i]=target[i]-nums[i];
        }
        int m=0, n=0, znak=0;
        for (int i=0; i!=nums.size(); i++)
        {
            if (s[i]==0)
            {
                ans+=m;
                ans+=abs(n);
                m=0;
                n=0;
                znak=0;
            }

            else if (s[i]>0&&znak>=0)
            {
                znak=1;
                if (s[i]>=m) m=s[i];
                else {ans+=(m-s[i]); m=s[i];}
            }

            else if (s[i]<0&&znak<=0)
            {
                znak=-1;
                if (s[i]<=n) n=s[i];
                else {ans+=(abs(n-s[i])); n=s[i];}
            }

            else if (s[i]<0&&znak>0)
            {
                ans+=m;
                m=0;
                znak=-1;
                n=s[i];
            }

            else if (s[i]>0&&znak<0)
            {
                ans+=abs(n);
                n=0;
                znak=1;
                m=s[i];
            }
        }
        ans+=m;
        ans+=abs(n);
        return ans;
    }
};