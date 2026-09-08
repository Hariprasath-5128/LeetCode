// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    
    int bad = -1;
    int start = 1;
    int end = n;

    while(start <= end){
        int mid = start + (end - start)/2 ;
        if(isBadVersion(mid)){
            bad = mid;
            end = mid - 1;
        }

        else{
            start = mid + 1;
        }
    }

    return bad;
}
