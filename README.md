The Idea of Solution:

First, we have array of numbers, and we want to reorder it such that 
nums[0] < nums[1] > nums[2] < nums[3].... .

We observe that the required array needs to be small and big ones, so we rearrange it to be
small < big > small < big > small… .

First, we sort the array:
So, numbers are ordered from small → big
Example: [5,5,5,4,4,4,4]
After sort: [4,4,4,4,5,5,5]

Then, Split into two halves:
small = [4,4,4,4]
big = [5,5,5]

Then, Fill alternately
Even indices → take small
Odd indices → take big
So, we fill like:
index: 0 1 2 3 4 5 6
put:   s b s b s b s
