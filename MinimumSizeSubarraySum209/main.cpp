//
//  main.cpp
//  MinimumSizeSubarraySum209
//
//  Created by Aj Gill on 9/22/19.
//  Copyright © 2019 Aj Gill. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    //Arbitrary large starting number for arraySize
    int beginPtr = 0, arraySize = 100000000, sum = 0;
    //Replaced while loop with a for loop to keep track of the end pointer for me
    for(int endPtr = 0; endPtr<nums.size(); endPtr++){
        sum += nums[endPtr];
        //If the sum meets the condition, check if the array size is smaller and make the window smaller
        while(sum >= s) {
            arraySize = min(endPtr - beginPtr + 1, arraySize);
            sum -= nums[beginPtr];
            beginPtr++;
        }
    }
    //If no match was found and the arraySize is still the same, return 0
    if(arraySize == 100000000){
        return 0;
    }
    return arraySize;
}

int main() {
    int s = 7;
    vector<int> numbers = {2,3,1,2,4,3};
    int minLength = minSubArrayLen(s, numbers);
    cout << minLength << "\n";
}
