int* soma(int a, int b) {
        int resultado = a + b;
            return &resultado;
}

int main() {
        int* r = soma(5, 3);
            
        *r = *r + 10;
}
