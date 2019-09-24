#include <stdio.h>
#include <string.h>

// RULES - The data which is to be passed into the code should be in the file name "writing.txt". The final image would be in "finaltry.txt" which would be generated automatically


int len,index[1280],index_in,index_counter=0,next=0,dropcheck=0;
char leng[4],index_ch[1],id_master[3],id_slave[3];

void removeSpaces(char *str)
{
    int count = 0;
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i];

    str[count] = '\0';
}

int hexadecimalToDecimal(char hexVal[])
{
    int len1 = strlen(hexVal);
    //int len = sizeof(hexVal)/sizeof(char);
    printf("Hex decimal len of hexval[] array : %d\n", len1);  
    printf("\n the lenght inside hexdec %d     ", len1);
    for(int i=0;i<len1;i++)
    {
    	printf("%c ", hexVal[i]);
    }
    printf("\n");
    int base = 1;
    int dec_val = 0;
    for (int i=len1-1; i>=0; i--)
    {
        if (hexVal[i]>='0' && hexVal[i]<='9')
        {
            dec_val += (hexVal[i] - 48)*base;
            base = base * 16;
        }
        else if (hexVal[i]>='A' && hexVal[i]<='F')
        {
            dec_val += (hexVal[i] - 55)*base;
            base = base*16;
        }
    }
    return dec_val;
}

void firstpacket(char ch[])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        leng[i] = ch[72+i];
    }
    len = hexadecimalToDecimal(leng);

    index_ch[0] = ch[76];
    index_in = hexadecimalToDecimal(index_ch);
    index[index_counter]=index_in;
    index_counter++;

    for(i=0;i<3;i++)
    {
        id_master[i] = ch[77+i];
    }

    printf("Inside the first len = %d, index = %d, identifier = %d\n",len,index_in, hexadecimalToDecimal(id_master));

    if(len>183)
    {
        next=1;
        FILE *wr;
        wr = fopen("finaltry.txt","w");

        for(i=80;i<446;i++)
        {
            fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = len-183;
    }
    else if(len<=183)
    {
        next=0;
        FILE *wr;
        wr = fopen("finaltry.txt","w");

        for(i=80;i<(len*2);i++)
        {
            fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = 0;
    }

}

void secondpacket(char ch[])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        leng[i] = ch[i];
    }
    len = hexadecimalToDecimal(leng);

    index_ch[0] = ch[4];
    index_in = hexadecimalToDecimal(index_ch);
    index[index_counter]=index_in;
    index_counter++;

    for(i=0;i<3;i++)
    {
        id_master[i] = ch[5+i];
    }

     printf("Inside the second len = %d, index = %d, identifier = %d\n",len,index_in, hexadecimalToDecimal(id_master));

    if(len>219)
    {
        next=1;
        FILE *wr;
        wr = fopen("finaltry.txt","w");

        for(i=8;i<446;i++)
        {
            fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = len-219;
    }
    else if(len<=219)
    {
        next=0;
        FILE *wr;
        wr = fopen("finaltry.txt","w");

        for(i=8;i<(len*2);i++)
        {
            fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = 0;
    }

}

void thirdpacket(char ch[])
{
    int i,j;
                                                           //DOne by SAhil
    //int fch = ch[0];
    index_ch[0] =ch[0]; 
                                                             // int len = strlen(index_ch);//sizeof(index_ch)/sizeof(char);
    printf("lenght of index_ch[1] inside the thirdpacket function: %d\n", strlen(index_ch)); 
    index_in = hexadecimalToDecimal(index_ch);
    printf("\nTrying to check index in three = %c \n",index_ch[0]);
    if(index[index_counter-1]!=(index_in-1))
    {
        dropcheck=1;
    }
    else{
           index[index_counter]=index_in;
           index_counter++;
    }

    for(i=0;i<3;i++)
    {
        id_slave[i] = ch[1+i];
    }
    for(i=0;i<3;i++)
    {
        if(id_master[i]!=id_slave[i])
        {
            dropcheck=1;
            break;
        }
    }

     printf("Inside the third len = %d, index = %d, identifier = %d\n",len,index_in, hexadecimalToDecimal(id_slave));

    if(len>221)
    {
        next=1;
        FILE *wr;
        wr = fopen("finaltry.txt","a");

        for(i=4;i<446;i++)
        {
            fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = len-221;
    }
    else if(len<=221)
    {
        next=0;
        FILE *wr;
        wr = fopen("finaltry.txt","a");

        for(i=4;i<(len*2);i++)
        {
           fprintf(wr, "%c",ch[i]);
            if(i%2!=0)
            {
                fprintf(wr, " ");
            } 
        }
        fprintf(wr, "\n");
        fclose(wr);
        len = 0;
    }

}

int main()
{
    char ch[1000];                        //= "0082000000000000000000000000000000000000000000000000000000000000000000000082591000ffd8fff7000b100010001001011100ffda0008015300000000000000000000000000000000000000000000000000000000000000000000000082591000ffd8fff7000b100010001001011100ffda0008015300000000000000000000000000000000000000000000000000000000000000000000000082591000ffd8fff7000b100010001001011100ffda000801531b5c4f7dd75b01dea08049e642225926579d241f0f8d6a8a5916953251531b5c4f7dd75b01dea0";
    char testcondition_1[] = "AAAA";
    char chek;
    int flag=0,i=0,cnt=0,no_tile=0,j=0;
    int ich=0;
    FILE *rf;
    rf = fopen("writing.txt","r");
    while((chek=getc(rf))!=' ')
    {
        cnt++;
        if(cnt>4)
        {
            break;
        }
    }
    fclose(rf);
    printf("value of cnt is %d\n",cnt);
    rf = fopen("writing.txt","r");
    while(no_tile<1280)
    {
        //FILE *rf;
        //rf = fopen("writing.txt","r");
        while(j<(223*(cnt+1)))
        {
            chek = getc(rf);
            ch[j] = chek;
            j++;
        }
        j=0;
        removeSpaces(ch);
        while(ch[ich]!='\0')
        {
        	printf("%c", ch[ich]);
        	ich++;
        }


    while(i<4)
    {
        //printf("kyu atak raha hai");
        if(ch[i]!=testcondition_1[i])
        {
            flag=1;
            break;
        }
        i++;
    }
    i=0;
    if(flag==0)
    {
        printf("it is the first packet\n");
        firstpacket(ch);
        no_tile++;
    }
    else if(flag!=0)
    {
        if(next!=1)
        {
            printf("it is the second packet\n");
            secondpacket(ch);
            no_tile++;
        }
        else if(next==1)
        {
            printf("it is the third packet\n");
            thirdpacket(ch);
            if(dropcheck==1)
            {
                printf("Dropped the image \n");
                return 0;
            }
            else{
                no_tile++;
            }
        }
    }
    }
    fclose(rf);
}

