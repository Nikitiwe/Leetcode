class Solution {
public:
    string reformatDate(string s) {
        string ans, m;
        ans+=s[s.size()-4];
        ans+=s[s.size()-3];
        ans+=s[s.size()-2];
        ans+=s[s.size()-1];
        ans+='-';
        m+=s[s.size()-8];
        m+=s[s.size()-7];
        m+=s[s.size()-6];
        if (m=="Jan") ans+="01";
        else if (m=="Feb") ans+="02";
        else if (m=="Mar") ans+="03";
        else if (m=="Apr") ans+="04";
        else if (m=="May") ans+="05";
        else if (m=="Jun") ans+="06";
        else if (m=="Jul") ans+="07";
        else if (m=="Aug") ans+="08";
        else if (m=="Sep") ans+="09";
        else if (m=="Oct") ans+="10";
        else if (m=="Nov") ans+="11";
        else ans+="12";
        ans+='-';
        if (s[1]>='0'&&s[1]<='9')
        {
            ans+=s[0];
            ans+=s[1];
        }
        else
        {
            ans+='0';
            ans+=s[0];
        }
        return ans;
    }
};