impl Solution {
    pub fn least_interval(tasks: Vec<char>, n: i32) -> i32 {
        let mut heap : BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();
        let mut freq : HashMap<char, i32> = HashMap::new();

        for c in tasks {
            *freq.entry(c).or_insert(0) += 1;
        }

        for &f in freq.values() {
            heap.push(Reverse((0, f)));
        }

        let mut time : i32 = 0;
        while let Some(&Reverse((t, l))) = heap.peek() {
            let data = heap.peek();
            if t > time {
                time = t;
            }
            if t <= time {
                heap.pop();
                if l > 1 {
                    heap.push(Reverse((t + n + 1, l - 1)));
                }
            }
            time += 1;
        }
        time
    }
}
