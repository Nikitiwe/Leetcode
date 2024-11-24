class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& w) {
        unordered_set<string> m;
        for (int i=0; i!=s.size(); i++)
        {
            vector<int> arr(26, 0);
            for (int j=0; j!=s[i].size(); j++) arr[s[i][j]-'a']++;
            string t;
            for (int j=0; j!=26; j++)
            {
                if (arr[j]==1) t+='1';
                else t+='0';
            }
            m.insert(t);
        }
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            vector<int> arr(26, 0);
            for (int j=0; j!=w[i].size(); j++) arr[w[i][j]-'a']++;
            string t;
            for (int j=0; j!=26; j++)
            {
                if (arr[j]==1) t+='1';
                else t+='0';
            }
            for (int j=0; j!=26; j++)
            {
                if (t[j]=='1')
                {
                    t[j]='0';
                    if (m.count(t)>0)
                    {
                        ans++;
                        break;
                    }
                    else t[j]='1';
                }
            }
        }
        return ans;
    }
};