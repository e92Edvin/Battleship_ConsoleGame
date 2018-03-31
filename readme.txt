
LinkedIn - https://www.linkedin.com/in/edvin-rusecki-848a3215b/
Any questions about game implementation write email to "edvin13579@gmail.com"


Battleship Short Game Description.


-------------------------------Game settings-------------------------------

You should input all coordinates of all ships.
1 Step -> You should input 4 coordinate of Carrier
2 Step -> You should input two times by 3 coordinate for 2 Battleships
3 Step -> You should input three times by 2 coordinate for 3 Cruisers
4 Step -> You should input four times by 1 coordinate for 4 Destroyers

You should choose level of difficulty.
Level 1:  10 ships with 1 coordinate 
Level 2:  12 ships with 1 coordinate 
Level 3:  15 ships with 1 coordinate 
Level 4:  20 ships with 1 coordinate
Level 5:  35 ships with 1 coordinate 

---------------------------------------------------------------------------
###########################################################################
-------------------------------Game controls-------------------------------

You can input coordinates only in one sequence :
NUMBER   LETTER  (all inputs must be in lowercase)

1   2   3   4   5   6   7   8   9  10
a   b   c   d   e   f   g   h   i   j

If your input will be wrong input will not be accepted.

Exmaple of wrong input:
11 a  (11 coordinate is not exists)
a 11  (bad order and 11 coordinate is not exists)
5e    (input must be separate)
5 E   (e in Uppercase)

Also, the input will not be accepted if you want to allocate a ship 
around other ships and it will not have enough free cells.

Correct input example:
5 g
6 g
4 g

The repository has a file with an input example.

---------------------------------------------------------------------------
###########################################################################
--------------------------Console output-----------------------------------

Console outputs:

Your ships map 
4 - it is coordinates of Carrier (Green color)
3 - it is coordinates of Battleships (Green color)
2 - it is coordinates of Cruisers (Green color)
1 - it is coordinates of Destroyers (Green color)
0 - it is empty coordinates (sea) (Blue color)

Next map allocate your shots on the enemy sea
@ - hitting the sea (Red color)
X - successful attacks
* - non-attacked coordinates

After output you need input new coordinates:
NUMBER   LETTER

And this continues until you or the program wins.
If user won outputs: "YOU WON".
If program won outputs: "COMPUTER WON!".

---------------------------------------------------------------------------
###########################################################################
--------------------------Implementation features--------------------------

A two-dimensional matrix was used to store the coordinates of the ships 
(the player and the program) also for displaying the player's attacked 
coordinates. 
To display the colors in console used library  <windows.h>

---------------------------------------------------------------------------
###########################################################################


