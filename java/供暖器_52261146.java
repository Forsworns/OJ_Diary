class Solution {
    // 双指针，贪心
    public int findRadius(int[] houses, int[] heaters) {
        int i=0, j=0, radius=0;
        final int I=houses.length,J=heaters.length;
        Arrays.sort(houses);
        Arrays.sort(heaters);
        while(i<I){
            if(j==J-1){
                break;
            }else{
                int d1 = Math.abs(houses[i]-heaters[j]), d2 = Math.abs(houses[i]-heaters[j+1]);
                while(d1>=d2){
                    j++;
                    d1 = d2;
                    if(j==J-1){
                        break;
                    }else{
                        d2 = Math.abs(houses[i]-heaters[j+1]);
                    }
                }
                radius = Math.max(radius,d1);
            }
            i++;
        } 
        while(i<I){
            radius = Math.max(radius,Math.abs(houses[i]-heaters[J-1]));
            i++;
        }
        return radius;
    }
}