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
                    printf("bestaat \n");
                    
                    //Sluit de map
                    closedir(pythoncodemap);
                } else if(ENOENT == errno){
                    //Als map niet bestaat
                    printf("map bestaat niet \n");
                }   

               
            }


        }
    } else {
        //Als de gene geen paramter toevoegt dan word deze bericht onder uitgevoerd...
        printf("Welkom bij ps schrijfer type --help om alle opties te tonen ... \n");
    }
}