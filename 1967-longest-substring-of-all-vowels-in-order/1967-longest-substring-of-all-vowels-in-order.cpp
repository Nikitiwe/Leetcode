class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int f=0, ans=0, temp=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (f==0)
            {
                if (s[i]=='a') {temp++; f=1;}
                else {temp=0;}
            }
            else if (f==1)
            {
                if (s[i]=='a') temp++;
                else if (s[i]=='e') {temp++; f=2;}
                else if (s[i]=='a') {temp=1; f=1;}
                else {f=0; temp=0;}
            }
            else if (f==2)
            {
                if (s[i]=='e') temp++;
                else if (s[i]=='i') {temp++; f=3;}
                else if (s[i]=='a') {temp=1; f=1;}
                else {f=0; temp=0;}
            }
            else if (f==3)
            {
                if (s[i]=='i') temp++;
                else if (s[i]=='o') {temp++; f=4;}
                else if (s[i]=='a') {temp=1; f=1;}
                else {f=0; temp=0;}
            }
            else if (f==4)
            {
                if (s[i]=='o') temp++;
                else if (s[i]=='u') {temp++; f=5; ans=max(ans, temp);}
                else if (s[i]=='a') {temp=1; f=1;}
                else {f=0; temp=0;}
            }
            else if (f==5)
            {
                if (s[i]=='u') {temp++; ans=max(ans, temp);}
                else if (s[i]=='a') {temp=1; f=1;}
                else {f=0; temp=0;}
            }
        }
        return ans;
    }
};