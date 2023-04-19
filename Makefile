comp = g++ -O3
all: vec3.o aleatorio.o ray.o main.o ppm.o obj.o aabb.o arvore.o
	rm -f *.ppm *.png
	clear
	$(comp) obj.o aleatorio.o ray.o main.o ppm.o vec3.o aabb.o arvore.o -o rtApp  && ./rtApp
	ffmpeg -i img.ppm img.png -y -nostats -loglevel 0 
	xdg-open img.png

main.o: main.cpp
	$(comp) -c  main.cpp
	
aabb.o: aabb.cpp
	$(comp) -c  aabb.cpp

arvore.o: arvore.cpp
	$(comp) -c  arvore.cpp
	

ray.o:	ray.cpp
	$(comp) -c ray.cpp

ppm.o: ppm.cpp
	$(comp) -c  ppm.cpp

vec3.o: vec3.cpp
	$(comp) -c  vec3.cpp


obj.o: obj.cpp
	$(comp) -c  obj.cpp

aleatorio.o: aleatorio.cpp
	$(comp) -c  aleatorio.cpp

clean:	
	rm -f *.o
	clear




