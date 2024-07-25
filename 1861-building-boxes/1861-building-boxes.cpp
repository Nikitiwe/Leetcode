class Solution {
public:
    int minimumBoxes(int n) {
        long long ans=0, t=1;
        while (n-t*(t+1)/2>=0)
        {
            n-=t*(t+1)/2;
            ans+=t;
            t++;
        }
        t=0;
        while (n-t*(t+1)/2>0)
        {
            t++;
        }
        ans+=t;
        return ans;
    }
};