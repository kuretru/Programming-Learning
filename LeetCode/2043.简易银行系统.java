/*
 * @lc app=leetcode.cn id=2043 lang=java
 *
 * [2043] 简易银行系统
 */

// @lc code=start
class Bank {
    private final long[] balance;

    public Bank(long[] balance) {
        this.balance = balance;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (verifyAccountId(account1) && verifyAccountId(account2) && verifyAccountMoney(account1, money)) {
            balance[account1 - 1] -= money;
            balance[account2 - 1] += money;
            return true;
        }
        return false;
    }

    public boolean deposit(int account, long money) {
        if (verifyAccountId(account)) {
            balance[account - 1] += money;
            return true;
        }
        return false;
    }

    public boolean withdraw(int account, long money) {
        if (verifyAccountId(account) && verifyAccountMoney(account, money)) {
            balance[account - 1] -= money;
            return true;
        }
        return false;
    }

    private boolean verifyAccountId(int account) {
        return 0 < account && account <= balance.length;
    }

    private boolean verifyAccountMoney(int account, long money) {
        return balance[account - 1] > money;
    }
}

/**
 * Your Bank object will be instantiated and called as such:
 * Bank obj = new Bank(balance);
 * boolean param_1 = obj.transfer(account1,account2,money);
 * boolean param_2 = obj.deposit(account,money);
 * boolean param_3 = obj.withdraw(account,money);
 */
// @lc code=end
