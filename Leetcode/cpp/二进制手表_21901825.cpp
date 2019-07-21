class Solution {
// 注意特殊情况不会有12点的时间，小时最大只能是11；还有分钟数不能超过59。
// 用dfs方法回溯
private:
    vector<string> ans;
    string convert(const string& s){
        string res;
        int hour = 0;
        for(int i=0;i<4;++i){
            hour += (s[i]-'0')*int(pow(2,3-i));
        }
        stringstream ss;
        ss<<hour;
        ss>>res;
        res+=":";
        int minute = 0;
        for(int i=4;i<10;++i){
            minute += (s[i]-'0')*int(pow(2,9-i));
        }
        string ms;
        stringstream sss;
        sss<<minute;
        sss>>ms;
        if(minute<10){
            ms = "0"+ms;
        }
        res+=ms;
        if(minute>59){ // 过滤掉非法时间
            res = "/0";
        }
        return res;
    }
    void dfs(string s, int idx, int num){ // 位置和当前剩余1的数目
        if(idx+num>10||num<0){ // 非法
            return;
        }
        if(num==0){ // 1用光了
            for(int i=idx;i<10;++i){
                s+="0";
            }
            ans.push_back(s);
            return;
        }
        dfs(s+"0",idx+1,num);
        if(s!="1"){
            dfs(s+"1",idx+1,num-1); // 过滤掉超过12点
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        dfs("",0,num);
        for(int i=0;i<ans.size();++i){
            ans[i] = convert(ans[i]);    
        }
        vector<string> realAns;
        for(int i=0;i<ans.size();++i){
            if(ans[i]!="/0"){
                realAns.push_back(ans[i]);
            }
        }
        return realAns;
    }
};