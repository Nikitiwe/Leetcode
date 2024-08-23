class Solution {
public:
    int countHousePlacements(int n) {
        long long ans=2, ans1=1, temp;
        for (int i=1; i<n; i++)
        {
            temp=ans;
            ans+=ans1;
            ans%=1000000007;
            ans1=temp;
        }
        return (ans*ans)%1000000007;
    }
};