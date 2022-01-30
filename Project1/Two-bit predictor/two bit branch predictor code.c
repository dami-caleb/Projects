#include <stdio.h>
#include <unistd.h> //By including the <unistd.h> header file we are able to use the sleep function

int main()
{
    /*We define(declear) the states*/
    #define taken 0
    #define weakly_taken  1
    #define  weakly_not_taken  2
    #define  not_taken  3
    
    int event; 
    int state = weakly_taken; //we assume we are in the weakly_taken state
    
    while(1){
        int i;
        for(i=0;i<5;i++){
            //the condition is true for i<0
            //therefore the event is taken
            event = taken;
          
          switch(state){
            
            case taken:
            if(event==0){
                state = taken;
    	        printf("TAKEN\n");
    	        sleep(5); //I have included this function, so we can see the code run in a way we can see it. (we)
            }
            else if(event==3){
                state = weakly_taken;
        	    printf("WEAKLY_TAKEN\n");
        	    sleep(5); 
            }
            break;
            
            
            case weakly_taken:
            if(event==0){
                state = taken;
            	printf("TAKEN\n"); //the state moves from a weakly_taken state to a taken state.
            	sleep(5);
            }
            else if(event==3){
                state = weakly_not_taken;
    	        printf("WEAKLY_NOT_TAKEN\n");
    	       sleep(5);
            }
            break;
            
            
            case weakly_not_taken:
            if(event==0){
                state=weakly_taken;
    	        printf("WEAKLY_TAKEN\n");
    	        sleep(5);
            }
            else if(event==3){
                state=not_taken;
    	        printf("NOT_TAKEN\n");
    	        sleep(5);
            }
            break;
            
            
            case not_taken:
            if(event ==0){
                state = weakly_not_taken;
    	        printf("WEAKLY_NOT_TAKEN\n");
    	        sleep(5);
            }
            else if(event==3){
                state = not_taken;
    	        printf("NOT_TAKEN\n");
    	        sleep(5);
            }
            break;
        }
        
        }
        //we are out of the for loop which means
        //the condition for the loop is no longer true (i.e. i>5)
        //therefore the event moves from "taken" to not_taken
        event = not_taken; //the two bit predictor still predicts we are in the taken state (which is wrong).
        printf("WEAKLY_NOT_TAKEN\n");
    	sleep(5);
    }

    return 0;
}
