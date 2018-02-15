#include <stdio.h>
#include <stdlib.h>
#include "file_utilities.h"


 /*
 *  Function that reads a file and puts it 
 *  into a array
 * 
 *  Help from https://stackoverflow.com/questions/238603/how-can-i-get-
 *  a-files-size-in-c
 *  and https://www.tutorialspoint.com/c_standard_library/c_function_fr
 *  ead.htm
 *
 *  @returns 1 if works correctly
 *  
 */
int read_file( char* filename, char** buffer ){
   
     long  sz;
     int counter = 0;
     FILE* fp;
     
     fp = fopen(filename,"r");
     
     
 if(fp != NULL){
    fseek(fp, 0L, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *buffer =(char*) malloc(sizeof(char)*(sz+1L));
    printf("works file read\n");
    fread(*buffer,sizeof(char),(size_t)sz,fp);
    fclose(fp);
    return 1;
}else{ 
	printf("Error\n");
        return 0;
}
     
  
      

                                          

}

 /*
 *  Function that takes a array that is the
 *  game board and writes it into a file
 *   
 *    
 *  @returns 1 if works correctly
 *        
 */

int write_file( char* filename, char  *buffer, int size){
	FILE* fp;
        fp = fopen(filename, "w");
 	if(fp != NULL){
        fprintf(fp,"%s", buffer);
        return 1;
        }
        else{
          printf("Error...while writing file");
          return 0;
	}


       fclose(fp);
}
