class Solution {
public:
    string minimizeStringValue(string s) {
        vector<int> arr(26, 0), a=arr;
        for (int i=0; i!=s.size(); i++) if (s[i]!='?') arr[s[i]-'a']++;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='?')
            {
                int t=0;
                for (int j=1; j!=26; j++)
                {
                    if (arr[j]<arr[t]) t=j;
                }
                arr[t]++;
                a[t]++;
            }
        }
        int l=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='?')
            {
                while (a[l]==0) l++;
                a[l]--;
                s[i]='a'+l;
            }
        }
        return s;
    }
};