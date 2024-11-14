class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& m) {
        vector<int> col(m[0].size(), 0), row(m.size(), 0);
        unordered_map<int, int> r, c;
        for (int i=0; i!=m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                r[m[i][j]]=i;
                c[m[i][j]]=j;
            }
        }
        for (int i=0; i!=arr.size(); i++)
        {
            col[c[arr[i]]]++;
            if (col[c[arr[i]]]==m.size()) return i;
            row[r[arr[i]]]++;
            if (row[r[arr[i]]]==m[0].size()) return i;
        }
        return -1;
    }
};