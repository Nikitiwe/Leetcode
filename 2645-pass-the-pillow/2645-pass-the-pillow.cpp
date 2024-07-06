class Solution {
public:
    int passThePillow(int n, int time) {
        time=time%(n+n-2);
        return min(time+1, n+n-1-time);
    }
};