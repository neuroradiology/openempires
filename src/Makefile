BIN = ../openempires

LIBS  = -lSDL2
LIBS += -lSDL2_ttf
LIBS += -lSDL2_net

SRCS  = Animation.c
SRCS += Args.c
SRCS += Blendomatic.c
SRCS += Channels.c
SRCS += Color.c
SRCS += Data.c
SRCS += Direction.c
SRCS += Drs.c
SRCS += Field.c
SRCS += File.c
SRCS += Frame.c
SRCS += Graphics.c
SRCS += Grid.c
SRCS += Icon.c
SRCS += Buttons.c
SRCS += Image.c
SRCS += Input.c
SRCS += Interfac.c
SRCS += Lines.c
SRCS += main.c
SRCS += Map.c
SRCS += Meap.c
SRCS += Mode.c
SRCS += Outline.c
SRCS += Overview.c
SRCS += Window.c
SRCS += Parts.c
SRCS += Packet.c
SRCS += Packets.c
SRCS += Palette.c
SRCS += Point.c
SRCS += Points.c
SRCS += Quad.c
SRCS += Rect.c
SRCS += Rects.c
SRCS += Registrar.c
SRCS += Scanline.c
SRCS += Sock.c
SRCS += Sockets.c
SRCS += State.c
SRCS += Slp.c
SRCS += Stack.c
SRCS += Surface.c
SRCS += Table.c
SRCS += Trait.c
SRCS += Terrain.c
SRCS += Text.c
SRCS += Tile.c
SRCS += Tiles.c
SRCS += Unit.c
SRCS += Units0.c
SRCS += Units1.c
SRCS += Units2.c
SRCS += Util.c
SRCS += Video0.c
SRCS += Video1.c
SRCS += Vram.c

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

# 0: Compile with gcc.
# 1: Compile with clang.

CLANG = 0

# 0: Compile as C.
# 1: Compile as C++ (Better type checking).

CPP = 0

# 0: Do not use address sanitizer.
# 1: Use address sanitizer.

SANITIZE_ADDRESS = 0

# 0: Do not use thread sanitizer.
# 1: Use thread sanitizer.

SANITIZE_THREAD = 0

FLAGS = -O3 -march=native -flto

DEBUG = -Og -g

ifeq (1, $(SANITIZE_ADDRESS))
FLAGS = $(DEBUG) -fsanitize=address
endif

ifeq (1, $(SANITIZE_THREAD))
FLAGS = $(DEBUG) -fsanitize=thread
endif

FLAGS += -Wall -Wextra -Wshadow -Wpedantic

ifeq (00, $(CLANG)$(CPP))
COMPILER = gcc -std=c99
endif

ifeq (01, $(CLANG)$(CPP))
COMPILER = g++ -std=c++11
endif

ifeq (10, $(CLANG)$(CPP))
COMPILER = clang -std=c11
endif

ifeq (11, $(CLANG)$(CPP))
COMPILER = clang++ -std=c++11
endif

$(BIN): $(OBJS) $(DEPS)
	$(COMPILER) $(FLAGS) $(OBJS) $(LIBS) -o $(BIN)

%.o : %.c %.d Makefile
	$(COMPILER) $(FLAGS) -DSANITIZE_THREAD=$(SANITIZE_THREAD) -DSANITIZE_ADDRESS=$(SANITIZE_ADDRESS) -MMD -MP -MT $@ -MF $*.d -c $<

-include *.d

%.d : ;

.PHONY clean:
clean:
	rm -f $(BIN)
	rm -f $(OBJS)
	rm -f $(DEPS)
