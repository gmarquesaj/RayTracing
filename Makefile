comp = g++ -O3 
all: vec3.o ray.o main.o ppm.o obj.o
	rm -f *.ppm *.png
	clear
	$(comp) obj.o ray.o main.o ppm.o vec3.o -o rtApp  && ./rtApp && ffmpeg -i img.ppm img.png -y 
	xdg-open img.png

main.o: main.cpp
	$(comp) -c  main.cpp
	
ray.o:	ray.cpp
	$(comp) -c ray.cpp

ppm.o: ppm.cpp
	$(comp) -c  ppm.cpp

vec3.o: vec3.cpp
	$(comp) -c  vec3.cpp


obj.o: obj.cpp
	$(comp) -c  obj.cpp

clean:	
	rm -f *.o
	clear
#vec3.o: vec3.cpp
#	$(comp) -c  vec3.cpp
