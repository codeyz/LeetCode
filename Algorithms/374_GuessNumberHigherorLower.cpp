// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int low, high, mid;
        low = 1, high = n;
        while(low <= high)
        {
            mid = (high - low) / 2 + low;
            if(!guess(mid))
                return mid;
            if(guess(mid) == -1)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};
