#include <algorithm>
#include <iostream>
#include <vector>

//given a binary array and an integer k, find the maxium consecutive 1s after flipping at most k 0s. 
//key idea: sliding window approach (using indexes) to find the answer in linear time
//the subarray can only contain at most k 0s (because we can flip them)
//keep track of zeros, if the amount of zeros exceeds k, move the left index, if the left is on a zero, take it away

int maxOnes(const std::vector<int>& arr, int k) {
    int n = arr.size();
    int zeros = 0;
    int maxLen = 0;
    int left = 0;
    int right = 0;

    while (right < n) {
        if (arr[right] == 0) {
            zeros++;
        }

        if (zeros > k) {
            if (arr[left] == 0) {
                zeros--;
            }
            left++;
        }

        if (zeros <= k) {
            int len = right - left + 1;
            maxLen = std::max(maxLen, len);
        }
        right++;

        std::cout << "right = " << right << ", left = " << left << ", zeros = " << zeros << ", maxLen = " << maxLen << "\n";
    }

    return maxLen;
}


int main() {

    std::vector<int> array { 1, 0, 0, 0, 1, 1, 1, 0, 1, 0 };

    std::cout << maxOnes(array, 2) << "\n";
        
    return 0;
}
