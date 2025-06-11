class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = -100000;
        for (int a = 0; a<=4; a++)
        {
            for (int b = 0; b<=4; b++)
            {
                if (a != b)
                {
                    priority_queue<tuple<int,int,int>> acbc, acbn, anbc, anbn;
                    int ca = 0, cb = 0;
                    vector<pair<int, int>> arr {{0,0}};
                    for (int i=0; i!=s.size(); i++)
                    {
                        if (s[i] - '0' == a) ca++;
                        else if (s[i] - '0' == b) cb++;

                        arr.push_back({ca, cb});
                        if (i >= k-1)
                        {
                            auto [x, y] = arr[i-k+1];
                            if (x % 2 == 0 && y % 2 == 0) acbc.push({-x+y, -x, -y});
                            else if (x % 2 == 0 && y % 2 == 1) acbn.push({-x+y, -x, -y});
                            else if (x % 2 == 1 && y % 2 == 0) anbc.push({-x+y, -x, -y});
                            else anbn.push({-x+y, -x, -y});
                        }

                        if (ca % 2 == 0 && cb % 2 == 0)
                        {
                            if (anbc.size() > 0)
                            {
                                auto [z, x, y] = anbc.top();
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else if (ca % 2 == 0 && cb % 2 == 1)
                        {
                            if (anbn.size() > 0)
                            {
                                auto [z, x, y] = anbn.top();
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else if (ca % 2 == 1 && cb % 2 == 0)
                        {
                            if (acbc.size() > 0)
                            {
                                auto [z, x, y] = acbc.top();
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else
                        {
                            if (acbn.size() > 0)
                            {
                                auto [z, x, y] = acbn.top();
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};