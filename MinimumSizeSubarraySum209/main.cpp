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
    if (nums.size() == 0){
        return 0;
    }
    int beginPtr = 0, endPtr = 0;
    int arraySize = nums.size();
    int sum = 0;
    while(beginPtr < nums.size()-1){
        //If that sum is smaller, make window larger
        if(sum < s && endPtr < nums.size()-1){
            cout << "First conditional\n";
            sum += nums[endPtr];
            //To prevent endPtr from adding over and over while at the end
//            if(endPtr < nums.size()-1 && endCounter < 5){
//                sum += nums[endPtr];
//                endCounter++;
//            }
            if(endPtr < nums.size()-1){
                endPtr++;
            }
            cout << "beginPtr:" << beginPtr << " beginPtrValue:" << nums[beginPtr] << " endPtr:"<< endPtr << " endPtrValue:" << nums[endPtr] << "\n";
            cout << "sum after addition: " << sum << "\n";
            cout << "arraySize: " << arraySize << "\n";
        }
        //If sum is larger, compare window size and make window smaller
        else if(sum >= s){
            cout << "Second conditional\n";
            sum -= nums[beginPtr];
            beginPtr++;
            arraySize = min(endPtr - beginPtr, arraySize);
            cout << "beginPtr:" << beginPtr << " beginPtrValue:" << nums[beginPtr] << " endPtr:"<< endPtr << " endPtrValue:" << nums[endPtr] << "\n";
            cout << "sum after subtraction: " << sum << "\n";
            cout << "arraySize: " << arraySize << "\n";
        }
        else{
            return arraySize;
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
