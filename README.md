## Understanding this repo
This repository contains code developed for a uno card game for a university project. </br>
The project aim was to devise a strategy that would be able to defeat a naive players strategy in an uno game. </br>
The naive strategy is to play the first card that the players sees that is a valid card in his hand of cards. </br>
The code I developed intelligently defeats not only the naive strategy but also your average players strategy. </br>
40 out of 700 engineering students were bold enough to submit their code to test their strategy against other students. </br>
Out of the 40, my strategy placed somewhere in the top 20. </br>

---
##Find further details in the "documentation" directory:
1. For details regarding project scope refer to: </br>
"Project Specification.pdf"

2. For details of my strategy, refer to: </br>
"Strategy.h"

3. For project marking criteria refer to: </br>
"Marking Schedule.pdf"

---
## How to simulate a game (and maybe test your own strategy against mine):
1. Run the simulation program.
> simulation.exe

   N.B.: </br> 
  * abcd001 contains the implementation of my streategy. </br>
  abcd002, abcd003 and abcd004 are all dummy players that play the first valid card that they see in their deck. 
  * If you have your own code to compete in a card game then label that file as abcd002.c (or any of the other dummy players) and watch your strategy compete against mine! </br>

---
## How to evaluate my code:
1. In a Visual Studio Command Prompt window, compile the review program by typing:
> cl /F review.exe /W4 review_program.obj abcd001_project2.c
  
2. Run the review program:
> review.exe

   and choose the Task that you want to review.
