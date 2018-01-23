#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;
int hp,money,hunger,water,lv,now,hpmax,day,ep,censhu,attack,def;
int moneyget,killcount,jingli,maxjingli; 
int speed;
int missionon=0,shittimes,studytimes;
int sqnkillcount;
int zhexue_c;
int bagnum[1010],enhp;
int zhexue=0;
string bagname[1010]={"0","疗伤圣水","经验瓶","门钥匙","面包","矿泉水","超级回复药","伤害药水","nb伤害药水","小木棍","木元素精华","粗木杆","~自然的眷顾~"};
int baguse[1010]={0,1,1,1};
int sp1,sp2,gameover,sp3,jq2;
char name[1000];
string skill[1010]={"0","万物回春","木盾","会心一击","自爆"};
string j23[100]={"好","好","好","，","我","会","定","期","发","布","任","务","给","你","，","完","成","所","有","任","务","就","能","加","入","我","们","哲","学","帮","!"};
string j22[300]={"小","子","，","我","对","你","很","感","兴","趣","，","想","不","想","加","入","我","们","哲","学","帮","？"};
string j2[300]={"你","听","到","了","背","后","的","声","音","你","转","过","身","看","见","一","名","黑","衣","男","子","饶","有","兴","趣","地","看","着","你","","","","","","","","","","","","","","","","","","","","","","","","",""};
string j1[100]={"你","叫","做",",","是","一","名","乞","丐",",","有","一","天","你","突","然","捡","到","了","100","元","！","你","决","定","脱","贫","致","富",".",".",".",".",".","."};
char load[11]={'L','o','a','d','i','n','g','.','.','.'};
int needxp,xp;
int psss[4][4]; 
string pssss[4]={"0","剪刀","石头","布"}; 
string gou[7]={"苟","利","国","家","生","死","已"};
string epp2[100]={"0","于","是","我","们","的","勇","士","用","钥","匙","打","开","了","哲","学","的","大","门",".",".",".",".",".","."};
int aim[20]={0,10000,100000,1000000,10000000,100000000,1000000000,1000000000};
//24点
int a[10],ex[10];
int path[10],x[10],y[10],z[10];
int number[101],i=0,p=1,temp=1;
char symbol[101],s[256],t[256];
int ans;
bool reach;
bool used[10]; 
void conf()
{
	system("cls");
	for(int i=1;i<=50;i++)cout<<"-";
	cout<<endl;
	cout<<"游戏名:人生赢家"<<endl;
	cout<<"版本号:v1.03"<<endl;
	cout<<"怠惰的制作者:沉迷学习的YSJ"<<endl;
	cout<<"作者qq：2500481138"<<endl; 
	cout<<"作者的洛谷id:Wy12121212"<<endl; 
	for(int i=1;i<=50;i++)cout<<"-";
	cout<<endl;
	system("pause");
}
int encrypt(int x)
{
	return ((200-x)*2333+666)*2-8848;
}
int disencrypt(int x)
{
	return -1*(((x+8848)/2-666)/2333-200);
}
void saveload()
{
	    FILE *fp=fopen("log.txt","w");
	    maxjingli=encrypt(maxjingli);
	    jingli=encrypt(jingli);
        money=encrypt(money);
        lv=encrypt(lv);
        hp=encrypt(hp);
        hunger=encrypt(hunger);
        hpmax=encrypt(hpmax);
        attack=encrypt(attack);
        def=encrypt(def);
        ep=encrypt(ep);
        day=encrypt(day);
        xp=encrypt(xp);
        needxp=encrypt(needxp);
        sqnkillcount=encrypt(sqnkillcount);     
        fprintf(fp,"%s\n %d %d %d %d %d %d %d %d %d ",name,money,lv,hp,hunger,water,hpmax,attack,def,ep);
        fprintf(fp,"%d %d %d %d %d %d ",day,xp,needxp,sp1,sp2,sp3);
        fprintf(fp,"%d %d %d %d %d %d %d %d %d",censhu,now,speed,jq2,moneyget,killcount,jingli,maxjingli,sqnkillcount);
        fprintf(fp,"\n");
		for(int i=1;i<=100;i++)fprintf(fp,"%d ",bagnum[i]);
		money=disencrypt(money);
        lv=disencrypt(lv);
        hp=disencrypt(hp);
        hunger=disencrypt(hunger);
        hpmax=disencrypt(hpmax);
        attack=disencrypt(attack);
        def=disencrypt(def);
        ep=disencrypt(ep);
        day=disencrypt(day);
        maxjingli=disencrypt(maxjingli);
        xp=disencrypt(xp);
        jingli=disencrypt(jingli);
        needxp=disencrypt(needxp);
        sqnkillcount=disencrypt(sqnkillcount);
        fclose(fp);
        cout<<"存档成功！！";
        system("pause");
}
void readload()
{
	    FILE *fp=fopen("log.txt","r");
        fscanf(fp,"%s%d%d%d%d%d%d%d%d%d",&name,&money,&lv,&hp,&hunger,&water,&hpmax,&attack,&def,&ep);
        fscanf(fp,"%d%d%d%d%d%d",&day,&xp,&needxp,&sp1,&sp2,&sp3);
        fscanf(fp,"%d%d%d%d%d%d%d%d%d",&censhu,&now,&speed,&jq2,&moneyget,&killcount,&jingli,&maxjingli,&sqnkillcount);
        for(int i=1;i<=100;i++)fscanf(fp,"%d",&bagnum[i]);
        money=disencrypt(money);
        lv=disencrypt(lv);
        hp=disencrypt(hp);
        hunger=disencrypt(hunger);
        hpmax=disencrypt(hpmax);
        attack=disencrypt(attack);
        def=disencrypt(def);
        ep=disencrypt(ep);
        day=disencrypt(day);
        xp=disencrypt(xp);
        needxp=disencrypt(needxp);
        jingli=disencrypt(jingli);
        maxjingli=disencrypt(maxjingli);
        sqnkillcount=disencrypt(sqnkillcount);
        fclose(fp);
}
void w()
{
    Sleep(speed);
}
void w_out(string a)
{
	int l=a.length();
	for(int i=0;i<l;i++)cout<<a[i],w();
}
void juqing1()
{
    for(int i=0;i<=2;i++)cout<<j1[i],w();
    cout<<name;
    for(int i=3;i<=34;i++)cout<<j1[i],w();
}
void juqing2()
{
	if(jq2)return;
    system("cls");
    cout<<"'";
    w();
    cout<<name,w(),cout<<"'!"<<endl;
    for(int i=0;i<=8;i++)cout<<j2[i],w();
    cout<<endl;
    cout<<"是否转身查看?"<<endl<<"Y/N"<<endl;
    char cmd;
    cin>>cmd;
    if(cmd=='Y')
    {
        system("cls");
        for(int i=9;i<=28;i++)cout<<j2[i],w();
        cout<<endl;
        system("pause");
        for(int i=0;i<=21;i++)cout<<j22[i],w();
        cout<<endl<<"加入:Y,不加入:N"<<endl;
        cin>>cmd;
        if(cmd=='Y')
        {
            for(int i=0;i<=30;i++)cout<<j23[i],w();
            cout<<endl;
            zhexue=1;
            zhexue_c=1;
        }
        else cout<<"'哼!'"<<endl;
    }
    system("pause");
    jq2=1;
}
int check()
{
	if(jingli<=0)
	{
		cout<<"你没有精力了！睡觉或者使用道具！"<<endl;
		cout<<"输入1强制睡觉!"<<endl;
		char cmd;
		cin>>cmd;
		if(cmd=='1')
		{
			hunger-=5;
			water-=10;
			jingli=maxjingli/2;
			day++;
			system("cls");
			w_out("一个临时的坏觉，你的精力回了一半(水分-10，饥饿-5)"),cout<<endl;
		} 
		system("pause");
	}
    if(hunger<=0)
    {
        cout<<"你在挨饿！hp下降！"<<endl;
        hp-=5;
        system("pause");
    }
    if(water<=0)
    {
        cout<<"你口干舌燥！hp急剧下降！"<<endl;
        hp-=10;
        system("pause");
    }
    if(hp<=0)
    {
        cout<<"You Die!!";
        return 1;
    }
    return 0;
}
void shit()
{
    long long tmp=rand()%(5+lv)+1;
    cout<<"你在粪堆里找到了"<<tmp<<"元!"<<endl;
    printf("生命值减少!\n饥饿值和水分增加!\n");
    hunger+=(5+lv/2);
    water+=(5+lv/2);
    moneyget+=tmp; 
    money+=tmp;
    xp+=(1+lv/2);
    hp-=(1+lv);
    if(missionon==1)shittimes++;
    system("pause");
}
void study()
{
    if(money<=0)cout<<"你的钱不够！"<<endl;
    else
    {
       for(long long i=0;i<=6;i++)cout<<gou[i]<<" ",w();
       cout<<endl;
       printf("你的经验增加了!\n你的金钱减少了!\n");
       xp+=3+(lv*2);
       moneyget-=1+(lv); 
       money-=1+(lv);
       if(missionon==2)studytimes++;
    }
    system("pause");    
}
void lottery()
{
    getchar();
    printf("1.1->10元彩票\n2.10->100元彩票\n3.100->10000元彩票\n4.10000->10000000元彩票\n");
    char cmd;
    cin>>cmd;
    if(cmd=='1')
    {
        if(money<1)cout<<"你的钱不够！"<<endl;
        else
        {
            xp++;
            money-=1;
            long long tmp=rand()%10+1;
            if(tmp==5)
            {
                money+=10;
                moneyget+=10;
                cout<<"恭喜你抽中了10元！"<<endl;
            }
            else cout<<"毛也没抽到！"<<endl;
        }
    }
    if(cmd=='2')
    {
        if(money<10)cout<<"你的钱不够！"<<endl;
        else
        {
            xp+=5;
            money-=10;
            long long tmp=rand()%10+1;
            if(tmp==5)
            {
                money+=100;
                moneyget+=100; 
                cout<<"恭喜你抽中了100元！"<<endl;
            }
            else cout<<"毛也没抽到！"<<endl;
        }
    }
    if(cmd=='3')
    {
        if(money<100)cout<<"你的钱不够！"<<endl;
        else
        {
            xp+=10;
            money-=100;
            long long tmp=rand()%20+1;
            if(tmp==5)
            {
                money+=10000;
                moneyget+=10000; 
                cout<<"恭喜你抽中了10000元！"<<endl;
            }
            else cout<<"毛也没抽到！"<<endl;
        }
    }
    if(cmd=='4')
    {
        if(money<10000)cout<<"你的钱不够！"<<endl;
        else
        {
            xp+=100;
            money-=10000;
            long long tmp=rand()%30+1;
            if(tmp==5)
            {
                money+=10000000;
                moneyget+=10000000; 
                cout<<"恭喜你抽中了10000000元！"<<endl;
            }
            else cout<<"毛也没抽到！"<<endl;
        }
    }
    system("pause");
    return;
}
void showstat()
{
    getchar();
    cout<<"用户名："<<name<<endl;
    cout<<"等级:"<<lv<<"级"<<"("<<xp<<"/"<<needxp<<")"<<endl;
    cout<<"金钱："<<money<<endl;
    cout<<"净获得金钱："<<moneyget<<endl;
    cout<<"饥饿值："<<hunger<<"/100"<<endl;
    cout<<"水分："<<water<<"/100"<<endl;
    cout<<"健康值："<<hp<<"/"<<hpmax<<endl;
    cout<<"精力："<<jingli<<"/"<<maxjingli<<endl; 
    cout<<"当前目标："<<aim[now]<<"元"<<endl;
    if(ep==2)
    {
        cout<<"攻击力:"<<attack<<endl;
        cout<<"防御力:"<<def<<endl;
    }
    cout<<"press any button to return"<<endl;
    getchar();

}
void dubo()
{
    if(money<=0)cout<<"你的钱不够！"<<endl;
    else
    {
        cout<<"你要赌多少钱?"<<endl;
        long long tmp;
        cin>>tmp;
        if(tmp<=0)
        {
            cout<<"fuckyou"<<endl;
            return;
        }
        if(money<tmp)cout<<"你的钱不够！"<<endl;
        else
        {
            xp+=5+(lv/2);
            money-=tmp;
            cout<<"猜大还是猜小?"<<endl<<"1-大   2-小"<<endl;
            long long cmd;
            cin>>cmd;
            int hehe=rand()%2+1,hs,t1,t2,t3;
            if(hehe==1)
            {
               bool haha=1;
               while(haha)
               {
                    t1=rand()%6+1;
                    t2=rand()%6+1;
                    t3=rand()%6+1;
                    hs=t1+t2+t3;
                    if(hs<9)
                    {
                        haha=0;
                        cout<<t1<<endl<<t2<<endl<<t3<<endl;
                    }
               }    
            }
            if(hehe==2)
            {
               bool haha=1;
               while(haha)
               {
                    t1=rand()%6+1;
                    t2=rand()%6+1;
                    t3=rand()%6+1;
                    hs=t1+t2+t3;
                    if(hs>=9)
                    {
                        haha=0;
                        cout<<t1<<endl<<t2<<endl<<t3<<endl;
                    }
               }    
            }
            if(hs>=9)
            {
                if(cmd==2)cout<<"血本无归！"<<endl;
                if(cmd==1)
                {
                    cout<<"你赢了!共获得"<<tmp*2<<"元"<<endl;
                    moneyget+=tmp*2;
                    money+=tmp*2;
                    xp+=tmp/10000;
                }
            }
            if(hs<9)
            {
                if(cmd==1)cout<<"血本无归！"<<endl;
                if(cmd==2)
                {
                    cout<<"你赢了!共获得"<<tmp*2<<"元"<<endl;
                    money+=tmp*2;
                    moneyget+=tmp*2; 
                    xp+=tmp/10000;
                }
            }
        }    
    }
    system("pause");
}
void showwork()
{
    getchar();
    system("cls");
    printf("1.搬砖 200元/10饥饿值&水分,成功率66%\n2.文字录入 400元/10饥饿值&水分,成功率40%\n");
    if(sp3)cout<<"3.抄作业 100元/饥饿值&经验 100%成功 可以批量接受工作 但是需要ysj的密码 "<<endl;
    printf("x.exit\n");
    char cmd;
    cin>>cmd;
    if(cmd=='x')return;
    if(cmd=='1')
    {
         getchar();
         long long tmp=rand()%3+1;
         hunger-=10;
         water-=10;
         if(tmp==2)cout<<"你的雇佣者对你很不满意！没有工资！"<<endl;
         else  
         {
            cout<<"成功应聘!你获得了200元!"<<endl;     
            money+=200;
            moneyget+=200;
            xp+=(2+lv);
         }
    }
    if(cmd=='2')
    {
         getchar();
         long long tmp=rand()%10+1;
         hunger-=10;
         water-=10;
         if(tmp>=4)cout<<"你的雇佣者对你很不满意！没有工资！"<<endl;
         else  
         {
            cout<<"成功应聘!你获得了400元!"<<endl;     
            money+=400;
            moneyget+=400;
            xp+=(3+lv);
         }
    }
    if(cmd=='3')
    {
         getchar();
         string password1;
         cout<<"请输入密码"<<endl;
         cin>>password1;
         if(password1=="Wy12121212")
         {
            cout<<"你要消耗多少饥饿值?"<<endl;
            int tmp;
            cin>>tmp;
            if(tmp<=0||hunger-tmp<0||water-tmp<0)cout<<"fuck you!"<<endl;
            else
            {
                hunger-=tmp;
               water-=tmp;
               cout<<"成功应聘!你获得了"<<tmp*100<<"元!"<<endl;     
               money+=tmp*100;
               moneyget+=tmp*100;
               xp+=(lv*2);        
            }    
         }
         else cout<<"密码错误!"<<endl;
    }
    cout<<"press any button to return"<<endl;
    getchar();
}
void shop()
{
	system("cls");
    cout<<"1.疗伤圣水 1000$"<<endl;
    cout<<"2.经验瓶 10$"<<endl;
    cout<<"3.门钥匙 100000$"<<endl;
    cout<<"4.面包 1000$"<<endl;
    cout<<"5.矿泉水 1000$"<<endl;
    cout<<"6.超级回复药 100000$"<<endl;
    cout<<"7.伤害药水 100000$"<<endl;
    cout<<"8.nb伤害药水 300000$"<<endl;
    cout<<"h.help"<<endl;
    cout<<"x.exit"<<endl;
    char cmd;
    cin>>cmd;
    if(cmd=='x')return;
    if(cmd=='h')
    {
        cout<<"1.恢复生命值3点，不超过生命上限"<<hpmax<<endl;
        cout<<"2.直接增加10+level点经验值，免去study的痛苦"<<endl;
        cout<<"3.???"<<endl;
        cout<<"4.回复30点饥饿"<<endl;
        cout<<"5.回复30点水分"<<endl;
        cout<<"6.回复100点血量"<<endl;
        cout<<"7.造成40点伤害,50%命中"<<endl;    
        cout<<"8.造成100点伤害,25%命中"<<endl;  
        system("pause");
        shop();
    }
    cout<<"是否批量购买?"<<endl<<"Y/N"<<endl;
    char cmd2;
    int num=1;
    cin>>cmd2;
    if(cmd2=='Y')
    {
        cout<<"买多少个?"<<endl;
        cin>>num;
        if(num<=0)return;
    }
    if(cmd=='1')
    {
        if(money<10*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[1]+=num;
        }
    }
    if(cmd=='2')
    {
        if(money<10*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[2]+=num;
        }
    }
    if(cmd=='3')
    {
        if(money<100000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[3]+=num;
        }
    }
    if(cmd=='4')
    {
        if(money<1000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[4]+=num;
        }
    }
    if(cmd=='5')
    {
        if(money<1000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[5]+=num;
        }
    }
    if(cmd=='6')
    {
        if(money<100000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[6]+=num;
        }
    }
    if(cmd=='7')
    {
        if(money<100000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[7]+=num;
        }
    }
    if(cmd=='8')
    {
        if(money<300000*num)cout<<"你的钱不够!"<<endl;
        else
        {
            cout<<"购买成功!"<<endl;
            bagnum[8]+=num;
        }
    }
    system("pause");
}
void weaponshop()
{
	
}
void ep2()
{
    for(long long i=1;i<=30;i++)cout<<epp2[i],w();
    ep=2;
    system("pause");
}
void bag()
{
    for(long long i=1;i<=100;i++)
    if(bagnum[i]!=0)
    {
        cout<<i<<":"<<bagname[i]<<" "<<bagnum[i]<<endl;
    }
    cout<<"1.使用"<<endl;
    cout<<"2.出售"<<endl;
    cout<<"x.exit"<<endl;
    char cmd;
    cin>>cmd;
    if(cmd=='x')return;
    cout<<"是否批量处理?"<<endl<<"Y/N"<<endl;
    char cmd2;
    int num=1;
    cin>>cmd2;
    if(cmd2=='Y')
    {
        cout<<"多少个?"<<endl;
        cin>>num;
        if(num<=0)return;
    }
    if(cmd=='1')
    {
        cout<<"请输入要使用物品的编号"<<endl;
        long long tmp;
        cin>>tmp;
        if(bagnum[tmp]-num<0)cout<<"你没有!"<<endl;
        else
        {
            cout<<"使用成功! "<<endl;
            bagnum[tmp]-=num;
            if(tmp==1)
            {
                hp+=3*num;
                if(hp>hpmax)hp=hpmax;
            }
            if(tmp==2)xp+=((10+lv)*num);
            if(tmp==3)
            {
                ep=2;
                ep2();
            }
            if(tmp==4)
            {
                hunger+=(30*num);
                if(hunger>100)hunger=100;
            }
            if(tmp==5)
            {
                water+=(30*num);
                if(water>100)water=100;
            }
            if(tmp==6)
            {
                hp+=100*num;
                if(hp>hpmax)hp=hpmax;
            }
        }
    }
    if(cmd=='2')
    {
        cout<<"请输入要出售物品的编号"<<endl;
        long long tmp;
        cin>>tmp;
        if(bagnum[tmp]-num<0)cout<<"你没有!"<<endl;
        else
        {
            cout<<"出售成功! "<<endl;
            bagnum[tmp]-=num;
            long long tmpp=0;
            if(tmp==1)tmpp=5;
            if(tmp==2)tmpp=5;
            if(tmp==3)tmpp=0;
            if(tmp==4)tmpp=500;
            if(tmp==5)tmpp=500;
            if(tmp==6)tmpp=50000;
            cout<<"卖了"<<tmpp*num<<"元" <<endl;
            money+=(tmpp*num);
            moneyget+=tmpp*num;
        }
    }
    system("pause");
}
void caishu()
{
    int tmp=rand()%100+1;
    int x;
    cout<<"在1-100间随意猜一个数 ，猜对有奖,你有六次机会"<<endl;
    cout<<"要押多少钱 ?"<<endl;
    long long mm;
    cin>>mm;
    bool win=0;
    if(mm<=0)return;
    if(mm>money)cout<<"钱不够"<<endl;
    else
    {
    money-=mm;
    for(long long i=1;i<=6;i++)
    {
        cout<<"猜一个数,你还有"<<6-i+1<<"次机会!" <<endl;
        cin>>x;
        if(x==tmp)
        {
            money+=mm*2;
            moneyget+=mm*2;
            cout<<"猜对了，获得"<<mm*2<<"元钱 !"<<endl;
			win=1;
            break; 
        }
        if(x>tmp)cout<<"猜大了!"<<endl;
        if(x<tmp)cout<<"猜小了!"<<endl;
    }    
    }
    if(!win)cout<<"你失败了!正确的数字是"<<tmp<<endl;
    system("pause");
}
void battlebag()
{
    for(int i=1;i<=100;i++)
    //if(bagnum[i]!=0)
    {
        cout<<i<<":"<<bagname[i]<<" "<<bagnum[i]<<endl;
    }
    cout<<"请输入要使用物品的编号"<<endl;
    int tmp;
    cin>>tmp;
    if(!bagnum[tmp])cout<<"你没有!"<<endl;
    else
    {
        cout<<"使用成功! "<<endl;
        bagnum[tmp]--;
        if(tmp==1)
        {
            hp+=3;
            if(hp>hpmax)hp=hpmax;
        }
        if(tmp==2)xp+=(10+lv);
        if(tmp==6)
        {
            hp+=100;
            if(hp>hpmax)hp=hpmax;
        }
        if(tmp==7)
        {
            int minz=rand()%2+1;
            if(minz==1)cout<<"命中!"<<endl,enhp-=40;
            else cout<<"未命中!"<<endl;
        }
        if(tmp==8)
        {
            int minz=rand()%4+1;
            if(minz==1)cout<<"命中!"<<endl,enhp-=100;
            else cout<<"未命中!"<<endl;
        }
    }
    system("pause");
}
void mission()
{
    if(missionon==0)
    {
       if(zhexue)
       {
           if(zhexue_c==1)
           {
               for(int i=1;i<=50;i++)cout<<"-";
               cout<<endl;
               cout<<"编号:1";
               cout<<"哲学帮任务1:吃十次屎"<<endl;
               cout<<"介绍:谁知盘中屎,粒粒皆辛苦"<<endl;
               cout<<"奖励:5000xp,1000$"<<endl;
               for(int i=1;i<=50;i++)cout<<"-";
               cout<<endl;
               cout<<endl;
           }
           if(zhexue_c==2)
           {
               for(int i=1;i<=50;i++)cout<<"-";
               cout<<endl;
               cout<<"编号:2";
               cout<<"哲学帮任务2:学20次习"<<endl;
               cout<<"介绍:苟利国家生死以，岂因祸福避趋之"<<endl;
               cout<<"奖励:10000xp,10000$"<<endl;
               for(int i=1;i<=50;i++)cout<<"-";
               cout<<endl;
               cout<<endl;
           }
       }
       cout<<"1.接受任务"<<endl;
       cout<<"x.exit"<<endl;
       char cmd;
       cin>>cmd;
       if(cmd=='x')return;
       if(cmd=='1')
       {
          int k;
          cout<<"输入要接受任务的编号" <<endl;
          cin>>k;
          if(k==1&&zhexue_c==1)
          {
                missionon=1;
                shittimes=0;
                cout<<"接收成功!"<<endl;
                getchar();
                return;         
          }
          if(k==2&&zhexue_c==2)
          {
                missionon=2;
                studytimes=0;
                cout<<"接收成功!"<<endl;
                getchar();
                return;
          }
       }    
    }
    else
    {
        if(missionon==1)
        {
            for(int i=1;i<=50;i++)cout<<"-";cout<<endl;
            cout<<"哲学帮任务1:吃十次屎"<<endl;
            cout<<"进度:"<<shittimes<<"/10"<<endl;
            cout<<"奖励:5000xp,1000$"<<endl;
            cout<<"1.提交任务"<<endl;
            cout<<"x.exit"<<endl;
            for(int i=1;i<=50;i++)cout<<"-";cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='x')return;
            if(cmd=='1')
            if(shittimes<10)cout<<"任务未完成!"<<endl;
            else
            {
                zhexue_c=2;
                missionon=0;
                xp+=5000;
                money+=1000;
                moneyget+=1000;
                cout<<"任务完成!"<<endl;
            }
        }
        if(missionon==2)
        {
            for(int i=1;i<=50;i++)cout<<"-";cout<<endl;
            cout<<"哲学帮任务2:学20次习"<<endl;
            cout<<"进度:"<<studytimes<<"/20"<<endl;
            cout<<"奖励:10000xp,10000$"<<endl;
            cout<<"1.提交任务"<<endl;
            cout<<"x.exit"<<endl;
            for(int i=1;i<=50;i++)cout<<"-";cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='x')return;
            if(cmd=='1')
            if(studytimes<20)cout<<"任务未完成!"<<endl;
            else
            {
                zhexue_c=3;
                missionon=0;
                xp+=10000;
                money+=10000;
                moneyget+=10000;
                cout<<"任务完成!"<<endl;
            }
        }
    }
    system("pause");
}
void daguai1()
{
    int tmp=rand()%20+1;
    bool battle=1;
    int enlv=tmp;
    enhp=100+enlv*10;
    int tmphp=enhp;
    int enattack=10+enlv*10;
    int endef=10+enlv*10;
    int tmpdef=endef;
    int flag=0;
    int huihe=0;
    if(tmp<=10)
    {
        w_out("你遭遇了一只树妖!"),cout<<endl;
        while(battle)
        {
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("怪物:树妖");
			cout<<endl;
			w();
            w_out("等级:");
			cout<<enlv;
			w();
			cout<<"级"<<endl;
            w_out("血量:");
			cout<<enhp<<endl;
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("Your Hp:");
			cout<<hp<<endl;
            w_out("1.attack 2.use something 3.run away");
			cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='1')
            {
                w_out("你发起了进攻!");
				cout<<endl;
                int miss=rand()%10+1;
                if(miss==3)w_out("You Miss!"),cout<<endl;
                else
                {
                	int randdamage=rand()%20+1-10;
                    enhp-=max((attack-endef+randdamage),1);
                    w_out("树妖受到了"),cout<<max((attack-endef+randdamage),1),w_out("点伤害"),cout<<endl;
                    if(enhp<=0)battle=0,flag=1;
                }            
            }
            if(cmd=='2')
            {
                battlebag();
            }
            if(cmd=='3')
            {
                int miss=rand()%5+1;
                if(miss==3)w_out("逃跑成功 !"),cout<<endl,battle=0;
                else w_out("逃跑失败!"),cout<<endl;
            }
            if(battle==0)break;
            w_out("树妖对你发起了进攻!"),cout<<endl;
            hp-=max((enattack-def),1);
            w_out("你受到了"),cout<<max((enattack-def),1),w_out("点伤害"),cout<<endl;
            if(hp<=0)battle=0,flag=2;
            cout<<endl;
            cout<<endl;
        }
    }
    if(tmp>10&&tmp<17)
    {
        enhp+=100;
        endef+=20;
        tmphp+=100;
        enattack+=20;
        w_out("你遭遇了一只真~树妖!"),cout<<endl;
        while(battle)
        {
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("怪物:真~树妖");
			cout<<endl;
			w();
            w_out("等级:");
			cout<<enlv;
			w();
			cout<<"级"<<endl;
            w_out("血量:");
			cout<<enhp<<endl;
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("Your Hp:");
			cout<<hp<<endl;
            w_out("1.attack 2.use something 3.run away");
			cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='1')
            {
                w_out("你发起了进攻!"),cout<<endl;
                int miss=rand()%7+1;
                if(miss==3)w_out("You Miss!"),cout<<endl;
                else
                {
                	int randdamage=rand()%20+1-10;
                    enhp-=max((attack-endef+randdamage),1);
                    w_out("真~树妖受到了"),cout<<max((attack-endef+randdamage),1)<<"点伤害"<<endl;
                    if(enhp<=0)battle=0,flag=1;
                }            
            }
            if(cmd=='2')
            {
                battlebag();
            }
            if(cmd=='3')
            {
                int miss=rand()%5+1;
                if(miss==3)w_out("逃跑成功 !"),cout<<endl,battle=0;
                else w_out("逃跑失败!"),cout<<endl;
            }
            if(battle==0)break;
            int skilll=rand()%8+1;
            if(tmphp-enhp<100)skilll=1;
            if(skilll!=3)
            {
               w_out("真~树妖对你发起了进攻!"),cout<<endl;
               hp-=max((enattack-def),1);
               w_out("你受到了"),cout<<max((enattack-def),1)<<"点伤害"<<endl;    
            }
            else
            {
                w_out("真~树妖使用了技能'"),cout<<skill[1],w_out("',血量增加了 !"),cout<<endl;
                enhp+=50;
                if(enhp>tmphp)enhp=tmphp;
            }
            if(hp<=0)battle=0,flag=2;
            cout<<endl;
            cout<<endl;
        }
    }
    if(tmp>=17)
    {
        endef-=30;
        enattack+=50;
        cout<<"你遭遇了一只木元素精灵!"<<endl;
        while(battle)
        {
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("怪物:木元素精灵");
			cout<<endl;
			w();
            w_out("等级:");
			cout<<enlv;
			w();
			cout<<"级"<<endl;
            w_out("血量:");
			cout<<enhp<<endl;
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("Your Hp:");
			cout<<hp<<endl;
            w_out("1.attack 2.use something 3.run away");
			cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='1')
            {
            	w_out("你发起了进攻!"),cout<<endl;
                int miss=rand()%7+1;
                if(miss==3)w_out("You Miss!"),cout<<endl;
                else
                {
                	int randdamage=rand()%20+1-10;
                    enhp-=max((attack-endef+randdamage),1);
                    w_out("木元素精灵受到了"),cout<<max((attack-endef+randdamage),1)<<"点伤害"<<endl;
                    if(enhp<=0)battle=0,flag=1;
                }                   
            }
            if(cmd=='2')
            {
                battlebag();
            }
            if(cmd=='3')
            {
                int miss=rand()%6+1;
                if(miss==3)w_out("逃跑成功 !"),cout<<endl,battle=0;
                else w_out("逃跑失败!"),cout<<endl;
            }
            if(battle==0)break;
            int skilll=rand()%8+1;
            if(skilll==5&&huihe!=0)skilll=1;
            if(skilll!=3&&skilll!=5)
            {
               w_out("木元素精灵对你发起了进攻!"),cout<<endl;
               hp-=max((enattack-def),1);
               w_out("你受到了"),cout<<max((enattack-def),1)<<"点伤害"<<endl;      
            }
            else
            {
                if(skilll==3)
                {
                   w_out("木元素精灵使用了技能'"),cout<<skill[1],w_out("',血量增加了 !"),cout<<endl;
                   enhp+=50;
                   if(enhp>tmphp)enhp=tmphp;    
                }
                if(skilll==5)
                {
                	w_out("木元素精灵使用了技能'"),cout<<skill[2],w_out("',防御暂时提高了 !"),cout<<endl;
                    endef+=30;
                    huihe=1;
                }
            }
            if(huihe&&huihe<4)huihe++;
            if(huihe==4)
            {
                huihe=0;
                endef-=30;
            }
            if(hp<=0)battle=0,flag=2;
            cout<<endl;
            cout<<endl;
        }
    }
    if(flag==0)cout<<"运气不错!"<<endl;
    if(flag==1)
    {
    	killcount++;
        w_out("胜利!"),cout<<endl;
        w_out("获得经验值："),cout<<enlv*100<<endl;
        w_out("战利品:");
        if(tmp<=10)
        {
        	int moneytmp=rand()%(tmp*10)+1;
        	w_out("金钱："),cout<<moneytmp<<endl;
			money+=moneytmp;
			moneyget+=moneytmp; 
            int hehe=rand()%2+1;
            for(int i=1;i<=hehe;i++)w_out("小树枝 "),bagnum[9]++;
            cout<<endl;
        }
        if(tmp>10&&tmp<17)
        {
        	int moneytmp=rand()%(tmp*10)+100;
        	w_out("金钱："),cout<<moneytmp<<endl;
			money+=moneytmp;
			moneyget+=moneytmp; 
            int hehe=rand()%4+1;
            for(int i=1;i<=hehe;i++)w_out("小树枝 "),bagnum[9]++;
            cout<<endl;
        }
        if(tmp>=17)
        {
        	int moneytmp=rand()%(tmp*10)+1000;
        	w_out("金钱："),cout<<moneytmp<<endl;
			money+=moneytmp;
			moneyget+=moneytmp; 
            int hehe=rand()%3+1;
            for(int i=1;i<=hehe;i++)w_out("木元素精华 "),bagnum[10]++;
            cout<<endl;
        }
        xp+=enlv*100;
    }
    if(flag==2)cout<<"You Die"<<endl,gameover=1;
    system("pause");
}
void boss1()
{
	bool battle=1,flag=0;
	char enlv='?';
	int enhp=1000;
	int endef=250;
	int enattack=250,huihe;
	endef+=sqnkillcount*20;
	enattack+=sqnkillcount*20;
	int tmphp=enhp,tmpdef=endef;
	cout<<"你遭遇了一只SQN!"<<endl;
    while(battle)
    {
        	for(int i=1;i<=50;i++)cout<<"-";
        	cout<<endl;
        	w_out("怪物:SQN");
			cout<<endl;
			w();
    		w_out("等级:");
			cout<<enlv;
			w();
			cout<<"级"<<endl;
            w_out("血量:");
			cout<<enhp<<endl;
            for(int i=1;i<=50;i++)cout<<"-";
            cout<<endl;
            w_out("Your Hp:");
			cout<<hp<<endl;
            w_out("1.attack 2.use something 3.run away");
			cout<<endl;
            char cmd;
            cin>>cmd;
            if(cmd=='1')
            {
            	w_out("你发起了进攻!"),cout<<endl;
                int miss=rand()%7+1;
                if(miss==3)w_out("You Miss!"),cout<<endl;
                else
                {
                	int randdamage=rand()%20+1-10;
                    enhp-=max((attack-endef+randdamage),5);
                    w_out("SQN受到了"),cout<<max((attack-endef+randdamage),5)<<"点伤害"<<endl;
                    if(enhp<=0)battle=0,flag=1;
                }                   
            }
            if(cmd=='2')
            {
                battlebag();
            }
            if(cmd=='3')
            {
                int miss=rand()%6+1;
                if(miss==3)w_out("逃跑成功 !"),cout<<endl,battle=0;
                else w_out("逃跑失败!"),cout<<endl;
            }
            if(battle==0)break;
            int skilll=rand()%8+1;
            if(skilll==5&&huihe!=0)skilll=1;
            if(skilll!=3&&skilll!=5&&skilll!=6&&skilll!=8)
            {
               w_out("SQN对你发起了进攻!"),cout<<endl;
               hp-=max((enattack-def),5);
               w_out("你受到了"),cout<<max((enattack-def),5)<<"点伤害"<<endl;      
            }
            else
            {
                if(skilll==3)
                {
                   w_out("SQN使用了技能'"),cout<<skill[1],w_out("',血量增加了 !"),cout<<endl;
                   enhp+=50;
                   if(enhp>tmphp)enhp=tmphp;    
                }
                if(skilll==5)
                {
                	w_out("SQN使用了技能'"),cout<<skill[2],w_out("',防御暂时提高了 !"),cout<<endl;
                    endef+=30;
                    huihe=1;
                }
                if(skilll==6)
                {
					w_out("SQN使用了技能'"),cout<<skill[3];
					int huixin=rand()%2+1;
					if(huixin==1)w_out("'但是好像没有击中");
					else w_out("'狠狠地击中了你,"),w_out("你受到了"),hp-=(2*max((enattack-def),5)),cout<<2*max((enattack-def),5)<<"点伤害"<<endl;
					cout<<endl;				
				}
				if(skilll==8)
                {
					w_out("SQN使用了技能'"),cout<<skill[4];
					w_out("'你和SQN各自受到了");
					int zibao=rand()%11+100;
					hp-=zibao,cout<<zibao<<"点伤害"<<endl;			
				}
            }
            if(huihe&&huihe<4)huihe++;
            if(huihe==4)
            {
                huihe=0;
                endef-=30;
            }
            if(hp<=0)battle=0,flag=2;
            cout<<endl;
    }
    if(flag==2)cout<<"You Die!",exit(0);
    if(flag==1)
    {
    	killcount++;
    	sqnkillcount++;
        w_out("胜利!"),cout<<endl;
        w_out("获得经验值："),cout<<sqnkillcount*10000<<endl;
        w_out("战利品: 无");
	}
    system("pause");
    return;
}
void boss1_final()
{
	
}
void settings()
{ 
	system("cls");
	cout<<"1.文字出现速度："<<speed<<"，默认速度：100"<<endl;
	cout<<"请输入想要更改的项目的编号来更改，e键退出当前页面"<<endl; 
	char cmd;
	cin>>cmd;
	if(cmd=='e')return;
	if(cmd=='1')
	{
		cout<<"想要更改为多少?（x>0)";
		int speedtmp;
		cin>>speedtmp;
		if(speedtmp>0)
		{
			speed=speedtmp;
			cout<<"更改成功!";
			settings();
		}
		else  cout<<"输入不合法！！",settings(); 
	}
}
void print()
{
    for(int i=1;i<=3;i++)
    {
        if(x[i]<y[i]&&(path[i]==1||path[i]==3))swap(x[i],y[i]);
        cout<<x[i];
        if(path[i]==1)cout<<"+";
        if(path[i]==2)cout<<"-";
        if(path[i]==3)cout<<"*";
        if(path[i]==4)cout<<"/";
        cout<<y[i]<<"="<<z[i]<<endl;
    }
}
void dfs(int step)
{
    if(ans<=0||reach)return;
    if(step==4&&ans==24)
    {
        //print();
        reach=1;
        return;
    }
    if(step>=4)return;
    for(int i=1;i<=4;i++)
    {
        if(!ex[i])
        {
            path[step]=1;
            x[step]=ans;
            ans+=a[i];
            y[step]=a[i];
            z[step]=ans;
            ex[i]=1;
            dfs(step+1);
            ex[i]=0;
            ans-=a[i];
            
            path[step]=2;
            x[step]=ans;
            ans-=a[i];
            y[step]=a[i];
            z[step]=ans;
            ex[i]=1;
            dfs(step+1);
            ex[i]=0;
            ans+=a[i];
            
            path[step]=3;
            x[step]=ans;
            ans*=a[i];
            y[step]=a[i];
            z[step]=ans;
            ex[i]=1;
            dfs(step+1);
            ex[i]=0;
            ans/=a[i];
            
            int tmp=ans;
            if(a[i]==0||(((int)(ans/a[i])*a[i]))!=tmp)return;
            path[step]=4;
            x[step]=ans;
            ans/=a[i];	
            y[step]=a[i];
            z[step]=ans;
            ex[i]=1;
            dfs(step+1);
            ex[i]=0;
            ans*=a[i];
        }
    }
}
void push()
{
	symbol[++p]=s[i];
}
int POW(int a,int b)
{
	int j,t=1;
	for(j=1;j<=b;j++) t*=a;
	return t;
}
void pop()
{
	switch(symbol[p--])
	{
		case'+':number[p]+=number[p+1];break;
		case'-':number[p]-=number[p+1];break;
		case'*':number[p]*=number[p+1];break;
		case'/':number[p]/=number[p+1];break;
		case'^':number[p]=POW(number[p],number[p+1]);break;
	}
}
bool can()
{
	if((s[i]=='+'||s[i]=='-')&&symbol[p]!='(')return 1;
	if((s[i]=='*'||s[i]=='/')&&
	    (symbol[p]=='*'||symbol[p]=='/'||symbol[p]=='^'))return 1;
	if(s[i]=='^'&&symbol[p]=='^')return 1;
	return 0;
}
int getin()
{
    s[strlen(s)]=')';symbol[p]='(';
    while(i<strlen(s))
    {
		while(s[i]=='(')
		{
			push();i++;
		}
		int x=0;
		while(s[i]>='0'&&s[i]<='9')
		{
			x=x*10+s[i++]-'0';

		}			
		bool yes=0;
		for(int fuck=1;fuck<=4;fuck++)
		if(a[fuck]==x&&!used[fuck]&&!yes)yes=1,used[fuck]=1;
		if(!yes)return 0;
		number[p]=x;
		do
		{
			if(s[i]==')')
			  {
					while(symbol[p]!='(')pop();
					number[--p]=number[p+1];
			  }
			  else
			  {
					while(can())pop();
					push();
    		  }
    		  i++;
		}while(i<strlen(s)&&s[i-1]==')');
	}
	if(number[0]==24)return 1;
	else return 0;
}
void twentyfour()
{
	memset(a,0,sizeof(a));
	memset(ex,0,sizeof(ex));
	memset(path,0,sizeof(path));
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	memset(z,0,sizeof(z));
	memset(number,0,sizeof(number));
	i=0,p=1,temp=1;
	memset(symbol,0,sizeof(symbol));
	memset(s,0,sizeof(s));
	memset(t,0,sizeof(t));
	ans=0;
	reach=0;
	memset(used,0,sizeof(used));
	getchar();
	srand(time(NULL));
	start24:for(int i=1;i<=4;i++)a[i]=rand()%10+1;
    for(int i=1;i<=4;i++)
    {
        ex[i]=1;
        ans=a[i];
        dfs(1);
        ex[i]=0;
    }
    if(!reach)
    goto start24;
    for(int i=1;i<=4;i++)cout<<a[i]<<" ";   
	cout<<endl;	
	gets(s);
	int getans=getin();
	if(getans)cout<<"You Win!! 获得100元奖励",money+=100,moneyget+=100;
	else cout<<"You Lose!!";
	system("pause");
}
void pss()
{
	psss[1][1]=-1;
	psss[1][2]=0;
	psss[1][3]=1;
	psss[2][1]=1;
	psss[2][2]=-1;
	psss[2][3]=0;
	psss[3][1]=0;
	psss[3][2]=1;
	psss[3][3]=-1;
	cout<<"1.经典模式(1->剪刀,2->石头,3->布)"<<endl;
	char cmd;
	cin>>cmd;
	cout<<"要押多少钱 ?"<<endl;
    long long mm;
    cin>>mm;
    bool win=0;
    if(mm<=0)return; 
    if(mm>money)cout<<"钱不够"<<endl;
    else
    {
    	money-=mm;
    	int enemy=rand()%3+1;
    	cout<<"老板已经想好出什么了，你呢?(输入一个整数 1->剪刀,2->石头,3->布)"<<endl;
    	/*
		1克2 2克3 3克1
		*/ 
		int cmdd;
		cin>>cmdd;
		w_out("你出的是");
		cout<<pssss[cmdd]<<endl; 		
		w_out("老板出的是");
		cout<<pssss[enemy]<<endl; 
		if(psss[cmdd][enemy]==1)
		{
			w_out("你赢了!");cout<<endl; 
			cout<<"获得"<<mm<<"元钱 !"<<endl;
			money+=(mm*2);
			moneyget+=(mm); 
			system("pause");
		}
		if(psss[cmdd][enemy]==0)
		{
			w_out("你输了!再接再厉!");
			cout<<endl; 
			system("pause");
		}
		if(psss[cmdd][enemy]==-1)
		{
			w_out("平局!");cout<<endl; 
			money+=(mm); 
			system("pause");
		}
	}
	return;
}
void hanoi()
{
	system("cls");
	int num=rand()%6+5,count=0;
	int a[20],b[20],c[20];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<=num;i++)a[i]=num-i+1;
	cout<<"输入大写字母x y将x顶上的圆盘移到y上，数字表示盘子的大小，大盘不能压在小盘上面，把A的所有盘移到C上胜利";
	cout<<endl; 
	cout<<"e.退出"<<endl; 
	while(1)
	{
		cout<<"当前移动步数: "<<count<<endl;
		bool check=1;
		for(int i=2;i<=num;i++)
		if(c[i]!=c[i-1]-1||c[i]==0)check=0;
		if(check)
		{
			cout<<"You Win!! 获得100元奖励",money+=100,moneyget+=100;
			system("pause");
			return;
		}
		int topa=0,topb=0,topc=0;
		cout<<"A: ";
		for(int i=1;i<=num;i++)
		if(a[i])cout<<a[i]<<" ",topa++;
		cout<<endl;
		cout<<"B: ";
		for(int i=1;i<=num;i++)
		if(b[i])cout<<b[i]<<" ",topb++;
		cout<<endl;
		cout<<"C: ";
		for(int i=1;i<=num;i++)
		if(c[i])cout<<c[i]<<" ",topc++;
		cout<<endl;
		char x,y;
		cin>>x;
		if(x=='e')return;
		cin>>y;
		if(x=='a')x='A';
		if(x=='b')x='B';
		if(x=='c')x='C';
		if(y=='a')y='A';
		if(y=='b')y='B';
		if(y=='c')y='C';
		int tmp,siz1,siz2,tmpp;
		if(x=='A')siz1=a[topa];
		if(x=='B')siz1=b[topb];
		if(x=='C')siz1=c[topc];
		if(y=='A')siz2=a[topa];
		if(y=='B')siz2=b[topb];
		if(y=='C')siz2=c[topc];
		if(siz1>siz2&&siz2!=0)
		{
			cout<<"不合法！！"<<endl; 
			continue;
		}
		if(x=='A')a[topa]=0;
		if(x=='B')b[topb]=0;
		if(x=='C')c[topc]=0;
		if(y=='A')a[topa+1]=siz1;
		if(y=='B')b[topb+1]=siz1;
		if(y=='C')c[topc+1]=siz1;
		count++;
		system("cls");
	}
	return;
} 
void quest()
{
	system("cls");
	string question[100],ans[100];
	int count=1,wincount=0;
	cout<<"输入字母全大写(输入只有字母或数字，汉字一律输入大写首字母)"<<endl; 
	question[1]="这个程序的作者叫什么名字？"; 
	ans[1]="YSJ";
	question[2]="th15.5在steam上定价多少？";
	ans[2]="80";
	question[3]="th16在steam上定价多少？";
	ans[3]="50";
	question[4]="2013年th的整数作是什么？ ";
	ans[4]="HZC";
	question[5]="th中公认最难的整数作是哪部 ？";
	ans[5]="GZZ";
	question[6]="2008~2014年th中公认最难的整数作是哪部 ？";
	ans[6]="XLC";
	question[7]="th是好游戏吗(YES/NO)?";
	ans[7]="YES";
	question[8]="响子脸的起源人物是谁？";
	ans[8]="YXXZ";
	question[9]="线段树中的'tag'代表什么？";
	ans[9]="LDBJ";
	question[10]="那个怀抱僵尸的洛天依是谁？";
	ans[10]="HQE";
	question[11]="信仰之山的别名？";
	ans[11]="MJS";
	question[12]="广有射怪鸟事是谁的bgm？";
	ans[12]="HPYM";
	question[13]="你记得自己至今吃过多少片面包吗？";
	ans[13]="13";
	question[14]="白玉楼的前庭师是谁？";
	ans[14]="HPYJ";
	question[15]="哪里最'适合'摘花？";
	ans[15]="TYHT";
	question[16]="'XXX,不认识的孩子呢 '中的XXX是谁？";
	ans[16]="JSC";
	question[17]="'金发的孩子好可怜啊'中的金发孩子是谁？";
	ans[17]="WYMLS"; 
	question[18]="在左偏树中，各种操作的本质是什么？(一英文单词)";
	ans[18]="MERGE";
	question[19]="在伸展树中一切操作的基础操作是什么？";
	ans[19]="ROTATE"; 
	question[20]="作者的QQ号是多少？";
	ans[20]="2500481138"; 
	int num=20;
	bool quested[100];
	memset(quested,0,sizeof(quested));
	while(count<=num)
	{
		system("cls");
		int number=rand()%num+1;;
		while(quested[number])number=rand()%num+1;
		cout<<"第";w();cout<<count;cout<<"轮"<<endl; 
		w_out("主持人:"),w_out(question[number]);
		cout<<endl<<"请回答:";
		string yourans;
		cin>>yourans;
		if(yourans==ans[number])
		{
			w_out("主持人:恭喜你，你答对了！"); 
			wincount++;
			w_out("你已经累计答对"),cout<<wincount<<"次!";
			cout<<endl; 
			system("pause");
		}
		else
		{
			w_out("主持人:很抱歉，你答错了");
			w_out("正确答案是:"),cout<<ans[number]<<endl;
			system("pause"); 
		}
		quested[number]=1;
		count++;
	}
	w_out("主持人:你已经答完了题库中现有的所有题！你的正确率是");
	printf("%llf",(wincount*1.0)/(num*1.0)*100);
	cout<<"%"<<endl;
	system("pause");
	return;
} 
void amusement()
{
	system("cls");
	cout<<"欢迎来到游乐园，你要体验什么项目？在游乐的同时还可能有金钱奖励哦"<<endl;
	cout<<"1.猜数游戏：在1~100间猜一个随机数，每次会告诉你猜大还是猜小，共有六次机会"<<endl;
	cout<<"2.24点：用四个数加减乘除拼出24"<<endl;
	cout<<"3.猜拳：经典玩法+克制打乱"<<endl; 
	cout<<"4.汉诺塔：小片->大片，A塔->C塔"<<endl;
	cout<<"5.知识问答"<<endl;
	cout<<"e.返回上一界面(-5精力)"<<endl;
	char cmd;
	cin>>cmd;
    if(cmd=='e')
    {
    	jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			return;
		}     
    }
    if(cmd=='1')
    {
    	jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			caishu();
		} 	
	}
	if(cmd=='2')
    {
    	jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			twentyfour();
		}	
	}
	if(cmd=='3')
    {
		jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			pss();
		}    	
	}
	if(cmd=='4')
    {
		check();
        if(jingli>=10)
		{
			jingli-=10;
			hanoi();
		} 	
	}
	if(cmd=='5')
    {
    	jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			quest();
		}	
	}
	amusement();
}
void duchang()
{
	system("cls");
	cout<<"小子，又来赌场了啊，还想把裤子都输掉吗？你这样的菜鸟又能赢什么钱"<<endl;
	cout<<"1.赌大小";
	if(!sp1)cout<<"(未解锁)";
	cout<<endl; 
	cout<<"2.彩票"<<endl;
	cout<<"3.自杀"<<endl; 
	cout<<"e.返回上一界面(-5精力)"<<endl;
	char cmd;
	cin>>cmd;
	if(cmd=='e')
    {
    	jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			return;
		}
    }
	if(cmd=='3')
	{
		cout<<"你tm是有毒吧?"<<endl;
        system("pause");
        hp-=hpmax;
        return;
	} 
	if(cmd=='1')
	{
		if(sp1)
		{
			jingli-=10;
    		check();
    		jingli+=10; 
        	if(jingli>=10)
			{
				jingli-=10;
				dubo();
			}	
		}
	} 
	if(cmd=='2')
	{
		jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			lottery();
		}				
	}
	duchang();
}
void jia()
{
	system("cls");
	cout<<"这里是你的家，充满着温馨的气息和你美好的回忆"<<endl;
	cout<<"1.存档(不消耗精力)"<<endl;
	cout<<"2.吃屎(emmmm,回复水分饥饿值，减hp，不定量捡到钱)"<<endl;
	cout<<"3.学习(+xp)"<<endl; 
	cout<<"4.睡觉(Sleep Satori)(+精力)"<<endl;
	cout<<"5.冥想(+IQ)"<<endl;
	cout<<"6.查看当前状态(不消耗精力)"<<endl;
		cout<<"b.查看背包"<<endl;
	cout<<"e.返回上一界面(-5精力)"<<endl;
	char cmd;
	cin>>cmd;	
	if(cmd=='b')
	{
		bag();
	}
	if(cmd=='e')
    {
    	jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			return;
		}
    }
    if(cmd=='1')
    {
    	saveload();
	}
	if(cmd=='2')
	{
		jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			shit();
		}		
	}
	if(cmd=='3')
	{
		jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
			study();
		}
	}
	if(cmd=='4')
	{
		hunger-=5;
		water-=10;
		jingli=maxjingli;
		day++;
		system("cls");
		w_out("多么一个好觉(jue)啊，你的精力已回满!(水分-10，饥饿-5)"),cout<<endl;
		system("pause");
	}
	if(cmd=='5')
	{
		jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
		}
	}
	if(cmd=='6')
	{
		showstat();
	}
    jia();
}
void downtown()
{
	system("cls");
	cout<<"空气阴沉，熙熙攘攘的市中心给你一种不安的气氛"<<endl;
	cout<<"1.人力市场(就是打工)"<<endl;
	cout<<"2.商店(买卖交易)";
	if(!sp3)cout<<"(未解锁)"; 
	cout<<endl;
	if(ep==2&&censhu>=1)cout<<"3.武器店"<<endl; 
	cout<<"b.查看背包"<<endl;
	cout<<"e.返回上一界面(-5精力)"<<endl;
	char cmd;
	cin>>cmd;	
	if(cmd=='b')
	{
		bag();
	}
	if(cmd=='e')
    {
    	jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			return;
		}
    }
	if(cmd=='1')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			showwork();
		}		
	}
	if(cmd=='2')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			shop();
		}		
	}
	if(cmd=='3')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			weaponshop();
		}		
	}
    downtown();
}
void forest()
{
	system("cls");
	cout<<"郁郁青青的树木映入你的眼帘，远处似乎有什么奇怪的叫声"<<endl;
	cout<<"1.探索"<<endl;
	cout<<"2.砍伐(需要精力20)"<<endl; 
	cout<<"b.查看背包"<<endl;
	cout<<"e.返回上一界面(-5精力)"<<endl;
	char cmd;
	cin>>cmd;	
	if(cmd=='2')
	{
		jingli-=20;
    	check();
    	jingli+=20; 
    	if(jingli>=20)
    	{
    		w_out("你非常卖力地挥舞着锈迹斑斑的破斧，树木发出不详的响声");
    		cout<<endl;
    		cout<<"一个小时后,你获得了: ";
			for(int i=1;i<=rand()%4+1;i++)cout<<"小树枝 ",bagnum[9]++;
			for(int i=1;i<=rand()%3+1;i++)cout<<"粗木杆 ",bagnum[11]++;
			system("pause");
		}
	}
	if(cmd=='b')
	{
		bag();
	}
	if(cmd=='e')
    {
    	jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			return;
		}
    }
    if(cmd=='1')
    {
    	jingli-=10;
    	check();
    	jingli+=10; 
        if(jingli>=10)
		{
			jingli-=10;
		}	
		else goto endf;
    	int poss=rand()%20+1;
    	poss=20;
		if(poss<=13)
		{
			daguai1();
		} 
		else
		{
			if(poss<=17)
			{
				int num=rand()%10+1;
				if(num<=9)
				{
					w_out("找到了一些材料:");
					for(int i=1;i<=rand()%3+1;i++) cout<<"小木棍 ",bagnum[9]++; 
					cout<<endl;
					system("pause");
				} 
				if(num==10)
				{
					w_out("找到了一些材料:");
					for(int i=1;i<=rand()%2+1;i++) cout<<"木元素精华 ",bagnum[10]++; 
					cout<<endl;
					system("pause");
				} 				
			}
			if(poss>17&&poss!=20)
			{
				w_out("找到了一处歇脚的好地方，你打算休息一下"),cout<<endl;
				cout<<"1.睡一觉(+30精力)"<<endl<<"2.冥想一会(+20hp)"<<endl;
				char cmd;
				cin>>cmd;
				if(cmd=='1')
				{
					w_out("树荫之下真是很清凉呐，你睡得很香" ),cout<<endl;
					jingli+=30;
					jingli=min(maxjingli,jingli);
					system("pause");
				}
				if(cmd=='2')
				{
					w_out("一刻钟过去了，你觉得自己能更好的了解这个世界了" ),cout<<endl;
					hp+=20;
					hp=min(hpmax,hp);
					system("pause");
				}
			}
			if(poss==20)
			{
				w_out("你发现了一个神秘的洞窟，是否前去探索？(25级以下不推荐)"),cout<<endl;
				cout<<"1.去   其他.不去"<<endl;
				char cmd;
				cin>>cmd;
				if(cmd=='1')
				{
					if(sqnkillcount<5)
					boss1();
					else boss1_final();
				}
			}
		}
	}
    endf:forest();
}
void show()
{
    system("cls");
    if(gameover==1)return;
    cout<<"day "<<day<<endl;
    //if(ep==2)cout<<"当前层数："<<censhu<<endl;
    cout<<"你要去哪里？(每次移动减5精力)"<<endl;
    cout<<"1.游乐场(休闲娱乐+赚点小钱)"<<endl;
    cout<<"2.赌场(财源滚滚/裤子输掉)"<<endl;
    cout<<"3."<<name<<"的家(存档啊，状态查询等等)"<<endl;
    cout<<"4.市中心(商店啊，打工啊什么的)"<<endl;
	cout<<"5.小森林(打怪，资源采集)";
	if(ep<2)cout<<"(尚未开启，据说需要什么钥匙)";
	cout<<endl;
    /*cout<<"1.打工"<<endl;
    cout<<"2.买彩票"<<endl;	
    cout<<"3.吃屎"<<endl;
    cout<<"4.学习"<<endl;
    cout<<"5.查看状态"<<endl;
    if(sp1)cout<<"6.赌博"<<endl;
    cout<<"7.自杀"<<endl;
    if(sp2)cout<<"8.商店"<<endl;
    cout<<"9.猜数游戏"<<endl;
    if(jq2)cout<<"m.任务"<<endl;
    cout<<"b.背包"<<endl;
    cout<<"x.存档"<<endl;*/
    cout<<"b.查看背包"<<endl;
	cout<<"s.游戏选项"<<endl;
	cout<<"c.游戏相关"<<endl;
    cout<<"e.退出游戏"<<endl;
    /*if(ep>=2)
    {
        cout<<"a.打怪"<<endl;
    }*/
    char cmd;
    cin>>cmd;
    if(cmd=='1')
    {
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			amusement();
		} 	
	}
	if(cmd=='b')
	{
		bag();
	}
	if(cmd=='2')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			duchang();
		}		
	}
	if(cmd=='3')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			jia();
		}	
	}
	if(cmd=='4')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5)
		{
			jingli-=5;
			downtown();
		}	
	}
	if(cmd=='5')
	{
		jingli-=5;
    	check();
    	jingli+=5; 
        if(jingli>=5&&ep>=2)
		{
			jingli-=5;
			forest();
		}	
	}
	if(cmd=='s')
	{
		settings();
	}
	if(cmd=='c')
	{
		conf(); 
	}
    /*if(cmd=='9')
    {
        caishu();
        return;
    }
    if(cmd=='5')
    {
        showstat();
        day--;
        hunger+=3;
        water+=3;
        return;
    }
    if(cmd=='1')
    {
        showwork();
        return;
    }
    if(cmd=='7')
    {
        cout<<"你tm是有毒吧?"<<endl;
        system("pause");
        hunger-=100;
        water-=100;
        return;
    }
    if(cmd=='2')
    {
        lottery();
        return;
    }
    if(cmd=='3')
    {
        shit();
        return;
    }
    if(cmd=='4')
    {
        study();
        return;
    }
    if(cmd=='6'&&sp1)
    {
        dubo();
        return;
    }
    if(cmd=='8'&&sp2)
    {
        shop();
        day--;
        hunger+=3;
        water+=3;
        return;
    }
    if(cmd=='b')
    {
        bag();
        day--;
        hunger+=3;
        water+=3;
        return;
    }
    if(cmd=='m')
    {
        mission();
        return;
    }
    if(cmd=='s')
    {
    	settings();
    	day--;
        hunger+=3;
        water+=3;
	}*/
    if(cmd=='e')
    {
        cout<<"你确定要这样离开？你存档了吗？"<<endl;
        cout<<"是：Y   否：N"<<endl;
        char cmdd;
        cin>>cmdd;
        if(cmdd=='Y')exit(0); 
        return; 
    }
    if(cmd=='y')xp+=500;
    if(cmd=='r')money+=100000000;
    if(cmd=='h')hunger+=100,water+=100;
    if(cmd=='*')hunger+=10000,jq2=1,water+=10000,money+=100000000,xp+=50000,bagnum[6]=10000,bagnum[3]=1,jingli=10000; 
}
int main()
{
    srand(time(NULL));
    cout<<"1.新建用户"<<endl;
    cout<<"2.读取存档"<<endl;
    char cmd;
    cin>>cmd;
    if(cmd=='1')
    {
       cout<<"enter your name:";
       cin>>name;    
       hpmax=hunger=water=money=hp=100;
       now=1;
       lv=1;
       censhu=1;
       sp1=0;
       xp=0;
       needxp=10;
       sp2=0;
       day=1;
       ep=1;
       attack=10;
       def=10;    
       sp3=0;
       jq2=0;
       speed=100;
       jingli=50;
       maxjingli=50;
       system("cls");
       juqing1();
    }
    if(cmd=='2')
    {
		readload();
    }
    gameover=0;
    for(int j=1;j<=1;j++)
    {
        system("cls");
        for(int i=0;i<=10;i++)cout<<load[i],w();
    }
    system("cls");
    while(1)
    {
        if(check())return 0;
        while(money>=aim[now]&&now<=7)now++;
        if(now>=2&&!jq2)
        {
            juqing2();
            cout<<"'任务'已解锁!"<<endl;
            system("pause");
        }
        if(aim[now]==0)aim[now]=2333;
        while(xp>=needxp&&lv<=100)
        {
            hpmax+=10;
            hp=hpmax;
            xp-=needxp;
            lv++;
            if(lv<=20)needxp*=1.5;
            else needxp+=500;
            attack+=10;
            def+=10; 
            w_out("你升级了！"),cout<<endl,w_out("生命值,攻击，防御增加10!") ,cout<<endl;
            if(lv%2==1)
			{
				maxjingli+=5;
				w_out("精力上限增加5!");
				cout<<endl;
			} 
        }
        if(lv>=3&&sp3==0)cout<<"你已解锁新工作!"<<endl,sp3=1,system("pause");
        if(lv>=5&&sp1==0)cout<<"你已解锁'赌博'!"<<endl,sp1=1,system("pause");
        if(lv>=10&&sp2==0)cout<<"你已解锁'商店'!"<<endl,sp2=1,system("pause");
        show();
    }
}
