class Solution {
public:
    int dayOfYear(string s) {
        int d=0, m=0, y=0;
        y+=s[0]-'0';
        y*=10;
        y+=s[1]-'0';
        y*=10;
        y+=s[2]-'0';
        y*=10;
        y+=s[3]-'0';
        d+=s[8]-'0';
        d*=10;
        d+=s[9]-'0';
        m+=s[5]-'0';
        m*=10;
        m+=s[6]-'0';
        if (m==1) return d;
        if (m>=2) d+=31;
        if (m>=3) d+=28;
        if (m>=4) d+=31;
        if (m>=5) d+=30;
        if (m>=6) d+=31;
        if (m>=7) d+=30;
        if (m>=8) d+=31;
        if (m>=9) d+=31;
        if (m>=10) d+=30;
        if (m>=11) d+=31;
        if (m>=12) d+=30;
        if ((y%4==0&&y>1900)&&m>2) return d+1;
        else return d;
    }
};