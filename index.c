//libs importeren
//Invoer uitvoer lib 
#include <stdio.h>
//String bewerking module geimporteerd
#include <string.h>
//error codes libary
#include <errno.h>
//Mappen libary 
#include <dirent.h>
//Standaar functies en zoals de system() functie geimporteerd
#include <stdlib.h>


//Main functie
int main(int argc, char **argv)
{
    //Als argc groter is dan 1 de dingen die je na de comando kan uitvoeren
    if (argc > 1) {
        int i;
        //Alle paramters na de commando worden geloopt en dan geprint...
        for (i = 1; i < argc; i++) {
            //Char variable gemaakt met --help als inhoud
            char *help = "--help";
            // -p opgeslagen in variablen
            char *pythonprogramma = "-p";
            //Checkt als --help word uit gevoerd en print dan informatie over de programma uit
            if (!strcmp(argv[i],help)) {
                printf("Voer -p uit om python code te schrijven en het teglijkertijd ook uit tevoeren\n");
            } else if(!strcmp(argv[i],pythonprogramma)) {
                //Checkt als -p in de array argv[] zit
                //Opent de python-code map
                DIR* pythoncodemap = opendir("python-code");
                //Checkt als map bestaat
                if (pythoncodemap) {
                    //opent bestand code.py en geeft het schrijf permission
                    FILE* pythoncode = fopen("python-code/code.py","w+");
                    //char variablen pythoncodetext met een buffer van 500....
                    char pythoncodetext[500];
                    //Print type je python code op het scherm
                    printf("Type je python code: \n");
                    //Leest de waarden van boven en word opgeslagen in de pythoncodetext variablen
                    scanf("%s",pythoncodetext);
                    //Schrijft de code in het bestand code.py
                    fprintf(pythoncode,"%s",pythoncodetext);
                    printf("%s\n",pythoncodetext);
                    //Sluit het bestand
                    fclose(pythoncode);
                    //Sluit de map
                    closedir(pythoncodemap);
                    //Python code word uigevoerd
                    system("python3 python-code/code.py");
                } else if(ENOENT == errno){
                    //Als map niet bestaat
                    printf("map bestaat niet en word dus gemaakt :) \n");
                    //Maakt de map
                    system("mkdir python-code");
                }   

               
            }


        }
    } else {
        //Als de gene geen paramter toevoegt dan word deze bericht onder uitgevoerd...
        printf("Welkom bij ps schrijfer type --help om alle opties te tonen ... \n");
    }
}