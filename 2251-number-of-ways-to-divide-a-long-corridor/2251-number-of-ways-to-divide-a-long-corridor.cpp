class Solution {
public:
    int numberOfWays(string s) {
        int cp=0, temp, f;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='S') cp++;
        }
        if (cp%2==1||cp==0) return 0;
        cp=0;
        long long ans=1;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='S')
            {
                cp++;
                if (cp>1&&cp%2==0) temp=i;
                else if (cp>1&&cp%2==1)
                {
                    ans*=(i-temp);
                    ans%=1000000007;
                }
            }
        }
        return ans;
    }
};