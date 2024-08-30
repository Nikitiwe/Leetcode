class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>> arr(257, vector<int> (8, 0));
        int f=-1, s=-1;
        for (int i=0; i!=8; i++) arr[0][i]=cells[i];
        for (int i=1; i!=arr.size(); i++)
        {
            for (int j=1; j!=7; j++) // тут можно попробовать прикрутить изменяющийся размер арр
            {
                if (arr[i-1][j-1]==arr[i-1][j+1]) arr[i][j]=1;
            }
            for (int k=0; k!=i; k++)
            {
                if (arr[k][0]==arr[i][0]&&arr[k][1]==arr[i][1]&&arr[k][2]==arr[i][2]&&arr[k][3]==arr[i][3]&&
                    arr[k][4]==arr[i][4]&&arr[k][5]==arr[i][5]&&arr[k][6]==arr[i][6]&&arr[k][7]==arr[i][7])
                    {f=k; s=i; break;}
            }
            if (f!=-1) break;
        }
        n-=f;
        n%=(s-f);
        return arr[f+n];
    }
};