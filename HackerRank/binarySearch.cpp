#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'binarySearch' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY nums
#  2. INTEGER target
#

def binarySearch(nums, target):
    n = len(nums);
    low = 0;
    high = n -1;
    while (low <= high):
        midpoint = low + (int)((high - low) // 2);
        if (nums[midpoint] == target):
            return midpoint;
        elif (nums[midpoint] > target):
            high = midpoint - 1;
        elif (nums[midpoint] < target ):
            low = midpoint + 1;
    return -1
if __name__ == '__main__':
    nums_count = int(input().strip())

    nums = []

    for _ in range(nums_count):
        nums_item = int(input().strip())
        nums.append(nums_item)

    target = int(input().strip())

    result = binarySearch(nums, target)

    print(result)

