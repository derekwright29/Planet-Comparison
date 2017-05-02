# Planet-Comparison
ASEN 1969 Sample of Work Project
Derek Wright
Spring 2017
CU Boulder

This program compares the major objects in the solar system with Earth by:

  mass (-m),
  diameter (-d),
  distance from the Sun (-s),
  length of year (-y) --> for planets only (not moons),
  length of day (-a), 
  surface gravitational acceleration (-g)
  
The objects that are included in this program are:

  Earth (duh),
  Mercury,
  Venus,
  Mars,
  Jupiter,
  Saturn,
  Uranus,
  Neptune,
  Pluto,
  Eris,
  Moon (Earth),
  Io,
  Europa,
  Ganymede,
  Callisto,
  Titan,
  Enceladus.
  
To compile the program, simply call 'make' in your terminal and in the correct directory. This will create the executable file "planetcomp."

An example call is like this:
  ./planetcomp -d Ganymede 
  ./planetcomp -m Uranus
  
Calls like these will print a usage messge and/or Earth's statistics
  ./planetcomp OR
  ./planetcomp -f Mars OR
  ./planetcomp -s Andromeda.
 
Happy Comparing
