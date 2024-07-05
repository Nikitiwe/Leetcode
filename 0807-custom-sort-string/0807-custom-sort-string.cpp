class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> ans(26, 0);
        string a;
        for (int i=0; i!=s.size(); i++)
        {
            ans[s[i]-'a']++;
        }
        for (int i=0; i!=order.size(); i++)
        {
            for (int j=0; j!=ans[order[i]-'a']; j++)
            {
                a=a+order[i];
            }
            ans[order[i]-'a']=0;
        }
        for (int i=0; i!=26; i++)
        {
            for (int j=0; j!=ans[i]; j++)
            {
                a=a+(char)(i+'a');
            }
        }
        return a;
    }
};