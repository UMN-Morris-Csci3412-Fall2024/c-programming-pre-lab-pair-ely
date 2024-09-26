# Leak report

The first memory leak occurred in check_whitespace.c by the memory being allocated by strip.
This occurs because strip is allocating memory and passing it to is_clean, and so it cannot
free the memory and is_clean is also not able to free it since it is being passed char const*.
To fix the memory leak, change strip to return char* to indicate that the caller must free the
memory. Then add free(clean) to is_clean to free the memory.

The other memory leaks in check_whitespace_test.cpp are all in the tests using strip. This is
because strip does not free the memory itself, but is now expecting the test to free it. To fix
this, assign the returned value of strip to a variable and call free() on that variable to free it.