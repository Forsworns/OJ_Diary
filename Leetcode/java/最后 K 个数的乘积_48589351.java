// 想到了可以只存储积，但是没有注意到是前缀积……直接存出来的不是后缀积
// 另外可以用数组变化来判断是否有零……
class ProductOfNumbers {
    private List<Integer> prevProduct;

    public ProductOfNumbers() {
        prevProduct = new ArrayList<>();
    }
    
    public void add(int num) {
        if(num!=0 && prevProduct.size()==0){
            prevProduct.add(num);
        }else{
            if(num!=0){
                prevProduct.add(num*prevProduct.get(prevProduct.size()-1));
            }else{
                prevProduct.clear();
            }
        }
    }
    
    public int getProduct(int k) {
        if(k>prevProduct.size()){
            return 0;
        }else if(k==prevProduct.size()){
            return prevProduct.get(prevProduct.size()-1);
        }else{
            return prevProduct.get(prevProduct.size()-1)/prevProduct.get(prevProduct.size()-1-k);
        }
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */