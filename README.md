# Cave Adventure Game Introduction
A text-based adventure game written in C++ where you explore and solve puzzles to escape a cave system. The game was based on Zork, a popular old school text-based adventure game. It was written for a C++ course at Aiken Technical College.

# Note
The game does not have an executable. To run the game you must have Microsoft Visual Studio or some other IDE that includes a C++ Debugger. Run the game either by copying the repository to your IDE of choice or by downloading the files and double clicking "Zork Project C++ ll.sln" if you use Visual Studio.

# Controls
All controls are text commands, written in a Command Prompt. The controls can also be seen initally upon program startup or by typing "commands" in the command prompt. The '->' icon indicates pressing the enter key and responding to another prompt.
- [go (main cardinal direction)]: move throughout the map (ex. go west)
- [look]: shows area description
- [inventory]: displays player inventory
- [commands]: displays command list
- [take (item)]: add area item into player inventory (ex. take rock)
- [drop (item)]: drop item from player inventory into the room (ex. drop rock)
- [talk to (object)]: attempt to talk to something (ex. talk to Jim)
- [give to (object) -> (item)]: attempt to give an item to something (ex. give to Jim [press enter] rock)
- [enter (object)]: attempt to enter something (ex. enter door)
- [place -> (object) -> (item)]: attempt to place an item onto an object (ex. place [press enter] table [press enter] rock)

# Map
A Map detailing the traversable areas of the game. The starting location is "Chasm Floor". Green arrows indicate which ways are accessable from where, areas like "Mossy Passageway" to "Mud Home" are one way, whereas all others go both ways. Orange arrows require a key or other item to enter. The red arrow and red square indicate the exit. The red circles indicate a portal thats takes you back and forth from those specific areas.

![image](https://github.com/user-attachments/assets/ebbc986a-21d0-4432-b5cc-c1f510f83e41)

# Walkthrough
This walkthrough contains all commands required to beat he game and escape the cave. Commands listed after other commands in parenthesis (ie 20: take the golden ring (talk to moe)) are optional for progression and are intended to show additional interactions or to demonstrate roadblocks.

1. go east
2. talk to skeleton (talk to moe)
3. go south
4. go south
5. go north
6. go east
7. enter barrier
8. yes
9. death
10. v
11. queen
12. go west
13. go north
14. go west
15. go west
16. go west
17. go south
18. take strange scroll
19. go east
20. take golden ring (talk to moe)
21. go west
22. go north
23. go north
24. go south
25. go east
26. go east
27. go east
28. give to moe
29. golden ring (talk to moe) (talk to moe)
30. go west
31. go west
32. go west
33. go south
34. go east
35. go east (investigate platform)
36. place -> platform -> green orb (investigate platform)
37. enter portal
38. investigate body (take the black sword)
39. sheathe the black sword
40. take the black sword (investigate body)
41. go east
42. go east
43. place -> alter -> strange scroll
44. go west
45. go south
46. go south
47. go south
48. draw the black sword
49. loot dragon
50. go north
51. go north
52. go west
53. go west
54. go west
55. place -> pedestal -> the black sword (investigate pedestal)
56. go south
57. go east
58. go east
59. retrieve green orb
60. go west
61. go west
62. go north
63. go north
64. place -> green slot -> green orb
65. place -> red slot -> red orb
66. place -> blue slot -> blue orb
