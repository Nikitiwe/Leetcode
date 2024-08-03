class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        vector<vector<int>> arr=grid;
        int sum=0, ans=0, temp;
        for (int i=0; i!=grid.size(); i++)
        {
            for (int j=0; j!=grid[0].size(); j++)
            {
                sum+=grid[i][j];
                arr[i][j]=0;
            }
        }
        if (sum<=2) return sum;
        if (grid.size()*grid[0].size()<=3) return sum;
        for (int i=0; i!=grid.size()/2; i++)
        {
            for (int j=0; j!=grid[0].size()/2; j++)
            {
                temp=0;
                temp+=grid[i][j];
                temp+=grid[i][grid[0].size()-1-j];
                temp+=grid[grid.size()-1-i][j];
                temp+=grid[grid.size()-1-i][grid[0].size()-1-j];
                if (temp==1) {ans++; sum--;}
                else if (temp==2) {ans=ans+2; sum=sum+2;}
                else if (temp==3) {ans++; sum++;}
            }
        }
        temp=0;
        if (grid[0].size()%2==1)
        {
            for (int i=0; i!=grid.size()/2; i++)
            {
                if (grid[i][grid[0].size()/2]!=grid[grid.size()-1-i][grid[0].size()/2]) {ans++; sum++; temp++;}
            }
        }
        if (grid.size()%2==1)
        {
            for (int j=0; j!=grid[0].size()/2; j++)
            {
                if (grid[grid.size()/2][j]!=grid[grid.size()/2][grid[0].size()-1-j]) {ans++; sum++; temp++;}
            }
        }
        if (sum==3) return sum;
        if (sum%2==1) {ans++; sum--;}
        if (sum%4==2&&temp==0) ans=ans+2;
        return ans;
    }
};