class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        int temp;
        while (n>1)
        {
            if (m.count(n)>0) return 0;
            m.insert(n);
            temp=n;
            n=0;
            while (temp>0)
            {
                n+=((temp%10)*(temp%10));
                temp/=10;
            }
        }
        return 1;
    }
};