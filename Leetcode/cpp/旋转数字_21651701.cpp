class Solution {
private:
	const int DILAV[7] = { 0,1,5,2,9,8,6 };
	const int IDX[10] = { 0,1,2,-1,-1,3,4,-1,5,6 };
	bool valid(int input) {
		return IDX[input] >= 0;
	}

public:
	int rotatedDigits(int N) {
		int answer = 0;
		for (int n = 1; n <= N; ++n) {
			const int orig = n;
			int num = n;
			int reversed = 0;
			int pos = 0;
			bool flag = true; // 每一位都在VALID中
			while (num / 10 != 0) {
				flag = valid(num % 10);
				if (!flag) {
					break;
				}
				reversed = reversed + pow(10, pos)*DILAV[IDX[num % 10]];
				pos++;
				num = num / 10;
			}
			if (flag) {
				if (valid(num % 10)) {
					reversed = reversed + pow(10, pos)*DILAV[IDX[num % 10]];
					if (reversed != orig) {
						answer++;
					}
				}
			}
		}
		return answer;
	}
};