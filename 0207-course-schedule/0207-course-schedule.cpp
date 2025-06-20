class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<int> arr(n, 0);
        vector<bool> isit(n, 0);
        for (int i=0; i!=p.size(); i++)
        {
            arr[p[i][0]]++;
        }
        int c = 0;
        while (c < n)
        {
            int id = -1;
            for (int i=0; i!=n; i++)
            {
                if (arr[i] == 0 && isit[i] == 0)
                {
                    isit[i] = 1;
                    id = i;
                    break;
                }
            }
            if (id != -1)
            {
                c++;
                for (int i=0; i!=p.size(); i++)
                {
                    if (p[i][1] == id)
                    {
                        arr[p[i][0]]--;
                    }
                }
            }
            else return 0;
        }
        return 1;
    }
};