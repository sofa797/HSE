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

### 3 Complexity Analysis of Binary search
#### 1. Time Complexity:
•  O(?n).
#### 2. Auxiliary Space:
• O(1).  
### 4 Advantages of Binary search
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

- [Контест №1 (16.11.24-17.11.24)](https://github.com/sofa797/HSE/tree/main/course%20C)
- [Контест №2 (07.12.24-08.12.24)]()
