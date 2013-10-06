//
//  main.c
//  ECRC2012A
//
//  Created by Shiyao Yu on 10/4/13.
//  Copyright (c) 2013 Shiyao Yu. All rights reserved.
//
//  The 2012 East Central Regional Contest Problem A: Babs' Box Boutique

#include <stdio.h>
#include <string.h>

int x[10];
int y[10];
int cell[10][3];
int max;
 int celllength = 0;

struct Cell {
    int num;
    int edge[3];
  //  int box[num][3] = 0;
};

int input();
int recursion (int num);
int bubble(int Xs[], int Ys[],int num);
int longestdecrease(int Ys[],int num);

int main()
{

    // insert code here...
  //  printf("Hello, World!\n");
    input();
    return 0;
}


int input()
{
    int num = 0 ;
    int tempnum = 0;
    int i = 0 ;
    int xyz[3];
    int flag = 3;
    int casetag=1;
   
//    struct Cell cell[10];
    for(i=0;;i++)
    {
        scanf("%d",&tempnum);
        if(tempnum == 0)
            return 1;
        if(num == 0)
        {
            num = tempnum;
            celllength = tempnum;
            continue;
        }
        if(num > 0)
        {
            if(flag>0)
            {
                flag--;
                xyz[flag] = tempnum;
                if(flag == 0)
                {
                    num--;
                    flag = 3;
                    cell[num][2]= xyz[2];
                    cell[num][1] = xyz[1];
                    cell[num][0] = xyz[0];

                    if(num == 0)
                    {
                        recursion(celllength-1);
                        printf("Case %d: %d\n",casetag,max);
                        casetag++;
                        max = 0;
                         celllength = 0;
                    }
                    ///    cell[num]
                }
            }

        }
            
    };
    return 1;
}

int recursion (int num)
{
    int i = 0;
    int xt[10];
    int yt[10];

        for (i = 0;i<3 ; i++)
        {
            if (i==0) {
                x[num] = (cell[num][1]>cell[num][2]) ? cell[num][1]:cell[num][2];
                y[num] = (x[num]==cell[num][1]) ? cell[num][2]: cell[num][1];
                if(num == 0)
                {
                    memcpy(xt,x,sizeof(x));
                    memcpy(yt,y,sizeof(y));
                    bubble(xt,yt,celllength);

            //        bubble(x,y,celllength);
                }
                else
                {
                    recursion(num-1);
                }
            }
            else if (i==1) {
                x[num] = (cell[num][0]>cell[num][2]) ? cell[num][0]:cell[num][2];
                y[num] = (x[num]==cell[num][0]) ? cell[num][2]: cell[num][0];
                if(num == 0)
                {
                    memcpy(xt,x,sizeof(x));
                    memcpy(yt,y,sizeof(y));
                    bubble(xt,yt,celllength);

           //         bubble(x,y,celllength);
                }
                else
                {
                    recursion(num-1);
                }
            }
            else if (i==2) {
                x[num] = (cell[num][1]>cell[num][0]) ? cell[num][1]:cell[num][0];
                y[num] = (x[num]==cell[num][1]) ? cell[num][0]: cell[num][1];
                if(num == 0)
                {
                    memcpy(xt,x,sizeof(x));
                    memcpy(yt,y,sizeof(y));
                    bubble(xt,yt,celllength);

           //         bubble(x,y,celllength);
                }
                else
                {
                    recursion(num-1);
                }
            }
         }

    
    return 1;
}

int bubble(int Xs[], int Ys[],int num)
{
    int i =0;
    int j = 0;
    int tempx,tempy;
//    printf("%d %d\n%d %d\n%d %d\n%d %d\n ----------------\n",Xs[0],Ys[0],Xs[1],Ys[1],Xs[2],Ys[2],Xs[3],Ys[3]);
//    int Xs[10]; //= Xs;
//    int Ys[10];
//    memcpy(Xs,Xt,num);
//    memcpy(Ys,Yt,num);
    for(i = 0 ; i < num-1 ; i++)
        for (j = i+1; j < num ; j++)
        {
            if(Xs[i] < Xs[j])
            {
                tempx =Xs[i];
                Xs[i] = Xs[j];
                Xs[j] = tempx;
                tempy = Ys[i];
                Ys[i] = Ys[j];
                Ys[j] = tempy;
            }
            else if(Xs[i] == Xs[j])
            {
                if(Ys[i] < Ys[j])
                {
                    tempy = Ys[i];
                    Ys[i] = Ys[j];
                    Ys[j] = tempy;
                }
            }
        }
  //  printf("%d %d\n%d %d\n%d %d\n%d %d\n ",Xs[0],Ys[0],Xs[1],Ys[1],Xs[2],Ys[2],Xs[3],Ys[3]);
    longestdecrease(Ys,num);
    return 1;
}

int longestdecrease(int Ys[],int num)
{
    int i = 0,j =0;
    int lis[num];
    for(i=0;i<num;i++)
    {
        lis[i] = 1;
        for(j=0;j<i;j++)
        {
            if(Ys[i] <= Ys[j] && lis[j] + 1 > lis[i])
            {
                lis[i]++;
            }
        }
    }
    for(i=0;i<num;i++)
    {
        if (max<lis[i])
        {
            max = lis[i];
     //       printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",Ys[0],Ys[1],Ys[2],Ys[3],Ys[4],Ys[5],Ys[6],Ys[7],Ys[8]);
        }
    }
//    if(Ys[1]==9)
//    printf("%d,%d,%d,%d,%d,%d,%d,%d,%d\n",Ys[0],Ys[1],Ys[2],Ys[3],Ys[4],Ys[5],Ys[6],Ys[7],Ys[8]);

//    printf("%d,%d,%d\n",Ys[0],Ys[1],Ys[2]);
 //   printf("Max %d\n",max);
    return 1;
}
