impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut  minPriv : i32 = 2147483647;
        let mut ans : i32 = 0;
        for price in &prices {
            minPriv = std::cmp::min(minPriv, *price);
            ans = std::cmp::max(ans, *price - minPriv);
        }
        ans
    }
}
