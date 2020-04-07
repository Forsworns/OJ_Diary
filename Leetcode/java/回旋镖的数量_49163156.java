import java.util.Arrays;

class Solution {
    private int compute(int[] p1, int[] p2){
        return (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);
    }

    public int numberOfBoomerangs(int[][] points) {
        int n = points.length;
        int ans = 0;
        for(int i=0;i<n;++i){
            // fix i, select j and k
            int[] distances = new int[n];
            for(int j=0;j<n;++j){
                distances[j] = compute(points[i],points[j]);
            }

            int now = distances[0];
            int amount = 0;
            Arrays.sort(distances);
            for(int d:distances){
                if(d!=now){
                    ans+=amount*(amount-1);
                    amount = 1;
                    now = d;
                }else{
                    amount++;
                }
            }
            ans += amount*(amount-1);
        }
        return ans;
    }
}