<h1>Introduction
</h1>

So_long is a project developped by myself in ecole 42. The project was developed in C and it was done in about a week. The library used to open windows and load sprites is called Minilibx and it was given by the school. The rest of the code was done by me.

# Goals
The goal of the project was to create a small top down 2D game using Minilibx, a library that allows the creation of minimal graphical interfaces. The project looks to introduce skills in:
- Sprites manipulation
- Introduction to Graphic interface
- Basic gameplay elements
# **Overview of The Game**
![overview of the game](/github_images/game_basics.gif "Overview of the game")

- The game aesthetic is from the Snes game earthbound.
- The goal of the game is to collect the tomatoes and reach the exit without getting killed by Sans.
- The player can move using WASD keys.

# Game Rules
The game works following several rules.
- The map is generated via a .ber file, following the rules specified in the **Map Rules** section.
- The player can move up, down, left and right
- The player cannot move into walls
- The game is not real time, things only happen after pressing a key
- Walking on tomatoes will make the player pick them up
- Once you get all of them, the exit door opens and you can leave
- Walking into the enemy will kill the player
- You can quit the game using the `ESC` key
- The enemy will walk from left to right until encountering a wall/tomato, then he will start to walk in the opposite direction

# Map Rules
The following is an example of a map correctly formated:
```shell
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C000000000X000000000C1
1111111111111111111111111111111111
```
The map can be composed of 6 different elements:
- `1` Will generate a wall
- `0` Will generate an empty tile where the player can move freely
- `E` Will generate the exit
- `P` Will generate the player
- `X` Will generate the enemy
- `C` Will generate a collectible

Then, the map has to obey the following rules:
- The first and last line have to be filled with `1`
- Lines' extremities must be `1`
- The map has to be rectangular, thus all lines must have the same length
- `E` `P` and `X` are can only be present once
- There can be any number of `C` `1` and `0`
# Run The Game
If you want to try the game yourself, you can git clone the project, then run the commands:

```shell
make
./so_long map.ber
```
The executable takes a .ber file as argument. You can play around and modify the map, as long as it follows the rules, the game will work.
# Sources
I found all of the sprites online, on the [Sprite Ressources](https://www.spriters-resource.com/) website. I edited most of them on Gimp to make the game look coherent.
1. The Sans sprites were made by "MisterMike" and can be found [here](https://www.spriters-resource.com/custom_edited/undertalecustoms/sheet/123992/).
2. The Ness sprites were ripped from Earthbound by users "Depressed Mario", "M. Bison", "Matheus123" and "Tonberry2k". They can be found [here](https://www.spriters-resource.com/snes/earthbound/sheet/104953/)
3. The rest of the sprites come from Earthbound and were ripped by user "Ryan914". They can be found [here](https://www.spriters-resource.com/snes/earthbound/sheet/3159/)