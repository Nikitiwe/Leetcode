class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        vector<int> a, b;
        int cur;
        for (int i=2; i<=n-2; i++)
        {
            a.clear();
            b.clear();
            cur=n;
            while (cur>0)
            {
                a.push_back(cur%i);
                cur=cur/i;
            }
            b=a;
            reverse(b.begin(), b.end());
            if(a!=b) return 0;
        }
        return 1;
    }
};