OBJ = bin/main.o bin/hero.o bin/controller.o bin/point.o bin/cell.o bin/field.o bin/view.o bin/buffEvent.o bin/debuffEvent.o bin/teleportEvent.o bin/generate_field.o bin/kill.o bin/game.o bin/management.o bin/read_file.o bin/user_commands.o

all: start

start: $(OBJ)
	g++ $(OBJ) -o run
	

bin/main.o: main.cpp
	g++ -c main.cpp -o bin/main.o
	

bin/hero.o: Entity/hero.cpp
	g++ -c Entity/hero.cpp -o bin/hero.o

bin/controller.o: Game/controller.cpp
	g++ -c Game/controller.cpp -o bin/controller.o

bin/point.o: Field/point.cpp
	g++ -c Field/point.cpp -o bin/point.o

bin/cell.o: Field/cell.cpp
	g++ -c Field/cell.cpp -o bin/cell.o

bin/field.o: Field/field.cpp
	g++ -c Field/field.cpp -o bin/field.o

bin/view.o: Game/view.cpp
	g++ -c Game/view.cpp -o bin/view.o

bin/buffEvent.o: Events/buffEvent.cpp
	g++ -c Events/buffEvent.cpp -o bin/buffEvent.o

bin/debuffEvent.o: Events/debuffEvent.cpp
	g++ -c Events/debuffEvent.cpp -o bin/debuffEvent.o

bin/teleportEvent.o: Events/teleportEvent.cpp
	g++ -c Events/teleportEvent.cpp -o bin/teleportEvent.o

bin/generate_field.o: Field/generate_field.cpp
	g++ -c Field/generate_field.cpp -o bin/generate_field.o

bin/kill.o: Events/kill.cpp
	g++ -c Events/kill.cpp -o bin/kill.o

bin/game.o: Game/game.cpp
	g++ -c Game/game.cpp -o bin/game.o

bin/management.o: Managment/management.cpp
	g++ -c Managment/management.cpp -o bin/management.o

bin/read_file.o: Managment/read_file.cpp
	g++ -c Managment/read_file.cpp -o bin/read_file.o

bin/user_commands.o: Managment/user_commands.cpp
	g++ -c Managment/user_commands.cpp -o bin/user_commands.o

clean:
	rm -rf bin/*.o start



