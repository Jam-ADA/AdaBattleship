# Challenge Outline:

The challenge given to students in this assignment was to "Use a structured, object-oriented design approach for the concept, design, development, testing and potential
post completion and further improvements of AdaShip (a REPL.IT C++ computer console version/adaptation ofthe classic paper-based Battleships game)."

To create a solution to this challenge, I followed the suggested steps to take and created a game from scratch in c++. This included making a menu,
a mode against the computer and then adapting that mode to create a player vs player mode, as well as creating several .cpp and header files that 
included the necessary code. The structure of the proposed solution is shown in the following UML style diagram:



![alt text](https://github.com/Jam-ADA/AdaBattleship/blob/main/UMLDesign.PNG "UML Diagram")



My working plan for this solution is to create each feature individually and build upon the solution incrementally. That way I can test each feature as I add it as well as testing to make sure each feature works well with previous designs.
This way of working will allow me to make sure the quality of each section of the program is up to a high standard, as well as giving me a clear goal to work towards at any given time, which will make development much more efficient.



My task/feature in the order to develop:

- Handle Input From User
- Load options from config file and create config class
- Develop Main Menu UI
- Allow User to choose different options in the menu
- Create a function for the user to create a board by placing ships
- Create a function for a computer to develop a board, must be compatible with different board sizes
- Create the player vs computer mode
- Allow this mode to be played by selecting it from the menu
- Make sure the whole game is playable without errors
- Create Player vs Player mode
- Link both modes to the menu
- Allow a user to play the whole game, either modes, without bugs

By doing these smaller tasks one by one, I can ensure they are built to a good quality and can test them both individually and together in order to make sure the program works well.



Potential objects that could be created:

- Config

Could contain attributes such as Board length and width, and each ships lengths
Would need to be accessed whenever creating a new board

- Player

A player object could potentially store each players score and how many ships are left

# Development:


I will ensure my code contains good standards of practice. Therefore I will follow certain naming protocals with my variables and objects, comment things such as #include statements so that a developer can know what each header is used for, and also make sure my code is readable and easily editable for anyone who wishes to use it.

### Phase 1 Development:

Tasks worked on:

- Handle Input From User
- Load options from config file and create config class

I created a getch() function as replit's c++ compiler doesn't support the original function, this allows input to be read from the console in real time. I then tested this function to make sure it works. I then created a file parser function to read information from the .ini file and load the variables into the config class for later use.

### Phase 2 Development :

Tasks worked on:

- Develop Main Menu UI
- Allow User to choose different options in the menu

Next, I created a menu ui and using the input getch() function, allowed the user to pick different options using the arrow keys and the enter key. I then created a colour header which allowed me to customise the console output to highlight the user's current choice and make it clear which choice the user was picking. I included instructions so the user doesn't get confused and tested this menu by outputting different texts when each option was chosen.

### Phase 3 Development:

Tasks worked on:

- Create a function for the user to create a board by placing ships
- Create a function for a computer to develop a board, must be compatible with different board sizes
- Create the player vs computer mode
- Allow this mode to be played by selecting it from the menu
- Make sure the whole game is playable without errors

This was one of the longest phases of development. I had to create each individual function such as the player generated board and automatically generated board functions. After testing each individual function, I then linked them and tested them again to ensure they worked well together. A big problem with c++ on replit is the lack of a good debugger, which made fixing errors such as core dumps difficult, as I had to manually search for which line was creating the memory problem. After making the gameplay loop and successfully running it through around 10 to 20 times to check there were no bugs, I then linked the option to the menu, allowing the user to play a game and return to the menu once finished to either quit or play again.  

##Phase 4 Development:

Tasks worked on:

- Create Player vs Player mode
- Link both modes to the menu
- Allow a user to play the whole game, either modes, without bugs

I used the player vs computer function as well as the player based functions and adapted them in order to create the player vs player mode. I had to change a lot of the text in order to make it obvious whose turn it was as well as change one of the board outputs so to not let the other player cheat and see their opponents board. I then linked this back to the menu the same way as the other function and proceeded to test both modes of the game multiple times to ensure there were no obvious bugs i may have missed.



After each phase I conducted extensive testing in order to iron out any issues that my be hidden in my code. This included a lot of memory misallocations issues which took a lot of time to solve. However, after testing each phase I managed to remove all the errors I was receiving beforehand.



One of the most challenging aspects of making the game was the fact repl.it currently doesn't have a good debugger for c++. This meant when there was a runtime error such as a core dump/segmentation fault, I would not know which line the error was occuring on and would have to manually go through my code in order to find out where the error occured. This took a lot of time and effort and made the development of the game take a very long time, especially compared to doing the same thing in a higher level language such as python which allows for quick debugging and would've taken a longer time.

Another challenge is my lack of experience with c++ when compared to other languages, as it took some time getting used to things such as header files and the #include statements. However thanks to this challenge my knowledge of c++ has improved greatly.

# Evaluation:



In my code I made sure to make it readable and not repeat code.

For example, I needed to produce a lot of random values for things such as the computer placement of ships and targetting. This could've taken a lot of time to write in the several lines of code needed in order to produce a random number within a specific range, but instead I created a function which meant I only had to write a single line to call the function each time instead.

![alt text](https://github.com/Jam-ADA/AdaBattleship/blob/main/Example1.PNG "Example 1")

Another example would be my colour header file. This was a file that contained a lot of the codes used when printing different colours and backgrounds, which was used frequently in my program. Having this file means I do not have to write the hard-to-read codes needed to change the colour of text, saving a lot of time when developing and also making the code a lot easier to read and understand.

![alt text](https://github.com/Jam-ADA/AdaBattleship/blob/main/Example2.PNG "Example 2")

Overall, I believe I made a good, working example of the battleship boardgame. However, development took a lot of time and stress and the replit compiler also provided quite a few issues which were a struggle to overcome. If I were to make this game again or had more time, I believe I'd be able to be a lot more efficient with my code and development process, as well as include a lot more features to make the game/solution even better. One of the biggest struggles for me when using c++ was the memory allocation, as this was the number one cause of issues in my code which costed me a lot of time.



