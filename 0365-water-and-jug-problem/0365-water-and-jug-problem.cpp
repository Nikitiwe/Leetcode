class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if (gcd(x, y)>1&&target%gcd(x, y)!=0) return 0;
        if (x<y) swap(x, y);
        if (y==1&&target<=x+1) return 1;
        int ty=0;
        for (int i=0; i!=(x+1)*(y+1); i++)
        {
            ty=(x%y+ty)%y;
            if (ty==target||ty+x==target||ty+y==target) return 1;
        }
        ty=0;
        for (int i=0; i!=(x+1)*(y+1); i++)
        {
            ty=(y+ty)%x;
            if (ty==target||ty+y==target) return 1;
        }
        return 0;
    }
};