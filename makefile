default:
	g++ src/*.cpp -o build/app.exe -lSDL3

linux:
	g++ src/*.cpp -o build/app -lSDL3
