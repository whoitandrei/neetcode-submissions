impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        if s1.len() > s2.len() {
            return false;
        }

        let mut count_ideal = [0i32; 26];
        for &b in s1.as_bytes() {
            count_ideal[(b - b'a') as usize] += 1;
        }
        
        let n1 = s1.len();
        let mut count_s2 = [0i32; 26];
        for &b in &s2.as_bytes()[..n1] {
            count_s2[(b - b'a') as usize] += 1;
        }

        let s2_bytes = s2.as_bytes();
        for i in n1..s2_bytes.len() {
            if count_s2 == count_ideal {
                return true;
            }
            let out = s2_bytes[i - n1];
            let in_ = s2_bytes[i];
            count_s2[(out - b'a') as usize] -= 1;
            count_s2[(in_ - b'a') as usize] += 1;
        }

        count_s2 == count_ideal
    }
}
