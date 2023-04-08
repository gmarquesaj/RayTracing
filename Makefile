all: main.o ppm.o vec3.o
	clear
	clang++ main.o ppm.o vec3.o -o rtApp  && ./rtApp && ffmpeg -i img.ppm img.png -y 
	xdg-open img.png

main.o: main.cpp
	clang++ -c  main.cpp
	


ppm.o: ppm.cpp

	clang++ -c  ppm.cpp

vec3.o: vec3.cpp

	clang++ -c  vec3.cpp
