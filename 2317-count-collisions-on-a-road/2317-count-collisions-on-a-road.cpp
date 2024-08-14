class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0, tempr = 0;
        bool isleftstay = 0;
        for (int i = 0; i != directions.size(); i++)
        {
            if (directions[i]=='S')
            {
                isleftstay=1;
                ans+=tempr;
                tempr=0;
            }
            else if (directions[i]=='R') tempr++;
            else
            {
                if (isleftstay==1||tempr>0) {ans++; isleftstay=1;}
                ans+=tempr;
                tempr=0;
            }
        }
        return ans;
    }
};