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

main.o: source/main.cpp
	$(CC) $(CFLAGS) -c source/main.cpp -o build/o/main.o

$(EXEC): main.o
	$(CC) $(CFLAGS) build/o/main.o $(CDEPS) -o build/bin/$(EXEC)