//Rotate counter clockwise by 90 degree.

#include<iostream>
#include<cstdio>

void print(int a[][4])
{
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
     printf("\n");
      printf("\n");
}

void rotate_ccw_90(int a[][4])
{
    //mirror diagonally
    for(int i=0;i<4;i++)
        for(int j=i;j<4;j++)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }

    //mirror horizontally
    for(int i=0;i<4/2;i++)
        for(int j=0;j<4;j++)
        {
            int temp = a[i][j];
            a[i][j] = a[4-i-1][j];
            a[4-i-1][j] = temp;
        }

}

int main()
{
    int a[4][4]={{1,2,3,4},
                 {5,6,7,8},
                 {9,10,11,12},
                 {13,14,15,16}};
    print(a);
    rotate_ccw_90(a);
    print(a);
}
