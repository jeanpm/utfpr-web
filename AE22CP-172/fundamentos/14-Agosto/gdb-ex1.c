int main() {
        int size = 10;
        int vetor[size];    
        for (int i = 0; i <= size; i++)
            vetor[i-1] = vetor[i] + vetor[i+1];
}
