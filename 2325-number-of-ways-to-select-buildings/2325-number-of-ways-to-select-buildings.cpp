class Solution {
public:
    long long numberOfWays(string s) {
        vector<long long> zero(s.size()+1, 0), one(s.size()+1, 0);
        long long ans=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='0')
            {
                zero[i+1]=zero[i]+1;
                one[i+1]=one[i];
            }
            else
            {
                one[i+1]=one[i]+1;
                zero[i+1]=zero[i];
            }
        }
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i]=='0') ans+=(one[i]*(one[s.size()]-one[i]));
            else ans+=(zero[i]*(zero[s.size()]-zero[i]));
        }
        return ans;
    }
};