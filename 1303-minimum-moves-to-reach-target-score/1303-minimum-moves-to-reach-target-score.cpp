class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=-1;
        while (target>0)
        {
            if (target%2==1)
            {
                target--;
                ans++;
            }
            else
            {
                if (maxDoubles>0)
                {
                    maxDoubles--;
                    target/=2;
                    ans++;
                }
                else
                {
                    ans+=target;
                    target=0;
                }
            }
        }
        return ans;
    }
};