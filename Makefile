INCLUDE_DIR = ./include/

SOURCE =  ./src/app.cpp
SOURCE += ./src/Window/Window.cpp
SOURCE += ./src/Object/Object.cpp
SOURCE += ./src/Player/PLayer.cpp
SOURCE += ./src/Primitive/PrimitiveGraphics.cpp

TARGET =  ./target/app.exe

LIBS =  -lsfml-graphics
LIBS += -lsfml-window
LIBS += -lsfml-system
LIBS += -lm
LIBS += -lbox2d

CC = g++

default:
	$(CC) -o $(TARGET) -I$(INCLUDE_DIR) $(SOURCE) $(LIBS) 
	./target/app.exe