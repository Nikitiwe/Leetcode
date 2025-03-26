class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int x, int y) {
        vector<vector<int>> ans;
        ans.push_back({x, y});
        for (int l = 1; l < rows + cols; l++)
        {
            for (int i=0; i<l; i++) // сверху справа , верх есть
            {
                if (x+l-i < rows && y+i < cols) ans.push_back({x+l-i, y+i});
            }
            for (int i=1; i<=l; i++) // снизу справа , право есть
            {
                if (x-l+i >= 0 && y+i < cols) ans.push_back({x-l+i, y+i});
            }
            for (int i=1; i<=l; i++) // сверху слева , лево есть
            {
                if (x+l-i < rows && y-i >=0) ans.push_back({x+l-i, y-i});
            }
            for (int i=0; i<l; i++)
            {
                if (x-l+i >= 0 && y-i >= 0) ans.push_back({x-l+i, y-i});
            }
            if (ans.size() == rows * cols) break;
        }
        return ans;
    }
};