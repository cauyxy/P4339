#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1
#define TRUE 2
#define FALSE 3
#define CUSTOMER 4
#define COMMODITY 5

//�û�����

typedef struct
{
    char name[100];  //�û���
    char key[100];    //����
    int score;      //����
    int level;      //��Ա�ȼ�
    int balance;   //���
    int identity;          //��ݣ����û�����Ʒ����
}Uinf;

typedef struct
{
    FILE *UserFile;
    int length;
}U;


int InitUserinformation(U *s);
int WriteUserCount(U *s);
int WriteUser(U *s,int idex,Uinf *u,char n[]);
int FindUsername(U *s,int *idex,char n[]);
int ReadUsername(U *s,int idex,Uinf *u);
int DisplayCOMMODITY(U *s);
int WriteMall(U *s,int idex,Uinf *u,char n[]);




/*****************�̳Ƕ��ձ�******************************


	typedef struct
	{
		char name[100];  //��Ʒ��
		char categories[100];    //����
		int price;      //�۸�
        int Residual;   //ʣ����
		int number;      //���
	}Minf;

	typedef struct
	{
		FILE *MallFile;
		int length;
	}M;


**********************************************************/




int main()
{


    char username[100];              //�û������ж� or ��¼����
    char userkey[100];               //�û������ж� or ��¼����
    //int  userscore;                  //���ݼ�¼
    //   int  userlevel;                  //���ݼ�¼
    // int  userTotalConsumption;       //���ݼ�¼

    char ad[6]={'a','d','m','i','n','\0'};

    int idex;

    U s;
    Uinf u;


    InitUserinformation(&s);

    for(;;)
    {
        int dl=0;
        int n=0;

        printf("��ӭ����С�꣡\n");
        printf("����������Щʲô��\n\n");
        printf("[1]��¼\n[2]ע��\n");
        printf("�������Ӧ����Ų��Իس�������\n");

        scanf("%d",&n);

        if (n==1)                  //��¼���
        {
            printf("�û�����1-16�֣���\n");
            scanf("%s",username);
            printf("���룺\n");
            scanf("%s",userkey);

            if((FindUsername(&s,&idex,username)==TRUE)&&(ReadUsername(&s,idex,&u))==0)       //�û� �û�����ȷ
            {
                if(strcmp(userkey,u.key)==0)
                {

                    printf("��½�ɹ���");

                    //userscore=u.score;
                    //userlevel=u.level;
                    //userTotalConsumption=u.balance;

                    for(;;)
                    {
                        int x=0;
                        DisplayCOMMODITY(&s);


                        printf("\n\n����Ҫ�� ��1����ֵ        ��2������\n");

                        scanf("%d",&x);

                        if(x==1)
                        {
                            printf("�������ֵ��");

                            scanf("%d",&x);

                            if(x<=0)
                            {
                                printf("���ļ�������\n\n\n");
                            }
                            else
                            {
                                FindUsername(&s,&idex,username);

                                ReadUsername(&s,idex,&u);

                                u.balance=u.balance+x;

                                printf("��ֵ�ɹ���\n");

                                printf("��ǰ��%d \n\n\n",u.balance);

                            }


                        }

                        else if(x==2)
                        {
                            int zj=0;
                            int c=0;
                            char mz[100][100];
                            char sl[100][100];

                            int i=0,j=0;

                            int gml=0;

                            int z=0;

                            for(;z!=3;i++)
                            {
                                char sp[100];

                                for(c=1;c==1||c==3;)
                                {
                                    printf("��������Ҫ�������Ʒ���ƣ�");

                                    scanf("%s",sp);

                                    c=FindUsername(&s,&idex,sp);

                                    ReadUsername(&s,idex,&u);

                                    if(c==1||c==3)printf("���ļ�������\n\n");

                                }

                                *mz[i]=u.name;

                                printf("����Ҫ�������Ʒ����Ʒ����%s  ���ࣺ%s  �۸�%d  ������%d  ��ţ�%d\n",u.name,u.key,u.score,u.level,u.balance);

                                for(c=0;c<=0||c>u.level;)
                                {
                                    printf("����Ҫ������");

                                    scanf("%d",&c);

                                    if(c<=0||c>u.level)printf("���ļ�������\n\n");
                                }

                                *sl[i]=c;

                                zj=zj+c*u.score;

                                printf("������Ʒ���ܼ��ǣ�%d\n",zj);

                                printf("�Ƿ���������Ʒ�� ��2��TRUE  ��3��FALSE \n");

                                scanf("%d",&z);


                            }

                            int y;

                            printf("ȷ�Ͻ��㣿  ��1��ȷ��   ��2���� \n");

                            scanf("%d",&y);

                            if(y==1)
                            {
                                FindUsername(&s,&idex,username);

                                ReadUsername(&s,idex,&u);

                                if(u.balance>zj)
                                {
                                    for(j=0;j<i;j++)
                                    {
                                        FindUsername(&s,&idex,mz[j]);

                                        ReadUsername(&s,idex,&u);

                                        gml = atoi(sl[j]);

                                        u.level=u.level-gml;

                                    }

                                    FindUsername(&s,&idex,username);

                                    ReadUsername(&s,idex,&u);

                                    u.balance=u.balance-zj;

                                }

                            }

                        }

                        else
                        {
                            printf("���ļ�������\n\n\n");
                        }


                    }

                }
                else
                {
                    printf("��������������������µ�¼��");
                }


            }

            else if(atoi(username)==atoi(ad)&&atoi(userkey)==114514)             //����Աģʽ
            {


                for(;dl!=3;)
                {
                    int b=0;
                    printf("����Աģʽ������������Ҫ��ʲô��\n��1�����¡�2�����䶯��3�������\n");

                    scanf("%d",&b);

                    if(b==1)
                    {

                        printf("��Ʒ����1-16�֣���\n");
                        scanf("%s",username);
                        if(FindUsername(&s,&idex,username)==ERROR)
                        {
                            return ERROR;
                        }

                        if(FindUsername(&s,&idex,username)==TRUE)
                        {
                            printf("ͬ����Ʒ�Ѵ���\n\n");
                        }
                        else if(FindUsername(&s,&idex,username)==FALSE)
                        {
                            WriteMall(&s,idex,&u,username);
                            printf("��Ʒ [%s]���³ɹ� \n",username);
                        }

                        printf("��������2����   ��3����\n");
                        scanf("%d",&dl);

                    }
                    else if(b==2)
                    {

                        printf("   ��������Ϊֹ�����п�� \n");

                        DisplayCOMMODITY(&s);

                        printf("��������޸Ĳ�Ʒ�Ĳ�Ʒ���� \n");

                        scanf("%s",username);

                        FindUsername(&s,&idex,username);

                        ReadUsername(&s,idex,&u);

                        printf("���޸Ĳ�Ʒ��:  ��Ʒ����%s  ���ࣺ%s  �۸�%d  ������%d  ��ţ�%d\n\n",u.name,u.key,u.score,u.level,u.balance);

                        printf("�����¼������ָ�꣺\n");

                        printf("��Ʒ����\n");
                        scanf("%s",u.name);

                        printf("���ࣺ\n");
                        scanf("%s",u.key);

                        printf("�۸�\n");
                        scanf("%d",&u.score);

                        printf("ʣ������\n");
                        scanf("%d",&u.level);

                        printf("��ţ�\n");
                        scanf("%d",&u.balance);

                        printf("  ����Ŀ�ѳɹ����� \n");

                        printf("��������2����   ��3����\n");
                        scanf("%d",&dl);

                    }

                    else if(b==3)
                    {
                        printf("�����ڴ� \n\n\n");

                        printf("��������2����   ��3����\n");
                        scanf("%d",&dl);
                    }


                    else printf("���ļ�������\n\n\n");

                }

            }

            else
            {
                printf("��������˺Ų����ڣ������µ�¼��");
            }

        }




        if (n==2)                                //ע�����
        {

            printf("�û�����1-16�֣���\n");
            scanf("%s",username);
            if(FindUsername(&s,&idex,username)==ERROR)
            {
                return ERROR;
            }

            if(FindUsername(&s,&idex,username)==TRUE)
            {
                printf("ͬ���û��Ѵ���\n\n");
            }
            else if(FindUsername(&s,&idex,username)==FALSE)
            {
                WriteUser(&s,idex,&u,username);
                printf("�û� [%s]ע��ɹ���\n",username);
            }

        }

        else
        {
            printf("���ļ�������\n\n\n");
        }

    }

}








