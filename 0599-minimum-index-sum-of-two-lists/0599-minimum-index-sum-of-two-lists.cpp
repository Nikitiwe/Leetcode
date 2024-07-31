class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        int a=3000;
        vector<string> ans;
        for (int i=0; i!=list1.size(); i++)
        {
            m[list1[i]]=i;
        }
        for (int i=0; i!=list2.size(); i++)
        {
            if (m.count(list2[i])!=0) a=min(a, i+m[list2[i]]);
        }
        for (int i=0; i!=list2.size(); i++)
        {
            if (m.count(list2[i])!=0&&i+m[list2[i]]==a) ans.push_back(list2[i]);
        }
        return ans;
    }
};