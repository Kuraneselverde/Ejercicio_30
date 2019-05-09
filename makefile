all: EJ30.git datos.dat 30F.x

EJ30.git: datos.dat G30F.py
	python3 G30F.py

datos.dat: 30F.x
	./30F.x

30F.x: 30F.cpp
	g++ 30F.cpp -o 30F.x

clean:
	rm -rf *.x *.dat *.png
