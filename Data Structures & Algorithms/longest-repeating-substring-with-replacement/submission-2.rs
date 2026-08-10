impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut counter : Vec<i32> = vec![0i32; 26];
        let mut l = 0;
        let mut res : i32 = 0;
        let mut maxFreq = 0;
        let s_bytes = s.as_bytes();

        for r in 0..s.len() {
            counter[(s_bytes[r] - b'A') as usize] += 1;
            maxFreq = max(maxFreq, counter[(s_bytes[r] - b'A') as usize]);

            if (r - l + 1) - maxFreq as usize > k.try_into().unwrap() {
                counter[(s_bytes[l] - b'A') as usize] -= 1;
                l += 1;
            }

            res = max(res, (r - l + 1).try_into().unwrap());
        }

        res
    }
}
