class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> addresses;
        for(int i=0;i<emails.size();i++){
            bool encounterAdd = false;
            string addr = "";
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='@'){
                    addr += emails[i].substr(j);
                    break;
                }
                else if(encounterAdd){
                    continue;
                }else{
                    if(emails[i][j]=='.'){
                        continue;
                    }else if(emails[i][j]=='+'){
                        encounterAdd = true;
                    }else{
                        addr += emails[i][j];
                    }
                } 
            }
            addresses.insert(addr);
        }
        return addresses.size();
    }
};