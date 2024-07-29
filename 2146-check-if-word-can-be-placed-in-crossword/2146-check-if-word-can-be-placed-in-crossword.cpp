class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        int l, r;
        for (int i=0; i<board.size(); i++)
        {
            l=0;
            r=0;
            while (1)
            {
                if (board[i][l]==' '||board[i][l]==word[r])
                {
                    l++; r++;
                    if (r==word.size()&&(l==board[i].size()||board[i][l]=='#')&&(l-r==0||board[i][l-r-1]=='#')) return 1;
                    if (r==word.size()) r=0;
                    if (l==board[i].size()) break;
                }
                else {l++; if (l==board[i].size()) break; r=0;}
            }
        }
        for (int i=0; i!=board[0].size(); i++)
        {
            l=0;
            r=0;
            while (1)
            {
                if (board[l][i]==' '||board[l][i]==word[r])
                {
                    l++; r++;
                    if (r==word.size()&&(l==board.size()||board[l][i]=='#')&&(l-r==0||board[l-r-1][i]=='#')) return 1;
                    if (r==word.size()) r=0;
                    if (l==board.size()) break;
                }
                else {l++; if (l==board.size()) break; r=0;}
            }
        }

        for (int i=0; i!=board.size(); i++)
        {
            l=board[i].size()-1;
            r=0;
            while (1)
            {
                if (board[i][l]==' '||board[i][l]==word[r])
                {
                    l--; r++;
                    if (r==word.size()&&(l==-1||board[i][l]=='#')&&(l+r==board[i].size()-1||board[i][l+r+1]=='#')) return 1;
                    if (r==word.size()) r=0;
                    if (l==-1) break;
                }
                else {l--; if (l==-1) break; r=0;}
            }
        }
        for (int i=0; i!=board[0].size(); i++)
        {
            l=board.size()-1;
            r=0;
            while (1)
            {
                if (board[l][i]==' '||board[l][i]==word[r])
                {
                    l--; r++;
                    if (r==word.size()&&(l==-1||board[l][i]=='#')&&(l+r==board.size()-1||board[l+r+1][i]=='#')) return 1;
                    if (r==word.size()) r=0;
                    if (l==-1) break;
                }
                else {l--; if (l==-1) break; r=0;}
            }
        }
        return 0;
    }
}; // Runtime Error 94/154 testcases passed
//Line 11: Char 52:
//=================================================================
//==20==ERROR: AddressSanitizer: heap-buffer-overflow on address