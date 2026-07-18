import java.util.*;

class Solution {
    public int[] sortByBits(int[] arr) {
        // Converting int[] to Integer[] so we can use a custom Comparator
        Integer[] temp = Arrays.stream(arr).boxed().toArray(Integer[]::new);

        Arrays.sort(temp, (a, b) -> {
            int countA = Integer.bitCount(a);
            int countB = Integer.bitCount(b);

            if (countA == countB)
                return a - b;

            return countA - countB;
        });

        // Copy back to the original int[] (auto-unboxing)
        for (int i = 0; i < arr.length; i++) {
            arr[i] = temp[i];
        }

        return arr;
    }
}
