class Solution {
public:
    int countAnagrams(string s) {
        s+=' ';
        long ans=1;
        int p=1000000007;
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]!=' ')
            {
                arr[s[i]-'a']++;
            }
            else
            {
                long a=1, m=1, d=1;
                for (int j=0; j!=26; j++)
                {
                    while (arr[j]>0)
                    {
                        a*=m;
                        a%=p;
                        m++;
                        d*=arr[j];
                        d%=p;
                        arr[j]--;
                    }
                }
                long t=1, pp=p-2;
                while (pp>0)
                {
                    if (pp%2==1)
                    {
                        t*=d;
                        t%=p;
                    }
                    d*=d;
                    d%=p;
                    pp/=2;
                }
                ans*=a;
                ans%=p;
                ans*=t;
                ans%=p;
            }
        }
        return ans;
    }
};