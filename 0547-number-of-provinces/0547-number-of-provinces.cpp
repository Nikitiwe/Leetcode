class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> temp;
        int recol=2, i, count=0;
        while (count<isConnected.size())
        {
            for (int j=0; j!=isConnected.size(); j++)
            {
                if (isConnected[j][j]==1) {temp.push_back(j); break;}
            }
            i=0;
            while (i<temp.size())
            {
                for (int j=0; j!=isConnected.size(); j++)
                {
                    if (isConnected[temp[i]][j]==1)
                    {
                        temp.push_back(j);
                        isConnected[temp[i]][j]=recol;
                        if (temp[i]==j) count++;
                    }
                }
                i++;
            }
            temp.clear();
            recol++;
        }
        return recol-2;
    }
};