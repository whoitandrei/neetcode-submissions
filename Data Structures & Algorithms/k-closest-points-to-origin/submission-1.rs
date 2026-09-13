use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn k_closest(points: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut heap: BinaryHeap<Reverse<(i64, Vec<i32>)>> = BinaryHeap::new();

        for p in points {
            let d = (p[0] as i64).pow(2) + (p[1] as i64).pow(2);
            heap.push(Reverse((d, p)));
        }

        let mut ans = Vec::new();
        for _ in 0..k {
            match heap.pop() {
                Some(Reverse((_, p))) => ans.push(p),
                None => break,
            }
        }

        return ans;
    }
}
