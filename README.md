# Date parsing in C #

*Library quality: works after hacking*

This code is able to parse dates in C and display them in a number of formats.  It was ripped from Git, and as such, is available under the GPLv2.

It also depends on a bunch of posix-like things and is not cross platform.  But, if you are working on a Linux (possibly Mac?) program that needs powerful date parsing and can tolerate the GPLv2, this will do the trick.

## Notes ##

 - Compiles with --std=gnu89, so just add the .c and the .h to your project.
 - See the main() at the bottom for possible usage demonstration.
 - This was done because the author needed ISO8601 date parsing in C.  Not much else is tested.
 - Git uses `struct strbuf` strings, but these were replaced with char * to reduce the amount of things I had to pull in.
 - `DATE_PARSE_ENABLE` is an #ifdef guard which excludes parts of the code I didn't port.
 - It works.
