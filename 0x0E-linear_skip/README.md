# 0x0E. Linear search in skip list
## Linear search in a skip list

Function that searches for a value in a sorted skip list of integers.

- Prototype : skiplist_t *linear_skip(skiplist_t *list, int value).
- Where list is a pointer to the head of the skip list to search in.
- A node of the express lane is placed every index which is a multiple of the square root of the size of the list.
- And value is the value to search for.
- You can assume that list will be sorted in ascending order.
- Your function must return a pointer on the first node where value is located.
- If value is not present in list or if head is NULL, your function must return NULL.
- Every time you compare a value in the list to the value you are searching, you have to print this value.