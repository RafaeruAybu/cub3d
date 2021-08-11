# cub3d
## subject
I had a School 42 MiniLibx window management library. With this i wrote a game engine like a Wolfenstein 3D.\
Game take a file(cub.map) and builds a map. Then game show the walls with textures.\
File cub.map includes list of textures and wall map.\
"1" is a wall.\
"2" is a sprite.\
"0" is a free space.\
"W","N","E","S" is a player spawn position and his camera direction.
Programm validates map. If there is a hole in a wall it will print an error.
A big part of a job was to make a perfect map file parser. The rules are:\
◦ The map must be closed/surrounded by walls, if not the program must returnan error.\
◦ Except for the map content, each type of element can be separated by one ormore empty line(s).\
◦ Except for the map content which always has to be the last, each type ofelement can be set in any order in the file.\
◦ Except for the map, each type of information from an element can be separatedby one or more space(s).\
◦ The map must be parsed as it looks in the file. Spaces are a valid part of themap and are up to you to handle. You must be able to parse any kind of map,as long as it respects the rules of the map.\
## usage
Clone the project.\
Make it.\
Start a program like this ./cub3D <map>.cub.\
Move with arrows on a keyboard.\
