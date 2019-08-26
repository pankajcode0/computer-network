#include <stdio.h>

int* encoding(int data[], int size, int encoded[])
{
encoded[0] = data[0]^data[1]^data[3]^data[4]^data[6];
encoded[1] = data[0]^data[2]^data[3]^data[5]^data[6];
encoded[3] = data[1]^data[2]^data[3]^data[7];
encoded[7] = data[4]^data[5]^data[6]^data[7];
encoded[2] = data[0];
encoded[4] = data[1];
encoded[5] = data[2];
encoded[6] = data[3];
encoded[8] = data[4];
encoded[9] = data[5];
encoded[10] = data[6];
encoded[11] = data[7];

return encoded;
}

int* decoding(int encoded[],int data[])
{
    int parity[4],error=-1;
    
    parity[0] = encoded[0]^encoded[2]^encoded[4]^encoded[6]^encoded[8]^encoded[10];
    parity[1] = encoded[1]^encoded[2]^encoded[5]^encoded[6]^encoded[9]^encoded[10];
    parity[2] = encoded[3]^encoded[4]^encoded[5]^encoded[6]^encoded[11];
    parity[3] = encoded[7]^encoded[8]^encoded[9]^encoded[10]^encoded[11];

    error = 1*parity[0]+2*parity[1]+4*parity[2]+8*parity[3];

    printf("error bit - %d\n",error);
    if(error>8){
        data[error-1]=!data[error-1];
    }
    return data;
}
int main()
{
    int data[8] = {0,1,1,0,0,0,0,1};
    int encoded[12],i;
    int *new,*newdata;

    encoding(data,8,encoded);

    

    for(i=0;i<12;i++)
    {
        printf("encoded bit %d - %d \n",i, encoded[i]);
    }
    encoded[5]=0;

    newdata = decoding(encoded,data);

    for(i=0;i<8;i++){
        printf("orignal data %d \n",newdata[i]);
    }

    return 0;    
}