class Solution {
public:
    string greatestLetter(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a')
            {
                if (arr[s[i]-'a']%2==0) arr[s[i]-'a']++;
            }
            else arr[s[i]-'A']+=2;
        }
        for (int i=25; i>=0; i--)
        {
            if (arr[i]>2&&arr[i]%2==1)
            {
                string ans="A";
                ans[0]+=i;
                return ans;
            }
        }
        return "";
    }
};