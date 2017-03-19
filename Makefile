CC=g++
C=-c
CP1= -fPIC -O2 
CP2=-larmadillo -llapack -lblas
bldr=build
octdir=Octave
all: mkdir x_solve copy file1 file2 clean_obj copy2 mk_wrk_dir

mkdir:
	mkdir -p build

x_solve: 
	$(CC) $(C) X_solve/x_solve.cpp
	$(CC) $(C) K_assmbly/k_spring.cpp 
	$(CC) $(C) K_assmbly/k_truss.cpp 
	$(CC) $(C) K_assmbly/main.cpp


copy:
	mv *.o $(bldr)/

file1:
	$(CC) $(CP1) $(bldr)/x_solve.o $(CP2) -o $(bldr)/x_solve

file2: 
	$(CC) $(CP1) $(bldr)/main.o $(bldr)/k_truss.o $(bldr)/k_spring.o $(CP2) -o $(bldr)/K_assmbly

clean_obj:
	rm -r $(bldr)/*.o

copy2: 
	cp $(octdir)/bndry_mngr.m $(bldr)/
	cp $(octdir)/input_mngr.m $(bldr)/

mk_wrk_dir:
	mkdir -p $(bldr)/boundary
	mkdir -p $(bldr)/input
	mkdir -p $(bldr)/output

