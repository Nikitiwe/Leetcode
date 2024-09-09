class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int x=0, o=0, xwg=0, xwv=0, xwd=0, owg=0, owv=0, owd=0;
        for (int i=0; i!=3; i++)
        {
            for (int j=0; j!=3; j++)
            {
                if (b[i][j]=='X') x++;
                else if (b[i][j]=='O') o++;
            }
        }
        if (x>5||o>4) return 0;
        if (o>x||x>o+1) return 0;
        for (int i=0; i!=3; i++)
        {
            if (b[i][0]=='X'&&b[i][1]=='X'&&b[i][2]=='X') xwg++;
            else if (b[i][0]=='O'&&b[i][1]=='O'&&b[i][2]=='O') owg++;
        }
        for (int j=0; j!=3; j++)
        {
            if (b[0][j]=='X'&&b[1][j]=='X'&&b[2][j]=='X') xwd++;
            else if (b[0][j]=='O'&&b[1][j]=='O'&&b[2][j]=='O') owd++;
        }
        if (b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X') xwd++;
        else if (b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O') owd++;
        if (b[2][0]=='X'&&b[1][1]=='X'&&b[0][2]=='X') xwd++;
        else if (b[2][0]=='O'&&b[1][1]=='O'&&b[0][2]=='O') owd++;
        if (xwg+xwv+xwd>0&&owg+owv+owd>0) return 0;
        if (xwg>=2||xwv>=2||owg>=2||owv>=2) return 0;
        if (xwg+xwv+xwd>0&&xwg+xwv+xwd<=2&&x==o+1) return 1;
        if (owg+owv+owd>0&&owg+owv+owd<=2&&x==o) return 1;
        if ((x==o||x==o+1)&&xwg+xwv+xwd+owg+owv+owd==0) return 1;
        return 0;
    } // говно говна
};