class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) return 1;
        if (n==1) return 10;
        vector<int> temp(n+1, 1);
        int ans=0;
        temp[1]=9;
        for (int i=2; i<=n; i++)
        {
            temp[i]=temp[i-1]*(11-i);
        }
        for (int i=0; i<=n; i++)
        {
            ans+=temp[i];
        }
        return ans;
    }
};