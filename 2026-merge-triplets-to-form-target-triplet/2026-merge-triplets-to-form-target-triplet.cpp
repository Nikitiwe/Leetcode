class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int ans=0;
        for (int i=0; i!=triplets.size(); i++)
        {
            if (triplets[i][0]==target[0])
            {
                if (triplets[i][1]<=target[1]&&triplets[i][2]<=target[2])
                {
                    ans++;
                    break;
                }
            }
        }
        for (int i=0; i!=triplets.size(); i++)
        {
            if (triplets[i][1]==target[1])
            {
                if (triplets[i][0]<=target[0]&&triplets[i][2]<=target[2])
                {
                    ans++;
                    break;
                }
            }
        }
        for (int i=0; i!=triplets.size(); i++)
        {
            if (triplets[i][2]==target[2])
            {
                if (triplets[i][1]<=target[1]&&triplets[i][0]<=target[0])
                {
                    ans++;
                    break;
                }
            }
        }
        if (ans==3) return 1;
        else return 0;
    }
};