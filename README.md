# This file includes:
 1. The exectuable app (app - Without step size, app_step - with step size).
 2. Source code test.cpp and test_step.cpp (contains the step size feature).
 3. Vizualizer (viz.py)

# Instructions to run on linux (Tried and tested on Ubuntu 18.04 and Ubuntu 16.04):
 # Run the following commands on the terminal (similar steps for test_step.cpp):
	 $ git clone https://github.com/capeieboi/Mowit.git
     $ cd Mowit
	 $ ./app_step
         $ python3 viz.py
     (OPTIONAL - If step 3 does not work) 
	 $ g++ -o app test_step.cpp 
	 $ ./app_step
 

video demo of the working - https://youtu.be/_UQXuVOX684

# Explanantion and some assumptions:
 1. The world space is a 2D 100x100 square, hence the coordinates that are input into the program must be within the range (0-      100,0-100),
 2. The obstacles are assumed to squares of 10x10 ( The input being the center of the square).
 3. The output is a list of points from the goal to the origin. 

# Things to be done differently:
 1. Make a header file for classes and functions.
 2. Add node limit to the algorithm.

