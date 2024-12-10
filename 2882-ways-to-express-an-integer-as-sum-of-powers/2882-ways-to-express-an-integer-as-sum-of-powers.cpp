class Solution {
public:
    int numberOfWays(int n, int xx) {
        vector<long> arr(n+1, 0), s;
        arr.back()=1;
        for (int i=1; i<=n; i++)
        {
            int x=xx;
            int a=i;
            while (x>1)
            {
                a*=i;
                x--;
            }
            if (a<=n) s.push_back(a);
            else break;
        }
        for (int j=0; j!=s.size(); j++)
        {
            for (int i=1; i<=n; i++)
            {
                if (i>=s[j])
                {
                    arr[i-s[j]]+=arr[i];
                    arr[i-s[j]]%=1000000007;
                }
            }
        }
        return arr[0];
    }
};