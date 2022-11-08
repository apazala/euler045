#include <inttypes.h>
#include <stdio.h>

int low_bound(int64_t value, int64_t arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) >> 1;
        int64_t midval = arr[mid];
        if (midval < value)
            low = mid + 1;
        else if (midval > value)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1);  // key not found.
}

#define LIMIT 1000000
int64_t pentagonal[LIMIT];

int main()
{
    for(int i = 1; i < LIMIT; i++){
        pentagonal[i] = pentagonal[i-1] + 3*i - 2;
    }
    int64_t hex = 0;
    int64_t maxpent = pentagonal[LIMIT-1];
    int count = 0;
    for(int i = 1; count < 3 && hex < maxpent; i++){
        hex = hex + 4*i - 3;
        if(low_bound(hex, pentagonal, LIMIT)>=0){
            printf("%" PRId64 "\n", hex);
            count++;
        }
    }
}