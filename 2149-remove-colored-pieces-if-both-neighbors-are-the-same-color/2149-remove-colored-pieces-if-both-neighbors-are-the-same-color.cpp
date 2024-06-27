class Solution {
public:
    bool winnerOfGame(string colors) {
        int delta=0;
        if (colors.size()<3) return 0;
        for (int i=1; i!=colors.size()-1; i++)
        {
            if (colors[i]=='A') {if (colors[i-1]=='A'&&colors[i+1]=='A') delta++;}
            else if (colors[i-1]=='B'&&colors[i+1]=='B') delta--;
        }
        if (delta>0) return 1;
        else return 0;
    }
};