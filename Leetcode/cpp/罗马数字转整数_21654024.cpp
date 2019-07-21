class Solution {
private:
    const int I = 1;
    const int IV = 4;
    const int V = 5;
    const int IX = 9;
    const int X = 10;
    const int XL = 40;
    const int L = 50;
    const int XC = 90;
    const int C = 100;
    const int CD = 400;
    const int D = 500;
    const int CM = 900;
    const int M = 1000;
public:
    int romanToInt(string s) {
        int answer = 0;
        for(int i=0;i<s.length();i++){
            switch(s[i]){
                case 'I':{
                    if(i+1<s.length() && s[i+1]=='V'){
                        i++;
                        answer+=IV;
                    }else if(i+1<s.length() && s[i+1]=='X'){
                        i++;
                        answer+=IX;
                    }else{
                        answer+=I;
                    }
                    break;
                }
                case 'V':{
                    answer+=V;
                    break;
                }
                case 'X':{
                    if(i+1<s.length() && s[i+1]=='L'){
                        i++;
                        answer+=XL;
                    }else if(i+1<s.length() && s[i+1]=='C'){
                        i++;
                        answer+=XC;
                    }else{
                        answer+=X;
                    }
                    break;
                }
                case 'L':{
                    answer+=L;
                    break;
                }
                case 'C':{
                    if(i+1<s.length() && s[i+1]=='D'){
                        i++;
                        answer+=CD;
                    }else if(i+1<s.length() && s[i+1]=='M'){
                        i++;
                        answer+=CM;
                    }else{
                        answer+=C;
                    }
                    break;
                }
                case 'D':{
                    answer+=D;
                    break;
                }
                case 'M':{
                    answer+=M;
                    break;
                }
            }
        }
        return answer;
    }
};