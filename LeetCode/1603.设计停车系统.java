/*
 * @lc app=leetcode.cn id=1603 lang=java
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem {
    private final int[] data;

    public ParkingSystem(int big, int medium, int small) {
        data = new int[]{0, big, medium, small};
    }

    public boolean addCar(int carType) {
        if (data[carType] > 0) {
            data[carType]--;
            return true;
        }
        return false;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
// @lc code=end
