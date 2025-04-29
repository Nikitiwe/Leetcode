class Solution {
public:
    int closestMeetingNode(vector<int>& arr, int a, int b) {
        if (a == b) return a;
        unordered_set<int> s, q;
        s.insert(a);
        q.insert(b);
        int ans = 100000000;
        for (int i=0; i!=arr.size(); i++)
        {
            if (a != -1)
            {
                a = arr[a];
                s.insert(a);
                if (q.count(a) != 0) ans = min(ans, a);
            }
            if (b != -1)
            {
                b = arr[b];
                q.insert(b);
                if (s.count(b) != 0) ans = min(ans, b);
            }
            if (ans < 100000000) return ans;
        }
        return -1;
    }
};