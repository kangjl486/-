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
	string p_addr;//
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
			cout << "您的输入有误 请重新输入" << endl;
		}
		
		//年龄
       cout << "请输入年龄" << endl;
       int age = 0;
       cin >> age;
       abs->personarray[abs->p_size].p_age = age;
		//电话
       cout << "请输入电话" << endl;
       string phone;//string类型不能用  =0 来初始化
       abs->personarray[abs->p_size].p_phone = phone;
		//地址
		cout << "请输入家庭地址" << endl;
        string addr;
        cin >> addr;
        abs->personarray[abs->p_size].p_addr = addr;
		//更新通讯录人数
        abs->p_size++;
        cout << "已添加成功" << endl;
        system("pause");//请按任意键继续
        system("cls");//清屏
	}
}



//封装显示联系人函数
void showperson(addressbooks* abs)
{
	//判断是否通讯录人数为0，如果为0，提示记录为空
	if (abs->p_size == 0)//for循环语句这里不加；号
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->p_size; i++)
		{
			cout << "姓名： " << abs->personarray[i].p_name << "\t";//水平制表符 空8格
			cout << "性别： " << (abs->personarray[i].p_sex == 1 ? "男" : "女") << "\t";//三目运算符节俭
			cout << "年龄： " << abs->personarray[i].p_age << "\t";
			cout << "电话： " << abs->personarray[i].p_phone << "\t";
			cout << "家庭住址： " << abs->personarray[i].p_addr << endl;
		}
	}
	system("pause");//任意键继续
	system("cls");//清屏
} 

//检测联系人是否存在如果存在，返回联系人所在数组中的具体位置，不存在返回-1
//参数1 通讯录   参数2 对比姓名
int isexist(addressbooks * abs,string name)
{
	for (int i = 0; i < abs->p_size; i++)
	{
		if (abs->personarray[i].p_name == name)
		{
			//找到了用户输入的姓名
			return i;//返回下标编码
		}
	}
	return - 1;//如果遍历结束都未找到，返回-1
}

//3.封装删除联系人的函数
void deleteperson(addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret == -1  未找到
	//ret != -1  找到了
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//找到人了 删除他  逻辑为 将删除后的人员数据向前移动 并将通讯录人数-1  要一个一个往前移
		for (int i = ret; i < abs->p_size; i++)
		{
			//数据前移操作
			abs->personarray[i] = abs->personarray[i + 1];
		}
		abs->p_size--;
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//封装查找联系人的函数
void findperson(addressbooks* abs)
{
	cout << "请输入您要查找的联系人： " << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在与通讯录中
	int ret = isexist(abs, name);
	if (ret != -1)//找到人了
	{
		cout << "姓名 ： " << abs->personarray[ret].p_name << "\t";
		cout << "性别 ： " << abs->personarray[ret].p_sex << "\t";
		cout << "年龄 ： " << abs->personarray[ret].p_age << "\t";
		cout << "电话 ： " << abs->personarray[ret].p_phone << "\t";
		cout << "住址 ： " << abs->personarray[ret].p_addr << endl;
	}
	else//未找到
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

//封装修改联系人的函数
void modifyperson(addressbooks* abs)
{
	cout << "请输入您要修改的联系人： " << endl;
	string name;
	cin >> name;

	int ret = isexist(abs, name);
	if (ret != -1)
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarray[ret].p_name = name;
		//性别
		cout << "请输入性别： " << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		cin >> sex;
		while (true)
		{
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].p_sex = sex;
				break;
			}
			cout << "输入有误请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[ret].p_age = age;
		//联系电话
		cout << "请输入联系电话： " << endl;
		string phone;
		cin >> phone;
		abs->personarray[ret].p_phone = phone;
		//家庭住址
		cout << "请输入家庭住址： " << endl;
		string addr;
		cin >> addr;
		abs->personarray[ret].p_addr = addr;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人： " << endl;
	}
	system("pause");
	system("cls");
}


/封装清空联系人函数    从逻辑上将通讯录中人数制为0
void cleanpeson(addressbooks * abs)
{
	abs->p_size = 0;//将档期记录联系人数量重置为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;
	//按任意键清屏
	system("pause");
	system("cls");
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
	cout << "*****0.推出通讯录*****" << endl;
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
		showperson(&abs);
		break;
	case 3://删除联系人
		//{
//	cout << "请输入删除联系人姓名： " << endl;
//	string name;
//	cin >> name;
//	if (isexist(&abs, name) == -1)//已声明变量不可重复使用
//	{
//		cout << "查无此人" << endl;
//	}
//	else
//	{
//		cout << "找到此人" << endl;
//	}
//}//break上方如果代码过多得使用{}框起来
	deleteperson(&abs);
		break;
	case 4://查找联系人
		findperson(&abs);
		break;
	case 5://修改联系人
		modifyperson(&abs);
		break;
	case 6://清空联系人
		cleanperson（&abs);
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
