# Assignment 6
## Coloring Algorithm
All Stack, Queue and Recursive implementation of coloring uses the same algorithm. We go from up -> down -> left -> right.

### Stack
* Starting from origin, we follow the same pattern, creating a cross (for the r = 3, c = 5 example). 
* After coloring is finished from that location, we move on to most right (if not already colored) then do the same operation etc.

### Queue
* Queue follows the same algorithm regarding following the pattern.
* However, next origin/starting location is not the edge or far most pixel, rather +- 1 from the origin

### Recursive
* Recursive function uses the same pattern, going from up -> down -> left -> right
* It has a base case where if the pixel is out of bounds or already colored, returns


### Regarding Backtracking
* For Stack and Queue operations, as we color the pixels before we move on to next origin/creating the next set stack and queue (or set of pixels to be colored), this prevents backtracking. 
* For recursive function, the base case acts the same way as a checkmark to prevent backtracking


## Line Arguments
usage: color [-help][-input <path>][-output <path>][-i <value>][-j <value>][-recursive][-queue][-stack]

help				prints the usage
input <path>		the inFile that has two integers the m rows and n columns followed by m by n b characters and r characters
output <path>		the outFile has m rows by n columns of R characters and blanks
i <value> 			an integer for the row of the starting pixel (origin is the upper left hand corner)
j <value> 			an integer for the column of the starting pixel (origin in the upper left hand corner)
recursive 			calls the recursive version
queue 				calls the version that uses the queue
stack 				calls the version of that uses an explicit stack