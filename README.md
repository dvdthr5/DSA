# Patterns of Algoritms:

## Monotonic Stacks

Monotic Stacks are useful when finding an element that comes next, whether that be for one element or an entire array. They can be used for classic problems like find the next greatest element and similar cases. In the case of next greatest element, the idea of using the stack is to iterate through the array, using the stack to track the element which the next greatest element have not been found for, popping the elements once found. 

## Fast and Slow Pointers

Fast and slow pointers inolves using two pointers that traverse a graph at different speeds. This method is useful for finding cycles in graphs. Conceptually, if you have two runners moving at vastly different speeds, on a straight course, they will never meet. If you have the same runners on a circular track, they will pass each other every so often due to different rates. If our pointers pass each other that means there is a cycle. Usually we do this by having the fast pointer move two nodes at a time and the slow pointer only iterating one node at a time.

## Sliding Window

When finding a subarray of k length, we use a sliding window of length k to save ourselves overhead on repeating calculations, subtracting the first value and adding the new value each times, instead of recalculating the sum of all k values. 
