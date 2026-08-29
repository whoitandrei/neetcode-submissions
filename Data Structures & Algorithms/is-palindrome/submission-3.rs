impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut l = 0;
        let s = s.as_bytes();
        let mut r = s.len();


        while l < r {
            while l < r && !s[l].is_ascii_alphanumeric() {
                l += 1;
            }
            while l < r && !s[r - 1].is_ascii_alphanumeric() {
                r -= 1;
            }

            if l >= r {
                break;
            }

            if s[l].to_ascii_lowercase() != s[r - 1].to_ascii_lowercase() {
                return false;
            }

            l += 1;
            r -= 1;
        }
        return true;
    }
}
