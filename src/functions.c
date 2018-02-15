#include <stdio.h>
#include <stdlib.h>
/*
 *  Function that creates array and copys contents of file into
 *  array and displays it
 *
 */

void resize(char** buffer,int row, int  col, char*** Board){
    

    int count =0;     
    //allocates memory for the board
        *Board = (char**) malloc(row * sizeof(char*));
        
     
      for(int i =0;i<row;i++){
		(*Board)[i] = (char*)malloc(col*sizeof(char));
     } 
    printf("Board\n");
    //fills board with data from file
    for(int i =0;i < row ;i++){
       for(int j = 0; j < col;j++){
            
                   (*Board)[i][j] = buffer[0][count]; 
		   count++;        
}
  
}
	//prints board   
    for(int i =0;i < row ;i++){
       for(int j = 0; j < col;j++){
           printf("%c", (*Board)[i][j]);
      }
           printf("\n");
      }

}
/*
 *  Function that copys the board and than performs game of life and 
 *  prints the board  
 */
void grow(char*** Board, int row,int col,char*** newB){
       
       
       int neighbors=0; 
       *newB = (char**) malloc(row * sizeof(char*));
     
     
            for(int i =0;i<row;i++){
                            (*newB)[i] = (char*) malloc(col*sizeof(char));
                                 }
       
         
	  for(int i =0;i<row;i++){
            for(int j = 0; j<col;j++){
                 (*newB)[i][j] = (*Board)[i][j];
}   
        

}
    
   //checks neighbors                             
    for(int i = 1;i<row-1;i++){
       for(int j = 1; j < col-1; j++){
     			
			  if((*newB)[i][j] == 'o'){  	
				if((*newB)[i+1][j] == 'o'){
					neighbors++;
				}
       			  
                                if((*newB)[i-1][j] == 'o'){
                                        neighbors++;
                                }
			 
                                if((*newB)[i][j+1] == 'o'){
                                        neighbors++;
                                }
			 
                                if((*newB)[i][j-1] == 'o'){
                                        neighbors++;
                                }

                          	if((*newB)[i+1][j+1] == 'o'){
                                        neighbors++;
                                }  
				if((*newB)[i+1][j-1] == 'o'){
                                        neighbors++;
                                }
				if((*newB)[i-1][j+1] == 'o'){
                                        neighbors++;
                                }
				  if((*newB)[i-1][j-1] == 'o'){
                                        neighbors++;
                                }
				if(neighbors < 2){
					(*Board)[i][j] = 'x';
				}else if(neighbors > 3){
            				  (*Board)[i][j] = 'x';
				}
				neighbors = 0;
				}else{

				 if((*newB)[i+1][j] == 'o'){
                                        neighbors++;
                                }

                                if((*newB)[i-1][j] == 'o'){
                                        neighbors++;
                                }

                                if((*newB)[i][j+1] == 'o'){
                                        neighbors++;
                                }

                                if((*newB)[i][j-1] == 'o'){
                                        neighbors++;
                                }

                                if((*newB)[i+1][j+1] == 'o'){
                                        neighbors++;
                                }
                                if((*newB)[i+1][j-1] == 'o'){
                                        neighbors++;
                                }
                                if((*newB)[i-1][j+1] == 'o'){
                                        neighbors++;
                                }
                                if((*newB)[i-1][j-1] == 'o'){
                                        neighbors++;
                                }

				if(neighbors == 3){
                                       ( (*Board)[i][j]='o'); 
				
				}
				}
				neighbors = 0;

                                      
}
}

			if((*newB)[0][0]== 'o'){
				    if((*newB)[0][1]== 'o'){
						neighbors++;
				    }
				    if((*newB)[1][0]== 'o'){                    
                                                neighbors++;
                                    }
				    if((*newB)[1][1]== 'o'){                    
                                                neighbors++;
                                    }
				     if(neighbors < 2){
                                        (*Board)[0][0] = 'x';
                                      }else if(neighbors > 3){
                                          (*Board)[0][0] = 'x';
                                      }
				}

			 if((*newB)[row-1][col-1]== 'o'){
                                    if((*newB)[row-1][col-2]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[row-2][col-1]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[row-2][col-2]== 'o'){
                                                neighbors++;
                                    }
                                     if(neighbors < 2){
                                        (*Board)[row-1][col-1] = 'x';
                                      }else if(neighbors > 3){
                                          (*Board)[row-1][col-1] = 'x';
                                      }
                                }
  				  if((*newB)[row-1][0]== 'o'){
                                    if((*newB)[row-2][0]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[row-1][1]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[row-2][1]== 'o'){
                                                neighbors++;
                                    }
                                     if(neighbors < 2){
                                        (*Board)[row-1][0] = 'x';
                                      }else if(neighbors > 3){
                                          (*Board)[row-1][0] = 'x';
                                      }
                                }
				  
                                    					
                              if((*newB)[0][col-1]== 'o'){
                                    if((*newB)[1][col-1]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[0][col-2]== 'o'){
                                                neighbors++;
                                    }
                                    if((*newB)[1][col-2]== 'o'){
                                                neighbors++;
                                    }
                                     if(neighbors < 2){
                                        (*Board)[0][col] = 'x';
                                      }else if(neighbors > 3){
                                          (*Board)[0][col] = 'x';
                                      }
                                
				}

		

















printf("\nNew Board\n");
//prints new board
for(int i =0;i < row ;i++){
       for(int j = 0; j < col;j++){
           printf("%c", (*Board)[i][j]);
      }
           printf("\n");
      }

   free(*newB);
}



  
    
 





                               

