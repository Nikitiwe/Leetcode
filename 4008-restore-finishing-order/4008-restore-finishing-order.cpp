class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_set<int> s;
        vector<int> ans;
        for (int i=0; i!=friends.size(); i++) s.insert(friends[i]);
        for (int i=0; i!=order.size(); i++)
        {
            if (s.count(order[i]) != 0) ans.push_back(order[i]);
        }
        return ans;
    }
};