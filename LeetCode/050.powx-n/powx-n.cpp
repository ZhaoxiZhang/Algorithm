class Solution {
public:
    double myPow(double x, int n) {
        bool isNegative = false;
        unsigned int un;
    	if (n < 0){
            isNegative = true;
        	un = -n;
        }else{
        	un = n;
        }
        cout << un << endl;
    	double res = 1;
    	while (un){
    		if (un & 1){
    			res *= x;
    		}
    		x *= x;
    		un >>= 1;
    	}
        if (isNegative){
            res = 1 / res;
        }
    	return res;
    }
};