class Solution {
public:
    int numDistinct(string s, string t) {
        if (t.size()>s.size()) return 0;
        vector<long long> prev(s.size(), 0), next(s.size(), 0), zero(s.size(), 0);
        long long temp;
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]==t[0]) prev[j]=1;
        }
        for (int i=1; i<t.size(); i++)
        {
            temp=0;
            for (int j=0; j<s.size(); j++)
            {
                if (s[j]==t[i]) next[j]=temp;
                if (s[j]==t[i-1]) temp+=prev[j];
                if (temp>2000000000) break; // ебать костыль
            }
            prev=next;
            next=zero;
        }
        temp=0;
        for (int j=0; j<s.size(); j++)
        {
            temp+=prev[j];
        }
        return temp;
    }
};