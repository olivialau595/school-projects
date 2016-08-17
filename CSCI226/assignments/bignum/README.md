# Big Number Calculator

This calculator created in Computer Systems (CSCI226 - Fall 2014) performs basic arithmetic for large 
positive numbers. The project shows a solution for numbers that are too big for our personal computers to 
handle. This is accomplished by computing in base 1000. The input numbers are split up by digits of 3 
so that each "digit" in the input number can have a max of 999. The operation is applied to each 
"digit" and the remainders are carried to the (Nth + 1)'s place, just like normal arithmetic.