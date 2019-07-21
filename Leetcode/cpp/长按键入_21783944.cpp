class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.length()>typed.length()){ // 输入不够长
            return false;
        }
        // 使用双指针
        int i=0; // name中的指针
        char last = name[0]; // 判断是否是多打出来的
        for(int j=0;j<typed.length();++j){ // typed中的指针
            if(i<name.length() && typed[j] == name[i]){
                last = name[i];
                ++i;
            }
            else if(typed[j]!=last){
                return false; // 如果不同，必须是上一个字母
            }
        }
        if(i!=name.length()){
            return false;
        }else{
            return true;
        }
    }
};