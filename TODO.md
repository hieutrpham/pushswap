# TODO

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
* push everything from b to a. a should be sorted

### kinda quicksort algo
* divide the stack into smaller chunks and sort them
