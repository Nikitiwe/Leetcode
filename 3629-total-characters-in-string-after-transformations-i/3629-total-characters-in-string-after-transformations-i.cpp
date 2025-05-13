class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<long> arr(26, 0), next(26, 0), zero(26, 0);
        long mod = 1e9 + 7;
        for (int i=0; i!=s.size(); i++) arr[s[i] - 'a']++;
        for (int k = 1; k<=t; k++)
        {
            for (int i=0; i!=26; i++)
            {
                next[(i+1)%26] += arr[i];
                next[(i+1)%26] %= mod;
            }
            next[1] += arr[25];
            next[1] %= mod;
            arr = next;
            next = zero;
        }
        long ans = 0;
        for (int i=0; i!=26; i++)
        {
            ans += arr[i];
            ans %= mod;
        }
        return ans;
    }
};