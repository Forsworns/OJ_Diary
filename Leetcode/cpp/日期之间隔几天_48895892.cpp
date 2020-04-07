// 应该是直接把年月转成日，又快又好写
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        int D[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int ans = 0;
        int year1 = atoi(date1.substr(0,4).c_str());
        int year2 = atoi(date2.substr(0,4).c_str());
        int month1 = atoi(date1.substr(5,2).c_str());
        int month2 = atoi(date2.substr(5,2).c_str());
        int day1 = atoi(date1.substr(8,2).c_str());
        int day2 = atoi(date2.substr(8,2).c_str());
        
        if(year1>year2){
            year1 ^= year2;            
            year2 ^= year1; 
            year1 ^= year2; 
            month1 ^= month2;            
            month2 ^= month1; 
            month1 ^= month2;
            day1 ^= day2;            
            day2 ^= day1; 
            day1 ^= day2;
        }
        
        for(int i=year1+1;i<year2;++i){
            if((i%4==0 && i%100!=0)||(i%400==0)){
                ans += 366;
            }else{
                ans += 365;   
            }    
        }
        
        if(year1==year2){
            if(month1==month2){
                ans += abs(day2-day1);
            }else{
                if(month1>month2){
                    month1 ^= month2;            
                    month2 ^= month1; 
                    month1 ^= month2;
                    day1 ^= day2;            
                    day2 ^= day1; 
                    day1 ^= day2;
                }
                for(int i=month1+1;i<=month2;++i){
                     ans+=D[i-1];
                }
                
                ans += D[month1-1]-day1;
                ans += day2;
            }
            
        }else{
            for(int i=month1+1;i<=12;++i){
                 ans+=D[i-1];
            }

            for(int i=1;i<month2;++i){
                ans+=D[i-1];
            }

            if(month1<=2 && ((year1%4==0 && year1%100!=0)||(year1%400==0))){        
                ans++;
            }
            if(month2>2 && ((year2%4==0 && year2%100!=0)||(year2%400==0))){
                ans++;
            }
            ans +=  D[month1-1] - day1;
            ans += day2;
        }
        
        return ans;
    }
};