class Solution {
public:
    long long smallestNumber(long long num) {
        string s=to_string(num), ans;
        if (s=="0") return 0;
        vector arr(10, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!='-') arr[s[i]-'0']++;
        }
        if (s[0]=='-')
        {
            ans=+"-";
            for (int i=9; i>=0; i--)
            {
                while (arr[i]>0)
                {
                    ans+=to_string(i);
                    arr[i]--;
                }
            }
        }
        else
        {
            for (int i=1; i<=9; i++)
            {
                if (arr[i]>0)
                {
                    ans+=to_string(i);
                    arr[i]--;
                    break;
                }
            }
            for (int i=0; i<=9; i++)
            {
                while (arr[i]>0)
                {
                    ans+=to_string(i);
                    arr[i]--;
                }
            }
        }
        return stoll(ans);
    }
};