class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {
        unordered_set<char> m;
        for (int i=0; i!=9; i++)
        {
            for (int j=0; j!=9; j++)
            {
                if (b[i][j]!='.') {
                if (m.count(b[i][j])!=0) return 0;
                else m.insert(b[i][j]);
                }
            }
            m.clear();
        }
        for (int i=0; i!=9; i++)
        {
            for (int j=0; j!=9; j++)
            {
                if (b[j][i]!='.') {
                if (m.count(b[j][i])!=0) return 0;
                else m.insert(b[j][i]);
                }
            }
            m.clear();
        }
        for (int i=0; i!=9; i=i+3)
        {
            for (int j=0; j!=9; j=j+3)
            {
                for (int a=0; a!=3; a++)
                {
                    for (int c=0; c!=3; c++)
                    {
                        if (b[i+a][j+c]!='.') {
                        if (m.count(b[i+a][j+c])!=0) return 0;
                        else m.insert(b[i+a][j+c]);
                        }
                    }
                }
                m.clear();
            }
        }
        
        return 1;
    }
};