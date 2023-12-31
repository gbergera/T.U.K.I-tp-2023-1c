# Custom libraries' paths
SHARED_LIBPATHS=
STATIC_LIBPATHS=

# Compiler flags
CDEBUG=-g -Wall -DDEBUG
CRELEASE=-O3 -Wall -DNDEBUG

# Source files (*.c) to be excluded from tests compilation
TEST_EXCLUDE= src/utils/utils_client.c src/utils/utils_server.c src/utils/utils_start.c src/utils/utils.c
