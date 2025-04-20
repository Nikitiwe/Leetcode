class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int ans = 0;
        queue<int> b;
        unordered_set<int> p;
        vector<int> have(status.size(), 0);
        for (int i=0; i!=initialBoxes.size(); i++) have[initialBoxes[i]] = 1;
        for (int i=0; i!=status.size(); i++)
        {
            if (status[i] == 1 && have[i] == 1)
            {
                b.push(i);
                p.insert(i);
            }
        }
        while (b.size() > 0)
        {
            int id = b.front(); b.pop();
            ans += candies[id];
            vector<int> temp;
            for (int i=0; i!=containedBoxes[id].size(); i++)
            {
                have[containedBoxes[id][i]] = 1;
                temp.push_back(containedBoxes[id][i]);
            }
            for (int i=0; i!=keys[id].size(); i++)
            {
                status[keys[id][i]] = 1;
                temp.push_back(keys[id][i]);
            }
            for (int i=0; i!=temp.size(); i++)
            {
                if (p.count(temp[i]) == 0 && status[temp[i]] == 1 && have[temp[i]] == 1)
                {
                    b.push(temp[i]);
                    p.insert(temp[i]);
                }
            }
        }
        return ans;
    }
};