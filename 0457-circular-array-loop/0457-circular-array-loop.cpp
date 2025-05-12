class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int isp = nums[i] > 0 ? 1 : -1;
            int t = nums[i];
            int sign = isp;
            int rem = abs(t) % n;
            if (rem == 0) continue;
            bool isit = true;
            int prev = i;
            // Маркируем стартовую ячейку
            nums[prev] = sign * ((2000 + i) * n + rem);
            while (true) {
                // Следующий индекс
                prev = (prev + sign * rem + n) % n;
                t = nums[prev];
                int cur_sign = t > 0 ? 1 : -1;
                rem = abs(t) % n;
                // Если направление меняется или шаг по массиву 0 — цикл невозможен
                if (cur_sign != sign || rem == 0) {
                    isit = false;
                    break;
                }
                // Если снова попали на свою метку — значит цикл
                if (abs(t) / n == 2000 + i && cur_sign == sign) {
                    if (isit) return true;
                    break;
                }
                // Если попали на чужую метку — разрыв
                if (abs(t) / n >= 2000 && abs(t) / n != 2000 + i) {
                    isit = false;
                    break;
                }
                // Ставим свою метку
                nums[prev] = sign * ((2000 + i) * n + rem);
            }
        }
        return false;
    }
};