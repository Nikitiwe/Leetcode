class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        if (((c1[0]-'a'+c1[1])%2)==((c2[0]-'a'+c2[1])%2)) return 1;
        else return 0;
    }
};