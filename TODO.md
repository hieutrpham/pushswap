# TODO
* parser
    * function that takes argv and parse data
* error checker
    * function that takes the ac and av. return 1 if no error
        * check for duplicates
        * check for not intergers (isdigit). strings: "", " ", "1 xs", ----23 4
        * check for INT_MAX, INT_MIN
        * display `Error\n` on stderr 2 in case of errors
    * anything else just print out usage function
