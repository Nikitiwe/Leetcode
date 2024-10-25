class Solution {
public:
    int countCharacters(vector<string>& w, string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            vector<int> t(26, 0);
            for (int j=0; j!=w[i].size(); j++)
            {
                t[w[i][j]-'a']++;
            }
            bool isit=1;
            for (int j=0; j!=26; j++)
            {
                if (t[j]>arr[j])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1) ans+=w[i].size();
        }
        return ans;
    }
};