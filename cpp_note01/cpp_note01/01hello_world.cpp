/*
�� C/C++ ��static������
1���ܵ���˵
	��1�������α�����ʱ��static ���εľ�̬�ֲ�����ִֻ�г�ʼ��һ�Σ������ӳ��˾ֲ��������������ڣ�ֱ���������н����Ժ���ͷš�
	��2��static ����ȫ�ֱ�����ʱ�����ȫ�ֱ���ֻ���ڱ��ļ��з��ʣ������������ļ��з��ʣ������� extern �ⲿ����Ҳ�����ԡ�
	��3��static ����һ�������������������ֻ���ڱ��ļ��е��ã����ܱ������ļ����á�
	��4��static ���εı��������ȫ���������ľ�̬������������ȫ�־�̬�����;ֲ���̬����������ȫ�������������ڴ档��ʼ����ʱ���Զ���ʼ��Ϊ 0��
	��5�����뱻�ͷŵ�ʱ�򣬿���ʹ��static���Ρ��������κ����д����ջ�ռ�����顣�����������������ں������ý����ͷſ���ʹ�� static ���Ρ�
	��6�����ǵ����ݰ�ȫ�ԣ���������Ҫʹ��ȫ�ֱ�����ʱ��Ӧ���ȿ���ʹ�� static����

2����̬��������ͨ����
	��̬ȫ�ֱ����������ص㣺
		��1����̬��������ȫ�������������ڴ棬�������潫Ҫ�ᵽ�ľ�̬�ֲ�����;
		��2��δ����ʼ���ľ�̬ȫ�ֱ����ᱻ�����Զ���ʼ��Ϊ0���ں��������������Զ�������ֵ������ģ�����������ʽ��ʼ�������ں������ⱻ�������Զ�����Ҳ�ᱻ��ʼ��Ϊ 0����
		��3����̬ȫ�ֱ������������������ļ����ǿɼ��ģ������ļ�֮���ǲ��ɼ��ġ�

	�ŵ㣺��̬ȫ�ֱ������ܱ������ļ����ã������ļ��п��Զ�����ͬ���ֵı��������ᷢ����ͻ��

3��ȫ�ֱ�����ȫ�־�̬����������
	1��ȫ�ֱ����ǲ���ʽ�� static ���ε�ȫ�ֱ�����ȫ�ֱ���Ĭ�������ⲿ�����Եģ����������������̣���һ���ļ��ڶ����ȫ�ֱ���������һ���ļ��У�ͨ�� extern ȫ�ֱ��������������Ϳ���ʹ��ȫ�ֱ�����
	2��ȫ�־�̬��������ʽ�� static ���ε�ȫ�ֱ������������������˱������ڵ��ļ����������ļ���ʹ�� extern ����Ҳ����ʹ�á�
		
4����̬�ֲ������������ص㣺
	��1���ñ�����ȫ�������������ڴ棻
	��2����̬�ֲ������ڳ���ִ�е��ö����������ʱ���״γ�ʼ�������Ժ�ĺ������ò��ٽ��г�ʼ����
	��3����̬�ֲ�����һ������������ʼ�������û����ʽ��ʼ�����ᱻ�����Զ���ʼ��Ϊ 0��
	��4����ʼ��פ����ȫ����������ֱ���������н���������������Ϊ�ֲ������򣬵��������ĺ������������ʱ������������֮������

	
tip�� 
	����ʲô���͵�ָ�룬ռ���ֽڶ�һ����32λ��ռ4�ֽڣ�64λ��ռ8�ֽ�
	cout << sizeof(int*) << endl;  //�鿴
*/


#include <iostream>  //���������������ͷ�ļ�
using namespace std;  //ʹ�ñ�׼�����ռ�

// ����ע�� //

// ����ע�� /* */

#define DAY		7

//ѧ���ṹ�嶨��
struct student
{
	//��Ա�б�
	string name;  //����
	int age;      //����
	int score;    //����
};

//��ʦ�ṹ�嶨��
struct teacher
{
	//��Ա�б�
	int id; //ְ�����
	string name;  //��ʦ����
	int age;   //��ʦ����
	struct student stu; //�ӽṹ�� ѧ��
};

//ֵ���ݣ��ββ�������ʵ��
void printStudent(struct student stu)
{
	stu.age = 28;
	cout << "�Ӻ����� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;
}

//��ַ���ݣ��β�������ʵ��
void printStudent2(struct student* stu)
{
	stu->age = 28;
	cout << "�Ӻ����� ������" << stu->name << " ���䣺 " << stu->age << " ������" << stu->score << endl;
}

//��ַ���� + const
void printStudent3(const struct student* stu)
{
	//stu->age = 28; // ��������Ϊ������const�����βΣ�һ���޸ľͻᱨ������ֹ����������������ĳ�Աֵ���޸ģ���ֻ����������д��
	cout << "const�����β� ������" << stu->name << " ���䣺 " << stu->age << " ������" << stu->score << endl;
}


