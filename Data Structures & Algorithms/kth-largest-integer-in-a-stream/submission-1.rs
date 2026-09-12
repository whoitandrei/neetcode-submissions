use std::cmp::Reverse;
use std::collections::BinaryHeap;

struct KthLargest {
    heap : BinaryHeap<Reverse<i32>>,
    k : usize,
}

impl KthLargest {
    pub fn new(k: i32, nums: Vec<i32>) -> Self {
        let k = k as usize;
        let mut heap = BinaryHeap::new();

        for num in nums {
            heap.push(Reverse(num));

            while heap.len() > k {
                heap.pop();
            }
        }

        Self { heap, k }
    }

    pub fn add(&mut self, val: i32) -> i32 {
        self.heap.push(Reverse(val));

        while self.heap.len() > self.k {
            self.heap.pop();
        }

        self.heap.peek().unwrap().0
    }
}
