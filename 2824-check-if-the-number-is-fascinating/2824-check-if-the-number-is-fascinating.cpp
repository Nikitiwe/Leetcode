class Solution {
public:
    bool isFascinating(int n) {
        if (n*3>999) return 0;
        unordered_set<int> m;
        m.insert(n/100);
        if ((n/10)%10==0) return 0;
        else m.insert((n/10)%10);
        if (n%10==0) return 0;
        else m.insert(n%10);
        n*=2;
        m.insert(n/100);
        if ((n/10)%10==0) return 0;
        else m.insert((n/10)%10);
        if (n%10==0) return 0;
        else m.insert(n%10);
        n/=2; n*=3;
        m.insert(n/100);
        if ((n/10)%10==0) return 0;
        else m.insert((n/10)%10);
        if (n%10==0) return 0;
        else m.insert(n%10);
        if (m.size()==9) return 1;
        else return 0;
    }
};