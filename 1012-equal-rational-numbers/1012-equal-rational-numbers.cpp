class Solution {
public:
    bool isRationalEqual(string s, string t) {
        vector<int> a, b;
        int temp=0, des=0;
        for (int i=0; i<s.size(); i++)
        {
            while (s[i]!='.'&&i<s.size()) {temp=temp*10+s[i]-'0'; i++;}
            a.push_back(temp); temp=0;
            if (i==s.size()) break;
         //   if (i==s.size()-1&&s[i]=='.') break;
            i++;
            if (i==s.size()) break;
         //   if (i==s.size()-1&&s[i]=='.') break;
            while (s[i]!='('&&i<s.size()) {temp=temp*10+s[i]-'0'; des++; i++;}
            a.push_back(temp); a.push_back(des); temp=0; des=0;
            if (i==s.size()) break;
            i++;
            if (i==s.size()) break;
            while (s[i]!=')'&&i<s.size()) {temp=temp*10+s[i]-'0'; des++; i++;}
            a.push_back(temp); a.push_back(des); temp=0; des=0;
        }
        for (int i=0; i<t.size(); i++)
        {
            while (t[i]!='.'&&i<t.size()) {temp=temp*10+t[i]-'0'; i++;}
            b.push_back(temp); temp=0;
            if (i==t.size()) break;
         //   if (i==t.size()-1&&s[i]=='.') break;
            i++;
            if (i==t.size()) break;
         //   if (i==t.size()-1&&s[i]=='.') break;
            while (t[i]!='('&&i<t.size()) {temp=temp*10+t[i]-'0'; des++; i++;}
            b.push_back(temp); b.push_back(des); temp=0; des=0;
            if (i==t.size()) break;
            i++;
            if (i==t.size()) break;
            while (t[i]!=')'&&i<t.size()) {temp=temp*10+t[i]-'0'; des++; i++;}
            b.push_back(temp); b.push_back(des); temp=0; des=0;
        }
        long long x1, x2=1, y1, y2=1;
        x1=a[0]; y1=b[0];
        temp=1;
        if (a.size()>1)
        {
            for (int i=0; i!=a[2]; i++) {temp=temp*10;}
            a[2]=temp; temp=1;
            x1=x1*a[2]+a[1]; x2=a[2];
        }
        if (b.size()>1)
        {
            for (int i=0; i!=b[2]; i++) {temp=temp*10;}
            b[2]=temp; temp=1;
            y1=y1*b[2]+b[1]; y2=b[2];
        }
        if (a.size()>3)
        {
            for (int i=0; i!=a[4]; i++) {temp=temp*10;}
            a[4]=temp-1; temp=1;
            x1=x1*a[4]+a[3]; x2=x2*a[4];
        }
        if (b.size()>3)
        {
            for (int i=0; i!=b[4]; i++) {temp=temp*10;}
            b[4]=temp-1; temp=1;
            y1=y1*b[4]+b[3]; y2=y2*b[4];
        }
        if (x1*y2==x2*y1) return 1;
        else return 0;
    }
};