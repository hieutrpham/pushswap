# TODO part 1

## Parsing and error checking
* error checker
    * function that takes the ac and av and check for some common errors
        * check for duplicates (use is_there_dup during parser) ✅
        * check for not intergers (isdigit). strings: "", " ", "1 xs", ----23 4 ✅
        * check for INT_MAX, INT_MIN ✅
        * display `Error\n` on stderr 2 in case of errors ✅
* parser
    * function that takes argv and parse data into a data structure (stack)
    * if ac == 2
        * split the argv
        * use ft_count_word to get the size of the int array and malloc for it
        * use ft_atol to convert string to int and store the int in the alloc'ed array
        * check if the array is already sorted. exit early if so
    * - [X] if ac > 2 
        * size of array is ac-1
        * use ft_atol to convert string to int and store the int in the alloc'ed array
        * check if the array is already sorted. exit early if so
> [!WARNING]
>  dupe checking after parsing

## Stack Operations

```C
// struct for the stack
typedef struct s_stack {
	int size;
	int top;
    int len;
	int *arr;
} t_stack;
```

* int size to keep track of the bottom element. also the max_size of the stack
* int top to keep track of the top of the stack. incremented when pushing.
* int len to keep track of how many elements in the stack.
    * used in swap. only swapping when `len >= 2`
    * used in algo to do certain sorting when `len = 3, len = 5`

* swap the first 2 elements
* push the top element between 2 stacks
* rotate stack
* reverse rotate stack

## Algo

### bad algo probably takes a lot of operations
* find the smallest int in stack a. rotate or reverse rotate until the top then push to b. keep doing it until stack a is empty
    * return the index of the min_int
    * store a sorted array in the stack so i know the correct index of all elements in the array
* push everything from b to a. a should be sorted

### kinda quicksort algo
* divide the stack into 3 chunks and sort them recursively
* kinda trippy still not sure how it works

### my algo. combination of chunk, greedy, insertion sort?
* i came up with an algorithm that combines several ideas from the articles i've read. lets say i have an unsorted array of numbers from 0-8. i would presort it and divide it into 3 chunks: 0-2, 3-5, 6-8. i'm going to process the first chunk which is 0-2. i scan the stack a for any number belonging to this chunk and see which takes the least operations to bring to the top. once i do i will push it over to stack b.
* once stack b has more than 1 numbers, any number i push from stack a will need to be check for the corrected slot
    * if a number in stack a is larger or smaller than all numbers in b, rotate b so that the current max number of b is on top then i would just push it
    * if a number in stack a is not larger or smaller than all numbers in b, i would need to find the closest but smaller number in stack b to bring it to the top of stack b before i push the number from stack a over. this way i maintain some descending order in stack b
* once stack a is empty, stack b should have a somewhat descending order. now i just have to push everything from stack b over to stack a.
    * before i do that, i have to confirm stack b is in descending order. if not i have to find the max number and rotate stack b until the max number is on top.

# TODO part 2 (algo)

* first i need a way to divide the sorted array into chunks. number of elements = sqrt(size)
    * `chunk_size = sqrt(arr_size)`
    * first chunk is `sorted_arr[0]` to `sorted_array[chunk_size - 1]`
    * 2nd chunk is `sorted_arr[chunk_size]` to `sorted_arr[2*chunksize - 1]` etc.
* first loop through stack a until a is empty
    * scan stack a from the top to find the first number belonging to the chunk in process
        * the function should return the index of the number
        * the moves required to send it to top would be equal to the index - top.
    * scan stack a from the bottom to find another number belonging to the chunk in process
        * the moves required here would be equal size - index + 1
    * calculate and compare the number of moves it takes to move those 2 number to top of stack_a.
        * proceed to move the number with the least number of moves
    * if after all the chunks are processed, stack a still might have some numbers left, sort them based on the number of elements (3, 5 or more)
