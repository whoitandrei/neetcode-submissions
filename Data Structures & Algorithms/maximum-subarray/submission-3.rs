impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        let mut curSum : i32 = i32::MIN;
        let mut maxSum : i32 = i32::MIN;

        for num in nums {
            if curSum < 0 {
                curSum = num;
            } else {
                curSum += num;
            }

            maxSum = maxSum.max(curSum);
        }

        return maxSum;
    }
}
