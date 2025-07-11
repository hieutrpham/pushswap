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
	int *arr;
} t_stack;
```

* swap the first 2 elements
* push the top element between 2 stacks
* rotate stack
* reverse rotate stack

## Algo
