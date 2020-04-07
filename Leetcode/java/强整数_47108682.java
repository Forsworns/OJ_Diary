class Solution {
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        Set<Integer> s = new HashSet<>();
        if(bound>=2) {
            s.add(2);
        } 
        if(x==1&&y!=1){
            for(int j=0;1+Math.pow(y,j)<=bound;++j){
                s.add((int) (1+Math.pow(y,j)));
            }
        } else if(x!=1&&y==1){
            for(int i=0;1+Math.pow(x,i)<=bound;++i){
                s.add((int) (Math.pow(x,i)+1));
            }
        } else if(x!=1&&y!=1){
            for(int i=0;Math.pow(x,i)<=bound;++i){
                for(int j=0;Math.pow(x,i)+Math.pow(y,j)<=bound;++j){
                    s.add((int) (Math.pow(x,i)+Math.pow(y,j)));
                }
            }
        }
        return new ArrayList<Integer>(s);
    }
}