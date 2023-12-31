/*

  Equipe: Emannuel Levi, Henrique Fernandes, Levi Mena, Raimundo Rafael
  Avaliação 04: Trabalho Final
  04.505.23 - 2023.2 - Prof.Daniel Ferreira
  Compilador: gcc (GCC) 13.2.1 20230801.

*/

#include "../include/SCM.h"

unsigned char **CreateSCM(struct pgm img, struct pgm filtered_img, unsigned char level){
  unsigned char **matrix = (unsigned char **) malloc(sizeof(unsigned char *) * level); // Aloca a matriz
  unsigned char *matrix_vector = (unsigned char *)calloc(sizeof(unsigned char), level * level); 
  /* Aloca um vetor no qual estarão os itens da matriz, todos zerados (calloc()) visto que cada item da matriz vai ser "incrementado" a cada mesma ocorrência dele*/
  for (int i = 0; i < level; i++) {
    matrix[i] = &matrix_vector[i * level]; // Assinala o inicio de cada linha da matriz como sendo o endereço de matrix_vector[i * level] (level sendo o fator da SCM)
  }
  
  unsigned char * DataOGImg = malloc(sizeof(unsigned char) * img.size);
  unsigned char * DataFilteredImg = malloc(sizeof(unsigned char) * filtered_img.size);
  for (int i = 0; i < img.size; i++){
    DataOGImg[i] = (unsigned char) ((img.data[i] / 256.0) * level);
    DataFilteredImg[i] = (unsigned char) ((filtered_img.data[i] / 256.0) * level);
  }
  for (unsigned long i = 0; i < img.size; i++){
    matrix[DataOGImg[i]][DataFilteredImg[i]]++; 
    /*Quantiza os valores dos pixels da imagem original e da imagem filtrada e incrementa os "encontros"*/ 
  }
  free(DataOGImg);
  free(DataFilteredImg);
  return matrix;
}

void freeMatrix(unsigned char **matrix) {
    free(matrix[0]); // Libera a memoria alocada no vetor 
    free(matrix); // Libera a memória alocada na matriz
}
