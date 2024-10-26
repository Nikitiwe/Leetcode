class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        stack<int> m;
        int l=0, r=0;
        while (l<pu.size()||r<po.size())
        {
            if (m.size()>0&&m.top()==po[r])
            {
                m.pop();
                r++;
            }
            else if (l<pu.size())
            {
                m.push(pu[l]);
                l++;
            }
            else return 0;
        }
        return 1;
    }
};