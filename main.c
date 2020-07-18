#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR 1
#define TRUE 2
#define FALSE 3
#define CUSTOMER 4
#define COMMODITY 5

//用户部分

typedef struct
{
    char name[100];  //用户名
    char key[100];    //密码
    int score;      //积分
    int level;      //会员等级
    int balance;   //余额
    int identity;          //身份：有用户和商品两种
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




/*****************商城对照表******************************


	typedef struct
	{
		char name[100];  //产品名
		char categories[100];    //种类
		int price;      //价格
        int Residual;   //剩余量
		int number;      //序号
	}Minf;

	typedef struct
	{
		FILE *MallFile;
		int length;
	}M;


**********************************************************/




int main()
{


    char username[100];              //用户查重判定 or 登录键入
    char userkey[100];               //用户查重判定 or 登录键入
    //int  userscore;                  //数据记录
    //   int  userlevel;                  //数据记录
    // int  userTotalConsumption;       //数据纪录

    char ad[6]={'a','d','m','i','n','\0'};

    int idex;

    U s;
    Uinf u;


    InitUserinformation(&s);

    for(;;)
    {
        int dl=0;
        int n=0;

        printf("欢迎光临小店！\n");
        printf("请问您想做些什么？\n\n");
        printf("[1]登录\n[2]注册\n");
        printf("请输入对应的序号并以回车结束：\n");

        scanf("%d",&n);

        if (n==1)                  //登录相关
        {
            printf("用户名（1-16字）：\n");
            scanf("%s",username);
            printf("密码：\n");
            scanf("%s",userkey);

            if((FindUsername(&s,&idex,username)==TRUE)&&(ReadUsername(&s,idex,&u))==0)       //用户 用户名正确
            {
                if(strcmp(userkey,u.key)==0)
                {

                    printf("登陆成功！");

                    //userscore=u.score;
                    //userlevel=u.level;
                    //userTotalConsumption=u.balance;

                    for(;;)
                    {
                        int x=0;
                        DisplayCOMMODITY(&s);


                        printf("\n\n您想要： 【1】充值        【2】购物\n");

                        scanf("%d",&x);

                        if(x==1)
                        {
                            printf("请输入充值金额：");

                            scanf("%d",&x);

                            if(x<=0)
                            {
                                printf("您的键入有误！\n\n\n");
                            }
                            else
                            {
                                FindUsername(&s,&idex,username);

                                ReadUsername(&s,idex,&u);

                                u.balance=u.balance+x;

                                printf("充值成功！\n");

                                printf("当前余额：%d \n\n\n",u.balance);

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
                                    printf("输入您想要购买的商品名称：");

                                    scanf("%s",sp);

                                    c=FindUsername(&s,&idex,sp);

                                    ReadUsername(&s,idex,&u);

                                    if(c==1||c==3)printf("您的键入有误！\n\n");

                                }

                                *mz[i]=u.name;

                                printf("您想要购买的商品：产品名：%s  种类：%s  价格：%d  余量：%d  序号：%d\n",u.name,u.key,u.score,u.level,u.balance);

                                for(c=0;c<=0||c>u.level;)
                                {
                                    printf("您需要几件？");

                                    scanf("%d",&c);

                                    if(c<=0||c>u.level)printf("您的键入有误！\n\n");
                                }

                                *sl[i]=c;

                                zj=zj+c*u.score;

                                printf("所有商品的总价是：%d\n",zj);

                                printf("是否购买其他商品？ 【2】TRUE  【3】FALSE \n");

                                scanf("%d",&z);


                            }

                            int y;

                            printf("确认结算？  【1】确认   【2】不 \n");

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
                            printf("您的键入有误！\n\n\n");
                        }


                    }

                }
                else
                {
                    printf("您输入的密码有误，请重新登录！");
                }


            }

            else if(atoi(username)==atoi(ad)&&atoi(userkey)==114514)             //管理员模式
            {


                for(;dl!=3;)
                {
                    int b=0;
                    printf("管理员模式已启动，您需要做什么：\n【1】上新【2】库存变动【3】新增活动\n");

                    scanf("%d",&b);

                    if(b==1)
                    {

                        printf("产品名（1-16字）：\n");
                        scanf("%s",username);
                        if(FindUsername(&s,&idex,username)==ERROR)
                        {
                            return ERROR;
                        }

                        if(FindUsername(&s,&idex,username)==TRUE)
                        {
                            printf("同名商品已存在\n\n");
                        }
                        else if(FindUsername(&s,&idex,username)==FALSE)
                        {
                            WriteMall(&s,idex,&u,username);
                            printf("产品 [%s]上新成功 \n",username);
                        }

                        printf("继续？【2】是   【3】否\n");
                        scanf("%d",&dl);

                    }
                    else if(b==2)
                    {

                        printf("   这是至今为止的所有库存 \n");

                        DisplayCOMMODITY(&s);

                        printf("请输入待修改产品的产品名： \n");

                        scanf("%s",username);

                        FindUsername(&s,&idex,username);

                        ReadUsername(&s,idex,&u);

                        printf("待修改产品是:  产品名：%s  种类：%s  价格：%d  余量：%d  序号：%d\n\n",u.name,u.key,u.score,u.level,u.balance);

                        printf("请重新键入各项指标：\n");

                        printf("产品名：\n");
                        scanf("%s",u.name);

                        printf("种类：\n");
                        scanf("%s",u.key);

                        printf("价格：\n");
                        scanf("%d",&u.score);

                        printf("剩余量：\n");
                        scanf("%d",&u.level);

                        printf("序号：\n");
                        scanf("%d",&u.balance);

                        printf("  该项目已成功更改 \n");

                        printf("继续？【2】是   【3】否\n");
                        scanf("%d",&dl);

                    }

                    else if(b==3)
                    {
                        printf("尽请期待 \n\n\n");

                        printf("继续？【2】是   【3】否\n");
                        scanf("%d",&dl);
                    }


                    else printf("您的键入有误！\n\n\n");

                }

            }

            else
            {
                printf("您输入的账号不存在，请重新登录！");
            }

        }




        if (n==2)                                //注册相关
        {

            printf("用户名（1-16字）：\n");
            scanf("%s",username);
            if(FindUsername(&s,&idex,username)==ERROR)
            {
                return ERROR;
            }

            if(FindUsername(&s,&idex,username)==TRUE)
            {
                printf("同名用户已存在\n\n");
            }
            else if(FindUsername(&s,&idex,username)==FALSE)
            {
                WriteUser(&s,idex,&u,username);
                printf("用户 [%s]注册成功！\n",username);
            }

        }

        else
        {
            printf("您的键入有误！\n\n\n");
        }

    }

}








