class Solution {
public:
    int reverse(int x) {
		long long int ans = 0;
		long long int temp = x;
		bool positive = (x>0);
		temp = abs(temp);
		while (temp != 0) {
			ans = ans * 10 + temp % 10;
			temp /= 10;
		}
		if (positive) {
			if (ans > pow(2, 31) - 1) {
				return 0;
			}
			else {
				return ans;
			}
		}
		if (!positive) {
			if (ans > pow(2, 31)) {
				return 0;
			}
			else {
				return -ans;
			}
		}
        return 0;
	}
};