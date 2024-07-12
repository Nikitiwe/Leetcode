class Solution {
public:
    int countVowelPermutation(int n) {
        vector<long long> ans(5, 1), next(5, 0);
        for (int i=2; i<=n; i++)
        {
            next[0]=(ans[1]+ans[2]+ans[4])%1000000007;
            next[1]=(ans[0]+ans[2])%1000000007;
            next[2]=(ans[1]+ans[3])%1000000007;
            next[3]=(ans[2])%1000000007;
            next[4]=(ans[2]+ans[3])%1000000007;
            ans=next;
        }
        return (ans[0]+ans[1]+ans[2]+ans[3]+ans[4])%1000000007;
    }
};