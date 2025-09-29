class Solution {
public:
    string majorityFrequencyGroup(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i] - 'a']++;
        }
        string ans = "";
        int k = 0;
        for (int i=s.size(); i>=1; i--)
        {
            string t = "";
            int kk = 0;
            for (int j=0; j<26; j++)
            {
                if (arr[j] == i)
                {
                    t += 'a'+j;
                    kk++;
                }
            }
            if (kk > k)
            {
                ans = t;
                k = kk;
            }
        }
        return ans;
    }
};