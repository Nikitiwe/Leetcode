class Solution {
public:
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        int a, b, c, d;

        a=e1[0][0]-'0';
        a*=10;
        a+=e1[0][1]-'0';
        a*=60;
        a+=(e1[0][3]-'0')*10;
        a+=e1[0][4]-'0';

        b=e1[1][0]-'0';
        b*=10;
        b+=e1[1][1]-'0';
        b*=60;
        b+=(e1[1][3]-'0')*10;
        b+=e1[1][4]-'0';

        c=e2[0][0]-'0';
        c*=10;
        c+=e2[0][1]-'0';
        c*=60;
        c+=(e2[0][3]-'0')*10;
        c+=e2[0][4]-'0';

        d=e2[1][0]-'0';
        d*=10;
        d+=e2[1][1]-'0';
        d*=60;
        d+=(e2[1][3]-'0')*10;
        d+=e2[1][4]-'0';
        if (a<c&&b>=c) return 1;
        if (a==c) return 1;
        if (a>c&&a<=d) return 1;
        return 0;        
    }
};
