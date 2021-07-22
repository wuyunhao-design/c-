
#include<iostream>
#include<iomanip>
using namespace std;
class Person
{
protected:
    int ID;//编号
public:
    Person(){}
    virtual void display() = 0;//输出相关信息
};


//学生类
class Student :public Person
{
public:
    Student() {
        cin >> ID;
        sum = 0;
        num = 0;
        for (int i = 0; i < 5; i++)
        {
            cin >> score[i];
            if (score[i] != -1)  //如果没有缺考
            {
                sum += score[i]; //计算考的课程 成绩的总分
            }
            else 
            {
                num++;  //记录缺考的门数
            } 
        }
    }
    void display()
    {
        
        if (num < 5)  //如果缺考的门数少于5门
        {
            printf("%d %d %.1f\n", ID, num, sum/(5-num));
           
        }
        else
        {
            cout << ID << " " << num << endl;  //达到5门输出课程号 和缺考门数
        }          
    }
private:
    float score[5];   //定义一个课程成绩数组
    int num;
    float sum;
};

//Teacher类
class Teacher :public Person
{
public:
    Teacher() {
        cin >> ID;
        num = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> yl[i]; num += yl[i];
        }
    }
    void display()
    {
        printf("%d %d\n", ID, num);
    }
private:
    int yl[3];  //定义一个数组，用来存放每年的论文数
    int num;
};

int main()
{
    int type;
    int i = 0;
    Person* pp[10];  //指针数组 题目中给的
    cin >> type;   //type 人员类型
    while (type != 0)
    {
        if (type == 1)
        {
            pp[i] = new Student;
            pp[i++]->display(); //调用display函数，进行输出数组中内容
        }
        else if(type ==2)
        {
            pp[i] = new Teacher;
            pp[i++]->display();  
        }
        cin >> type;   //输入0 退出while 循环
    }
    
    delete* pp; //手动释放空间
}

