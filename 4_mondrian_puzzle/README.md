# The Mondrian Art Puzzle
![](https://img.shields.io/badge/-HARD-red.svg?style=for-the-badge)

The artist Piet Mondrian is a famous mid-century abstract artist. His designs
of brightly colored rectangles on a canvas should be familiar to you even if
you don't know his name. He's even given his name to a visual programming
language _Piet_.

The idea for this challenge comes from [this](https://youtu.be/AWcY2-FBa9k)
TED-Ed video. And can be shorted to the following:

> Fit non-congruent rectangles into a `n * n` square grid. What is the smallest
> difference possible between the areas of the largest and the smallest
> rectangles?

Remember a non-congruent rectangle is a shape with distinct measurements, so a
8x1 rectangle is the same as a 1x8, but distinct from a 2x4.

The challenge is to write a program that can heuristically subdivide the canvas
and find a minimal area range.

This is sequence [A276523](http://oeis.org/A276523) in the OEIS database.

## Input

You'll be given an integer `n`, one per line, from `STDIN`. This is the size of
your canvas to work with.

**Example:**

```
11
```

## Output

Your program should emit the smallest value you can find for that canvas size,
optionally the dimensions of the rectangles your program generated.

**Example:**

```
6
3 X 4
2 X 6
2 X 7
3 X 5
4 X 4
2 X 8
2 X 9
3 X 6
```

## Bonus

Note that solutions above `n = 44` don't yet have a known or proven lower
bound. Do your best.

---

_You can read the original problem [here](https://redd.it/9dv08q)_.
