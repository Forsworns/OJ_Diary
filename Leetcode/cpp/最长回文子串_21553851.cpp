class Solution {
public:
    string longestPalindrome(string s) {
        int maxR = 0, center = 0;
        string t = "$#";
        for(int i=0;i<s.size();++i){
            t+=s[i];
            t+="#";
        }
		int *r = new int[t.size()](); //t中的以各个字符为中心的回文串的长度
        int mx=0,id=0;            //用来记录回文串包含关系的游标，前者为边界，后者为中心。
        for(int i=0;i<t.size();++i){
            r[i] = mx>i ? min(r[id*2-i],mx-i): 1;
            while(t[i-r[i]]==t[i+r[i]]){r[i]++;}  //超过了mx，无法获取到包含关系，只能遍历检查了
            if(mx<i+r[i]){
                //超出了边界mx，更新mx和id
                mx = i+r[i];
                id = i;
            }
            if(maxR<r[i]){
                maxR = r[i];
                center = i;
            }
        }
        int start = (center-maxR)/2;
        int len = maxR-1;
		return s.substr(start,len);
	}
};