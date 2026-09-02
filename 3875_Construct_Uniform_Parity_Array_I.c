bool uniformArray(int* nums1, int nums1Size) {
    // We can always construct a uniform-parity array.
    //
    // 1. If all numbers are already even, keep them as they are.
    // 2. If all numbers are already odd, keep them as they are.
    // 3. If there are both odd and even numbers, subtract a number
    //    with the opposite parity from each element. The result is odd.
    //
    // Therefore, a valid nums2 can always be constructed.
    // No actual construction is required, so simply return true.

    return true;
}
