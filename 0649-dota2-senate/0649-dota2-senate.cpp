class Solution {
public:
    string predictPartyVictory(string s) {
        int r=0, d=0;
        string temp;
        while (s.size()>1)
        {
            temp="";
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i]=='R'&&d<=0) {r++; temp+="R";}
                else if (s[i]=='R'&&d>0) d--;
                else if (s[i]=='D'&&r<=0) {d++; temp+="D";}
                else if (s[i]=='D'&&r>0) r--;
            }
            s=temp;
            if (r>=s.size()) return "Radiant";
            if (d>=s.size()) return "Dire";
        }
        if (s[0]=='R') return "Radiant";
        else return "Dire";
    }
};