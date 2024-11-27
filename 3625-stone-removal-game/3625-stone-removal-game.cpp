class Solution {
public:
    bool canAliceWin(int n) {
        int t=10;
        for (int i=0; i!=10; i++)
        {
            n-=t;
            if (n<0) return i%2;
            t--;
        }
        return -1;
    }
};