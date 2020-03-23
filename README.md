This file includes:
 1. The exectuable app
 2. Source code test.cpp

##Instructions to run on linux (Tried and tested on Ubuntu 18.04 and Ubuntu 16.04):
 Run the following commands on the terminal:
	1) git clone https://github.com/capeieboi/Mowit.git
        2) cd Mowit
	3) ./app
        	4) (OPTIONAL - If step 3 does not work) g++ -o app test.cpp 
		5) ./app

video demo of the working - https://youtu.be/_UQXuVOX684

Explanantion and some assumptions:
 1. The world space is a 2D 100x100 square, hence the coordinates that are input into the program must be within the range (0-100,0-100)
 2. The obstacles are assumed to squares of 10x10 ( The input being the center of the square)
 3. Step size is not included in the algorithm 
