class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++) m[arr[i]]++;
        for (int i=0; i!=target.size(); i++)
        {
            m[target[i]]--;
            if (m[target[i]]<0) return 0;
        }
        return 1;
    }
};