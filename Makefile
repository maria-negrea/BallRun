all():
	clear
	g++ *.h *.cpp -lglut -lGL -lGLU -Wall -I /usr/include/SOIL -lSOIL -w
	clear
	./a.out