int InitUserinformation(U *s)
{
    FILE *fp;
    if((fp=fopen("FileUser.dat","rb+"))==NULL)
    {
        printf("���������û�ϵͳ\n");
        if((fp=fopen("FileUser.dat","wb+"))==NULL){
            printf("�û�ϵͳ����ʧ�ܣ�����ϵ����Ա\n");
            return ERROR;
        }

    }


    s->UserFile=fp;
    s->length=0;
    WriteUserCount(s);

    return 0;
}




int WriteUserCount(U *s)
{
    int i;
    rewind(s->UserFile);
    i=fwrite(&s->length,sizeof(int),1,s->UserFile); //s->length  Ȼ��*s->length

    if(i==0)
    {
        return ERROR;
    }

    return 0;
}




int WriteUser(U *s,int idex,Uinf *u,char n[])
{
    int i;
    /*printf("�û�����1-16�֣���\n");
    scanf("%s",u->name);*/

    strcpy(u->name,n);

    printf("���룺\n");
    scanf("%s",u->key);

    u->score=0;
    u->level=0;
    u->balance=0;
    u->identity=CUSTOMER;

    fseek(s->UserFile,sizeof(int)+sizeof(Uinf)*idex,SEEK_SET);
    i=fwrite(u,sizeof(Uinf),1,s->UserFile);

    if(i==0)
    {
        return ERROR;
    }

    s->length++;
    WriteUserCount(s);
    return 0;
}



