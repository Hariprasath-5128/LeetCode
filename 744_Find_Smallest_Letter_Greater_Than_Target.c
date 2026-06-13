char nextGreatestLetter(char* letters, int lettersSize, char target) {
    int low = 0; 
    int high = lettersSize-1;
    while(low<high){
        int mid = (low+high)/2;
        
        if(letters[mid]>target){
            high = mid; // not mid-1 because you may loose the immediate greater element than the target
        }
        else{
            low = mid+1;
        }
    }
    return letters[low]>target ? letters[low]: letters[0];
}
