class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for (int i=0; i!=arr.size(); i++) m[arr[i]]++;
        unordered_set<int> n;
        for (auto i=m.begin(); i!=m.end(); i++)
        {
            n.insert(i->second);
        }
        if (m.size()==n.size()) return 1;
        else return 0;
    }
};