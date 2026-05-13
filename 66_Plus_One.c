/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    if(digits[digitsSize-1] != 9){
        digits[digitsSize-1]++;
        *returnSize = digitsSize;
        return digits;
    }
    else{

        bool isallnine = true;

        for(int i = 0; i < digitsSize; i++){ 
            if(digits[i] != 9){
                isallnine = false;
                break;
            }
        }

        if(isallnine){

            int* newarr = (int*)malloc(sizeof(int) * (digitsSize + 1)); 

            newarr[0] = 1;

            for(int i = 1; i <= digitsSize; i++){
                newarr[i] = 0;
            }

            *returnSize = digitsSize + 1; 
            return newarr;
        }
        else{

            int k = digitsSize - 1;

            while(digits[k] == 9){
                digits[k] = 0;
                k--;
            }

            digits[k]++;

            *returnSize = digitsSize;
            return digits;
        }
    }
}