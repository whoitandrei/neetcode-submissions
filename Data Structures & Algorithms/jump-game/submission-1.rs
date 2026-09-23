impl Solution {
    pub fn can_jump(nums: Vec<i32>) -> bool {
        let mut max_reach : i32 = 0;

        for i in 0..nums.len() {
            if max_reach < i as i32 {
                return false;
            }
            max_reach = max_reach.max(i as i32 + nums[i]);
        }
        
        max_reach >= (nums.len() as i32 - 1) 
    }
}
