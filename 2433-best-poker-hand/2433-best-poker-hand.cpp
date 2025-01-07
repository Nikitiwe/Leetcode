class Solution {
public:
    string bestHand(vector<int>& r, vector<char>& s) {
        if (s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3]&&s[3]==s[4]) return "Flush";
        unordered_map<int, int> m;
        for (int i=0; i!=r.size(); i++)
        {
            m[r[i]]++;
            if (m[r[i]]==3) return "Three of a Kind";
        }
        for (auto i=m.begin(); i!=m.end(); i++) if (i->second==2) return "Pair";
        return "High Card";
    }
};