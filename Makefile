CC=g++
C=-c
CP1= -fPIC -O2 
CP2=-larmadillo -llapack -lblas
bldr=build
 
build/all: mkdir build/xsolve build/K_assmbly copy file1 file2 clean_obj

mkdir:
	mkdir -p build

build/xsolve:
	$(CC) $(C) X_solve/x_solve.cpp

build/K_assmbly:
	$(CC) $(C) K_assmbly/*.cpp

copy:
	mv *.o $(bldr)/

file1:
	$(CC) $(CP1) $(bldr)/x_solve.o $(CP2) -o $(bldr)/x_solve

file2: 
	$(CC) $(CP1) $(bldr)/main.o $(bldr)/k_truss.o $(bldr)/k_spring.o $(CP2) -o $(bldr)/K_assmbly

clean_obj:
	rm -r $(bldr)/*.o
