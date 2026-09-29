impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let n : i32 = nums.len() as i32;
        let mut res = n;

        for i in 0..n {
            res = res ^ i;
            res = res ^ nums[i as usize];
        }

        res
    }
}
