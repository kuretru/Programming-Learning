import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @lc app=leetcode.cn id=1600 lang=java
 *
 * [1600] 皇位继承顺序
 */

// @lc code=start
class Person {
    final String name;
    final List<Person> children;
    boolean dead;

    public Person(String name) {
        this.name = name;
        this.dead = false;
        this.children = new ArrayList<>();
    }
}

class ThroneInheritance {
    private final Map<String, Person> map;
    private final Person king;

    public ThroneInheritance(String kingName) {
        this.map = new HashMap<>();
        this.king = new Person(kingName);
        this.map.put(kingName, king);
    }

    public void birth(String parentName, String childName) {
        Person child = new Person(childName);
        map.get(parentName).children.add(child);
        map.put(childName, child);
    }

    public void death(String name) {
        map.get(name).dead = true;
    }

    public List<String> getInheritanceOrder() {
        List<String> result = new ArrayList<>();
        preorderTravel(result, king);
        return result;
    }

    private void preorderTravel(List<String> result, Person root) {
        if (!root.dead) {
            result.add(root.name);
        }
        for (Person child : root.children) {
            preorderTravel(result, child);
        }
    }
}

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */
// @lc code=end
