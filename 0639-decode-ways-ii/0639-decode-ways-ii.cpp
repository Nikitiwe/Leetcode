class Solution {
public:
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        vector<long> ans(s.size(), 0);
        if (s[0]=='*') ans[0]=9;
        else ans[0]=1;
        if (s.size()>1) {
        if (s[1]=='*')
        {
            ans[1]+=9*ans[0];
            if (s[0]=='*')
            {
                ans[1]+=15;
            }
            else
            {
                if (s[0]=='1') ans[1]+=9;
                else if (s[0]=='2') ans[1]+=6;
            }
        }
        else if (s[1]=='0')
        {
            if (s[0]=='*') ans[1]+=2;
            else if (s[0]<'3') ans[1]+=1;
        }
        else
        {
            ans[1]+=1*ans[0];
            if (s[0]=='*')
            {
                ans[1]+=1;
                if (s[1]<'7') ans[1]+=1;
            }
            else
            {
                if (10*(s[0]-'0')+s[1]-'0'<27) ans[1]+=1;
            }
        }

        for (int i=2; i<s.size(); i++)
        {
            if (s[i]=='0'&&s[i-1]=='0') return 0;
            if (s[i]=='*') // текущий *
            {
                ans[i]+=9*ans[i-1]; // тогда это +9вариантов на предыдущий ответ
                if (s[i-1]=='*') // предыдущий тоже *
                {
                    ans[i]+=15*ans[i-2];
                }
                else
                {
                    if (s[i-1]=='1') ans[i]+=9*ans[i-2];
                    else if (s[i-1]=='2') ans[i]+=6*ans[i-2];
                }
            }
            else if (s[i]=='0')
            {
                if (s[i-1]=='*') ans[i]+=2*ans[i-2];
                else if (s[i-1]<'3') ans[i]+=1*ans[i-2];
            }
            else
            {
                ans[i]+=1*ans[i-1];
                if (s[i-1]=='*')
                {
                    ans[i]+=1*ans[i-2];
                    if (s[i]<'7') ans[i]+=1*ans[i-2];
                }
                else
                {
                    if (s[i-1]!='0'&&10*(s[i-1]-'0')+s[i]-'0'<27) ans[i]+=1*ans[i-2];
                }
            }
            ans[i]%=1000000007;
        }
        }
        return ans[ans.size()-1];
    }
};