class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& nums) {
        deque<int> d;
        for (int i=0; i!=s.size(); i++) d.push_back(s[i]);
        int id = 0;
        int c = 0;
        while (d.size() > 0)
        {
            int t = d.front();
            d.pop_front();
            if (t == nums[id])
            {
                c = 0;
                id++;
            }
            else
            {
                c++;
                d.push_back(t);
            }
            if (c == d.size()) break;
        }
        return d.size();
    }
};