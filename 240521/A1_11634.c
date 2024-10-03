#include <stdio.h>

int main(){
    FILE *fileinput, *fileoutput;
    char fileinputname[] = "A1_11634_inputA.txt";
    char fileoutputname[] = "A1_11634_outputA.txt";
    fileinput = fopen(fileinputname, "r");
    fileoutput = fopen(fileoutputname, "w");
    if(fileinput == NULL || fileoutput == NULL){
        printf("Fail to open file\n");
        return 1;
    }

    int number;
    while(fscanf(fileinput, "%d", &number) != EOF)
        if(number){
            int count = 0;
            int check[10000] = {0};
            while(!check[number]){
                count++;
                check[number] = 1;
                number *= number;
                number /= 100;
                number %= 10000;
            }
            fprintf(fileoutput, "%d\n", count);
        }
        
    fclose(fileinput);
    fclose(fileoutput);

    return 0;
}