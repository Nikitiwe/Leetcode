class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int ans = 1000000000;
        int m = 0, s = targetSeconds;
        while (s > 99)
        {
            m++;
            s -= 60;
        }
        {
            int c1 = m/10, c2 = m%10, c3 = s/10, c4 = s%10;
            int t = 0;
            int temp = startAt;
            bool isp = 0;
            if (c1>0)
            {
                isp = 1;
                if (temp != c1)
                {
                    t += moveCost + pushCost;
                    temp = c1;
                }
                else t += pushCost;
            }
            if (c2>0 || isp == 1)
            {
                isp = 1;
                if (temp != c2)
                {
                    t += moveCost + pushCost;
                    temp = c2;
                }
                else t += pushCost;
            }
            if (c3>0 || isp == 1)
            {
                isp = 1;
                if (temp != c3)
                {
                    t += moveCost + pushCost;
                    temp = c3;
                }
                else t += pushCost;
            }
            if (c4>0 || isp == 1)
            {
                isp = 1;
                if (temp != c4)
                {
                    t += moveCost + pushCost;
                    temp = c4;
                }
                else t += pushCost;
            }
            ans = min(ans, t);
        }
        if (s >= 60)
        {
            m++;
            s -= 60;
            if (m<=99)
            {
                int c1 = m/10, c2 = m%10, c3 = s/10, c4 = s%10;
                int t = 0;
                int temp = startAt;
                bool isp = 0;
                if (c1>0)
                {
                    isp = 1;
                    if (temp != c1)
                    {
                        t += moveCost + pushCost;
                        temp = c1;
                    }
                    else t += pushCost;
                }
                if (c2>0 || isp == 1)
                {
                    isp = 1;
                    if (temp != c2)
                    {
                        t += moveCost + pushCost;
                        temp = c2;
                    }
                    else t += pushCost;
                }
                if (c3>0 || isp == 1)
                {
                    isp = 1;
                    if (temp != c3)
                    {
                        t += moveCost + pushCost;
                        temp = c3;
                    }
                    else t += pushCost;
                }
                if (c4>0 || isp == 1)
                {
                    isp = 1;
                    if (temp != c4)
                    {
                        t += moveCost + pushCost;
                        temp = c4;
                    }
                    else t += pushCost;
                }
                ans = min(ans, t);
            }
        }
        return ans;
    }
};