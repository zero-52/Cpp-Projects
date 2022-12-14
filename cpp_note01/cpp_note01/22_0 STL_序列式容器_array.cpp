/* array 容器
	array 容器是 C++ 11 标准中新增的序列容器(std::array)
	简单地理解，它就是在 C++ 普通数组的基础上，添加了一些成员函数和全局函数。
	在使用上，它比普通数组更安全，且效率并没有因此变差。

	array容器存储的所有元素位于连续且相邻的内存中。
	和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩。
	所以，在使用该容器的过程无法借由增加或移除元素而改变其大小，它只允许访问或者替换存储的元素

	array容器支持随机访问，array迭代器支持随机访问

	array 容器的大小必须保证能够容纳复制进来的数据，存储字符串的话，还需要在末尾放置一个’\0'做为字符串的结束符。
	strcpy() 在拷贝字符串的同时，会自动在最后添加\0。

	swap()对两个相同数组（类型相同，大小相同）中元素的进行互换

	当两个 array 容器满足大小相同并且保存元素的类型相同时，两个 array 容器可以直接直接做赋值操作，即将一个容器中的元素赋值给另一个容器

	当两个 array 容器满足大小相同并且保存元素的类型相同时，如果其保存的元素也支持比较运算符，就可以用任何比较运算符直接比较两个 array 容器。

	两个容器比较大小的原理，和两个字符串比较大小是一样的:
	即从头开始，逐个取两容器中的元素进行大小比较（根据 ASCII 码表），直到遇到两个不相同的元素，那个元素的值大，则该容器就大。

*/

#include<iostream>
using namespace std;
#include<array>

void arr_test01()
{
	array<int, 4> arr1; //这样创建array容器，各个元素不会做默认初始化，值是不确定的

	arr1[0] = 1;
	arr1[1] = 2;

	for (int i = 0; i < arr1.size(); i++)
	{
		cout << arr1[i] << " ";
	}
	cout << endl;


	array<int, 2> arr2{}; //这样创建各个元素默认初始化为 0
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;


	array<int, 5> arr3{1,2}; //剩下三个元素默认初始化为 0

	/*访问方式*/
	//① arr[2]
	//② arr.at(2)
	//③ get<2>(arr)
	//④ arr.data()//得到首个元素的指针， arr.data()+1 相当于 arr[1]

	//arr.size() //看大小
	//arr.empty() //看是否为空


	/*
	基于范围的for循环（C++11）
		对于一个有范围的集合而言，由程序员来说明循环的范围是多余的，有时候还会容易犯错误。
		因此C++11中引入了基于范围的for循环。
		for循环后的括号由冒号“ ：”分为两部分：
			第一部分是范围内用于迭代的变量
			第二部分则表示被迭代的范围。
			
	对于任何可以使用迭代器的容器，都可以使用基于范围的循环。
			*/
	array<int, 5> arr4{ 1,2,3 };
	for (int e : arr4) //类型可以是引用和指针
	{
		cout << e << " ";
	}
	cout << endl;

}
int main22_0()
{
	arr_test01();
	return 0;
}


/*
array容器成员函数汇总
	
	成员函数		功能
	begin()		返回指向容器中第一个元素的随机访问迭代器。
	end()		返回指向容器最后一个元素之后一个位置的随机访问迭代器，通常和 begin() 结合使用。
	rbegin()	返回指向最后一个元素的随机访问迭代器。
	rend()		返回指向第一个元素之前一个位置的随机访问迭代器。
	cbegin()	和 begin() 功能相同，只不过在其基础上增加了 const 属性，不能用于修改元素。
	cend()		和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	crend()		和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改元素。
	size()		返回容器中当前元素的数量，其值始终等于初始化 array 类的第二个模板参数 N。
	max_size()	返回容器可容纳元素的最大数量，其值始终等于初始化 array 类的第二个模板参数 N。
	empty()		判断容器是否为空，和通过 size()==0 的判断条件功能相同，但其效率可能更快。
	at(n)	返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
	front()	返回容器中第一个元素的直接引用，该函数不适用于空的 array 容器。
	back()	返回容器中最后一个元素的直接应用，该函数同样不适用于空的 array 容器。
	data()	返回一个指向容器首个元素的指针。利用该指针，可实现复制容器中所有元素等类似功能。
	fill(val)	将 val 这个值赋值给容器中的每个元素。
	array1.swap(array2)	交换 array1 和 array2 容器中的所有元素，但前提是它们具有相同的长度和类型。

除此之外，C++ 11 标准库还新增加了 begin() 和 end() 这 2 个函数，和 array 容器包含的 begin() 和 end() 成员函数不同的是，
标准库提供的这 2 个函数的操作对象，既可以是容器，还可以是普通数组。当操作对象是容器时，它和容器包含的 begin() 和 end() 
成员函数的功能完全相同；如果操作对象是普通数组，则 begin() 函数返回的是指向数组第一个元素的指针，同样 end() 返回指向数
组中最后一个元素之后一个位置的指针（注意不是最后一个元素）。

另外，在 <array> 头文件中还重载了 get() 全局函数，该重载函数的功能是访问容器中指定的元素，并返回该元素的引用。

正是由于 array 容器中包含了 at() 这样的成员函数，使得操作元素时比普通数组更安全。
*/