class Solution {
public:
    long long pow(int x, int n) {
        long long res = 1;
        while (n > 0) {
            if (n & 1) {
                res *= x;
            }
            x *= x;
            n >>= 1;
        }
        return res;
    }

    int reverse(int x) {
    	if (x == INT_MIN)	return 0;
    	bool flag = false;
    	if (x < 0)	flag = true,x = -x;
        int a[20];
        int len = 0;
        while (x) {
            a[len++] = x % 10;
            x /= 10;
        }
        long long res = 0;
        for (int i = 0; i < len; i++) {
            //cout << a[i] << " " << pow(10, i) << endl;
            res += a[len - 1 - i] * pow(10, i);
        }
        if (res > INT_MAX)  return 0;
        else if (flag)	return -res;
        else	return res;
    }
};