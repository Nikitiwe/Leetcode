class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> arr(9, vector<int> ()), next, ans;
        for (int a=1; a<=9; a++)
        {
            arr[a-1].push_back(a);
        }
        for (int a=2; a<=k; a++)
        {
            for (int i=0; i!=arr.size(); i++)
            {
                int sum=0;
                for (int j=0; j!=arr[i].size(); j++) sum+=arr[i][j];
                if (sum<n)
                {
                    for (int b=arr[i][arr[i].size()-1]+1; b<=9; b++)
                    {
                        if (sum+b<=n)
                        {
                            vector<int> t=arr[i];
                            t.push_back(b);
                            next.push_back(t);
                        }
                    }
                }
            }
            arr=next;
            next.clear();
        }
        for (int i=0; i!=arr.size(); i++)
        {
            int sum=0;
            for (int j=0; j!=arr[i].size(); j++) sum+=arr[i][j];
            if (sum==n) ans.push_back(arr[i]);
        }
        return ans;
    }
};