INCLUDE_DIR = ./include/

CORE_SOURCE =  ./src/app.cpp
CORE_SOURCE += ./src/Engine/ContactListener/ContactListener.cpp
CORE_SOURCE += ./src/Engine/Object/Object.cpp
CORE_SOURCE += ./src/Engine/Engine.cpp
CORE_SOURCE += ./src/Engine/Primitive/PrimitiveGraphics.cpp
SOURCE =  $(CORE_SOURCE)
SOURCE += ./src/GameObjects/Player/PLayer.cpp
SOURCE += ./src/GameObjects/Wall/Wall.cpp

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
core:
	$(CC) -o $(TARGET) -I$(INCLUDE_DIR) $(CORE_SOURCE) $(LIBS)