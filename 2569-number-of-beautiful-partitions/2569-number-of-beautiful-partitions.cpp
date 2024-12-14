class Solution {
public:
    int beautifulPartitions(string s, int kk, int l) {
        if (kk==1)
        {
            if (s.size()<l) return 0;
            if (s[0]!='2'&&s[0]!='3'&&s[0]!='5'&&s[0]!='7' ) return 0;
            if (s[s.size()-1]=='2'||s[s.size()-1]=='3'||s[s.size()-1]=='5'||s[s.size()-1]=='7') return 0;
            return 1;
        }
        if (s[0]!='2'&&s[0]!='3'&&s[0]!='5'&&s[0]!='7' ) return 0;
        if (s[s.size()-1]=='2'||s[s.size()-1]=='3'||s[s.size()-1]=='5'||s[s.size()-1]=='7') return 0;
        long mod=1000000007;
        vector<int> isit(s.size()-1, 0);
        vector<long> arr(s.size()-1, 0), next=arr, zero=arr;
        for (int i=0; i<s.size()-1; i++) if ( (s[i+1]=='2'||s[i+1]=='3'||s[i+1]=='5'||s[i+1]=='7')&&(s[i]!='2'&&s[i]!='3'&&s[i]!='5'&&s[i]!='7') )
        {
            if (i>=l-1&&s.size()>=l+1+i)
            {
                isit[i]=1;
                arr[i]=1;
            }
        }
        for (int k=2; k<kk; k++)
        {
            for (int i=s.size()-l-1; i>=0; i--)
            {
                if (isit[i]==1) for (int j=i-l; j>=0; j--)
                {
                    if (isit[j]==1)
                    {
                        next[i]+=arr[j];
                    }
                }
                next[i]%=mod;
            }
            arr=next;
            next=zero;
        }
        long ans=0;
        for (int i=0; i!=arr.size(); i++) ans+=arr[i];
        return ans%mod;
    }
};