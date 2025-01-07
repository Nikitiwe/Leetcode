class Solution {
public:
    int countTime(string s) {
        unordered_set<int> m;
        for (int k=0; k<3000; k++)
        {
            int t=k, sum=0;
            if (s[4]=='?') sum+=t%10;
            else sum+=s[4]-'0';
            t/=10;
            if (s[3]=='?'&&t%10<=5) sum+=(t%10)*10;
            else if (s[3]=='?'&&t%10>5) sum+=10000;
            else sum+=(s[3]-'0')*10;
            t/=10;
            if (s[1]=='?') sum+=(t%10)*60;
            else sum+=(s[1]-'0')*60;
            t/=10;
            if (s[0]=='?') sum+=(t%10)*600;
            else sum+=(s[0]-'0')*600;
            if (sum<1440) m.insert(sum);
        }
        return m.size();
    }
};