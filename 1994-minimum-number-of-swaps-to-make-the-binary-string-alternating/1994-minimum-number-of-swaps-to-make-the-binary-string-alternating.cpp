class Solution {
public:
    int minSwaps(string s) {
        int one=0, zero=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='1') one++;
            else zero++;
        }
        if (abs(one-zero)>1) return -1;
        int ans=0, ans1=0;;
        if (one>zero)
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (i%2==0&&s[i]=='0') ans++;
            }
            return ans;
        }
        else if (one<zero)
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (i%2==0&&s[i]=='1') ans++;
            }
            return ans;
        }
        else
        {
            for (int i=0; i!=s.size(); i++)
            {
                if (i%2==0&&s[i]=='1') ans++;
                if (i%2==0&&s[i]=='0') ans1++;
            }
        }
        return min(ans, ans1);
    }
};