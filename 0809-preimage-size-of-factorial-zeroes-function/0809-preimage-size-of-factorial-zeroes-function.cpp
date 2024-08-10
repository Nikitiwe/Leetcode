class Solution {
public:
    int preimageSizeFZF(long k) {
        long n=k*4, ans=0, temp;
        temp=n;
        while (temp>0)
        {
            temp/=5;
            ans+=temp;
        }
        if (ans==k) return 5;
        n++;
        while (n%5!=0) n++;
        while (ans<k)
        {
            temp=n;
            while (temp%5==0)
            {
                ans++;
                temp/=5;
            }
            n+=5;
        }
        if (ans==k) return 5;
        else return 0;
    }
};