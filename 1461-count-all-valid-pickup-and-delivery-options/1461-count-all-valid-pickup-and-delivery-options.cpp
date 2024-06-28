class Solution {
public:
    int countOrders(int n) {
        long long ans=1;
        int c=1;
        for (int i=1; i!=n; i++)
        {
            c=i*(2*i+1);
            ans=(ans*(c+2*i+1))%1000000007;
        }
        return ans;
    }
};