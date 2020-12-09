#Assingment 8 - Results

This file discusses and analyzes the results obtained by using Linear Probing, Quadratic Probing and Double Hashing in an array.

##My Results
As expected, Quadratic Probing did less comparison as during insertion, if the key is not empty, it is more likely to jump to an empty cell. Moreover, in linear probing, more values are placed lot closer to each other leading to more clusterred cell structure. If space is dynamically allocated, as with increasing number of members, Quadratic Probing may be less efficient.

##Mathematical and Empirical Values
###Linear Probing
* For Linear Probing, following the formula provided in the assignment, we expect the Average number of comparisons for 100.000 trials (100 trials and 1000 member per array) where X is known to be in the array to be 1.5. In my run, I got 1.50306.
* For values of X that are known not to exist in the array T, is 2.5 and my result is 2.49564.
* As it can be seen the theoretical and practical values are almost the same confirm the formula.

###Quadratic Probing
* We expect the Average number of comparisons for 100.000 trials (100 trials and 1000 member per array) where X is known to be in the array to be 1.443147. In my run, I got 0.79012.
* For values of X that are known to not exist in the array T, is 2.193137 and my result is 1.65406.
* The practical values do not match up with theoretical values. This is due to implementation of Quadratic probing where one can implement a way that we alternate between adding a square number then subtracting a square number or only adding square number.

###Double Hashing
* I do not have any reference values however still providing my findings of my runs.
* For X, that exists in the array, I got 0.78619.
* And for X, that do not exists in the array, I got 1.64662, pretty similar to Quadratic Probing.