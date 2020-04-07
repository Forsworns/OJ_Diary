impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        if prices.len()==0 {
            return 0
        }
        let mut buy_in = prices[0];
        let mut profit = 0;
        for i in 1..prices.len() {
            if prices[i] < prices[i-1] {
                profit = profit + prices[i-1] - buy_in; // yesterday should sold
                buy_in = prices[i];
            } 
        }
        if prices[prices.len()-1] != buy_in {
            profit += prices[prices.len()-1] - buy_in; // discuss last day
        }
        return profit
    }
}