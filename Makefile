all():
	clear
	g++ *.h *.cpp -lglut -lGL -lGLU -Wall -I /usr/include/SOIL -lSOIL
	clear
	./a.out