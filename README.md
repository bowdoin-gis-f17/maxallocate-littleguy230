# maxallocate

Write a little program to figure out how much memory (in bytes) the system lets you allocate before malloc fails (i.e. returns NULL pointer). Your program should print out the number of bytes it could allocate (before malloc() failed).

If this number turns out to be very large and hard to read (it probably will be), then print it also in MB. To do this, use bit shift operations in C/C++.

Play around by compiling with -m64 and see whether the result changes (dont forget to check out what -m64 flag does).

Watch out for: overflows. As you declare your variables, be mindful of the range of an int.
