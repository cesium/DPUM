# Sleeping Barber
![](https://img.shields.io/badge/-MEDIUM-yellow.svg?style=for-the-badge)

The sleeping barber problem is a classic inter-process communication and synchronization problem between multiple operating system processes. The problem is analogous to that of keeping a barber working when there are customers, resting when there are none, and doing so in an orderly manner.

In short:
1. There is a barber’s shop where there is only one barber.
2. There is one barber chair and a number of waiting chairs for the customers.
3. When there are no customers the barber sits on the barber chair and sleeps.
4. When a customer arrives he awakes the barber or waits in one of the vacant chairs if the barber is cutting someone else’s hair.
5. When all the chairs are full, the newly arrived customer simply leaves.

You must implement a version of this problem, keeping in mind some problems may arise.

A customer may arrive and observe that the barber is cutting hair, so he goes to the waiting room. While they're on their way, the barber finishes their current haircut and goes to check the waiting room. Since there is no one there (maybe the waiting room is far away and the barber walks faster passing the customer, or maybe the customer went to the restroom or was going towards the chair and the barber thought he was leaving), so the barber goes back to their chair and sleeps. The barber is now waiting for a customer, but the customer is waiting for the barber.
In another situation, two customers may arrive at the same time when there happens to be a single seat in the waiting room. They observe that the barber is cutting hair, go to the waiting room, and both attempt to occupy the single chair. (Adapted from Wikipedia)

## Input format

You can hard code all the variables (the time each operation takes to finish and the number of waiting chairs).

## Output format

Your program must output every action as showed by the example.
You should use integers for identifying the clients.

Examples
```
[*] Client enters shop id
[*] Seat available for client id
[*] Kicking client id
[+] Cutting hair of client id
[+] Done cutting hair of client id
```

## General notes

This challenge is a bit different, please do read these notes.

1. Since the interesting part of this problem is the algorithm itself, you can use external libraries (within reason)
2. Keep all the code in a single file
3. Put your solution on `<your username>/<file with solution>`
4. We are looking for elegant solutions, no need to format your code in a code golf style
5. There isn't a objective definition of "elegant", that's up for the current CAOS direction to decide. We will mainly focus on concepts used and code length (withing reason).
