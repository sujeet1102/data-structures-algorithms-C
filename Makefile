main: src/*.c src/*.h
	gcc -o main src/*.c src/*.h

clean:
	rm main

