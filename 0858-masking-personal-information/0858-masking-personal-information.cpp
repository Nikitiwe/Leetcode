class Solution {
public:
    string maskPII(string s) {
        string ans, temp;
        int a;
        if ((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z'))
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i]=='@') a=i;
                if (s[i]>='A'&&s[i]<='Z') temp+=s[i]-'A'+'a';
                else temp+=s[i];
            }
            ans+=temp[0];
            ans+="*****";
            ans+=temp[a-1];
            for (int i=a; i!=s.size(); i++)
            {
                ans+=temp[i];
            }
        }
        else
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i]>='0'&&s[i]<='9') temp+=s[i];
            }
            if (temp.size()==10) return ans+"***-***-"+temp[6]+temp[7]+temp[8]+temp[9];
            else if (temp.size()==11) return ans+"+*-***-***-"+temp[7]+temp[8]+temp[9]+temp[10];
            else if (temp.size()==12) return ans+"+**-***-***-"+temp[8]+temp[9]+temp[10]+temp[11];
            else return ans+"+***-***-***-"+temp[9]+temp[10]+temp[11]+temp[12];
        }
        return ans;
    }
};