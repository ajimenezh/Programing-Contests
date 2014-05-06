Challenge 20 - forfor

To solve this problem let us start with counting the ways we can partition a number in the sum of k positive numbers. This number is C(k + (n - k -1), k), where C() is the binomial coefficient.
This doesn't solve the original problem where each partition has a different weight, but knowing that each weight is of the order of n^2, it seems that the solution can be a number of the order of n^(k-1+2). So we can try to fit the answer for small n to a polynomial of order (k+2)=8, and it seems we got the answer.