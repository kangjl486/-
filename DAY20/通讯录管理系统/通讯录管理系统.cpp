#include<iostream>
#include<string>
#define MAX 1000//宏常量方便后期维护
using namespace std;

//设计联系人结构体
struct person
{
	//性名
	string p_name;
	//性别
	int p_sex;//1,男 2，女  不用字符串防止输入其他无关信息
	//年龄
	int p_age;
	//电话
	string p_phone;
    //住址
	string p_addr;
};
//设计通讯录结构体
struct addressbooks
{
	//通讯录中保存的联系人数组
	struct person personarray[MAX];//使用MAX方便后期维护
		//通讯录中当前记录的联系人个数
		int p_size;
};

//封装添加联系人函数
void addperson(addressbooks * abs)
{
	//判断通讯录是否已满，如果满了就不再添加
	if (abs->p_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarray[abs->p_size].p_name = name;
		//性别
		cout << "请输入您的性别： " << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2 应为正确的输入 可退出循环
			//如有误 则继续输入
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->p_size].p_sex = sex;
				break;
			}
		}
		
		//年龄

		//电话

		//地址
	}
}

//封装菜单界面
void showmunu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****7.推出通讯录*****" << endl;
	cout << "**********************" << endl;
}






int main()
{
	//创建通讯鲁结构体变量
addressbooks abs;
//初始化通讯录中当前人员个数
abs.p_size = 0;
int select = 0;//创建用户选择输入变量
while (true)//除退出外持续使用程序
{
	//调用菜单
	showmunu();
		cin >> select;
	switch (select)
	{
	case 1://添加联系人
		addperson(&abs);//利用地址传递 修改实参
		break;
	case 2://显示联系人
		break;
	case 3://删除联系人
		break;
	case 4://查找联系人
		break;
	case 5://修改联系人
		break;
	case 6://清空联系人
		break;
	case 0://推出通讯录
		cout << "欢迎下次使用通讯录" << endl;
		system("pause");
		return 0;
		break;


	default:
		break;
	}
}





	system("pause");
	return 0;
}
