# 0x1B. C - Sorting algorithms & Big O

## General Learning Objectives :page_with_curl:

* At least four different sorting algorithms
* What is the Big O notation, and how to evaluate the time complexity of an algorithm
* How to select the best sorting algorithm for a given input
* What is a stable sorting algorithm

## Tasks :heavy_check_mark:

* Task 0 - Write a function that sorts an array of integers in ascending order using the Bubble sort algorithm
    - Prototype: void bubble_sort(int *array, size_t size);
    - You’re expected to print the array after each time you swap two elements

* Task 1 - Write a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
    - Prototype: void insertion_sort_list(listint_t **list);
    - You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
    - You’re expected to print the list after each time you swap two elements

* Task 2 - Write a function that sorts an array of integers in ascending order using the Selection sort algorithm
    - Prototype: void selection_sort(int *array, size_t size);
    - You’re expected to print the array after each time you swap two elements

* Task 3 - Write a function that sorts an array of integers in ascending order using the Quick sort algorithm
    - Prototype: void quick_sort(int *array, size_t size);
    - You must implement the Lomuto partition scheme.
    - The pivot should always be the last element of the partition being sorted.
    - You’re expected to print the array after each time you swap two elements

* Task 4 - Write a function that sorts an array of integers in ascending order using the Shell sort algorithm, using the Knuth sequence
    - Prototype: void shell_sort(int *array, size_t size);
    - You must use the following sequence of intervals (a.k.a the Knuth sequence):
        - n+1 = n * 3 + 1
        - 1, 4, 13, 40, 121, ...
    - You’re expected to print the array each time you decrease the interval

* Task 5 - Write a function that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
    - Prototype: void cocktail_sort_list(listint_t **list);
    - You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.
    - You’re expected to print the list after each time you swap two elements

* Task 6 - Write a function that sorts an array of integers in ascending order using the Counting sort algorithm
    - Prototype: void counting_sort(int *array, size_t size);
    - You can assume that array will contain only numbers >= 0
    - You are allowed to use malloc and free for this task
    - You’re expected to print your counting array once it is set up
        - This array is of size k + 1 where k is the largest number in array

* Task 7 - Write a function that sorts an array of integers in ascending order using the Merge sort algorithm
    - Prototype: void merge_sort(int *array, size_t size);
    - You must implement the top-down merge sort algorithm
    - You are allowed to use printf
    - You are allowed to use malloc and free only once (only one call)

* Task 8 - Write a function that sorts an array of integers in ascending order using the Heap sort algorithm
    - Prototype: void heap_sort(int *array, size_t size);
    - You must implement the sift-down heap sort algorithm
    - You’re expected to print the array after each time you swap two elements

* Task 9 - Write a function that sorts an array of integers in ascending order using the Radix sort algorithm
    - Prototype: void radix_sort(int *array, size_t size);
    - You must implement the LSD radix sort algorithm
    - You can assume that array will contain only numbers >= 0
    - You are allowed to use malloc and free for this task
    - You’re expected to print the array each time you increase your significant digit

* Task 10 - Write a function that sorts an array of integers in ascending order using the Bitonic sort algorithm
    - Prototype: void bitonic_sort(int *array, size_t size);
    - You can assume that size will be equal to 2^k, where k >= 0 (when array is not NULL …)
    - You are allowed to use printf
    - You’re expected to print the array each time you swap two elements

* Task 11 - Write a function that sorts an array of integers in ascending order using the Quick sort algorithm
    - Prototype: void quick_sort_hoare(int *array, size_t size);
    - You must implement the Hoare partition scheme.
    - The pivot should always be the last element of the partition being sorted.
    - You’re expected to print the array after each time you swap two elements

* Task 12 - Write a function that sorts a deck of cards.
    - Prototype: void sort_deck(deck_node_t **deck);
    - You are allowed to use the C standard library function qsort

## Function Prototypes :file_folder:

 File                       | Prototype                                         |
| -------------------------- | ------------------------------------------------- |
| `print_array.c`            | `void print_array(const int *array, size_t size)` |
| `print_list.c`             | `void print_list(const listint_t *list)`          |
| `0-bubble_sort.c`          | `void bubble_sort(int *array, size_t size);`      |
| `1-insertion_sort_list.c`  | `void insertion_sort_list(listint_t **list);`     |
| `2-selection-sort.c`       | `void selection_sort(int *array, size_t size);`   |
| `3-quick_sort.c`           | `void quick_sort(int *array, size_t size);`       |
| `100-shell_sort.c`         | `void shell_sort(int *array, size_t size);`       |
| `101-cocktail_sort_list.c` | `void cocktail_sort_list(listint_t **list);`      |
| `102-counting_sort.c`      | `void counting_sort(int *array, size_t size);`    |
| `103-merge_sort.c`         | `void merge_sort(int *array, size_t size);`       |
| `104-heap_sort.c`          | `void heap_sort(int *array, size_t size);`        |
| `105-radix_sort.c`         | `void radix_sort(int *array, size_t size);`       |
| `106-bitonic_sort.c`       | `void bitonic_sort(int *array, size_t size);`     |
| `107-quick_sort_hoare.c`   | `void quick_sort_hoare(int *array, size_t size);` |
