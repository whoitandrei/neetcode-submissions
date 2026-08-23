impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut pq = BinaryHeap::new();
        let mut ans = Vec::new();
        let k = k as usize;

        for i in 0..nums.len() {
            pq.push((nums[i], i));

            if i >= k {
                while let Some(&(_, ind)) = pq.peek() {
                    if ind <= i - k {
                        pq.pop();
                    } else {
                        break;
                    }
                }
            }

            if i >= k - 1 {
                if let Some(&(value, _)) = pq.peek() {
                    ans.push(value);
                }
            }
        }

        ans
    }
}
