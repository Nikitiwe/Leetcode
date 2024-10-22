class Solution {
public:
    int countOperations(int x, int y) {
        int ans=0;
        if (x<y) swap(x, y);
        while (x>0&&y>0)
        {
            ans+=x/y;
            x%=y;
            if (x>0)
            {
                ans+=y/x;
                y%=x;
            }
        }
        return ans;
    }
};