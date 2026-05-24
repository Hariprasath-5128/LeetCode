long long max(long long a, long long b){
    return (a > b) ? a : b;
}

// https://chatgpt.com/c/6a129d37-0560-8321-92d5-9b07b2245790
// Clear explanation for derivation of the recurrence relation

int maxRotateFunction(int* nums, int numsSize) {
    long long sum = 0;
    long long f0 = 0;

    // Calculate total sum and F(0)
    for(int i = 0; i < numsSize; i++){
        sum += nums[i];
        f0 += (long long)i * nums[i];
    }

    long long ans = f0;
    long long curr = f0;

    // Use recurrence relation:
    // F(k) = F(k-1) + sum - n * nums[n-k]
    for(int k = 1; k < numsSize; k++){
        curr += sum - (long long)numsSize * nums[numsSize - k];
        ans = max(ans, curr);
    }

    return (int)ans;
}
