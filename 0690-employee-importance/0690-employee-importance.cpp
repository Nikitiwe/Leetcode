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
    void f(vector<Employee*> e, int id, int &ans)
    {
        int t = -1;
        for (int i=0; i!=e.size(); i++) if (e[i]->id == id)
        {
            t = i;
            break;
        }
        ans += e[t]->importance;
        for (int i=0; i<e[t]->subordinates.size(); i++) f(e, e[t]->subordinates[i], ans);
    }

    int getImportance(vector<Employee*> e, int id) {
        int ans = 0;
        f(e, id, ans);
        return ans;
    }
};