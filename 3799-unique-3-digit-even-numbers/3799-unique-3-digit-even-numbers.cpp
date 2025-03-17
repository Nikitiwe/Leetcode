class Solution {
public:
    int totalNumbers(vector<int>& d) {
        unordered_set<int> s;
        for (int i=1; i<=9; i++)
        {
            int ida = -1;
            for (int t=0; t!=d.size(); t++)
            {
                if (d[t] == i)
                {
                    ida = t;
                    break;
                }
            }
            if (ida != -1) for (int j=0; j<=9; j++)
            {
                int idb = -1;
                for (int t=0; t!=d.size(); t++)
                {
                    if (d[t] == j && t != ida)
                    {
                        idb = t;
                        break;
                    }
                }
                if (idb != -1) for (int k=0; k<=8; k+=2)
                {
                    for (int t=0; t!=d.size(); t++)
                    {
                        if (d[t] == k && t != ida && t != idb)
                        {
                            s.insert(100*i + 10*j + k);
                        }
                    }
                }
            }
        }
        return s.size();
    }
};