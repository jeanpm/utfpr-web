# Anotações & Sugestões

1. Formatação do texto do código:
	1.1 Utilize espaços:
		novo->prox = l->inicio;  // Mais legível
		novo->prox=l->inicio;    
	
	1.2 Em minha opinião, asteriscos deveriam ficar ao lado do tipo, e não aos
		lado da variável. Set *a
		
		Set* s; // Fica claro que o tipo da variável s é (Set*)
		
		Exemplo de tipo ponteiro:
		
		#define Set_ptr Set*		
		Set_ptr s; //  


2. Se a resolução de um problema utiliza código desenvolvido anteriormente:

	2.1. Se certifique de que esse código esteja correto, isso evita que se
		 procure por erros em lugares indevidos.
		 
		 . A divisão do código em pequenas funções, facilita que esse objetivo
		   seja alcançado.
		   

3. Garanta que os casos base funcionem:
	
	3.1 Transformação de decimal para binário:
		
		. Funciona para número igual a zero?
		. Funciona para número igual a um?
		. Funciona para número > 1 
		
4. Simplificações ajudam a legibilidade do código (porém evite excessos)
	
	4.1 Este código
	
		if(L->inicio == NULL)
			return 1;
		else
			return 0;
		
		É equivalente a esse:
		
		return (L->inicio == NULL);


5. Repetições de código (copy/paste), são sempre arriscadas, visto que é comum
   esquecermos de trocar nomes de variáveis e coisas similares.
   
	5.1 Se a mesma sequência de código é utilizada várias vezes, crie uma função
		com aquela funcionalidade.
		
		. Imprimir itens da tabela hash_item
		. Iniciar qualquer estrutura de dados, etc.
		. Inicializar listas da tabela hash
		
	5.2 Pode parecer que se perde tempo, com essa abordagem, porém em caso de 
		possíveis bugs, o tempo economizado para encontrá-los vale a pena! 
	
		. Muitos perderam tempo procurando erros que tinha origem na alocação
		  inicial de estruturas que era posteriormente utilizadas.
		  
		  
6. Esquecer de ler a entrada!		  


7. Misturar a implementação dos tratamento de colisões

	7.1 Encadeamento separado utiliza listas
	7.2 Enderaçamento aberto (teste linear) não as utiliza.
	7.3 Em nenhuma dessas implementações é razoável percorrer a tabela inteira
	    a procura de elementos repetidos, antes da inserção. Isso vai contra 
	    toda a idéia de tabelas hash. Torna todo o processo de procura ineficiente.
	    
	    
8. Em geral, o tempo que se gasta para debugar um código é proporcional à:

	8.1 Sua familiaridade com as bibliotecas utilizadas
	8.2 Prática de programação
	8.3 Paciência de rever o código passo a passo, ao invés de alteração e
		recompilação.
		
9. Utilizar uma forma de implementação diferente da pedida no enunciado da 
   questão. Sendo que ambas implementações 'base' foram disponibilizadas e 
   analizadas em aula.