int InitUserinformation(U *s)
{
    FILE *fp;
    if((fp=fopen("FileUser.dat","rb+"))==NULL)
    {
        printf("初次启用用户系统\n");
        if((fp=fopen("FileUser.dat","wb+"))==NULL){
            printf("用户系统启用失败！请联系管理员\n");
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
    i=fwrite(&s->length,sizeof(int),1,s->UserFile); //s->length  然后*s->length

    if(i==0)
    {
        return ERROR;
    }

    return 0;
}




int WriteUser(U *s,int idex,Uinf *u,char n[])
{
    int i;
    /*printf("用户名（1-16字）：\n");
    scanf("%s",u->name);*/

    strcpy(u->name,n);

    printf("密码：\n");
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
            fprintf(stdout,"***产品名：%s  种类：%s  价格：%d  余量：%d  序号：%d\n\n",u.name,u.key,u.score,u.level,u.balance);
        }
    }
    return 0;
}





int WriteMall(U *s,int idex,Uinf *u,char n[])
{
    int i;
    /*printf("用户名（1-16字）：\n");
    scanf("%s",u->name);*/

    strcpy(u->name,n);

    printf("种类：\n");
    scanf("%s",u->key);

    printf("价格：\n");
    scanf("%d",&u->score);

    printf("剩余量：\n");
    scanf("%d",&u->level);

    printf("序号：\n");
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