class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> ans(rooms.size(), 0);
        ans[0]=1;
        for (int i=0; i!=rooms.size(); i++)
        {
            for (int j=0; j!=rooms.size(); j++)
            {
                if (ans[j]==1)
                {
                    for (int k=0; k!=rooms[j].size(); k++)
                    {
                        ans[rooms[j][k]]=1;
                    }
                }
            }
            if (find(ans.begin(), ans.end(), 0)==ans.end()) return 1;
        }
        return 0;
    }
};