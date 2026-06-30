int singleNumber(int* nums, int numsSize) {
    int x = 0;

    //All other numbers are exactly two times while the output alone is single time;
    //If a number XOR with itself results 000 (two times), and those result XOR with the (single time) number gives the answer;

    for(int i = 0; i<numsSize; i++){
        x = x ^ nums[i];
    }
    return x;
}
