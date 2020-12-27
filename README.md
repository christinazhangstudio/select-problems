# select-problems
This repository and its files were authored by Christina Zhang in Fall-Winter 2020.

<details open>
<summary>Table of Contents</summary>

- [About this repository](#about)
- [Priority Queue - Heap Implementation](#pq-hi)
- [Recursion and Dynamic Programming - Pebble Example](#pebble)
- [Competitive problems](#comp)
- [Contact](#contact)
</details>

- - - -
## About this repository <a name="about"/>
This repository consists of code for selected algorithms, data structures, or competitive problems/challenges.

- - - -
## Priority Queue - Heap Implementation <a name="pq-hi"/>

- - - -
## Recursion and Dynamic Programming - Pebble Example <a name="pebble"/>
Consider the following simple two player game:
- There is a pile of *n* pebbles.
- The  players  take  turns  removing  pebbles  from  the  pile.  Specifically  they **must** do one of the following on their turn:
  - Remove 1 pebble from the pile
  - Remove 2 pebbles from the pile
  - Remove half of the remaining pebbles from the pile (rounded up).
- The player that is forced to take the last pebble loses. 

We want to decide if there is a way for the first player to win the game (i.e., assuming perfect play by both players find out whether the first player to take their turn will always win). 

Start by showing that if *n* = 3 player 1 always wins (assuming optimal play):
![alt text](images/pebble0.JPG)


Next show that if *n* = 4 player 1 always loses (assuming optimal play):
![alt text](images/pebble1.JPG)

- - - -
## Competitive problems <a name="comp"/>
| Problem | Solution |
| --- | --- |
| <a href='https://open.kattis.com/problems/vote'>Popular Vote</a> | [Python 3](popular-vote.py) |
| <a href='https://open.kattis.com/problems/lostlineup'>Lost Lineup</a> | [C](lostline-up.c) |

- - - -
## Contact <a name="contact"/>
christinazhang2013@gmail.com
