class Solution {
public:
    string getHappyString(int n, int kk) {
        vector<string> prev = {"a", "b", "c"}, next, zero;
        for (int k=2; k<=n; k++)
        {
            for (int i=0; i!=prev.size(); i++)
            {
                if (prev[i].back() != 'a') next.push_back(prev[i] + "a");
                if (prev[i].back() != 'b') next.push_back(prev[i] + "b");
                if (prev[i].back() != 'c') next.push_back(prev[i] + "c");
            }
            prev = next;
            next = zero;
        }
        sort(prev.begin(), prev.end());
        if (kk-1 < prev.size()) return prev[kk-1];
        else return "";
    }
};