#define _CRT_SECURE_NO_WARNINGS
#include <iostream> //标准输入输出流  in输入  out 输出
//using namespace std;//使用命名空间 std 打开一个叫std房间

enum season {SPR,SUM,AUT,WIN}; //枚举

using namespace std;
struct COMP
{
    float real;
    float image;
};
COMP operator+(COMP one, COMP another)  //操作符重载
{
    one.real += another.real;
    one.image += another.image;
    return one;
}

#if 0
//优点：内嵌代码，辟免压栈与出栈的开销
//缺点: 代码替换，易使生成代码体积变大，易产生逻辑错误。
#endif
#define SQR(x) ((x)*(x))    //宏函数

#if 0
//优点：高度抽象，避免重复开发
//缺点: 压栈与出栈，带来开销
#endif
inline int sqr(int x)   //内联函数
{
    return x*x;
}
#endif

//函数入口地址
int main()
{
/*数据类型*/
    //布尔
    bool flag = true;
    if(flag != false)
    {
        printf("i know bool type now\n");
    }
    //枚举
    enum season s = SPR;
    s = 0;

/*输入与输出*/
    //cin && cout
    char name[30];
    int age;
    cout<<"pls input name and age:"<<endl;
    cin>>name;
    cin>>age;
    // cin>>name>>age;
    cout<<"your name is: "<<name<<endl;
    cout<<"your age is: "<<age<<endl;
    //格式化
    printf("%c\n%d\n%f\n",'a',100,120.00);
    printf("%5c\n%5d\n%6.2f\n",'a',100,120.00);
    cout<<setw(5)<<'a'<<endl<<setw(5)<<100<<endl  
        <<setprecision(2)<<setiosflags(ios::fixed)<<120.00<<endl; //setprecision(2) 可以设置有效位数，setprecision(n)<<setiosflags(ios::fixed)合用，可以设置小数点右边的位数
    //输出十进制，十六进制，八进制。默认输出十进制的数据
    int i = 123;
    cout<<i<<endl;
    cout<<dec<<i<<endl;
    cout<<hex<<i<<endl;
    cout<<oct<<i<<endl;
    cout<<setbase(16)<<i<<endl;
    //还可以设置域宽的同时，设置左右对齐及填充字符。
    cout<<setw(10)<<1234<<endl;
    cout<<setw(10)<<setfill('0')<<1234<<endl;
    cout<<setw(10)<<setfill('0')<<setiosflags(ios::left)<<1234<<endl;
    cout<<setw(10)<<setfill('-')<<setiosflags(ios::right)<<1234<<endl;

/*函数重载*/
    //引例
    int abs(int a)
    {
        return a>0? a:-a;
    }
    double abs(double a)
    {
        return a>0? a:-a;
    }
    //extern “C"

/*操作符重载*/
    OMP c1 = {1,2};
    COMP c2 = {3,4};
    COMP sum = operator+(c1,c2); //c1+c2;
    cout<<sum.real<<" "<<sum.image<<endl;

/*引用*/
    int a;
    int &b = a;
    cout<<&a<<&b<<endl; //变量与引用具有相同的地址。

/*new/delete*/ //成对堆内存的申请和释放
    //开辟单变量地址空间
    int *p = new int; //开辟大小为 sizeof(int)空间
    int *a = new int(5); //开辟大小为 sizeof(int)空间，并初始化为5
    //开辟数组空间
    //一维
    int *a = new int[100];//开辟一个大小为 100 的整型数组空间
    delete a; //释放单个 int 的空间
    //二维
    int (*a)[6] = new int[5][6];
    delete []a;//释放 int 数组空间
    //三维
    int (*a)[5][6] = new int[3][5][6];

/*类型强转*/
    //静态类型转换
    static_cast<目标类型> (标识符）

    int a = 10;
    int b = 3;
    cout<<static_cast<float>(a)/b<<endl;//所谓的静态，即在编译期内即可决定其类型的转换，用的也是最多的一种
    //动态类型转换
    dynamic_cast<目标类型> (标识符）//用于多态中的父子类之间的强制转化
    //（脱）常量类型转换
    const_cast<目标类型> (标识符) //目标类类型只能是指针或引用。
    const A a = {200};
    A &a2 = const_cast<A&>(a);
    a2.data = 300;
    cout<<a.data<<a2.data<<endl; //结论：可以改变 const 自定义类的成员变量，但是对于内置数据类型，却表现未定义行为.
    //重解释类型转换
    reinterpret_cast<目标类型> (标识符) //，reinterpret 即为重新解释，此标识符的意思即为数据的二进制形式重新解释，但是不改变其值

    int a[5] = {1,2,3,4,5};
    printf("%x\n",*((int*)((int)a +1)));
    cout<<*(reinterpret_cast<int*>(reinterpret_cast<int>(a)+1))<<endl;

/*封装*/
//访问属性    属性 对象内部 对象外
//public      公有 可访问 可访问
//protected   保护 可访问 不可访问
//private     私有 可访问 不可访问






























	system("pause"); //阻塞功能
	return EXIT_SUCCESS; //返回正常退出

}