class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& s) {
        int l=0;
        while (l<arr.size())
        {
            bool isit=0;
            int t=l;
            for (int i=0; i!=s.size(); i++)
            {
                if (arr[l]==s[i][0])
                {
                    for (int j=0; j!=s[i].size(); j++)
                    {
                        if (arr[l]==s[i][j]) l++;
                        else
                        {
                            isit=1;
                            break;
                        }
                        if (l==arr.size()) return 1;
                    }
                }
                if (isit==1) break;
            }
            if (isit==1) break;
            if (l==t) break;
        }
        if (l==arr.size()) return 1;
        else return 0;
    }
};