class Solution {
public:
    int maxProduct(vector<string>& w) {
        vector<vector<int>> arr(w.size(), vector<int> (26, 0));
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=0; j!=w[i].size(); j++) arr[i][w[i][j]-'a']++;
        }
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=0; j<i; j++)
            {
                bool isit=1;
                for (int a=0; a!=26; a++)
                {
                    if (arr[i][a]>0&&arr[j][a]>0)
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) ans=max(ans, (int)(w[i].size()*w[j].size()));
            }
        }
        return ans;
    }
};