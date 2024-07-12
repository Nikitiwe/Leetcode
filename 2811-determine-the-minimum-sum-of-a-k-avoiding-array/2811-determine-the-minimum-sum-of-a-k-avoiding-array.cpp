class Solution {
public:
    int minimumSum(int n, int k) {
        int sum=0;
        for (int i=1; i<=k/2; i++)
        {
            sum+=i;
            n--;
            if (n==0) return sum;
        }
        int i=k;
        while (1)
        {
            sum+=i;
            i++;
            n--;
            if (n==0) return sum;
        }
        return sum;
    }
};