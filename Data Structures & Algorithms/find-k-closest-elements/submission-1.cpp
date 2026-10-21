class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (arr.size() <= k) return arr;

        size_t l = 0, r = k;
        for (; 
             r < arr.size() 
             && abs(arr[l] - x) > abs(arr[r] - x)
             || abs(arr[l] - x) == abs(arr[r] - x) && arr[l] == arr[r];
             ++r, ++l) {

        }

        return vector<int>(arr.begin() + l, arr.begin() + r);
    }
};