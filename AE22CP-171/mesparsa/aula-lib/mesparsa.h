



typedef struct _Matriz_Interface Matriz;

Matriz* new_matrix();

void print_row(Matriz* m, long i);

void print_col(Matriz* m, long j);

void print_matrix(Matriz* m);


// Se o item já existe, substituir seu valor
int put(Matriz* m, long i, long j, float valor);


// Se o item já existe, substituir seu valor
float get(Matriz* m, long i, long j);

int add_to_col(Matriz* m, long col, float val);

int add_to_row(Matriz* m, long row, float val);


void freeMatriz(Matriz* m);

