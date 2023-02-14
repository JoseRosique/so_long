<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cl4qxms4g001609l49j835g66/project/2768861" alt="joslopez's 42 so_long Score" /></a>
# so_long

<b>MANDATORY PART</b>
<p>Your project must comply with the following rules:</p>
<p>• You must use the MiniLibX. Either the version available on the school machines,
or installing it using its sources.</p>
<p>• You have to turn in a Makefile which will compile your source files. It must not
relink.</p>
<p>• Your program has to take as parameter a map description file ending with the .ber
extension.<p/n>
<b>Game</b>
<p>• The player’s goal is to collect every collectible present on the map, then escape
chosing the shortest possible route.</p>
<p>• The W, A, S, and D keys must be used to move the main character.</p>
<p>• The player should be able to move in these 4 directions: up, down, left, right.</p>
<p>• The player should not be able to move into walls.</p>
<p>• At every move, the current number of movements must be displayed in the shell.</p>
<p>• You have to use a 2D view (top-down or profile).</p>
<p>• The game doesn’t have to be real time.</p>
<p>• Although the given examples show a dolphin theme, you can create the world you
want.</p>
<b>Graphic management</b>
<p>• Your program has to display the image in a window.</p>
<p>• The management of your window must remain smooth (changing to another window, minimizing, and so forth).</p>
<p>• Pressing ESC must close the window and quit the program in a clean way.</p>
<p>• Clicking on the cross on the window’s frame must close the window and quit the
program in a clean way.</p>
<p>• The use of the images of the MiniLibX is mandatory.</p>
<b>Map</b>
<p>• The map has to be constructed with 3 components: walls, collectibles, and free
space.</p>
<p>• The map can be composed of only these 5 characters:</p>
<p>0 for an empty space,</p>
<p>1 for a wall,</p>
<p>C for a collectible,</p>
<p>E for a map exit,</p>
<p>P for the player’s starting position.</p>
<p>• The map must contain 1 exit, at least 1 collectible, and 1 starting position to
be valid.</p>
<p>• The map must be rectangular.</p>
<p>• The map must be closed/surrounded by walls. If it’s not, the program must return
an error.</p>
<p>• You have to check if there’s a valid path in the map.</p>
<p>• You must be able to parse any kind of map, as long as it respects the above rules.</p>
<p>• If any misconfiguration of any kind is encountered in the file, the program must
exit in a clean way, and return "Error\n" followed by an explicit error message of
your choice.</p>
