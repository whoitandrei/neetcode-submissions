// The guess API is already defined for you.
// fn guess(num: i64) -> i32:
//     -1 if num is higher than the picked number
//      1 if num is lower than the picked number
//      0 if num is equal to the picked number

impl Solution {
    pub unsafe fn guess_number(n: i64) -> i64 {
        let mut l = 0;
        let mut r = n;

        while l <= r {
            let mid = l + (r - l) / 2;

            match unsafe { guess(mid) } {
                0 => return mid,
                1 => l = mid + 1,
                -1 => r = mid - 1,
                _ => unreachable!(),
            }
        }
        unreachable!()
    }
}
