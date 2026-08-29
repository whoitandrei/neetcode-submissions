impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut mp : HashMap<i32, i32> = HashMap::new();

        for i in 0..nums.len() {
            if let Some(&j) = mp.get(&(target - nums[i])) {
                return vec![j, i as i32];
            }
            mp.insert(nums[i], i as i32);
        }

        vec![]
    }
}
