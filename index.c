//libs importeren
//Invoer uitvoer lib 
#include <stdio.h>
//String bewerking module geimporteerd
#include <string.h>


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
            if (!strcmp(argv[i],help)) {
                printf("hoi\n");
            }


        }
    } else {
        //Als de gene geen paramter toevoegt dan word deze bericht onder uitgevoerd...
        printf("Welkom bij ps schrijfer type --help om alle opties te tonen ... \n");
    }
}