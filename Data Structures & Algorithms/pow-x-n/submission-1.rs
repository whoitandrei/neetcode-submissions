impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        if x == 0 as f64 {
            return 0f64;
        }
        if n == 0 {
            return 1f64
        }

        let mut res = Self::my_pow(x, (n/2).abs());
        res = res * res;
        if (n).abs() % 2 > 0 { 
            res = res * x 
        }

        if n > 0 {
            return res;
        }

        1f64 / res
    }
}
