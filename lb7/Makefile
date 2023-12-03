OBJ = bin/main.o \
 	bin/hero.o \
	bin/controller.o \
	bin/point.o bin/cell.o \
	bin/field.o bin/buffEvent.o \
	bin/debuffEvent.o \
	bin/teleportEvent.o \
	bin/generate_field.o \
	bin/kill.o \
	bin/game.o \
	bin/read_file.o \
	bin/set_file_management.o \
	bin/console_read.o \
	bin/management.o \
	bin/set_console_management.o \
	bin/file_controle.o \
	bin/game_tracker.o \
	bin/view_console.o \
	bin/win_message.o \
	bin/lose_message.o \
	bin/new_game_message.o \
	bin/do_command_message.o \
	bin/dont_command_message.o \
	bin/log_tracker.o \
	bin/manage_logs.o \
	bin/console_output.o \
	bin/file_output.o \


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

bin/read_file.o: Managment/read_file.cpp
	g++ -c Managment/read_file.cpp -o bin/read_file.o

bin/set_file_management.o: Managment/set_file_management.cpp
	g++ -c Managment/set_file_management.cpp -o bin/set_file_management.o

bin/console_read.o: Managment/console_read.cpp
	g++ -c Managment/console_read.cpp -o bin/console_read.o

bin/management.o: Managment/management.cpp
	g++ -c Managment/management.cpp -o bin/management.o

bin/set_console_management.o: Managment/set_console_management.cpp
	g++ -c Managment/set_console_management.cpp -o bin/set_console_management.o

bin/file_controle.o: Managment/file_controle.cpp
	g++ -c Managment/file_controle.cpp -o bin/file_controle.o

bin/game_tracker.o: View/game_tracker.cpp
	g++ -c View/game_tracker.cpp -o bin/game_tracker.o

bin/view_console.o: View/view_console.cpp
	g++ -c View/view_console.cpp -o bin/view_console.o

bin/win_message.o: Logs/win_message.cpp
	g++ -c Logs/win_message.cpp -o bin/win_message.o

bin/lose_message.o: Logs/lose_message.cpp
	g++ -c Logs/lose_message.cpp -o bin/lose_message.o

bin/new_game_message.o: Logs/new_game_message.cpp
	g++ -c Logs/new_game_message.cpp -o bin/new_game_message.o

bin/do_command_message.o: Logs/do_command_message.cpp
	g++ -c Logs/do_command_message.cpp -o bin/do_command_message.o

bin/dont_command_message.o: Logs/dont_command_message.cpp
	g++ -c Logs/dont_command_message.cpp -o bin/dont_command_message.o

bin/log_tracker.o: Logs/log_tracker.cpp
	g++ -c Logs/log_tracker.cpp -o bin/log_tracker.o

bin/manage_logs.o: Logs/manage_logs.cpp
	g++ -c Logs/manage_logs.cpp -o bin/manage_logs.o

bin/console_output.o: Logs/console_output.cpp
	g++ -c Logs/console_output.cpp -o bin/console_output.o

bin/file_output.o: Logs/file_output.cpp
	g++ -c Logs/file_output.cpp -o bin/file_output.o


clean:
	rm -rf bin/*.o start

