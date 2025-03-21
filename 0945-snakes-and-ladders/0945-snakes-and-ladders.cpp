class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
        vector<int> arr(b.size()*b.size(), 0);
        int t = 0;
        for (int i=b.size()-1; i>=0; i--)
        {
            if ((i-b.size()+1)%2==0) for (int j=0; j!=b.size(); j++)
            {
                arr[t] = b[i][j]-1;
                t++;
            }
            else for (int j=b.size()-1; j>=0; j--)
            {
                arr[t] = b[i][j]-1;
                t++;
            }
        }
        int c = 1;
        for (int i=0; i!=arr.size(); i++) if (arr[i]<i && arr[i]>=0) c++;
        vector<int> ans(arr.size(), 10000);
        ans[0] = 0;
        for (int k = 0; k < c; k++)
        {
            for (int i=0; i!=arr.size(); i++)
            {
                t = ans[i] + 1;
                for (int j=1; j<=6; j++)
                {
                    if (i+j<arr.size())
                    {
                        if (arr[i+j] == -2) ans[i+j] = min(ans[i+j], t);
                        else
                        {
                            ans[arr[i+j]] = min(ans[arr[i+j]], t);
                        }
                    }
                }
            }
        }
        if (ans.back() < 10000) return ans.back();
        else return -1;
    }
};