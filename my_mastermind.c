#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
// this  function is comparing two indexes / IF theyare isn't same it will return 0 else 1.
int compare(char ar1[], char ar2[]){
    int l = strlen(ar1);
    for(int i = 0; i < l; i++){
        if(ar1[i] != ar2[i]){
            return 0;
        }
    }
    return 1;
}
// this function cheks is there same index in array/
int contain(char* arr, char a){
    for(int i=0 ; i < 4 ; i++){
        if(arr[i]==a){
        return 1;
        }
    }
return 0;
}
// this function cheks length and characters if they does not meet our standards it will return 0.
int iscorrect( char* arr){
    // cheking for length
    if(strlen(arr)>4 || strlen(arr)<4){
        return 0;
    }
    // cheking for presence of only numbers and only from 0 to 7.
    for(int i =0 ; i < 4; i++){
        if(arr[i] >= '8' && arr[i] <='z'){
            return 0;
        }
    }
    // cheking for non-identity.
    for (int i = 0; i < 4; i++){
        for(int j = i +1; j < 4; j++){
            if(arr[j]==arr[i])
            return 0;
        }
    }
    return 1;
}
//this function is creating random code if the user not write in the begining.
void secretCode(char *code){
    srand(time(NULL));
    int i=0;
    while(i<4){
        char temp = rand()%8 + '0';
        if(!contain(code, temp)){
            code[i] = temp;
            i++;
        }
    }
}

int main(int argc, char* argv[]){
    char code[100000];
    int attempts = 10;
    int wp = 0;
    int mp = 0;
    int t =0;
    int c = 0;
// this loop is to check if the user entered the password or the number of rounds.
    for(int i = 1; i < argc; i++){
        if(compare(argv[i], "-c")){ 
            c = i + 1; 
        } 
        if(compare(argv[i], "-t")){ 
            t = i + 1; 
            attempts = atoi(argv[t]); 
        } 
    } 
    
 // and if the user not entered the code, it will automatically created.   
    if(c == 0){ 
        secretCode(code);
    }else{ 
        for(int i = 0; i < 4; i++){ 
            code[i] = argv[c][i]; 
        } 
    } 


    // printf("%s\n", code);
    printf("will you find the secret code?\n---\n");
    //this loop for rounds.
    for(int j =0 ; j < attempts; j++){
        printf("Round %d\n", j);
        int correctInp = 1;
        char input[100000];
        do{
            printf(">");
            wp = 0;
            mp = 0;
            scanf("%s", input);
            if(iscorrect(input) == 0){
               correctInp =0;
               printf("Wrong input!\n");
            }else{
                correctInp = 1;
                }
        }
        while(correctInp != 1);
        // this loop for counting well placed and misplaced piaces.
        for( int c = 0; c <4; c++){
            if(code[c] == input[c]){
                wp++;
            }
            if(code[c] != input[c] && contain(code, input[c])){
                mp++;
            }
        }
        // if well placed piaces all will correct it will print congartz! otherwise it will shows number of wp and wp/
        if(wp == 4){
            printf("Congratz! You did it!\n");
            return 0;
        }else{
            printf("Well placed pieces: %d\n", wp);
            printf("Misplaced pieces: %d\n", mp);
        }
        printf("---\n");
    }
}
