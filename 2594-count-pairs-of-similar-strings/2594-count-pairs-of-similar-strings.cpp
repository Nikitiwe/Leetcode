class Solution {
public:
    int similarPairs(vector<string>& w) {
        vector<vector<int>> arr(w.size(), vector<int> (26, 0));
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=0; j!=w[i].size(); j++) arr[i][w[i][j]-'a']++;
        }
        int ans=0;
        for (int i=0; i!=w.size(); i++)
        {
            for (int j=i+1; j<w.size(); j++)
            {
                bool isit=1;
                for (int k=0; k!=26; k++)
                {
                    if ((arr[i][k]==0&&arr[j][k]!=0)||(arr[i][k]!=0&&arr[j][k]==0))
                    {
                        isit=0;
                        break;
                    }
                }
                if (isit==1) ans++;
            }
        }
        return ans;
    }
};