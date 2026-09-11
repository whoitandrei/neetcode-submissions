impl Solution {
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut pq = BinaryHeap::new();

        for stone in stones {
            pq.push(stone);
        }

        while pq.len() >= 2 {
            let first = pq.pop().unwrap();
            let second = pq.pop().unwrap();

            if first - second > 0 {
                pq.push(first - second);
            }
        }

        if pq.len() > 0 {
            return pq.pop().unwrap();
        }
        0
    }
}
