class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = Arrays.stream(A).reduce((a,b)->a+b).getAsInt();
        if(sum % 3 != 0){
            return false;
        }
        int current = 0;
        int count = 0;
        boolean ans = false;
        for(int a : A){
            current += a;
            if(current == sum / 3){
                count++;
                current = 0;
            }
        }
        return count == 3;
    }
}