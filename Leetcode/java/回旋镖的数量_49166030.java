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
            Map<Integer,Integer> distances = new HashMap<>(); 
            for(int j=0;j<n;++j){
                int d = compute(points[i],points[j]);
                distances.compute(d, (k,v) -> {
                    if(v==null){
                        return 1;
                    }else{
                        return v+1;
                    }
                });
            }

            for(int amount:distances.values()){
                ans += amount*(amount-1);
            }
        }
        return ans;
    }
}