#Переменные
CXXFLAGS = -Wall -Wextra -O2
LFLAGS   = -Wl,-O2
CXX = g++
LIBS_SO = -L../external/SFML/lib/release/ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -lgcov
INCPATH =  -I. -I../external/SFML/include  
VPATH = objects:source
DIR_OBJ=objects/
DIR_SRC=source/
APP = game
ARCHIVE_NAME=game.zip
DIR_DOX=doxs
DIR_EXTERNAL=../external

OBJECTS = base_hero_explosion.o \
		effect_of_the_rune.o \
		end_game.o \
		enemy_hit.o \
		game_draw.o \
		game_end_window.o \
		game_process.o \
		hero_shot.o \
		main.o \
		mouse_click.o \
		move_enemy.o \
		move_hero.o \
		pause_menu.o \
		randomize_enemy_coordinates.o \
		randomize_enemy_target_coordinates.o \
		randomize_enemy_type.o \
		randomize_rune_coordinates.o \
		take_rune.o \
		update_spawn_rune.o

SOURCE = base_hero_explosion.cpp \
		effect_of_the_rune.cpp \
		end_game.cpp \
		enemy_hit.cpp \
		game_draw.cpp \
		game_end_window.cpp \
		game_process.cpp \
		hero_shot.cpp \
		main.cpp \
		mouse_click.cpp \
		move_enemy.cpp \
		move_hero.cpp \
		pause_menu.cpp \
		randomize_enemy_coordinates.cpp \
		randomize_enemy_target_coordinates.cpp \
		randomize_enemy_type.cpp \
		randomize_rune_coordinates.cpp \
		take_rune.cpp \
		update_spawn_rune.cpp

HEADERS = cursors.h \
		game_end_window.h \
		game_objects.h \
		game_process.h \
		main.h \
		menu_bar.h \
		move_enemy.h \
		pause_end_menu.h \
		take_rune.h \
		tool_bar.h

.DEFAULT: 
	@make default
.PHONY : all clean arch doc
.SILENT: wc

#Правила сборки

${APP}: $(OBJECTS)
	$(CXX) $(LFLAGS) $^ $(LIBS_SO) -o $@
	-@mkdir ${DIR_OBJ}
	-@mv *.o ${DIR_OBJ}
	
#export LD_LIBRARY_PATH=../external/SFML/lib/release/:$LD_LIBRARY_PATH

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $< 

base_hero_explosion.o: base_hero_explosion.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

effect_of_the_rune.o: effect_of_the_rune.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

end_game.o: end_game.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

game_process.o: game_process.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

enemy_hit.o: enemy_hit.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

game_draw.o: game_draw.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

game_end_window.o: game_end_window.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

hero_shot.o: hero_shot.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

mouse_click.o: mouse_click.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

move_enemy.o: move_enemy.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

move_hero.o: move_hero.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

pause_menu.o: pause_menu.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

randomize_enemy_coordinates.o: randomize_enemy_coordinates.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

andomize_enemy_target_coordinates.o: randomize_enemy_target_coordinates.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

randomize_enemy_type.o: randomize_enemy_type.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

randomize_rune_coordinates.o: randomize_rune_coordinates.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

take_rune.o: take_rune.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

update_spawn_rune.o: update_spawn_rune.cpp
	$(CXX) $(CXXFLAGS) -c $(INCPATH) $<

#
all:
	-@mkdir ${DIR_OBJ}
	-@mkdir ${DIR_SRC} 
	-@mv *.h *.cpp ${DIR_SRC}
	 @${MAKE} ${APP}

clean:
	-@rm -rf ${DIR_OBJ} ${APP}
	-@cd ${DIR_SRC} && mv *.cpp *.h ..; cd ..; rmdir ${DIR_SRC}

arch: ${SOURCE} ${HEADERS}
	@zip -r ${ARCHIVE_NAME} $^ ${DIR_EXTERNAL} ${DIR_DOX}

doc:
	@cd ${DIR_DOX} && doxygen Doxyfile

wc: ${SOURCE} ${HEADERS}
	echo "newline word byte name"
	wc $^

doc_delete:
	@cd ${DIR_DOX} && mv image Doxyfile README.md ..
	-@rm -rf ${DIR_DOX}
	@mkdir ${DIR_DOX}
	@mv image Doxyfile README.md ${DIR_DOX}

default:
	@echo "Доступные цели makefile:"
	@echo " all - настройка окружения и сборка проекта;"
	@echo " "${APP}" - сборка проекта;"
	@echo " arch - архивация проекта;"
	@echo " doc - создание документации проекта;"
	@echo " wc - вывод статичтической информации по *.cpp файлам;"
	@echo " clean - удалить настроенное оеружение и собранный проект;"
	@echo " doc_delete - удалить документацию."
	@echo "\n Доступные цели для объектных фалйов:"
	@echo "  "${OBJECTS}

##                                                                                        ##
#Руководство по make:                                                                      #
#http://kappa.cs.petrsu.ru/~kulakov/courses/casetools/autobuild/make/gnu-make-ru.html#SEC45#
##                                                                                        ##