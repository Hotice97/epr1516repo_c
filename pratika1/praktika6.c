#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000
#define MAX0 30

static int zv = 0; //zählvariable für den index
int zahl;

typedef struct {
    char* name;
    int matrikelNummer;
} studierende; //name des structs


//Funktion zum Anzeigen aller Einträge in struct studierende
void ausgebenStudierende(studierende *s[], int anzahl) {
    int i; //zaehlvariable

    for(i = 0; i < anzahl; i++) {
        printf("Position      :%d \n",i+1);
        printf("Name          :%s",s[i]->name);
        printf("Matrikelnummer:%d\n\n",s[i]->matrikelNummer);
    }
}

studierende *datenEinlesen() {
    studierende *neu;
    neu = (studierende*) malloc(sizeof(studierende));       //weist neu dynamischen speicher mit der länge von studierende zu
    char puff[MAX0];//puffer

    getchar();
    printf("Name eingeben: \n");
    fgets(puff,MAX0,stdin);                             //liest einen string ein und speichert in puffer
    neu->name = (char*) malloc((MAX0)*sizeof(char));   //weist name dynamischen speicher zu mit MAX0 mal größe von char
    strncpy(neu->name,puff,MAX0);                      //kopiert name nach puffer
    printf("Matrikelnummer eingeben: \n");
    scanf("%d", &neu->matrikelNummer);

    return neu;
}

int sucheNachNummer(studierende*s[], int anzahl, int matrikelNummer) {
    int i = 0;
    for(i=0;i<=anzahl;i++)
    {
        if(matrikelNummer==s[i]->matrikelNummer)
        {
            printf("Die Matrikelnummer %d hat die Position %d\n", matrikelNummer, i+1);
            return i;
        }
    }
    printf("Nicht gefunden.");
    return i;
}

int sucheNachName(studierende *s[], int anzahl, char *name) {
    int i;
    int x = 1; //Aenderungsvariable

    for(i = 0; i < anzahl; i++)
    {
        if(strcmp(name,s[i]->name) == 0 ){
            printf("Position         :%d\n", i+1);
            printf("Name             :%s",s[i]->name);
            printf("Matrikelnummer   :%d\n",s[i]->matrikelNummer);
            printf("\n\t<ENTER>\n");
            getchar();

            x = 0;
            return i;
        }
    }

    if(x)//Wenn der name nicht gefunden wurde
    {
        printf("Der Name konnt nicht gefunden werden! \n");
    }

    return 0;
}

void loeschen (studierende *s[], int*anzahl, int stelle) {
    int z = (sucheNachNummer(s,*anzahl, stelle)); //stelle der gewählten matrikelnummer
    int i = 0;

    if(z >= 0)
    {
        s[z]->matrikelNummer = 0;
        s[z]->name = "\0";
        (*anzahl)--;

        for(i = z+1; i < MAX; i++){
            s[i -1] = s[i];
        }
    }
}

void sortiereAbsteigendNachName(studierende*s[],int anfangzahl, int anzahl) {
    int i, j;

    if(anfangzahl< anzahl)
    {
        i = anfangzahl;
        j = anzahl;
        do
        {
            while (strcmp(s[i]->name, s[(i+j)/2]->name) < 0)
                i++;
            while (strcmp(s[j]->name, s[(i+j)/2]->name) > 0)
                j--;
            if(i<=j)
            {

                char *puffer;

                int *puffernummer;

                puffer = s[i]->name;
                puffernummer = s[i]->matrikelNummer;
                s[i]->name = s[j]->name;
                s[i]->matrikelNummer = s[j]->matrikelNummer;
                s[j]->name = puffer;
                s[j]->matrikelNummer = puffernummer;

                i++;
                j--;
            }
        }
        while (i<j);
        sortiereAbsteigendNachName(s,anfangzahl,j);
        sortiereAbsteigendNachName(s,i,anzahl);
    }
}

int main() {

    studierende** immatrikuliert;
    immatrikuliert= (studierende **) malloc(MAX*sizeof(studierende*)); //dynamische speicherplatzzuweisung zu immatrikuliert

    int x; //statusvariable
    int i,j; //zaehlvariablen
    int auswahl; //switch variable

    int numeric = 0;

    printf("Geben Sie die Anzahl der hinzuzufügenden Studenten ein: \n");
    scanf("%d",&zahl);


    //Einlesen der Daten
    for(i = 0; i < zahl; i++)
    {
        immatrikuliert[zv] = datenEinlesen();
        zv++;
    }

    do{
        printf("1.Alle Einträge anzeigen   " "2.Student hinzufügen   "
                       "3.Suche nach Nummer   " "4.Suche nach Name   "
                       "5.Löschen   " "6.SortierenNachName   " "0.Beenden   ");
        scanf("%d",&auswahl);

        switch(auswahl){
            case 1: {
                ausgebenStudierende(immatrikuliert,zv); break;
            }
            case 2:
                printf("Geben Sie die Anzahl der hinzuzufügenden Studenten ein: \n");
                scanf("%d",&zahl); printf("\n");
                for(i = 0; i < zahl; i++){
                    immatrikuliert[zv] = datenEinlesen();
                    zv++;
                };
                break;
            case 3:{
                printf("Die zu suchende Matrikelnummer eingeben: \n");
                int m;
                scanf("%d",&m);
                int x = sucheNachNummer(immatrikuliert,zv, m);
                break;
            }
            case 4:{
                printf("Den zu suchenden Namen eingeben: ");
                char name[MAX0];
                getchar();
                fgets(name,MAX0,stdin);
                char* name1;
                int len = strlen(name);
                name1= (char*)malloc((len+1)*sizeof(char));
                strncpy(name1,name,len+1);
                printf("%d\n",sucheNachName(immatrikuliert,zv,name1));
                break;
            }
            case 5:{
                printf("Welche Matrikelnummer wollen Sie löschen?: \n");
                int stelle;
                scanf("%d", &stelle);
                loeschen(immatrikuliert, &zv, stelle);
                break;
            }
            case 6:{
                sortiereAbsteigendNachName(immatrikuliert,0,zv-1);
                break;
            }
        }

    } while(auswahl!=0);

    printf("Das Programm wird nun beendet!\n");
    free(immatrikuliert);
    return 0;
}