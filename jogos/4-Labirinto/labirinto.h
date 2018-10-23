struct labirinto{
	int colunas;
	int linhas;
	char** matriz;
};

typedef struct labirinto LABIRINTO;
struct pocicao{
	int x;
	int y;
	
};
typedef struct pocicao POCISAO;


	void lerLabirinto();
	void alocaLabirinto();
	void imprimeLabirinto();
	void achaInicio();
	void move();
	int chegou();