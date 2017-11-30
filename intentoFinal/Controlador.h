

void cont_init();

int cont_altaCliente (char* nombre,char* apellido,char* dni, int estado);

int cont_altaAlquiler (int* idCliente, int* idEquipo, int* idOperador, int* tiempoEstimado, int* tiempoReal, int* estado);

int cont_bajaCliente (int id);

int cont_bajaAlquileres(int id);

int cont_modificarCliente(char* nombre,char* apellido,char* dni, int id, int estado);

int cont_listarClientes ();

int cont_listarAlquileres ();

int cont_modificarSocio (char* nombre,char* apellido,char* dni, int id, int estado);

int cont_altaServicio (char* descripcion);

int cont_bajaServicio(int id);

int cont_modificarServicio (char* descripcion, int id, int estado);

int cont_listarServicios ();
