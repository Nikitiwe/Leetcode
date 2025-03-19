class Solution {
public:
    int reachNumber(int t) {
        if (t<0) t*=-1;
        int a=0, sum = 0;
        while (sum < t)
        {
            a++;
            sum += a;
        }
        while ((sum-t)%2 == 1)
        {
            a++;
            sum += a;
        }
        return a;
    }
};