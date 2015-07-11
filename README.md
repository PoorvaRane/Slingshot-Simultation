# Projectile-Game

A Projectile based Game implemented on OpenGL.

The purpose of this project was to understand the fundamental concepts of 2-D and 3-D tranformations and is written in C++.

To be able to run the projects on a linux distribution, use the following command to install OpenGL:

	sudo apt-get install freeglut3 freeglut3-dev mesa-utils


PROJECTILE BASED GAME:

The objective of this game is to hit the bricks 3 times each to make them disappear.

	Play Controls:
        'w' = Increase velocity of projectile
        's' = Decrease velocity of projectile
        'a' = Decrease angle of projectile
        'd' = Increase angle of projectile
        Spacebar = Launch the first projectile/Start Game
        'q' = Quit the game

To play the game, open the directory it is present in and compile it using the following command:
        
        g++ projectile.cpp -lGL -lGLU -lglut -lm
        
Then run it using:

        ./a.out


Project Contributors :<br>
1. Poorva Ganesh Rane <br>
2. Balaji Bala <br>
3. Nidhi Sridhar <br>
