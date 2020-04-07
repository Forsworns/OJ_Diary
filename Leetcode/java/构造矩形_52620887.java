class Solution {
    public int[] constructRectangle(int area) {
        // L>=W
        int L=area, W;
        for(W=(int) Math.floor(Math.sqrt(area));W>=1;--W){
            if(area%W==0){
                L=area/W;
                break;
            }
        }
        return new int[]{L,W};
    }
}