//��̬����ֻ��ʼ��һ�Σ������ٵ��ú���Ҳ���ᱻ���³�ʼ��
void static_test()
{
	static int s_test = 10;
	s_test += 5;
	cout << "��̬����ֻ��ʼ��һ�Σ������ٵ��ú���Ҳ���ᱻ���³�ʼ�� s_test = " << s_test << endl;
}

//һ����Ŀֻ����һ��main����
int main1()
{
	/* ��� */
	cout << "hello world" << endl;  //endl�� end line �ǻ��е���˼
	cout << "hello C++\n";			//Ҳ������ \n ��ʾ����
	cout << "hello";
	
	/* ���� */
	// C++�ڴ�������ʱ�����������һ����ʼֵ������ᱨ��
	int a = 10;  
	cout << "a = " << a << endl;


	/* ���������ڼ�¼�����в��ɸ��ĵ����� */
	cout << "һ���У�" << DAY << "��" << endl;  //�곣��
	const int month = 30;				// const �������� ���εĳ���
	cout << "һ���У�" << month << "��" << endl;
	//DAY = 8;  //���󣬲��ܶԺ곣����ֵ
	//month = 28;  //���󣬲��ܶ� const ����ĳ������и�ֵ
	
	/* ���ͣ�short ��int ��long�� long long */

	/* ������ */
	float f1 = 3.14f;  //�ڸ�float��������ֵʱ�����ڳ�ֵ�����Сдf�������Ǵ�Ĭ�ϵ�doubleת��Ϊfloat��������һ��ת��
	cout << "f1 = " << f1 << endl;
	double d1 = 3.14;
	cout << "d1 = " << d1 << endl;  //���۵�����˫���ȣ��ںڴ������Ĭ�����ֻ��ʾ6λ��Ч����

	cout << "float ռ���ڴ�ռ�Ϊ��sizeof(float) = " << sizeof(float) << endl;
	cout << "double ռ���ڴ�ռ�Ϊ��sizeof(double) = " << sizeof(double) << endl;

	/* ��ѧ������ */
	float f2 = 3e2;  //3*10^2
	float f3 = 3e-2;  //3*10^(-2)
	cout << "f2 = " << f2 << endl;
	cout << "f3 = " << f3 << endl;


	/* �ַ��� ���ַ��ͱ��������ǰ��ַ������ŵ��ڴ��д洢�����ǽ���Ӧ��ASCII������뵽�洢��Ԫ��a-97; A-65 */
	char ch = 'a';  //�ַ��ͱ����ǵ����ţ��ҵ�������ֻ����һ���ַ�
	cout << "����һ���ַ��ͱ�����" << ch << endl;
	cout << ch << " ��Ӧ��ASCII��Ϊ��" << int(ch) << endl;


	/* ת���ַ� */
	cout << "\\" << endl;
	cout << "\n" << endl;
	cout << "aa\tHello" << endl; 
	cout << "aaa\tHello" << endl; 
	cout << "aaaa\tHello" << endl;


	/* C����ַ������壺char strName[];  �� char str1[] = "hello world" */
	char str_C[] = "hello world!";
	cout << "C����ַ������� " << str_C << endl;

	/* C++����ַ������壺string �ַ�����;  �� string str2 = "hello world" */
	string str_Cplus = "hello world!";  //��Ҫ#include <string>��vs2019�Ժ�İ汾�Ѿ�Ĭ������
	cout << "C++����ַ������� " << str_Cplus << endl;
	

	/* bool���� */
	bool flag1 = true;
	cout << "bool: true = " << flag1 << endl;  // 1

	bool flag2 = false;
	cout << "bool: false = " << flag2 << endl;  //0


	int my1 = 10, my2 = 20, my3 = 30;
	my3 = my2 = my1;  //��ֵ��������
	cout << my3 << "\t" << my2 << "\t" << my1 << endl; //10 10 10


	/* �������� */

	//��������
	int aaa = 0;  //�ȶ���������ڽ�������
	cout << "���������ͱ�����" << endl;
	cin >> aaa;
	cout << "���ͱ��� a = " << aaa << endl;

	//����������
	double d = 0;
	cout << "�����븡���ͱ�����" << endl;
	cin >> d;
	cout << "�����ͱ��� d = " << d << endl;

	/*	+	-	*	/	%  �Ӽ��˳�ȡ��
	*	==  !=  >  <  >=  <=  �Ƚ������
	*	&&  ||  !    �߼������
	*/

	//���õ���
	int a1 = 10;
	a1++; //�ȼ���a = a + 1
	cout << a1 << endl; // 11

	//ǰ�õ���
	int b1 = 10;
	++b1;
	cout << b1 << endl; // 11

	//����
	//ǰ�õ����ȶԱ�������++���ټ������ʽ
	int a2 = 10;
	int b2 = ++a2 * 10;
	cout << a2 << endl; // 11
	cout << b2 << endl;  // 110

	//���õ����ȼ������ʽ����Ա�������++
	int a3 = 10;
	int b3 = a3++ * 10;
	cout << a3 << endl; // 11
	cout << b3 << endl;  //100

	/* ָ�룬��ָ�롢Ұָ�� */

	/* const����ָ�룺����ָ�� �� ָ�볣�� �� ������ָ�������γ��� */
	int aa = 10;
	int bb = 10;

	//����ָ�룺const���ε���ָ�룬ָ��ָ����Ըģ�ָ��ָ���ֵ�����Ը���
	const int* p1 = &aa;
	p1 = &bb; //��ȷ
	//*p1 = 100;  ����


	//ָ�볣����const���ε��ǳ�����ָ��ָ�򲻿��Ըģ�ָ��ָ���ֵ���Ը���
	int* const p2 = &aa;
	//p2 = &bb; //����
	*p2 = 100; //��ȷ

	//const������ָ�������γ���
	const int* const p3 = &aa;
	//p3 = &bb; //����
	//*p3 = 100; //����


	/* �ṹ�壺�Զ����������ͣ�һ���������͵ļ��� 
		�﷨��
			struct �ṹ���� { �ṹ���Ա�б� }��

		ͨ���ṹ�崴�������ķ�ʽ�����֣�
			struct �ṹ���� ������
			struct �ṹ���� ������ = { ��Ա1ֵ �� ��Ա2ֵ...}
			����ṹ��ʱ˳�㴴������
	*/

	/* �ṹ�����飺struct �ṹ���� ������[Ԫ�ظ���] = { {} , {} , ... {} } 
	* ���ȶ���� student �ṹ��
		struct student arr[3]=
		{
			{"����",18,80 },
			{"����",19,60 },
			{"����",20,70 }
		};

		cout << arr[0].name << arr[1].name <<endl;
	
	*/


	/* �ṹ��ָ�룬�� -> ���� */
	struct student stu1 = { "����",19,60 };
	struct student* pstu1 = &stu1;
	pstu1->name = "ָ������";
	cout << "�ṹ��ָ�� ������" << stu1.name << " ���䣺 " << stu1.age << " ������" << stu1.score << endl;
	cout << "�ṹ��ָ�� ������" << pstu1->name << " ���䣺 " << pstu1->age << " ������" << pstu1->score << endl;


	/* �ṹ��Ƕ�� */
	struct teacher t1;
	t1.id = 10000;
	t1.name = "����";
	t1.age = 40;

	t1.stu.name = "��ͬѧ";
	t1.stu.age = 18;
	t1.stu.score = 100;

	cout << "��ʦ ְ����ţ� " << t1.id << " ������ " << t1.name << " ���䣺 " << t1.age << endl;
	cout << "����ѧԱ ������ " << t1.stu.name << " ���䣺" << t1.stu.age << " ���Է����� " << t1.stu.score << endl;


	/* �ṹ������������ */

	student stu = { "����",18,100 };
	//ֵ����
	printStudent(stu);
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;

	//��ַ���ݣ�ͬ��Ӱ��������������
	printStudent2(&stu);  //�������е��βθ�Ϊָ�룬���Խ�ʡ�ڴ�ռ䣬���Ҳ��Ḵ���µĸ���������
	cout << "�������� ������" << stu.name << " ���䣺 " << stu.age << " ������" << stu.score << endl;


	/* �ṹ��ָ�����βΣ���const���Σ���Ȼ��ָ����Խ�ʡ�ڴ�ռ䣬������ָ�����β�ʱ����ʱ����Ϊ������޸���������Ա��ֵ��ʹ��const��Ϊ����ָ�����βξͿ��Է�ֹ����� */
	student stu2 = { "С��",25,99 };
	printStudent3(&stu2);


	//��̬����ֻ��ʼ��һ�Σ������ٵ��ú���Ҳ���ᱻ���³�ʼ��
	cout << endl << endl;
	static_test();  //15
	static_test(); //20���ڶ��ε���ʱ������Ծ�̬�������³�ʼ��
	//�����ڵľ�̬�����溯��ִ�н�����������Ҳ��֮����������̬����������ʼ����ȫ������ֱ�������������н������ͷš�
	

	system("pause");
	return 0;
}


// ע�͹淶 

/*****************************************************************************
 *  @file     xxx.h
 *  @brief    cpp����ѧϰ�ʼ�
 *
 *  @author   Tod
 *  @version  1.0.1(�汾��)
 *  @email    xxxxxx@xxx.com
 *  @date     2022-08-31
 *****************************************************************************/


 /**
  * @brief ������Ҫ˵��
  * @param t1    ����1
  * @param t2    ����2
  *
  * @return ����˵��
  *     false�� fail
  *     true�� succeed
  */