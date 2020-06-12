proyecto:
	g++ -o proyecto.out proyecto.cpp -lGL -lglfw -lGLEW -lSOIL -lGLU -lglut -lm -Wall

texture:
	g++ -o texture_test.out texture_test.cpp drawTexture.h drawColor.h -lGL -lglfw -lSOIL -lGLEW -lGLU -lglut -lm


test:
	g++ -o test.out color_test.cpp -lGL -lglfw -lGLEW -lGLU -lglut -Wall