int FindUsername(U *s,int *idex,char n[])
{
    int i;
    Uinf u;

    for( i=0; i<s->length; i++)
    {
        if(ReadUsername(s,i,&u)==ERROR)
        {
            return ERROR;
        }
        else if(strcmp(n,u.name)==0)
        {
            *idex=i;
            return TRUE;
        }
    }
    *idex=s->length;
    return FALSE;
}




int ReadUsername(U *s,int idex,Uinf *u)
{
    int i;
    fseek(s->UserFile,sizeof(int)+sizeof(Uinf)*idex,SEEK_SET);
    i=fread(u,sizeof(Uinf),1,s->UserFile);

    WriteUserCount(s);

    if(i==0)
    {
        return ERROR;
    }
    return 0;
}



int DisplayCOMMODITY(U *s)
{
    int i;
    Uinf u;

    for( i=0; i<s->length; i++)
    {
        if(ReadUsername(s,i,&u)==ERROR)
        {
            return ERROR;
        }

        if(u.identity==COMMODITY)
        {
            fprintf(stdout,"***��Ʒ����%s  ���ࣺ%s  �۸�%d  ������%d  ��ţ�%d\n\n",u.name,u.key,u.score,u.level,u.balance);
        }
    }
    return 0;
}





int WriteMall(U *s,int idex,Uinf *u,char n[])
{
    int i;
    /*printf("�û�����1-16�֣���\n");
    scanf("%s",u->name);*/

    strcpy(u->name,n);

    printf("���ࣺ\n");
    scanf("%s",u->key);

    printf("�۸�\n");
    scanf("%d",&u->score);

    printf("ʣ������\n");
    scanf("%d",&u->level);

    printf("��ţ�\n");
    scanf("%d",&u->balance);

    u->identity=COMMODITY;

    fseek(s->UserFile,sizeof(int)+sizeof(Uinf)*idex,SEEK_SET);
    i=fwrite(u,sizeof(Uinf),1,s->UserFile);

    if(i==0)
    {
        return ERROR;
    }

    s->length++;
    WriteUserCount(s);
    return 0;
}