OBJ = main.o hero.o controller.o point.o cell.o field.o view.o buffEvent.o debuffEvent.o teleportEvent.o generate_field.o kill.o

all: start

start: $(OBJ)
	g++ $(OBJ)
	

main.o: main.cpp
	g++ -c main.cpp

hero.o: hero.cpp
	g++ -c hero.cpp

controller.o: controller.cpp
	g++ -c controller.cpp

point.o: point.cpp
	g++ -c point.cpp

cell.o: Field/cell.cpp
	g++ -c Field/cell.cpp

field.o: Field/field.cpp
	g++ -c Field/field.cpp

view.o: view.cpp
	g++ -c view.cpp

buffEvent.o: Events/buffEvent.cpp
	g++ -c Events/buffEvent.cpp

debuffEvent.o: Events/debuffEvent.cpp
	g++ -c Events/debuffEvent.cpp

teleportEvent.o: Events/teleportEvent.cpp
	g++ -c Events/teleportEvent.cpp

generate_field.o: Field/generate_field.cpp
	g++ -c Field/generate_field.cpp

kill.o: Events/kill.cpp
	g++ -c Events/kill.cpp

clean:
	rm -rf *.o start



