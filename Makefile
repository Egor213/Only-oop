OBJ = main.o hero.o controller.o point.o cell.o field.o

all: start

start: $(OBJ)
	g++ $(OBJ)
	rm -rf *.o start

main.o: main.cpp
	g++ -c main.cpp

hero.o: hero.cpp
	g++ -c hero.cpp

controller.o: controller.cpp
	g++ -c controller.cpp

point.o: point.cpp
	g++ -c point.cpp

cell.o: cell.cpp
	g++ -c cell.cpp

field.o: field.cpp
	g++ -c field.cpp

clean:
	rm -rf *.o start

