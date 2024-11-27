class Solution {
public:
    bool canAliceWin(int n) {
        int t=10;
        for (int i=0; i!=10; i++)
        {
            n-=t;
            if (n<0)
            {
                if (i%2==0) return 0;
                else return 1;
            }
            t--;
        }
        return -1;
    }
};