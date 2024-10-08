class Solution {
public:
    bool canReach(string s, int mi, int ma) {
        if (s[s.size()-1]=='1') return 0;
        int temp=1, n=s.size();
        s[0]='2';
        for (int i=0; i!=n; i++)
        {
            //if (s[i]=='2'&&n-1<=i+ma) return 1;
            if (s[i]=='2') for (int j=max(temp, i+mi); j<=min(n-1, i+ma); j++)
            {
                if (s[j]=='0')
                {
                    s[j]='2';
                }
                temp=j;
            }
        }
        if (s[n-1]=='2') return 1;
        else return 0;
    }
};