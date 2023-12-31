#ifndef CPU
#define CPU_H_

#include<utils/utils.h>

typedef struct{
    char* ip_memoria;
	char* puerto_memoria;
	char* retardo_instruccion;
	char* puerto_escucha;
	char* tam_max_segmento;

}CPU_config;

CPU_config cpu_config;

t_log * cpu_logger;
t_log * mandatory_logger;
t_config * cpu_config_file;

int conexion_cpu;
int socket_cpu;
int socket_kernel;

int id_segmento;
int tamanio_segmento;
int direccion_base;



void load_config(void);
void leer_consola(t_log*);
void paquete(int);
void terminar_programa(t_log*, t_config*);

/*-------------- CONEXIONES ------------*/
void establecer_conexion(char* , char* , t_config*, t_log*);
void handshake_cliente(int socket_cliente);
void handshake_servidor(int socket_cliente);

void process_dispatch();


/*-------------- REGISTROS ------------*/

t_registro* registros;

#define REQUEST 0
#define RESPONSE 1

void init_registers();
void set_registers(contexto_ejecucion* ce);
void save_context_ce(contexto_ejecucion* ce);
void add_value_to_register(char* registerToModify, char* valueToAdd);
void add_two_registers(char* registerToModify, char* registroParaSumarleAlOtroRegistro);
void enviar_ce_con_string(int client_socket, contexto_ejecucion* ce, char* parameter, int codOP);
void enviar_ce_con_string_entero(int client_socket, contexto_ejecucion* ce, char* parameter, char* x, int codOP);
void enviar_ce_con_dos_enteros(int client_socket, contexto_ejecucion* ce, char* x, char* y, int codOP);
void enviar_ce_con_entero(int client_socket, contexto_ejecucion* ce, char* parameter, int codOP);
void enviar_ce_con_string_2_enteros(int client_socket, contexto_ejecucion* ce, char* parameter, int x, char* y, int codOP);

/*------------------- INSTRUCCIONES --------------------*/

#define BADKEY -1
#define I_SET 1
#define I_IO 2
#define I_EXIT 3
#define I_WAIT 4
#define I_SIGNAL 5
#define I_YIELD 6
#define I_F_OPEN 7
#define I_F_CLOSE 8
#define I_F_SEEK 9
#define I_F_READ 10
#define I_F_WRITE 11
#define I_F_TRUNCATE 12
#define I_CREATE_SEGMENT 13
#define I_DELETE_SEGMENT 14
#define I_MOV_IN 15
#define I_MOV_OUT 16



int keyfromstring(char *key);

/*-------------- PROCESOS -------------------*/


int check_interruption;
int sigsegv;
int id_segmento_con_segfault;
int desplazamiento_segfault;
int tamanio_segfault;
pthread_mutex_t m_execute_instruct;

/*-------------- CICLO DE INSTRUCCION --------------------*/

char* fetch_next_instruction_to_execute(contexto_ejecucion* ce);
char** decode(char* linea);
void execute_instruction(char** instruccion_a_ejecutar, contexto_ejecucion* ce);
void update_program_counter(contexto_ejecucion* ce);
void execute_process(contexto_ejecucion* ce);

/*-------------- MMU --------------------*/



uint32_t traducir_direccion_logica(uint32_t logical_address, contexto_ejecucion* ce, uint32_t valor_a_sumar);
char* fetch_value_in_memory(uint32_t physical_adress, contexto_ejecucion* ce, uint32_t size);
void store_value_in_register(char* register_mov_in, char* value);
char* encontrarValorDeRegistro(char* register_to_find_value);
void escribir_valor(uint32_t physical_address, char* register_value_mov_out, uint32_t pid, uint32_t size);

/* ------------- ENVIO DE PAQUETES -----------*/

void enviar_paquete_con_string_entero(int client_socket, char* parameter, char* x, int codOP);
void enviar_paquete_con_string_2_enteros(int client_socket, char* parameter, uint32_t x, char* y, int codOP);
void enviar_paquete_con_dos_enteros(int client_socket, char* x, char* y, int codOP);
void enviar_ce_con_string_3_enteros(int client_socket, contexto_ejecucion* ce, char* parameter, uint32_t x, char* y, uint32_t z ,int codOP);

uint32_t read_int(char* buffer, int* desp);

uint32_t tamanio_registro(char* registro);

#endif