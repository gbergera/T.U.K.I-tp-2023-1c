#include <stdlib.h>
#include <stdio.h>
#include <commons/config.h>
#include <utils/hello.h>
#include <valgrind/valgrind.h>

int main(int argc, char *argv[]) {
    // if (argc < 2) {
    //     fprintf(stderr, "Se esperaba: %s [CONFIG_PATH]\n", argv[0]);
    //     exit(1);
    // }

    // t_config *config = config_create(argv[1]);
    // if (config == NULL) {
    //     perror("Ocurrió un error al intentar abrir el archivo config");
    //     exit(1);
    // }

    // void print_key_and_value(char *key, void *value) {
    //     printf("%s => %s\n", key, (char *)value);
    // }
    // dictionary_iterator(config->properties, print_key_and_value);

    // config_destroy(config);
    hello_world();
    funcion("Hola Mundo", 42);
    printf("test\n");
    return 0;
}

void funcion(char *str, int i) {
    VALGRIND_PRINTF_BACKTRACE("%s: %d\n", str, i);
    }