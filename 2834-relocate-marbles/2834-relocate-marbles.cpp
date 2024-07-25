class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> m(nums.begin(), nums.end());;
        for (int i=0; i!=moveFrom.size(); i++)
        {
            m.erase(moveFrom[i]);
            m.insert(moveTo[i]);
        }
        nums.clear();
        for (auto it=m.begin(); it!=m.end(); it++)
        {
            nums.push_back(*it);
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};