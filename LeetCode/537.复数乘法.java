/*
 * @lc app=leetcode.cn id=537 lang=java
 *
 * [537] 复数乘法
 */

// @lc code=start
class ComplexNumber {
    private int realPart;
    private int imaginaryPart;

    public ComplexNumber(String num) {
        int plusIndex = num.indexOf('+');
        this.realPart = Integer.parseInt(num.substring(0, plusIndex));
        this.imaginaryPart = Integer.parseInt(num.substring(plusIndex + 1, num.length() - 1));
    }

    public ComplexNumber multiply(ComplexNumber y) {
        int realPart = this.realPart * y.realPart - this.imaginaryPart * y.imaginaryPart;
        int imaginaryPart = this.imaginaryPart * y.realPart + y.imaginaryPart * this.realPart;
        this.realPart = realPart;
        this.imaginaryPart = imaginaryPart;
        return this;
    }

    @Override
    public String toString() {
        return String.format("%d+%di", realPart, imaginaryPart);
    }
}

class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        ComplexNumber x = new ComplexNumber(num1);
        ComplexNumber y = new ComplexNumber(num2);
        x = x.multiply(y);
        return x.toString();
    }
}
// @lc code=end
