class Solution {
private:
	vector<char> *mapFunction;
public:
    string convert(string s, int numRows) {
		mapFunction = new vector<char>[numRows];
		string converted = "";
		if (numRows == 1) {
			converted = s;
		}
		else {
			for (int i = 0; i < s.size(); ++i) {
				int clause = i % (2 * numRows - 2);
				if (clause < numRows) {
					mapFunction[clause].push_back(s[i]);
				}
				else {
					mapFunction[2 * numRows - 2 - clause].push_back(s[i]);
				}
			}
			for (int i = 0; i < numRows; ++i) {
				for (vector<char>::iterator it = mapFunction[i].begin(); it < mapFunction[i].end(); ++it) {
					converted += (*it);
				}
			}
		}
		return converted;
	}
};