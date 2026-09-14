impl Solution {
    pub fn find_kth_largest(nums: Vec<i32>, k: i32) -> i32 {
        let mut heap : BinaryHeap<i32> = BinaryHeap::new();
        for num in nums {
            heap.push(num);
        }
        
        let mut res = 0;
        for i in 1..k+1 {
            if i == k {
                res = heap.pop().unwrap();
            }
            heap.pop();
        }
        res
    }
}
