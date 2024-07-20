class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ans=0;
        while (2*ans*(ans+1)*(2*ans+1)<neededApples)
        {
            ans++;
        }
        return 8*ans;
    }
};