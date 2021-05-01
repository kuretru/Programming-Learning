import java.util.*;

/*
 * @lc app=leetcode.cn id=690 lang=java
 *
 * [690] 员工的重要性
 */

// @lc code=start
/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> data = new HashMap<>();
        for (Employee employee : employees) {
            data.put(employee.id, employee);
        }
        Deque<Integer> queue = new LinkedList<>();
        queue.add(id);
        int result = 0;
        while (!queue.isEmpty()) {
            Employee employee = data.get(queue.pop());
            result += employee.importance;
            for (int subordinate : employee.subordinates) {
                queue.push(subordinate);
            }
        }
        return result;
    }
}
// @lc code=end
