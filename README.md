*This project has been created as part of the 42 curriculum by malavaud and mrojouan.*

# CUB3D

# DESCRIPTION

*CUB3D* is a project inspired by the lassic game Wolfenstein 3D.

The goal of the project is to create a simple 3D graphical representation of a maze using *raycasting*. The player can move around the map and look around while walls are rendered from a first-person prespective.

The project is written in C and ususes the *MiniLibx*

The main concepts covered by this project are:
- Parsing and validating a configuration file
- Parsing and validating a map
- Handling textures and colors
- Player movement and rotation
- Raycasting
- Rendering walls from a frist-person perspective
- Basic event and window management with *MiniLibx*

# INSTRUCTIONS

## Compilation

Clone the repository and enter the project directory:

```bash
git clone <repository-url>
cd cub3d
```

Compile the project with:

```bash
make
```

This will create the cub3d executable.

To remove the object files:

```bash
make clean
```

To remove the object files and executable:

```bash
make fclean
```

To recompile the project from scratch:

```bash
make re
```

## Execution

The program takes a .cub map file as an argument:

```bash
./cub3d maps/map.cub
```

The .cub file contains:
- The paths to the wall textures (NO, SO, WE, EA)	
- The floor and ceilling colors (F, C)
- The map layout
- The player's starting position and orientation (N, S, E or W)

Example :

```bash
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 100,150,50
C 100,180,255

1111111
1000001
10N0001
1000001
1111111
```

## Controls

- W = Move forward
- S = Move backward
- A = Move left 
- D = Move right
- Left arrow = Rotate left
- Rigth arrow = Rotate rigth
- ESC = Exit the game

# RESSOURCES

- 42 *MiniLibx* documentation
- Wikipedia Raycasting 
- [Raycasting documentation](https://lodev.org/cgtutor/raycasting.html)

## AI usage

AI was used as a learning and debugging assistant during the development of this project.

It was mainly used for:
- Understanding reaycasting concepts
- Getting explanations of mathematical concepts used for ray directions, distances, and wall projection
- Understanding textures, player movement, rotation, and collision detection.

The project was implemented and understood by the author. AI was used to explain concepts, suggest approaches, and help debug problems rather than to generate the complete project automatically.