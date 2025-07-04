class NumMatrix {
public:
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& m) {
        arr.assign(m.size() + 1, vector<int>(m[0].size() + 1, 0));
        for (int i=0; i!=m.size(); i++)
        {
            for (int j=0; j!=m[0].size(); j++)
            {
                arr[i+1][j+1] = m[i][j];
                arr[i+1][j+1] += arr[i][j+1];
                arr[i+1][j+1] += arr[i+1][j];
                arr[i+1][j+1] -= arr[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return arr[row2+1][col2+1] - arr[row2+1][col1] - arr[row1][col2+1] + arr[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */