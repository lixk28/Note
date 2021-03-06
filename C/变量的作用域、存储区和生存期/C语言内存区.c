//*** 生存期：变量值的存在时间
// 有的变量在程序运行的整个过程都存在
// 有的变量是在调用器所在的函数才临时分配存储单元，而在函数调用之后就释放了 

//*** 变量的存储方式有两种：静态存储方式和动态存储方式
// 静态存储方式指在程序运行期间由系统分配固定的存储空间的方式
// 动态存储方式指在程序运行期间根据需要进行动态的分配存储空间的方式

//*** C程序由下列部分组成：

// (1)代码区：主要存储程序代码指令

// (2)数据区： // <1>常量区：存储常量字符串
               // <2>全局区(静态区)(static)：存储全局变量和静态变量
			   // 初始化的全局变量和静态变量放在一块，未初始化的放在相邻的另一块 
			   // 该区中存储的变量值在程序结束后才释放 
 
// (3)栈区(stack)：主要存储局部变量、自动变量及每次函数调用时所需要保存的信息（返回地址；环境信息）
//                 由编译器自动分配释放 
//                 变量从定义时存在，函数结束时自动释放 

// (4)堆区(heap)：动态存储分配，由程序员分配释放；由malloc，calloc分配的内存区域
//                heap中储存的变量的生存期由free决定，未释放则一直存在 

// C语言中，每一个变量或函数都有两个属性：数据类型和数据的存储类别
// C的存储类别包括4种：自动的(auto)、静态的(static)、寄存器的(register)、外部的(extern)
 
