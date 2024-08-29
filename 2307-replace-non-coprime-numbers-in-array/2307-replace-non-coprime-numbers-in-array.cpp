class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        while (1) {
        ans.clear();
        long temp=nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            if (temp!=1)
            {
                if (nums[i]==1)
                {
                    ans.push_back(temp);
                    temp=1;
                }
                else if (temp%nums[i]==0) continue;
                else if (nums[i]%temp==0) temp=nums[i];
                else
                {
                    int t=gcd(temp, nums[i]);
                    if (t>1)
                    {
                        temp*=nums[i];
                        temp/=t;
                    }
                    else
                    {
                        ans.push_back(temp);
                        temp=nums[i];
                    }
                }
            }
            else
            {
                ans.push_back(temp);
                temp=nums[i];
            }
        }
        ans.push_back(temp);
        if (ans.size()==nums.size()) break;
        nums=ans;

        ans.clear();
        reverse(nums.begin(), nums.end());
        temp=nums[0];
        for (int i=1; i<nums.size(); i++)
        {
            if (temp!=1)
            {
                if (nums[i]==1)
                {
                    ans.push_back(temp);
                    temp=1;
                }
                else if (temp%nums[i]==0) continue;
                else if (nums[i]%temp==0) temp=nums[i];
                else
                {
                    int t=gcd(temp, nums[i]);
                    if (t>1)
                    {
                        temp*=nums[i];
                        temp/=t;
                    }
                    else
                    {
                        ans.push_back(temp);
                        temp=nums[i];
                    }
                }
            }
            else
            {
                ans.push_back(temp);
                temp=nums[i];
            }
        }
        ans.push_back(temp);
        reverse(ans.begin(), ans.end());
        if (ans.size()==nums.size()) break;
        nums=ans;
        }
        return ans;
    }
};