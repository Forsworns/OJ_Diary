class Solution {
    static final String[] WEEK = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    static final int[] MONTHS = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    static final int YEAR = 2020;
    static final int MONTH = 2;
    static final int DAY = 23;

    private int trans2day(int day, int month, int year){
        int total = 0;
        year = year;
        int leapNumbers = year/4+year/400-year/100;
        total = leapNumbers + year*365;
        if(((year%4==0&&year%100!=0)||year%400==0) && month<3){
            total-=1;
        }
        for(int i=1;i<month;++i){
            total+=MONTHS[i];
        }
        total+=day;
        return total;
    }

    public String dayOfTheWeek(int day, int month, int year) {
        int refer = trans2day(DAY,MONTH,YEAR);
        int target = trans2day(day,month,year);
        return WEEK[((target-refer)%7+7)%7];
    }
}