class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size()!=s1.size()+s2.size()) return 0;
        vector<vector<int>> arr(s1.size()+1, vector<int> (s2.size()+1, 0));
        arr[0][0]=1;
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=0; j!=arr[0].size(); j++)
            {
                if (i>0&&arr[i-1][j]==1&&s3[i+j-1]==s1[i-1]) arr[i][j]=1;
                if (j>0&&arr[i][j-1]==1&&s3[i+j-1]==s2[j-1]) arr[i][j]=1;
            }
        }
        if (arr[s1.size()][s2.size()]==1) return 1;
        else return 0;
    }
};