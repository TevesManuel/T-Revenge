default:
	g++ -o ./target/app.exe ./src/app.cpp -lsfml-graphics -lsfml-window -lsfml-system -lbox2d
	./target/app.exe