# TODO
* error checker
    * function that takes the ac and av and check for some common errors
        * check for duplicates (use is_there_dup during parser) ✅
        * check for not intergers (isdigit). strings: "", " ", "1 xs", ----23 4 ✅
        * check for INT_MAX, INT_MIN ✅
        * display `Error\n` on stderr 2 in case of errors ✅
* parser
    * function that takes argv and parse data into a data structure (stack)
