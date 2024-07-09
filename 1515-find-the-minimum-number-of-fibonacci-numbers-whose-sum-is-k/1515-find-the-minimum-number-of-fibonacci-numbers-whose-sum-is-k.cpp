class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib{1, 1};
        while(fib[fib.size()-1]<k)
        {
            fib.push_back(fib[fib.size()-1]+fib[fib.size()-2]);
        }
        int ans=0, m=fib.size()-1;
        while (k>0)
        {
            for (int i=m; i>0; i--)
            {
                if (fib[i]<=k)
                {
                    m=i;
                    k-=fib[i];
                    ans++;
                }
            }
        }
        return ans;
    }
};