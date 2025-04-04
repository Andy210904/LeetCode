/**
 * // This is MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface MountainArray {
 *     public int get(int index) {}
 *     public int length() {}
 * }
 */
 
class Solution {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int n = mountainArr.length();
        int l = 0;
        int r = n - 1;
        int peak = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            int m = mountainArr.get(mid);
            int a = (mid > 0) ? mountainArr.get(mid - 1) : Integer.MIN_VALUE;
            int b = (mid < n - 1) ? mountainArr.get(mid + 1) : Integer.MIN_VALUE;

            if (a < m && m < b) {
                l = mid + 1;
            } else if (a > m && m > b) {
                r = mid - 1;
            } else {
                peak = mid;
                break;
            }
        }

        // If target is at the peak index
        if (target == mountainArr.get(peak)) {
            return peak;
        } 
        int l1 = 0;
        int r1 = peak - 1;
        int l2 = peak + 1;
        int r2 = n - 1;
        while (l1 <= r1) {
            int mid = (l1 + r1) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val < target) {
                l1 = mid + 1;
            } else {
                r1 = mid - 1;
            }
        }
        while (l2 <= r2) {
            int mid = (l2 + r2) / 2;
            int val = mountainArr.get(mid);
            if (val == target) {
                return mid;
            } else if (val > target) {
                l2 = mid + 1;
            } else {
                r2 = mid - 1;
            }
        }
        return -1;
    }
}
