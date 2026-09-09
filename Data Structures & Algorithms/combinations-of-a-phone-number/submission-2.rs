impl Solution {

    fn backtrack(digits : &str,
                 ind : usize,
                 mapping : &[&str; 8],
                 cur : &mut String,
                 res : &mut Vec<String>) {

        if ind == digits.len() {
            res.push(cur.clone());
            return;
        }

        let digit = digits.as_bytes()[ind] - b'2';
        let letters = mapping[digit as usize];

        for letter in letters.chars() {
            cur.push(letter);
            Self::backtrack(
                digits,
                ind + 1,
                mapping,
                cur,
                res
            );
            cur.pop();
        }
    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() {
            return Vec::new();
        }

        let mapping = [
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
        ];

        let mut res = Vec::new();
        let mut cur = String::new();

        Self::backtrack(
            &digits,
            0,
            &mapping,
            &mut cur,
            &mut res
        );

        return res;
    }
}
