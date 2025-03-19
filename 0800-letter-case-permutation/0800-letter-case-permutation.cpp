class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int a = 0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z') a++;
        }
        vector<string> ans;
        int k = 1;
        while (a>0)
        {
            k*=2;
            a--;
        }
        for (int j=0; j<k; j++)
        {
            int t = j;
            string w;
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i]>='a' && s[i]<='z')
                {
                    int b = s[i] - 'a';
                    if (t%2==0) w += 'a' + b;
                    else w += 'A' + b;
                    t /=2;
                }
                else if (s[i]>='A' && s[i]<='Z')
                {
                    int b = s[i] - 'A';
                    if (t%2==0) w += 'a' + b;
                    else w += 'A' + b;
                    t /=2;
                }
                else w += s[i];
            }
            ans.push_back(w);
        }
        return ans;
    }
};