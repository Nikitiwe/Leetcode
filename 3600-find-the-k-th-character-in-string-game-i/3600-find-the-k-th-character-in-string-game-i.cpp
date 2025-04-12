class Solution {
public:
    char kthCharacter(int k) {
        int a = 0;
        while (k > 1)
        {
            int st = 1;
            while (st*2 < k) st *= 2;
            k -= st;
            a++;
        }
        return 'a' + a%26;
    }
};