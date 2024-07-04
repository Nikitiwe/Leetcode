class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> a, b, c;
        for (int i=0; i!=n; i++)
        { a.push_back(i); }
        b=a;
        c=a;
        int ans=0;
        while (1)
        {
            for (int i=0; i!=n; i++)
            {
                if (i%2==0) c[i]=b[i/2];
                else c[i]=b[(n+i-1)/2];
            }
            ans++;
            if (c==a) break;
            b=c;
        }
        return ans;
    }
};