# Libraries
LIBS=utils commons


# Custom libraries' paths
SHARED_LIBPATHS=
STATIC_LIBPATHS=../utils

# Compiler flags
CDEBUG=-g -Wall -DDEBUG
CRELEASE=-O3 -Wall -DNDEBUG

# Arguments when executing with start, memcheck or helgrind
ARGS=./config/consola.config ./config/pruebas/prueba.txt

# Valgrind flags
MEMCHECK_FLAGS=--track-origins=yes --log-file="runlogs/memcheck.log"
HELGRIND_FLAGS=--log-file="runlogs/helgrind.log"

# Source files (*.c) to be excluded from tests compilation
TEST_EXCLUDE=src/main.c
