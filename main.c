#include <stdio.h>
#include <stdlib.h>

void eroare(char s[]){
    FILE *er = fopen("eroare.txt","a");
    fprintf(er,"%s\n",s);
    fclose(er);
}

int main() {
    FILE *pf = freopen("temp.out","w",stdout);

    system("dir *.srt /b /a-d");
    char s[100];
    fclose(pf);

    pf = fopen("temp.out","r");

    while(fscanf(pf,"%[^\n]\n",s)==1){
        FILE *srt = fopen(s,"r");

        if(srt==NULL) {
            char er[100];
            sprintf(er,"Fisierul \"%s\" nu poate fi deschis :(\n",s);
            eroare(er);
            return -1;
        }
        char *text = malloc(sizeof(char)*500000);
        int len = 0;
        while(fscanf(srt,"%c",&text[len])==1){
            len++;
        }
        for(int i=0;i<len;i++){
            switch (text[i]) {
                case 'ª':
                    //S
                    text[i] = 'S';
                    break;
                case 'Þ':
                    //T
                    text[i] = 'T';
                    break;
                case 'º':
                    //s
                    text[i] = 's';
                    break;
                case 'þ':
                    //t
                    text[i] = 't';
                    break;
            }
        }
        fclose(srt);
        char cmd[100];
        sprintf(cmd,"del \"%s\"",s);
        system(cmd);
        //char new_srt[100];
        //sprintf(new_srt,"new_%s",s);
        srt = fopen(s,"w");
        for(int i=0;i<len;i++){
            fprintf(srt,"%c",text[i]);
        }
        free(text);
        fclose(srt);
    }
    fclose(pf);
    system("del temp.out");
    return 1;
}
