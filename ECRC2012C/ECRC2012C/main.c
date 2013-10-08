//
//  main.c
//  ECRC2012C
//
//  Created by Shiyao Yu on 10/6/13.
//  Copyright (c) 2013 Shiyao Yu. All rights reserved.
//

#include <stdio.h>
#include <stddef.h>
#include <string.h>



typedef struct piece
{
    int num[6];
    int tag;// = 8;
    int first;
}Pieces;

Pieces piece[7];
int output[7];

int tagnum(int plusnum, Pieces ap);
int afunction(int piecenum , int output[]);

void inport();

int main(int argc, const char * argv[])
{

    // insert code here...
   // printf("Hello, World!\n");
    inport();
    return 0;
}

void inport()
{
    int num=0;
    int tempnum = 0;
    int i = 0,j=0,k=0;
    int piecenum=0;
    int newarray[7] = {0,1,2,3,4,5,6};
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
 
        for(k=0;k<7;k++)
        {
            for(j=0;j<6;j++)
            {
                scanf("%d", &tempnum);
                piece[k].num[j] = tempnum;
   //             printf("%d ",tempnum);
            }
   //         printf("\n");
            piece[k].tag = 8;

        }
        printf("case %d: ",i+1);
        if(afunction(piecenum,newarray)==0)
        {
            printf("No solution\n");
        }
    //TODO next function
    }
}

int afunction(int piecenum , int output[])
{
    int i=0,j=0,k=0;
 //   Pieces newP;
    int newOutput[7];
    int tempnum;
    for(i=piecenum;i<7;i++)
    {
    //    newP = piece[output[i]];
        if(piecenum == 0)
        {
            // next step;
            for(j=0; j < 6; j++)
            {
                if(piece[output[i]].num[j] == 1)
                {
                    piece[output[i]].tag = j;
                    break;
                }
            }
            memcpy(newOutput,output,7*sizeof(int));
            tempnum = newOutput[i];
            newOutput[i] = newOutput[piecenum];
            newOutput[piecenum] = tempnum;
            if(afunction(piecenum+1,newOutput))
                return 1;
        }
        else if(piecenum == 1)
        {
            for(j=0; j < 6; j++)
            {
                if(piece[output[i]].num[j] == tagnum(0,piece[output[0]]))
                {
                    piece[output[i]].tag = j;
                    break;
                }
            }
            memcpy(newOutput,output,7*sizeof(int));
            //memcpy(newOutput,output,sizeof(output));
            tempnum = newOutput[i];
            newOutput[i] = newOutput[piecenum];
            newOutput[piecenum] = tempnum;
            if(afunction(piecenum+1,newOutput))
                return 1;
        }
        else if(piecenum>1 && piecenum < 6)
        {
            for(j=0;j<6;j++)
            {
                if(piece[output[i]].num[j] == tagnum(piecenum-1,piece[output[0]]))
                {
                    piece[output[i]].tag = j;
                    if(tagnum(1,piece[output[i]]) == tagnum(-1,piece[output[piecenum-1]]) )
                    {
                     //   memcpy(newOutput,output,sizeof(output));
                        memcpy(newOutput,output,7*sizeof(int));

                        tempnum = newOutput[i];
                        newOutput[i] = newOutput[piecenum];
                        newOutput[piecenum] = tempnum;
                        if (afunction(piecenum+1,newOutput))
                            return 1;
                    }
                }
            }
        }
        else if(piecenum == 6)
        {
            for(j=0;j<6;j++)
            {
                if(piece[output[i]].num[j] == tagnum(piecenum-1,piece[output[0]]))
                {
                    piece[output[i]].tag = j;
                    if((tagnum(1,piece[output[i]]) == tagnum(-1,piece[output[piecenum-1]]))&& (tagnum(-1,piece[output[i]])== tagnum(1,piece[output[1]])))
                    {
                        for(k=0;k<7;k++)
                        {
                            printf("%d ",output[k]);
                        }
                        printf("\n");
                        return 1;
                    }
                    
                }
            }
        }
    }
    return 0;
}

int tagnum(int plusnum, Pieces ap)
{
    int tempnum;
    tempnum = ap.tag + plusnum;
    tempnum = (tempnum + 6)%6;
    return  ap.num[tempnum];

}

