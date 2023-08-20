NAME = my_plot

CFLAGS = -W -Wall -Wextra

LIBS = -l$(NAME) -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

SRC = $(wildcard ./src/*.c)

LIB_SRC = $(wildcard ./src/func/*.c) \
				$(wildcard ./src/libs/*.c)

LIB_OBJ = $(LIB_SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: archive build clean

archive: $(LIB_OBJ)
	ar -rcs C:\Users\ADMIN\Code\my_libs\lib$(NAME).a $(LIB_OBJ)

build:
	@if not exist "./out" mkdir "./out"
	@gcc $(CFLAGS) $(SRC) -LC:\Users\ADMIN\Code\my_libs $(LIBS) -I./includes -o ./out/$(NAME)

clean:
	@if exist ./src/*.o del /Q src\*.o
	@if exist ./src/func/*.o del /Q src\func\*.o
	@if exist ./src/libs/*.o del /Q src\libs\*.o
