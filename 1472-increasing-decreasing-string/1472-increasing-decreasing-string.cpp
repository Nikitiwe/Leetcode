class Solution {
public:
    string sortString(string s) {
        vector<int> arr(26, 0);
        string ans;
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        while (ans.size()<s.size())
        {
            for (int i=0; i!=26; i++)
            {
                if (arr[i]>0)
                {
                    ans+='a'+i;
                    arr[i]--;
                }
            }
            for (int i=25; i>=0; i--)
            {
                if (arr[i]>0)
                {
                    ans+='a'+i;
                    arr[i]--;
                }
            }
        }
        return ans;
    }
};