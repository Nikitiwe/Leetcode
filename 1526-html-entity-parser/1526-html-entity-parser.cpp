class Solution {
public:
    string entityParser(string s) {
        string ans;
        int i=0;
        while (i<s.size())
        {
            if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='q'&&i+2<s.size()&&s[i+2]=='u'&&i+3<s.size()&&s[i+3]=='o'&&i+4<s.size()&&s[i+4]=='t'&&i+5<s.size()&&s[i+5]==';')
            {ans+='"'; i=i+6;}
            else if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='a'&&i+2<s.size()&&s[i+2]=='p'&&i+3<s.size()&&s[i+3]=='o'&&i+4<s.size()&&s[i+4]=='s'&&i+5<s.size()&&s[i+5]==';')
            {ans+="'"; i=i+6;}
            else if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='a'&&i+2<s.size()&&s[i+2]=='m'&&i+3<s.size()&&s[i+3]=='p'&&i+4<s.size()&&s[i+4]==';')
            {ans+="&"; i=i+5;}
            else if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='f'&&i+2<s.size()&&s[i+2]=='r'&&i+3<s.size()&&s[i+3]=='a'&&i+4<s.size()&&s[i+4]=='s'&&i+5<s.size()&&s[i+5]=='l'&&i+6<s.size()&&s[i+6]==';') {ans+="/"; i=i+7;}
            else if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='g'&&i+2<s.size()&&s[i+2]=='t'&&i+3<s.size()&&s[i+3]==';')
            {ans+=">"; i=i+4;}
            else if (s[i]=='&'&&i+1<s.size()&&s[i+1]=='l'&&i+2<s.size()&&s[i+2]=='t'&&i+3<s.size()&&s[i+3]==';')
            {ans+="<"; i=i+4;}
            else {ans+=s[i]; i++;}
        }
        return ans;
    }
};