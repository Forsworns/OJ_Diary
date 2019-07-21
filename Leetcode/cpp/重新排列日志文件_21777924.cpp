class Solution {
private:
    pair<string,string> split(const string& input){
        pair<string,string> res;
        for(int i=0;i<input.length();++i){
            if(input[i]==' '){
                res = make_pair(input.substr(0,i+1),input.substr(i+1));
                break;
            }
        }
        
        return res;
    }
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        vector<pair<string,string>> charVec;
        vector<pair<string,string>> numVec;
        for(int i=0;i<logs.size();++i){
            auto item = split(logs[i]);
            if(item.second[0]>='0'&&item.second[0]<='9'){
                numVec.push_back(item);
            }else{
                charVec.push_back(item);
            }
        }
        
        sort(charVec.begin(),charVec.end(),[](auto x,auto y){
            if(x.second==y.second){
                return x.first<y.first;
            }
            return x.second<y.second;
        });
        
        for(auto &x : charVec){
            ans.push_back(x.first+x.second);
        }
        for(auto &x : numVec){
            ans.push_back(x.first+x.second);
        }
        
        return ans;
    }
};