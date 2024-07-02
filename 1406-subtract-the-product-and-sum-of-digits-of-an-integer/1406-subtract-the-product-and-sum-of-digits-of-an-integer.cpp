class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod=1, sum=0, temp;
        while (n>0)
        {
            temp=n%10;
            prod=prod*temp;
            sum=sum+temp;
            n=n/10;
        }
        return prod-sum;
    }
};