class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string> pow;
        int a=1;
        string temp;
        for (int i=1; i<=30; i++)
        {
            temp=to_string(a);
            sort(temp.begin(), temp.end());
            pow.push_back(temp);
            a*=2;
        }
        temp=to_string(n);
        sort(temp.begin(), temp.end());
        if (find(pow.begin(), pow.end(), temp)==pow.end()) return 0;
        else return 1;
    }
};