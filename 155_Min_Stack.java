import java.util.*;

class MinStack {

    List<Integer> list = new ArrayList<>();
    List<Integer> minStack = new ArrayList<>();

    public MinStack() {
    }

    public void push(int value) {
        list.add(value);

        if (minStack.isEmpty()) {
            minStack.add(value);
        } else {
            int min = Math.min(value, minStack.get(minStack.size() - 1));
            minStack.add(min);
        }
    }

    public void pop() {
        list.remove(list.size() - 1);
        minStack.remove(minStack.size() - 1);
    }

    public int top() {
        return list.get(list.size() - 1);
    }

    public int getMin() {
        return minStack.get(minStack.size() - 1);
    }
}
