class Solution {
public:
    int numPrimeArrangements(int n) {
        unordered_set<int> m({2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97});
        long ans=1, d=0, p=0;
        for (int i=1; i<=n; i++)
        {
            if (m.count(i)==0)
            {
                d++;
                ans*=d;
                ans%=1000000007;
            }
            else
            {
                p++;
                ans*=p;
                ans%=1000000007;
            }
        }
        return ans;
    }
};