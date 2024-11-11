class Solution {
public:
    bool checkValid(vector<vector<int>>& m) {
        vector<int> arr(m.size(), 0);
        for (int i=0; i!=m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                arr[m[i][j]-1]++;
                if (arr[m[i][j]-1]>i+1) return 0;
            }
        }
        for (int j=0; j!=m[0].size(); j++)
        {
            for (int i=0; i!=m.size(); i++)
            {
                arr[m[i][j]-1]++;
                if (arr[m[i][j]-1]>m.size()+j+1) return 0;
            }
        }
        return 1;
    }
};