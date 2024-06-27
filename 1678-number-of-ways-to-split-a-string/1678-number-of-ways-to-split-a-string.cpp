class Solution {
public:
    int numWays(string s) {
        int count=0, sum;
        long l=0, r=0, l1=0, r1=0;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i]=='1') count++;
        }
        l=s.size();
        if (count==0) return ((l-2)*(l-1)/2)%1000000007;
        if (count%3!=0) return 0;
        else sum=count/3;
        int sum2=sum*2;
        count=0;
        int i=0;
        for (i; i!=s.size(); i++)
        {
            if (s[i]=='1')
            {
                count++;
                if (count==sum) l=i;
                else if (count==sum+1) l1=i;
                if (count==sum2) r=i;
                else if (count==sum2+1) r1=i;
            }
        }
        return ((r1-r)*(l1-l))%1000000007;
    }
};
