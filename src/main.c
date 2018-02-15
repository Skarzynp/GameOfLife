#include <stdio.h>
#include <stdlib.h>
#include  "file_utilities.h" 
#include "functions.h"

/*
 *This Project loads a file of a gameboard and than 
 *performs conways game of life with the game board
 *  
 *
 *     
 * Author: Parker Skarzynski
 * Version 1.0
 */
int main(int argc, char** argv){
  

 char* buffer;
 char* filename;
 int row,col,cont,its,size; 
 char** Board;
 char**  newB;
 
     filename = (char*) malloc(sizeof(char)*16);
     printf("Enter file to open: %s" , filename);
     scanf("%s", filename);
     printf("%s\n", filename);
     printf("How many rows\n");
     scanf("%d", &row);
     printf("How many columns\n");
     scanf("%d", &col);
     size = row * col;     
     read_file(filename, &buffer);
     resize(&buffer,row ,col,&Board);
    
     grow(&Board,row,col,&newB);
      
     free(filename);
  



    do{ 
    	printf("1:save,2:load,3:run gen,4:run multiple gens,5:end ");
     	scanf("%d", &cont);	
        
     
  //Saves a file
  if( cont  == 1){
         filename = (char*) malloc(sizeof(char)*16);
         printf("name of file: ");
         scanf("%s", filename); 
	 write_file(filename , buffer, size);
         free(filename);
	 free(buffer);
  }
   //Open new file
   else if(cont == 2){
     
         filename = (char*) malloc(sizeof(char)*16);
         printf("Enter file to open: ");
         scanf("%s", filename);
	 read_file(filename, &buffer);
	 free(filename);
	 resize(&buffer,row ,col,&Board);
         free(buffer);

  }
   //run genration
   else if(cont == 3){
         grow(&Board,row,col,&newB);
  } 
   //run multiple generations 
   else if(cont == 4){
	printf("How many iterations? ");
	scanf("%d", &its);
	for(int i =0;i < its;i++){
     		grow(&Board,row,col,&newB);
	
}}
}while(cont != 5);

     
   
}


