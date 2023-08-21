NAME = my_plot

CFLAGS = -W -Wall -Wextra

LIBS = -l$(NAME)

SRC = $(wildcard ./src/*.c)

LIB_SRC = $(wildcard ./src/func/*.c) \
				$(wildcard ./src/libs/*.c)

CSFML	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

LIB_OBJS = $(patsubst %.c, %.o, $(LIB_SRC))

all: archive build clean

archive: build_obj
	ar -rcs C:\Users\ADMIN\Code\my_libs\lib$(NAME).a $(LIB_OBJS)

build:
	@if not exist "./out" mkdir "./out"
	@gcc $(CFLAGS) $(SRC) -LC:\Users\ADMIN\Code\my_libs $(LIBS) -I./includes -o ./out/$(NAME) $(CSFML)

clean:
	@if exist ./src/*.o del /Q src\*.o
	@if exist ./src/func/*.o del /Q src\func\*.o
	@if exist ./src/libs/*.o del /Q src\libs\*.o
	@if exist ./*.o del /Q *.o

build_obj:
	@gcc $(CFLAGS) $(CSFML) -c -I./includes $(LIB_SRC)
	@move *.o ./src/func