# Lecture 4. Search

## Linear search
### 1 Introduction
In Linear Search, we iterate over all the elements of the array and check if it the current element is equal to the target element. If we find any element to be equal to the target element, then return the index of the current element. Otherwise, if no element is equal to the target element, then return -1 as the element is not found. Linear search is also known as sequential search.
### 2 Algorithm
For example: Consider the array ```arr[] = {10, 50, 30, 70, 80, 20, 90, 40}``` and ```key = 30```.
![l1](https://github.com/user-attachments/assets/ddf30d23-0134-4ca3-99a3-2e9136e27d71)  
![l2](https://github.com/user-attachments/assets/8083b5e5-5990-4b7b-8646-4e5729d10f37)  
![l3](https://github.com/user-attachments/assets/102f555b-b7ae-4843-8596-a7f537147503)

### 3 Complexity Analysis of linear search
#### 1. Time Complexity:
• Best Case: In the best case, the key might be present at the first index. So the best case complexity is O(1).  
• Average Case: O(n).  
• Worst Case: In the worst case, the key might be present at the last index i.e., opposite to the end from which the search has started in the list. So the worst-case complexity is O(n) where N is the size of the list.
#### 2. Auxiliary Space:
• O(1) as except for the variable to iterate through the list, no other variable is used. 
### 4 Advantages of linear search
• Linear search can be used irrespective of whether the array is sorted or not. It can be used on arrays of any data type.  
• Does not require any additional memory.  
• It is a well-suited algorithm for small datasets.  
### 5 Disadvantages of linear search
• Linear search has a time complexity of O(n), which in turn makes it slow for large datasets.  
• Not suitable for large arrays.  

## Binary search
### 1 Introduction
Binary search is a search algorithm used to find the position of a target value within a sorted array. It works by repeatedly dividing the search interval in half until the target value is found or the interval is empty. The search interval is halved by comparing the target element with the middle value of the search space.
### 2 Algorithm
1. Divide the search space into two halves by finding the middle index “mid”. 
2. Compare the middle element of the search space with the key. 
3. If the key is found at middle element, the process is terminated.
4. If the key is not found at middle element, choose which half will be used as the next search space.
  - If the key is smaller than the middle element, then the left side is used for next search.
  - If the key is larger than the middle element, then the right side is used for next search.
5. This process is continued until the key is found or the total search space is exhausted.  
To understand the working of binary search, consider the following illustration:
Consider an array ```arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}``` and the ```target = 23```.
![b1](https://github.com/user-attachments/assets/5208e96a-d328-442e-b188-e0ec09c9b26a)
![b2](https://github.com/user-attachments/assets/3e6240a5-d94e-4d41-81ef-81b2ce0e200a)
![b3](https://github.com/user-attachments/assets/0302521a-1b68-4edb-bfba-7ea03301899b)
![b4](https://github.com/user-attachments/assets/02ebb7ae-de84-4fd2-ae94-b73d4e087a1e)

The Binary Search Algorithm can be implemented in the following two ways:  
- Iterative Binary Search Algorithm
- Recursive Binary Search Algorithm
### 3 Complexity Analysis of Binary search
#### 1. Time Complexity:
• Best Case: O(1).  
• Average Case: O(log(n)).  
• Worst Case: O(log(n)).  
#### 2. Auxiliary Space:
• O(1), If the recursive call stack is considered then the auxiliary space will be O(log(n)).  
### 4 Advantages of Binary search
• Binary search is faster than linear search, especially for large arrays.  
• More efficient than other searching algorithms with a similar time complexity, such as interpolation search or exponential search.  
• Binary search is well-suited for searching large datasets that are stored in external memory, such as on a hard drive or in the cloud.  
### 5 Disadvantages of Binary search
• The array should be sorted.  
• Binary search requires that the data structure being searched be stored in contiguous memory locations.   
• Binary search requires that the elements of the array be comparable, meaning that they must be able to be ordered.  

## Jump search
### 1 Introduction
Like Binary Search, Jump Search is a searching algorithm for sorted arrays. The basic idea is to check fewer elements (than linear search) by jumping ahead by fixed steps or skipping some elements in place of searching all elements.  
The increasing order of performance is:
linear search  <  jump search  <  binary search  
### 2 Algorithm
- Jump Search is an algorithm for finding a specific value in a sorted array by jumping through certain steps in the array.
- The steps are determined by the sqrt of the length of the array. 
- Here is a step-by-step algorithm for the jump search:
- Determine the step size m by taking the sqrt of the length of the array n.
- Start at the first element of the array and jump m steps until the value at that position is greater than the target value.
- Once a value greater than the target is found, perform a linear search starting from the previous step until the target is found or it is clear that the target is not in the array.
- If the target is found, return its index. If not, return -1 to indicate that the target was not found in the array. 

### 3 Complexity Analysis of Jump search
#### 1. Time Complexity:
•  O(?n).
#### 2. Auxiliary Space:
• O(1).  
### 4 Advantages of Jump search
• Better than a linear search for arrays where the elements are uniformly distributed.  
• Jump search has a lower time complexity compared to a linear search for large arrays.  
• The number of steps taken in jump search is proportional to the square root of the size of the array, making it more efficient for large arrays.  
• It is easier to implement compared to other search algorithms like binary search or ternary search.  
• Jump search works well for arrays where the elements are in order and uniformly distributed, as it can jump to a closer position in the array with each iteration.  
### 5 Important points
• Works only with sorted arrays.  
• The optimal size of a block to be jumped is (? n). This makes the time complexity of Jump Search O(? n).  
• The time complexity of Jump Search is between Linear Search ((O(n)) and Binary Search (O(Log(n))).  
• Binary Search is better than Jump Search, but Jump Search has the advantage that we traverse back only once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be searched is the smallest element or just bigger than the smallest). So, in a system where binary search is costly, we use Jump Search.  

## Ternary search
### 1 Introduction
Ternary search is a search algorithm that is used to find the position of a target value within a sorted array. It operates on the principle of dividing the array into three parts instead of two, as in binary search. The basic idea is to narrow down the search space by comparing the target value with elements at two points that divide the array into three equal parts.  
### 2 Algorithm
1. Initialization:  
- Set two pointers, left and right, initially pointing to the first and last elements of our search space.  
2. Divide the search space:  
- Calculate two midpoints, mid1 and mid2, dividing the current search space into three roughly equal parts:  
- mid1 = left + (right – left) / 3  
- mid2 = right – (right – left) / 3  
- The array is now effectively divided into [left, mid1], (mid1, mid2), and [mid2, right].  
3. Comparison with Target:  
- If the target is equal to the element at mid1 or mid2, the search is successful, and the index is returned
- If the target is less than the element at mid1, update the right pointer to mid1 – 1.
- If the target is greater than the element at mid2, update the left pointer to mid2 + 1.
- If the target is between the elements at mid1 and mid2, update the left pointer to mid1 + 1 and the right pointer to mid2 – 1.
4. Repeat or Conclude:  
- Repeat the process with the reduced search space until the target is found or the search space becomes empty.
- If the search space is empty and the target is not found, return a value indicating that the target is not present in the array.
Illustration:  
![t](https://github.com/user-attachments/assets/a95c535f-fc52-428f-bbc1-04979da6dbb2)

### 3 Complexity Analysis of Ternary search
#### 1. Time Complexity:
•  O(2 * log3n).
#### 2. Auxiliary Space:
• O(log3n).  
### 4 Advantages of Ternary search
• Ternary search can find maxima/minima for unimodal functions, where binary search is not applicable.  
• Ternary Search has a time complexity of O(2 * log3n), which is more efficient than linear search and comparable to binary search.  
• Fits well with optimization problems.  
### 5 Disadvantages of Ternary search
• Ternary Search is only applicable to ordered lists or arrays, and cannot be used on unordered or non-linear data sets.  
• Ternary Search takes more time to find maxima/minima of monotonic functions as compared to Binary Search.  

## Exponential search
### 1 Introduction
The name of this searching algorithm may be misleading as it works in O(Log n) time. The name comes from the way it searches an element.  
### 2 Algorithm
The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater.  
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration).  
### 3 Complexity Analysis of Exponential search
#### 1. Time Complexity:
• O(log(n)).  
#### 2. Auxiliary Space:
• The above implementation of Binary Search is recursive and requires  O(log(n)) space. With iterative Binary Search, we need only O(1) space.  
### 4 Applications of Exponential Search
Exponential Binary Search is particularly useful for unbounded searches, where size of array is infinite.  
It works better than Binary Search for bounded arrays, and also when the element to be searched is closer to the first element.

## interpolation search
### 1 Introduction
The Interpolation Search is an improvement over Binary Search for instances, where the values in a sorted array are uniformly distributed. Interpolation constructs new data points within the range of a discrete set of known data points. Binary Search always goes to the middle element to check. On the other hand, interpolation search may go to different locations according to the value of the key being searched. For example, if the value of the key is closer to the last element, interpolation search is likely to start search toward the end side.  
To find the position to be searched, it uses the following formula.  
![int](https://github.com/user-attachments/assets/cd96c7ed-9bb9-4700-8627-59733c200da0)

### 2 Algorithm
• In a loop, calculate the value of “pos” using the probe position formula.  
• Step2: If it is a match, return the index of the item, and exit.  
• Step3: If the item is less than arr[pos], calculate the probe position of the left sub-array. Otherwise, calculate the same in the right sub-array.  
• Step4: Repeat until a match is found or the sub-array reduces to zero.  

### 3 Complexity Analysis of Interpolation search
#### 1. Time Complexity:
• O(log2(log2(n))) for the average case, and O(n) for the worst case.  
#### 2. Auxiliary Space:
• O(1).  

- [Linear Search](https://www.geeksforgeeks.org/linear-search/)
- [Binary Search](https://www.geeksforgeeks.org/binary-search/)
- [Jump Search](https://www.geeksforgeeks.org/jump-search/)
- [Ternary Search](https://www.geeksforgeeks.org/ternary-search/)
- [Exponential Search](https://www.geeksforgeeks.org/exponential-search/)
- [Interpolation Search](https://www.geeksforgeeks.org/interpolation-search/)
