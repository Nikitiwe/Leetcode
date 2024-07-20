class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long ans=0, m=100000;
        while (ans<m-1)
        {
            if (2*ans*(ans+1)*(2*ans+1)<neededApples) ans=(ans+m)/2;
            else if (2*ans*(ans+1)*(2*ans+1)>neededApples) {m=ans; ans/=2;}
            else break;
        }
        if (2*ans*(ans+1)*(2*ans+1)<neededApples) ans++;
        return 8*ans;
    }
};

