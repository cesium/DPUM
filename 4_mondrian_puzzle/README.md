# The Modrian Puzzle

# Description:
The artist Piet Mondrian is a famous mid-century abstract artist. His designs of brightly colored rectangles on a canvas should be familiar to you even if you don't know his name. He's even given his name to a visual programming language Piet.

I learned about this puzzle from this video from TED-Ed on the challenge. Briefly:

"Fit non-congruent rectangles into a n*n square grid. What is the smallest difference possible between the areas of the largest and the smallest rectangles?"

Remember a non-congruent rectangle is a shape with distinct measurements, so a 8x1 rectangle is the same as a 1x8, but distinct from a 2x4.

Your challenge today is to write a program that can heuristically subdivide the canvas and find a minimal area range.

This is sequence A276523 in the OEIS database.

# Input:
You'll be given an integer n, one per line. This is the size of your canvas to work with. Example:

11

# Output:
Your program should emit the smallest value you can find for that canvas size, optionally the dimensions of the rectangles your program generated. Example:

6
3 X 4
2 X 6
2 X 7
3 X 5
4 X 4
2 X 8
2 X 9
3 X 6
