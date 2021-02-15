# 0x18. Merge Sort
## Merge sort

Function that sorts an array of integers in ascending order using the `Merge Sort` algorithm:

- **Prototype:** `void merge_sort(int *array, size_t size);`
- Must implement the `top-down` merge sort algorithm.
    - When divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. `{1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}`
    - Sort the left array before the right array
- It is allowed to use `printf`
- It is allowed to use `malloc` and `free` only once (only one call)
