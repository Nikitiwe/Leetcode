class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int a3=max({a, b, c}), a1=min({a, b, c}), a2=a+b+c-a1-a3;
        int ans=0;
        while (a2+a1>1+a3)
        {
            a1--;
            a2--;
            ans++;
        }
        return ans+min(a3, a1+a2);
    }
};