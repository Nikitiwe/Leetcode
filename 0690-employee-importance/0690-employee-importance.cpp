/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void f(unordered_map<int, int> &m, vector<Employee*> e, int id, int &ans)
    {
        ans += e[m[id]]->importance;
        for (int i=0; i<e[m[id]]->subordinates.size(); i++) f(m, e, e[m[id]]->subordinates[i], ans);
    }

    int getImportance(vector<Employee*> e, int id) {
        int ans = 0;
        unordered_map<int, int> m;
        for (int i=0; i!=e.size(); i++) m[e[i]->id] = i;
        f(m, e, id, ans);
        return ans;
    }
};