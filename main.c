#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int searchStringInFilenameAndReplace(char *inputFileName, char* targetString, char* replaceString, char *newFilename);

int main(int argc, char *argv[])
{
    char strNewName[256], target1[]=" - DASH_V.webm", target2[]=" - DASH_A.webm", newName1[]=".mp4", newName2[]=".aac";

    if(argc==2){
        //printf(("%s\n",argv[1]));
        if(searchStringInFilenameAndReplace(argv[1],target1,newName1,strNewName)==0){
            //printf(("%s\n",strNewName));
            rename(argv[1],strNewName);
        }
        else if(searchStringInFilenameAndReplace(argv[1],target2,newName2,strNewName)==0){
            //printf(("%s\n",strNewName));
            rename(argv[1],strNewName);
        }
        else{
            printf("%s and %s not find in argv[1]\n",target1,target2);
            system("pause");
        }
    }
    else{
        printf("Need file name in argv[1]\n");
        system("pause");
    }

    return 0;
}

// xxx - DASH_V.webm -> xxx.mp4, targetString = " - DASH_V.webm" replaceString=".mp4"
// xxx - DASH_A.webm -> xxx.aac, targetString = " - DASH_A.webm" replaceString=".aac"
int searchStringInFilenameAndReplace(char *inputFileName, char* targetString, char* replaceString, char *newFilename)
{
    int nn=0;
    nn = strstr(inputFileName,targetString)-inputFileName; //search target String in input file name
    if(nn>0){ // if find
        strncpy(newFilename, inputFileName, nn); //copy the filename before the target string
        newFilename[nn]='\0'; //put \0 in string end
        strcat(newFilename,replaceString); //put replace string in the end of new file name
        return 0;
    }
    return 1;
}
