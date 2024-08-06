class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        string s;
        for (int i=0; i<=num; i++)
        {
            s=to_string(i);
            reverse(s.begin(), s.end());
            if (i+stoi(s)==num) return 1;
        }
        return 0;
    }
};