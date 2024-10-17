class Solution {
public:
    string sortSentence(string s) {
        string ans;
        for (int i=1; i<=9; i++)
        {
            for (int j=0; j!=s.size(); j++)
            {
                if (s[j]-'0'==i)
                {
                    int k=j;
                    while(k>0&&s[k]!=' ') k--;
                    if (k>0) k++;
                    while(s[k]!=i+'0')
                    {
                        ans+=s[k];
                        k++;
                    }
                    ans+=' ';
                    break;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};