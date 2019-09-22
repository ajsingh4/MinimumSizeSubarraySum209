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
    int beginPtr = 0, endPtr = 0;
    int arraySize = 1000000;
    int sum = 0;
    while(endPtr < nums.size()){
        //If that sum is smaller, make window larger
        if(sum < s){
            cout << "Running through the if\n";
            sum += nums[endPtr];
            cout << "beginPtr:" << beginPtr << " beginPtrValue:" << nums[beginPtr] << " endPtr:"<< endPtr << " endPtrValue:" << nums[endPtr] << "\n";
            cout << "sum: " << sum << "\n";
            endPtr++;
            continue;
        }
        //If sum is larger, compare window size and make window smaller
        if(sum >= s){
            cout << "Running through the else if\n";
            sum -= nums[beginPtr];
            cout << "beginPtr:" << beginPtr << " beginPtrValue:" << nums[beginPtr] << " endPtr:"<< endPtr << " endPtrValue:" << nums[endPtr] << "\n";
            cout << "sum: " << sum << "\n";
            if((endPtr - beginPtr) < arraySize){
                arraySize = endPtr - beginPtr;
            }
            cout << "arraySize: " << arraySize << "\n";
            beginPtr++;
        }
    }
    return arraySize;
}

int main() {
    int s = 7;
    vector<int> numbers = {2,3,1,2,4,3};
    int minLength = minSubArrayLen(s, numbers);
    cout << minLength << "\n";
}
