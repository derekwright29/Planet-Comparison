#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double diam[] = {12756, 0.38, 0.95, 0.53, 11.21, 9.44, 4.01, 3.88, 0.18, 0.1825, 0.2725, 0.2859, 0.245, 0.378, 0.4134, 0.404, 0.0396}; //km
double mass[] = {5.97e24, 0.06, 0.815, 0.11, 318, 95, 15, 17, 0.002, 0.00278, 0.0123, 0.015, 0.008, 0.0181, 0.025, 0.0225, 0.000018}; //kg
double dist[] = {93, 0.39, 0.72, 1.52, 5.20, 9.54, 19.18, 30.06, 39.44, 68,  0, 0, 0, 0, 0, 0, 0}; //in Mmi
double days[] = {24.0, 58.65, 116.65, 1.03, 0.41, 0.44, 0.72, 0.72, 6.38, 1.08, 27.32, 1.77, 3.55, 16.69, 7.15, 15.9, 1.37}; //
double year[] = {365, 0.24, 0.63, 1.88, 11.86, 29.46, 84.01, 164.80, 247.70, 561.4, 0, 0, 0, 0, 0, 0, 0};
double grav[] = {9.8, 0.38, 0.9, 0.38, 2.64, 0.93, 0.89, 1.12, 0.06, 0.083, 0.165, 0.183, 0.134, 0.126, 0.146, 0.139, 0.0115};

const char planetstr[17][10] = {"Earth", "Mercury", "Venus", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto", "Eris", "Moon", "Io", "Europa", "Callisto", "Ganymede", "Titan", "Enceladus"};


int UsageMsg();
int checkPlanet(char ** input);
int checkOption(char ** input);
int printEarthStats();
int printPlanet(int opt, int pla);

int main(int argc, char ** argv)
{
  //check argc
  if (argc <= 2)
  {
    UsageMsg();    
    printEarthStats();
    return -1;
  }

  if (argc > 3)
  {
    UsageMsg();
    return -1;
  }
  //check option
  int opt = checkOption(argv);
  //printf("Opt is: %d", opt);
  //check planet
  int pla = checkPlanet(argv);
  //printf("Pla is: %d", pla);
  
  printPlanet(opt, pla);
  
  return 0;
}

int checkPlanet(char ** input)
{
  size_t i;
  for (i = 0; i < (sizeof(planetstr)/sizeof(planetstr[0])); i++)
  {
    if (strcmp(input[2], planetstr[i]) == 0)
      return i;
  }

  UsageMsg();
  return -1;
}

int checkOption(char ** input)
{
  const char options[6][3] = {"-d", "-m", "-s", "-a", "-y", "-g"};
  
  for (size_t i = 0; i < (sizeof(options)/sizeof(options[0])); i++)
  {
    if (strcmp(input[1], options[i]) == 0)
      return i;
  }

  UsageMsg();
  return -1;
}

int printEarthStats()
{
  printf("\nEarth\'s Stats:\nDiameter (km): %g\nMass (kg): %g\nDistance from Sun (Mmi): %g\nLength of Day (earth hours): %g\nLength of Year (earth days): %g\nGravitational Acceleration at Surface (m/s/s): %g\n\n", diam[0], mass[0], dist[0], days[0], year[0], grav[0]);

  return 0;
}

int printPlanet(int opt, int pla)
{
  if (opt == 0)
  {
    printf("\n%s\'s diameter is %g times that of Earth, and is equal to %g km.\n\n", planetstr[pla], diam[pla], (diam[pla] * diam[0]));
    return 0;
  }

  if (opt == 1)
  {
    printf("\n%s\'s mass is %g times that of Earth, and is equal to %g kg.\n\n", planetstr[pla], mass[pla], (mass[pla] * mass[0]));
    return 0;
  }
  
  if (opt == 2)
  {
    printf("\n%s\'s distance from Sun is %g times that of Earth, and is equal to %g Million miles.\n\n", planetstr[pla], dist[pla], (dist[pla] * dist[0]));
    return 0;
  }

  if (opt == 3)
  {
    printf("\n%s\'s day is %g times that of Earth, and is equal to %g Earth hours.\n\n", planetstr[pla], days[pla], (days[pla] * days[0]));
    return 0;
  }

  if (opt == 4)
  {
    printf("\n%s\'s year is %g times that of Earth, and is equal to %g Earth days.\n\n", planetstr[pla], year[pla], (year[pla] * year[0]));
    return 0;
  }

  if (opt == 5)
  {
    printf("\n%s\'s surface gravity is %g times that of Earth, and is equal to %g m/s/s.\n\n", planetstr[pla], grav[pla], (grav[pla] * grav[0]));
    return 0;
  }
  else
    return -1;
}

int UsageMsg()
{
  printf("\nThis program allows you to compare Earth\'s: \n\tdiameter (-d),\n\tmass (-m),\n\tdistance from Sun (-s),\n\tlength of day (-a),\n\tlength of year (-y),\n\tsurface gravity (-g)\n\nto mamy other objects in the Solar System: Mercury, Venus, Mars, Jupiter, Saturn, Uranus, Neptune, Pluto, Eris, Moon, Io, Europa, Callisto, Ganymede, Titan, and Enceladus.\n\nExample call: ./planetcomp -m Titan\n\nAs a note, zero values mean N/A. All distances and years of moons have the same value as their parent object.\n\n");


  return -1;
}
