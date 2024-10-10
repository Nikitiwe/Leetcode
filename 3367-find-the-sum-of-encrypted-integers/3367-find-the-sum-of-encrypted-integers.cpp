class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum=0;
        for (int i=0; i!=nums.size(); i++)
        {
            string s=to_string(nums[i]);
            int t=0;
            for (int j=0; j!=s.size(); j++) t=max(t, s[j]-'0');
            for (int j=0; j!=s.size(); j++) s[j]='0'+t;
            t=stoi(s);
            sum+=t;
        }
        return sum;
    }
};