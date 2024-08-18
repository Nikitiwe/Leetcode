class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        string s;
        s=to_string(nums[0]);
        vector<vector<int>> arr(s.size(), vector<int> (10, 0));
        for (int i=0; i!=nums.size(); i++)
        {
            s=to_string(nums[i]);
            for (int j=0; j!=s.size(); j++)
            {
                arr[j][s[j]-'0']++;
            }
        }
        long long ans=0, n=nums.size();
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=0; j!=10; j++)
            {
                if (arr[i][j]>0) ans+=(n-arr[i][j])*arr[i][j];
            }
        }
        return ans/2;
    }
};