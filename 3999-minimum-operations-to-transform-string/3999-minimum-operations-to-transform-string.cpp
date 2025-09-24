class Solution {
public:
    int minOperations(string s) {
        int ans = 25;
        char c = 'b';
        unordered_set<char> q;
        for (int i=0; i!=s.size(); i++) q.insert(s[i]);
        for (int i=0; i<25; i++)
        {
            if (q.count(c + i) != 0) return ans;
            ans--;
        }
        return 0;
    }
};