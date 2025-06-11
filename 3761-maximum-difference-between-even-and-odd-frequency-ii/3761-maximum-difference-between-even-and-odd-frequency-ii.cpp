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
                    tuple<int,int,int> acbc{-1,-1,-1}, acbn{-1,-1,-1}, anbc{-1,-1,-1}, anbn{-1,-1,-1};
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
                            tuple<int,int,int> t{-x+y, -x, -y};
                            if (x % 2 == 0 && y % 2 == 0)
                            {
                                acbc = max(acbc, t);
                            }
                            else if (x % 2 == 0 && y % 2 == 1)
                            {
                                acbn = max(acbn, t);
                            }
                            else if (x % 2 == 1 && y % 2 == 0)
                            {
                                anbc = max(anbc, t);
                            }
                            else
                            {
                                anbn = max(anbn, t);
                            }
                        }

                        if (ca % 2 == 0 && cb % 2 == 0)
                        {
                            if (anbc != tuple<int, int, int>{-1, -1, -1})
                            {
                                auto [z, x, y] = anbc;
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else if (ca % 2 == 0 && cb % 2 == 1)
                        {
                            if (anbn != tuple<int, int, int>{-1, -1, -1})
                            {
                                auto [z, x, y] = anbn;
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else if (ca % 2 == 1 && cb % 2 == 0)
                        {
                            if (acbc != tuple<int, int, int>{-1, -1, -1})
                            {
                                auto [z, x, y] = acbc;
                                if (ca + x > 0 && cb + y > 0) ans = max(ans, ca + x - cb - y);
                            }
                        }
                        else
                        {
                            if (acbn != tuple<int, int, int>{-1, -1, -1})
                            {
                                auto [z, x, y] = acbn;
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