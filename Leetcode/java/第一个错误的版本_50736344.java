/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */
// 同样是二分查找
public class Solution extends VersionControl {
    private int binary(int low,int high){
        if(low>=high-1){
            if(isBadVersion(low)){
                return low;
            }else{
                return high;
            }
        }else{
            int now = low+(high-low)/2; // 二分的这个技巧很重要，否则很容易溢出
            if(isBadVersion(now)){
                return binary(low,now);
            }else{
                return binary(now,high);
            }
        }
    }
    public int firstBadVersion(int n) {
        return binary(1,n);
    }
}