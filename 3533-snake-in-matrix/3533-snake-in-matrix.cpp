class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x=0, y=0;
        for (int i=0; i!=commands.size(); i++)
        {
            if (commands[i]=="UP") y--;
            else if (commands[i]=="DOWN") y++;
            else if (commands[i]=="RIGHT") x++;
            else if (commands[i]=="LEFT") x--;
        }
        return y*n+x;
    }
};