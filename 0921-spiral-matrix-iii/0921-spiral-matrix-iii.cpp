class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;
        ans.push_back({rStart, cStart});
        int count=1, n=rows*cols, y=rStart, x=cStart, temp=0;
        while (count<n)
        {
            temp++;
            for (int i=0; i<temp; i++) // слева направо
            {
                x++;
                if (y>=0&&y<rows&&x>=0&&x<cols) {ans.push_back({y, x}); count++;}
            }
            for (int i=0; i<temp; i++) // сверху вниз
            {
                y++;
                if (y>=0&&y<rows&&x>=0&&x<cols) {ans.push_back({y, x}); count++;}
            }
            temp++;
            for (int i=0; i<temp; i++)
            {
                x--;
                if (y>=0&&y<rows&&x>=0&&x<cols) {ans.push_back({y, x}); count++;}
            }
            for (int i=0; i<temp; i++)
            {
                y--;
                if (y>=0&&y<rows&&x>=0&&x<cols) {ans.push_back({y, x}); count++;}
            }
        }
        return ans;
    }
};