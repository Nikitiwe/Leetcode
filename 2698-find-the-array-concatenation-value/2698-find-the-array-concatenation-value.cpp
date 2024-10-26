class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        for (int i=0; i<nums.size()/2; i++)
        {
            int t=0;
                string s=to_string(nums[i]);
                for (int j=0; j!=s.size(); j++)
                {
                    t*=10;
                    t+=s[j]-'0';
                }
                s=to_string(nums[nums.size()-1-i]);
                for (int j=0; j!=s.size(); j++)
                {
                    t*=10;
                    t+=s[j]-'0';
                }
            ans+=t;
        }
        if (nums.size()%2==1)
        {
            int t=0;
            string s=to_string(nums[nums.size()/2]);
            for (int j=0; j!=s.size(); j++)
            {
                t*=10;
                t+=s[j]-'0';
            }
            ans+=t;
        }
        return ans;
    }
};