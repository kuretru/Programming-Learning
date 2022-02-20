/*
 * @lc app=leetcode.cn id=969 lang=java
 *
 * [969] 煎饼排序
 */

// @lc code=start
class Solution {
    private void reverse(int[] data, int k) {
        for (int i = 0, j = k; i < j; i++, j--) {
            int tmp = data[i];
            data[i] = data[j];
            data[j] = tmp;
        }
    }

    private boolean finished(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] > arr[i]) {
                return false;
            }
        }
        return true;
    }

    public List<Integer> pancakeSort(int[] arr) {
        List<Integer> data = new ArrayList<>(arr.length);
        for (int i : arr) {
            data.add(i);
        }
        Collections.sort(data);
        List<Integer> result = new ArrayList<>();
        for (int i = arr.length - 1; i >= 0; i--) {
            if (finished(arr)) {
                break;
            }
            for (int j = 0; j <= i; j++) {
                if (arr[j] == data.get(i)) {
                    if (j > 0) {
                        reverse(arr, j);
                        result.add(j + 1);
                    }
                    reverse(arr, i);
                    result.add(i + 1);
                    break;
                }
            }
        }
        return result;
    }
}
// @lc code=end
