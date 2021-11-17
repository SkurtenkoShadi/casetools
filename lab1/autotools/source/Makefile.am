game_CPPFLAGS =  -I../external/SFML/include 
game_LDADD =  -L../external/SFML/lib/release/ -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -lgcov
bin_PROGRAMS = game
gamedir=.

game_SOURCES = base_hero_explosion.cpp \
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

game_HEADERS= cursors.h \
		game_end_window.h \
		game_objects.h \
		game_process.h \
		main.h \
		menu_bar.h \
		move_enemy.h \
		pause_end_menu.h \
		take_rune.h \
		tool_bar.h

#export LD_LIBRARY_PATH=../external/SFML/lib/release/:$LD_LIBRARY_PATH
