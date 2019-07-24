CC		= g++
CFLAGS	= -W -Wall
CDEPS	= -lGL -lGLU -lglut

EXEC	= koeboes.exe

all: remdir makedir cpdatatobuild $(EXEC)

remdir:
	@echo "Cleaning Build Folder"
	@rm -rf build/

makedir:
	@echo "Making Build Folder"
	@mkdir -p build/bin/
	@mkdir -p build/o/

cpdatatobuild:
	@echo "Copying Data Files to Build Folder"
	@cp -r Data/ build/Data/

control.o: source/control.cpp source/control.hpp
	$(CC) $(CFLAGS) -c source/control.cpp -o build/o/control.o

texture.o: source/texture.cpp source/texture.hpp
	$(CC) $(CFLAGS) -c source/texture.cpp -o build/o/texture.o

render.o: source/render.cpp source/render.hpp
	$(CC) $(CFLAGS) -c source/render.cpp -o build/o/render.o

main.o: source/main.cpp
	$(CC) $(CFLAGS) -c source/main.cpp -o build/o/main.o

$(EXEC): control.o texture.o render.o main.o
	$(CC) $(CFLAGS) build/o/control.o build/o/texture.o build/o/render.o build/o/main.o $(CDEPS) -o build/bin/$(EXEC)