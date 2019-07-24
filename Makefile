CC		= g++
CFLAGS	= -W -Wall
CDEPS	= -lGL -lGLU -lglut

EXEC	= koeboes.exe

all: remdir makedir $(EXEC)

remdir:
	@rm -rf build/

makedir:
	@mkdir -p build/bin/
	@mkdir -p build/o/


control.o: source/control.cpp source/control.hpp
	$(CC) $(CFLAGS) -c source/control.cpp -o build/o/control.o

render.o: source/render.cpp source/render.hpp
	$(CC) $(CFLAGS) -c source/render.cpp -o build/o/render.o

main.o: source/main.cpp
	$(CC) $(CFLAGS) -c source/main.cpp -o build/o/main.o

$(EXEC): control.o render.o main.o
	$(CC) $(CFLAGS) build/o/control.o build/o/render.o build/o/main.o $(CDEPS) -o build/bin/$(EXEC)