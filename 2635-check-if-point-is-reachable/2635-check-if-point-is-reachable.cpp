class Solution {
public:
    bool isReachable(int x, int y) {
        while (x % 2 == 0) x /= 2;
        while (y % 2 == 0) y /= 2;
        while (1)
        {
            if (x == 1 || y == 1) return 1;
            if (x % 3 == 0 && y % 3 == 0) return 0;
            if (x > y) x -= y;
            else y -= x;
            
            if (x <= 0 || y <= 0) return 0;
            while (x % 2 == 0) x /= 2;
            while (y % 2 == 0) y /= 2;
        }
        return 0;
    }
};