//
//  main.c
//  ECRC2012A
//
//  Created by Shiyao Yu on 10/4/13.
//  Copyright (c) 2013 Shiyao Yu. All rights reserved.
//
//  The 2012 East Central Regional Contest Problem A: Babs' Box Boutique

#include <stdio.h>


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

int main(int argc, const char * argv[])
{

    // insert code here...
    printf("Hello, World!\n");
    input();
    return 0;
}


int input()
{
    int num;
    int tempnum;
    int i;
    int xyz[3];
    int flag = 3;
    int casetag=1;
   
//    struct Cell cell[10];
    for(i=0;;i++)
    {
        scanf("%d",&tempnum);
        if(tempnum == 0)
            break;
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
                        recursion(celllength);
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
    int i;

        for (i = 0;i<3 ; i++)
        {
            if (i==0) {
                x[num] = cell[num][1]>cell[num][2] ? cell[num][1]:cell[num][2];
                y[num] = (x[num]==cell[num][1]) ? cell[num][2]: cell[num][1];
                if(num == 0)
                {
                    bubble(x,y,celllength);
                }
                else
                {
                    recursion(num-1);
                }
            }
            else if (i==1) {
                x[num] = cell[num][0]>cell[num][2] ? cell[num][0]:cell[num][2];
                y[num] = (x[num]==cell[num][0]) ? cell[num][2]: cell[num][0];
                if(num == 0)
                {
                    bubble(x,y,celllength);
                }
                else
                {
                    recursion(num-1);
                }
            }
            else if (i==2) {
                x[num] = cell[num][1]>cell[num][0] ? cell[num][1]:cell[num][0];
                y[num] = (x[num]==cell[num][1]) ? cell[num][0]: cell[num][1];
                if(num == 0)
                {
                    bubble(x,y,celllength);
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
        }
    longestdecrease(Ys,num);
    return 1;
}

int longestdecrease(int Ys[],int num)
{
    int i,j;
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
            max = lis[i];
    }
    return 1;
}
