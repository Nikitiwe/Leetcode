/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& s, Master& master) {
        if (s.size() <= 10)
        {
            for (int i=0; i!=s.size(); i++) master.guess(s[i]);
        }
        vector<string> w = s;
        while (w.size() > 1)
        {
            vector<vector<int>> arr(w.size(), vector<int>(w.size(), 0));
            for (int i=0; i!=w.size(); i++)
            {
                for (int j=0; j!=w.size(); j++)
                {
                    for (int k=0; k!=6; k++) if (w[i][k] == w[j][k]) arr[i][j]++;
                }
            }
            vector<int> ma(w.size(), 0);
            for (int i=0; i!=w.size(); i++)
            {
                vector<int> t(7, 0);
                int a = 0;
                for (int j=0; j!=w.size(); j++)
                {
                    t[arr[i][j]]++;
                    a = max(a, t[arr[i][j]]);
                }
                ma[i] = a;
            }
            int ans = 0;
            for (int i=0; i!=w.size(); i++)
            {
                if (ma[i] < ma[ans]) ans = i;
            }
            vector<string> next;
            int t = master.guess(w[ans]);
            for (int i=0; i!=w.size(); i++) if (arr[ans][i] == t) next.push_back(w[i]);
            w = next;
        }
        master.guess(w[0]);
    }
};