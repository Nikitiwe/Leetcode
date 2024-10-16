class Solution {
public:
    int distanceTraveled(int m, int a) {
        int c=0;
        while (m>0)
        {
            c++;
            m--;
            if (c%5==0&&a>0)
            {
                m++;
                a--;
            }
        }
        return c*10;
    }
};