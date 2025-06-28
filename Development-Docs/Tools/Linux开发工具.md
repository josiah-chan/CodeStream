# 一、linux安装git及使用

## 1、在 Gitee 上创建仓库

1. 登录并创建 Gitee账号。
2. 点击右上角的 `+` 号，选择 `新建仓库`。
3. 输入仓库名称、描述、是否开源等信息。
4. 可以选择是否初始化仓库（对于空仓库，建议不初始化）。
5. 点击 `创建` 按钮完成仓库的创建。

![](https://pic.imgdb.cn/item/664acdf5d9c307b7e93dfea4.jpg)

## 2、本地安装Git及公钥配置

Linux下安装Git，在命令行中输入以下命令：

```shell
sudo apt install git
```

从 Gitee（或其他 Git 托管平台）克隆一个仓库到本地，输入命令get clone ssh协议下的远程仓库

```shell
git clone git@gitee.com:jazz-kelly/262class.git
```

![](https://pic.imgdb.cn/item/664ad094d9c307b7e9406135.jpg)

提示”无法读取远程仓库，需要确认权限”

![](https://pic.imgdb.cn/item/664ad138d9c307b7e940ff8d.jpg)

下一步开始配置公钥，在终端里输入命令

```shell
ssh-keygen
```

![](https://pic.imgdb.cn/item/664ad193d9c307b7e9415453.jpg)

通过公钥所在路径，使用cat命令查看并复制id_rsa.pub的公钥内容到 Git 仓库上

![](https://pic.imgdb.cn/item/664ad28bd9c307b7e9424214.jpg)

打开Git网页，在设置界面下的安全设置里的SSH公钥里添加，完成后执行上面的get clone命令；

![](https://pic.imgdb.cn/item/664ad33ed9c307b7e942fb81.jpg)

注意此处执行get clone命令，一定要看清本机的文件夹，不要在前一步添加密钥的.ssh/文件夹下执行此命令。选定本地代码工作区，在常用其他文件夹中远程克隆仓库，完成后在本地的会出现Git里面命名的文件夹

![](https://pic.imgdb.cn/item/664ae1d7d9c307b7e974390a.jpg)

## 3、将本地代码提交到Gitee上

先明确下Git的工作流程

![](https://pic.imgdb.cn/item/664acd0ad9c307b7e93d3e21.png)

①在本地代码文件夹下完成代码编写后提交代码，先使用命令 git add <file>

```shell
git add . # 添加所有文件到暂存区
git status # 查看文件当前已在暂缓区域
```

可以当前需要提交的代码文件字体变红色

![](https://pic.imgdb.cn/item/664b3985d9c307b7e9e5c3d0.png)

![](https://pic.imgdb.cn/item/664b3a03d9c307b7e9e626a7.png)

下一步执行命令git commit -m "add a license file" 命令，将代码从暂存区到仓库

![](https://pic.imgdb.cn/item/664b3b13d9c307b7e9e815f3.jpg)

若有上面的提示，按照操作命令添加 user.name 和 user.email

![](https://pic.imgdb.cn/item/664b3bafd9c307b7e9ea96e8.jpg)

user相关名字配置好后，执行 git commit -m 命令，再输入 git push 命令，完成到远程仓库的过程

```shell
git push
```

![](https://pic.imgdb.cn/item/664b3c47d9c307b7e9edbe6b.jpg)

查看Git仓库代码，发现此时代码已经完成上传，并可查看每次改动记录

![](https://pic.imgdb.cn/item/664b3d56d9c307b7e9f11cc6.jpg)

![](https://pic.imgdb.cn/item/664b3d74d9c307b7e9f19511.jpg)

## 4、本地查看代码变动日志及回滚操作

终端输入命令：get log -<数字> 可查看代码改动记录时间及人员，加上数字查看固定记录

![](https://pic.imgdb.cn/item/664b4313d9c307b7e90723c0.jpg)

若发现最新一次的代码提交运行有误，在终端先输入想要回滚的命令

```shell
git reset --hard <日志>
```

完成后执行git push强制命名，让远程仓库中的代码回到修改前状态

```shell
git push
git push -f
```

![](https://pic.imgdb.cn/item/664b445ed9c307b7e90ef2a9.jpg)

至此，远程代码到 Git 仓库的基本流程已完成

# 二、GDB专题

## 一、启动程序调试

### 纲要

- 使用 -g 参数 可以生成可调试的程序
- 使用 gdb 命令，后跟可执行文件路径，启动GDB，并加载程序
- 可以通过 --args 选项程序执行参数

### 生成可调试的程序

- 要生成可调试的程序，需要确保在编译时包涵可调试信息。通常使用编译器的 -g 选项来生成调试信息。

  ```shell
  gcc -g <源文件.c> -o <可执行文件名>
  ```

### 启动程序调试的方式

- 直接启动可执行文件

- 使用 gdb 命令直接启动可执行文件并进入GDB调试模式.

  ```shell
  gdb <可执行文件名>
  ```

- 附加到正在运行的进程

- 如果程序已经在运行，可以使用attach命令将GDB附加到正在运行的进程上

  ```shell
  gdb attach <进程ID>
  ```

## 二、设置断点

### 纲要

- 使用break命令在特定行、函数或地址设置断点。
- 使用条件断点，使用条件表达式来触发断点。
- 使用watch命令设置数据访问断点，当指定内存地址的值发生变化时触发断点。
- 使用save保存和source恢复断点信息。

### 基本断点设置

- 在特定行号上设置断点：break <行号>
- 在函数名处设置断点：break <函数名>
- 在文件名和行号处设置断点：break <文件名>：<行号>

### 查看断点设置信息

```shell
(gdb) info break
```

### 条件断点

在满足特定条件时触发断点，使用 break 命令的条件参数，如：

```shell
break <行号> if <条件表达式>
break <函数名> if <条件表达式>
```

示例：

```shell
(gdb) break 10 if i == 5
```

### 保存和回复断点信息的放方法

- 保存断点信息：将当前所有的断点信息保存到 breakpoints.txt 文件中

  ```shell
  (gdb) save breakpoints breakpoints.txt
  ```

- 恢复断点信息：在下次 GDB 绘话中，使用 source 命令加载保存的断点文件

  ```shell
  (gdb) source breakpoints.txt
  ```

## 三、执行程序

### 纲要

- 使用 run 命令启动程序执行
- 使用 continue 命令继续执行命令
- 使用 step和next ，逐语句执行程序
- 使用 until 继续执行程序直到指定行数
- 使用 finish 结束当前函数
- 使用 stepi / nexti 逐条汇编指令执行程序
- 使用 advance 程序从当前位置移动到指定位置

### run

- run 命令用于启动被调试的程序，它会从头开始执行程序，并根据设置的断点或异常情况暂停执行

  ```shell
  (gdb) run
  ```

### continue

- continue 命令用于继续执行已经暂停的程序。程序可以因为断点、异常或者用户手动暂停而停止。

  ```shell
  (gdb) continue
  ```

### step / next

- step 命令用于逐语句执行程序，并进入任何调用的函数中

  ```shell
  (gdb) step 或者 s
  ```

- next 命令用于逐过程执行程序，跳过函数内部的细节

  ```shell
  (gdb) next 或者 n
  ```

- finish 命令用于执行完当前函数并停止在调用该函数的地方。

  ```shell
  (gdb) finish
  ```

## 四、查看和修改变量

### 4.1 查看变量 

使用 `print` 或 `p` 命令查看变量的值。

- 查看变量的值：

  ```shell
  (gdb) print my_variable
  ```

- 查看数组元素的值：

  ```shell
  (gdb) print arr[0]
  ```

- 查看结构体成员的值：

  ```shell
  (gdb)print my_struct.member
  ```

### 4.2 修改变量

- 使用 `print` 命令的赋值形式修改变量的值。

  ```shell
  (gdb) print my_variable=5
  ```

- 或使用 `set` 命令

  ```shell
  (gdb) set variable my_variable=5
  ```

## 五、回溯和栈堆跟踪

### 5.1 查看调用栈

- 使用 `backtrace` 或 `bt` 命令查看当前线程的调用栈。·使用backtrace或bt命令查看函数调用的堆栈跟踪信息。

  ```shell
  (gdb) backtrace
  ```

- 这会显示当前函数调用栈的所有帧，从最近的一帧开始到最初的调用者。每个帧显示函数名称、文件名、行号和参数信息。

### 5.2 选择栈帧

- 使用frame在帧之间切换

  ```shell
  (gdb) frame <帧号>
  ```

- 命令可以切换到指定的栈帧，查看特定函数调用的局部变量和参数信息。

- 例如，frame2切换到第二个帧，显示该函数调用的上下文信息。

  ```shell
  (gdb) frame 2
  ```

## 六、查看内存

### 6.1 使用 `x` 命令查看内存内容。

```shell
(gdb) x/10b &my_variable  # 查看以字节为单位的10个内存单元
```

### 6.2 使用 watch 命令监视内存地址的变化：

```shell
watch *0x12345678
```

## 七、查看源代码

### 7.1 列出源代码

使用 `list` 或 `l` 命令列出源代码。

```shell
(gdb) list main
```

### 7.2 使用 list <filename>:<linenum> 命令查看指定文件和行号处的源代码：

```shell
(gdb) list main.c:10
```

## 八、控制程序状态

### 8.1 暂停程序

使用 `Ctrl+C` 组合键暂停正在运行的程序。

### 8.2 终止程序

使用 `kill` 命令终止被调试的程序。

```shell
(gdb) kill
```

## 九、调试多线程程序

### 9.1 列出线程

使用 `info threads` 命令列出所有线程。

```shell
(gdb) info threads
```

### 9.2 切换线程

使用 `thread` 命令后跟线程号来切换线程。

```shell
(gdb) thread 2
```

## 十、设置自定义调试环境的方法

### 10.1 使用 `.gdbinit` 文件

在 GDB 启动时，会读取当前目录下的 `.gdbinit` 文件中的命令。可以在该文件中设置自定义的调试环境。

## 十一、条件执行和断点

### 11.1 设置条件断点

使用 `break` 命令后跟条件表达式来设置条件断点。

```shell
(gdb) break myfunc if x > 10
```

## 十二、断点管理

### 12.1 禁用断点

使用 `disable` 命令禁用断点。

```shell
(gdb) disable 1
```

### 12.2 启用断点

使用 `enable` 命令启用断点。

```shell
(gdb) enable 1
```

### 12.3 删除断点

使用 `delete` 命令删除断点。

```shell
(gdb) delete 1
```

## 十三、信号处理

### 13.1 捕获信号

使用 `handle` 命令捕获并处理信号。

```shell
(gdb) handle SIGINT stop
```

Makefile学习总结(技能总结篇)
===================

编译分为四个步骤:

### 【1.预编译】命令: gcc -E main.cpp > main.ii (> 是重定向到main.ii 文件)

![](https://pic2.zhimg.com/v2-71222062e419e89c82bdad887630b29d_b.jpg)

作用:

①展开头文件 
在写有#include <filename>或#include "filename"的文件中，将文件filename展开，通俗来说就是将fiename文件中的代码写入到当前文件中； 
②宏替换 
③去掉注释 
④条件编译 
即对#ifndef #define #endif进行判断检查，也正是在这一步，#ifndef #define #endif的作用体现出来，即防止头文件被多次重复引用

### 【2.编译】gcc -S main.ii 会得到main.s (main.s就是汇编代码)

![](https://pic2.zhimg.com/v2-7bb20e79a63a2ab03fc1b4aad8b46059_b.jpg)

作用:

将代码转成汇编代码，并且在这个步骤中做了两件很重要的工作： 
①编译器在每个文件中保存一个函数地址符表，该表中存储着当前文件内包含的各个函数的地址； 
②因为这步要生成汇编代码，即一条一条的指令，而调用函数的代码会被编译成一条call指令，call指令后面跟的是jmp指令的汇编代码地址，而jmp指令后面跟的才是“被调用的函数编译成汇编代码后的第一条指令”的地址，但是给call指令后面补充上地址的工作是在链接的时候做的事情。

查看一下汇编文件main.s:

![](https://pic1.zhimg.com/v2-d9b4d1fefc16122869d00fe347218aec_b.jpg)

### 【3.汇编】 gcc -c main.s 生成main.o 文件

![](https://pic4.zhimg.com/v2-7c12cf16099fbb76b8f41eeebf6262e3_b.jpg)

作用:

将汇编代码转成机器码。 .o文件就是常见的依赖项

### 【4.链接】

![](https://pic2.zhimg.com/v2-e11a2412d9bc240d043ba1f48fb79cb5_b.jpg)

作用:

编译器将生产的多个.o文件链接到一起生成一个可执行.exe / a.out文件； 
但是在这个过程中，编译器做的一个重要的事情是将每个文件中call指令后面的地址补充上；方式是从当前文件的函数地址符表中开始找，如果没有，继续向别的文件的函数地址符表中找，找到后填补在call指令后面，如果找不到，则链接失败。

### 【Makefile运行逻辑】

![](https://pic4.zhimg.com/v2-545a34b80f7822a51d87d62d703d1607_b.jpg)

同时存在Makefile 和 makefile 的文件。 **优先执行makefile文件**

![](https://pic1.zhimg.com/v2-b6391a8c4180a288d6e91ebdae805b3c_b.jpg)

![](https://pic3.zhimg.com/v2-c1e9658dfe8344a3c9a25d4bd766b8e2_b.jpg)

### 【Makefile基本语法】

Makefile就是将一系列的工作流串在一起自动执行，构成Makefile最基本的要素是**目标、依赖、命令**。也就是为了实现目标需要哪些依赖并执行什么样的命令。

**目标**: 一般是指要编译的目标，也可以是一个动作

**依赖**: 指执行当前目标所要依赖的选项。包括其他目标，某个具体文件或库等，一个目标可以有多个依赖。

**命令**:该目标下要执行的具体命令,可以没有，也可以有多条。

![](https://pic4.zhimg.com/v2-ec1588ce266354c53a77c7e3bd81bedf_b.jpg)

其中，target表示要生成的目标，dependences表示生成target需要的依赖，而command就是生成target要执行什么命令。在格式上，命令所在行行首都有一个<tab> (备注:4个space键不可以：makefile:2: *** missing separator. Stop.)。

目标：

举例1：没有指定目标的时候，默认使用第一个目标

![](https://pic1.zhimg.com/v2-1faedad9a4d6919c643c26de187cdce4_b.jpg)

举例2：如果指定目标，则执行对应的目标。

![](https://pic1.zhimg.com/v2-5c0e4eb739ed207e78aac578470b38d0_b.jpg)

### 【Makefile文件的命名】

Makefile 其实就是一个规范。规范与文件的命令没有直接关系。

方式1：将文件名命令为"Makefile"，然后在Makefile文件所在的目录直接使用make命令就可以自动解析"Makefile"文件的内容。

方式2: 任意命名，比如我们使用一个叫makefile_test的文件来编写Makefile内容。在执行make的时候使用-f参数指定文件名。如下：

make -f makefile_test

### 【makefile的常用选项】

make \[-f file\] \[option\] \[target\]

make 默认从当前目录中寻找makefile、Makefile文件作为make的输入文件

-f FILE, --file=FILE, --makefile=FILE

Read FILE as a makefile.

解释: 可以指定除上述文件名之外的文件作为输入文件。

-n, --just-print, --dry-run, --recon

Don't actually run any commands; just print them.

只输出命令,并不执行。用来调试使用。类似于日志

-s, --silent, --quiet Don't echo commands.

只执行命令，但并不显示具体命令，此处可在命令中用@符抑制命令的输出。

-w, --print-directory Print the current directory.

显示执行前、执行后的路径。

-C DIRECTORY, --directory=DIRECTORY

Change to DIRECTORY before doing anything.

dir 指定makefile所在的目录

### 【makefile的编译流程】

![](https://pic1.zhimg.com/v2-4bdd1b45b478c6aa5bbece63dddefab0_b.jpg)

看一下makefile文件：

![](https://pic1.zhimg.com/v2-e1317c9d8dbbeb7dcbf0290f3448a09c_b.jpg)

make执行结果:

![](https://pic1.zhimg.com/v2-06268a8cd08b368fc78f3ebf4957abec_b.jpg)

修改一下add.c 文件的add(int, int)函数

![](https://pic1.zhimg.com/v2-9fb74da098b5eee84ce2562487941a78_b.jpg)

再make一次

![](https://pic2.zhimg.com/v2-d690cd616d1912bdc647aba48ab4c041_b.jpg)

**目的：节省编译时间。** 

### 【Makefile变量】

Makefile也支持变量，使用上和Shell中的变量很相似，比如：Makefile中变量可以分为三大类：系统变量、系统常量和自定义变量

系统变量

$\* 不包括扩展名的目标文件名称

$@ 表示目标文件的完整名称

$< 表示第一个依赖文件

$? 表示比目标还要新的依赖文件列表 

$^ 表示所有不重复的依赖文件，以空格分隔

$\+ 这个变量很像“$^”，也是所有依赖目标的集合。只是它不去除重复的依赖目标。

$% 仅当目标是归档成员，则该变量表示目标的归档成员名称

举例:

![](https://pic4.zhimg.com/v2-8390353b22c924fa477dd788d73d5bf3_b.jpg)

系统常量 (可以使用make -p命令查看)

AR : 函数库打包程序。默认命令是 ar

AS : 汇编语言编译程序。默认命令是 as

CC : C语言编译程序。默认命令是 cc

CXX : C++语言编译程序。默认命令是 g++

CPP : C程序的预处理器（输出是标准输出设备）。默认命令是 $(CC) –E

RM : 删除文件命令。默认命令是 rm –f

![](https://pic2.zhimg.com/v2-8e34bee3c9b2cac3e1f3484811eaf791_b.jpg)

了解了系统变量之后,我们再对makefile进行一次修改。

![](https://pic2.zhimg.com/v2-195038c7149a6f257f19a1c0ef3dfa51_b.jpg)

2\. 自定义变量

前面我们声明的BUILDDIR就是一个自定义变量，要注意的是，如果声明了一个和默认变量一样的变量就会覆盖默认变量，这也给我们提供了一个改变默认规则的入口。

自定义变量要注意的是赋值方式，在Makefile中有以下几种赋值方式：

= 延迟赋值，在Makefile运行时才会被赋值 (用的是终值，不管变量调用写在赋值前还是赋值后，调用时都是取终值)

:= 立即赋值，立即赋值是在真正运行前就会被赋值 (只受当前行及之前的代码影响，而不会受后面的赋值影响)

?= 空赋值，如果变量没有设置过才会被赋值

+= 追加赋值，可以理解为字符串的加操作

### 【Makefile伪目标】

有些时候，我们希望不生成具体的目标文件，只想执行命令，比如在Linux通过源码安装经常会使用make clean来清除安装产生的额外的中间文件，比如：

test: test.o

gcc -o test test.o

clean:

rm -rf *.o test

按照Makefile的规则clean也是一个目标，但我们不希望生成clean目标文件，就可以使用.PHONY将其声明为伪目标，表示只执行命令，不生成目标文件。例如：

.PHONY: clean install ...

test: test.o

gcc -o test test.o

clean:

rm -rf *.o test

demo一下做个解释:

![](https://pic1.zhimg.com/v2-22b31632e7e5f54fd3191a377f4a22b4_b.jpg)

加上伪文件的结果：

![](https://pic1.zhimg.com/v2-deedbf009fe1ae601e5af581e3b64a6c_b.jpg)

### 【Makefile模式匹配】

在Makefile中模式匹配使用%来实现，表示匹配任意多个非空字符，相当于shell中的*。模式匹配有什么用呢？假如现在有非常多的.c源文件要生成目标.o文件，我们可以像下面这样写：

%.o: %.c

cc -c $^ -o $@

上面的意思是将所有.c文件都经过编译器编译生成.o文件，其中表示的是所有的依赖，在上面的场景中就是当前目录下所有.c文件。而$^表示的是所有的依赖，在上面的场景中就是当前目录下所有.c文件。而表示的是所有的依赖，在上面的场景中就是当前目录下所有.c文件。而$@表示目标文件。也就是%.o所代表的所有文件。可以看到模式匹配可以大幅减少Makefile的代码量。

![](https://pic1.zhimg.com/v2-055ba499381354df38be879dd9934100_b.jpg)

wildcard : 匹配文件。 (使用示例:获取指定目录下所有的.c文件)

patsubst : 模式匹配与替换(使用示例:指定目录下所有的.c文件替换成.o文件)

![](https://pic3.zhimg.com/v2-1592abc444ea53ebf6a200c470b15b36_b.jpg)

当我们有了这个工具之后，就可以对依赖项目进一步更新：

![](https://pic3.zhimg.com/v2-369b25185b5cf3431505f154f2079b16_b.jpg)

### 【Makefile 动态库】 (wins:.dll文件 类uinx:.so文件)

动态链接库: 不会把代码编译到二进制文件中，而是在运行时候才会去加载，所以只需要一个地址。

-fPIC: 产生位置无关的代码.

-shared: 共享.

-l (小写L): 指定动态库.

-I (大写i): 指定头文件目录，默认当前目录.

-L: 手动指定库文件搜索目录, 默认只链接共享目录.

gcc -shared -fPIC SoTest.c -o libSoTest.so

gcc -lSoTest -L./ main.c -o main

提供libSoTest.so和SoTest.h给客户使用。

![](https://pic1.zhimg.com/v2-52095c6fd705f91201fc17731dc89590_b.jpg)

修改makefile的写法：

![](https://pic1.zhimg.com/v2-e4b971831131819389046ba99d877e44_b.jpg)

问题分析:编译时指定了要依赖的动态库，但是运行时，找不到.so文件

解决1: 动态库编译完成之后要发布，否则程序运行时找不到

/etc/ld.so.conf

/etc/ld.so.conf.d/*.conf

/usr/lib unix system resource

/usr/local/lib

![](https://pic2.zhimg.com/v2-44d1f70b45f1bd57c69eeaa1f763d3f9_b.jpg)

![](https://pic2.zhimg.com/v2-4f82326fac719f8ab1e088e756d16ca9_b.jpg)

解决2:运行时手动指定动态库目录

DYLD\_LIBRARY\_PATH=./src_so

export DYLD\_LIBRARY\_PATH

(DYLD\_LIBRARY\_PATH是MAC使用的命令。 linux使用的命令是:LD\_LIBRARY\_PATH)

![](https://pic1.zhimg.com/v2-14a6e9df2ed3feb83363a4c515687eac_b.jpg)

解决3:

-Wl,rpath=$(PATH)

### 【Makefile 静态库】

静态链接库：会把静态库的代码编译到二进制中，当程序编译完成后，该文件可以删除。

缺点： 程序体积过大，并且库中的内容如果有更新，则需要重新编译生成程序。

![](https://pic1.zhimg.com/v2-099ab94dd7daaacddb956a951f6a5f50_b.jpg)

使用动态库和静态库一起的makefile 最后面是这样子的.

![](https://pic3.zhimg.com/v2-4d4e8979848c09d926b3378b8098b01e_b.jpg)

### 【Makefile 公共文件】

![](https://pic1.zhimg.com/v2-11eab5dd29f3a3585b74cf52388efc54_b.jpg)

引用公共头

![](https://pic2.zhimg.com/v2-0707b90864ef8bcd88cdf77e177445e9_b.jpg)

### 【Makefile 中使用shell】

![](https://pic3.zhimg.com/v2-9201cb8074fe67255a3145330a8ec316_b.jpg)

### 【Makefile 条件判断】

ifeq判断是否相等，相等返回true， 不相等返回false.

ifneq判断是否不相等，不相等返回true, 相等返回false.

ifdef判断变量是否存在，存在返回true, 不存在返回false.

ifndef判断变量是否不存在，不存在返回true 存在返回false

![](https://pic2.zhimg.com/v2-ac9bee2ac65dd77f5897cbcbf3340d41_b.jpg)

### 【Makefile 命令行传参】

![](https://pic1.zhimg.com/v2-4c8fcd50f90b6544955e3500984b5ecc_b.jpg)

### 【Makefile 嵌套调用】

![](https://pic1.zhimg.com/v2-0e96bf6cd44c775d4c739f1e3588b0a0_b.jpg)

### 【Makefile 函数】

函数定义 & 调用

![](https://pic2.zhimg.com/v2-431bc4737a11a4134ad7edbef05232e1_b.jpg)

函数传参:

![](https://pic1.zhimg.com/v2-6cb925b54d90446fc0d18d822b4874c4_b.jpg)

### 【Makefile install】

一般功能作用：

1.创建目录，将可执行文件拷贝到指定目录(安装目录)

2.加全局可执行的路径

3.加全局的启停脚本

![](https://pic4.zhimg.com/v2-51369d0cce043cb991ddc2ee63dd9c23_b.jpg)

执行make install 操作

![](https://pic4.zhimg.com/v2-9a01481f9c0510548b67df285b22a55b_b.jpg)

全局可执行demo

![](https://pic2.zhimg.com/v2-e2b3712c49fa2465f3979fdeb95335dd_b.jpg)

查看链接情况

![](https://pic2.zhimg.com/v2-1a51fe108248d595ea038bf30f1ede55_b.jpg)

注： 软连接 和 硬链接的区别。

![](https://pic4.zhimg.com/v2-eff411e82709e823ae4ec1a64eb37707_b.jpg)

ln 的使用语法:

**命令:\`ln \[参数\] \[源文件或目录\] \[目标文件或目录\]\`**

### 【Makefile 加上启停脚本】

![](https://pic3.zhimg.com/v2-18574db5b50dd7c839d6e96fa8990fd6_b.jpg)

![](https://pic1.zhimg.com/v2-ffae818e3897b0c288e6d3c329398f64_b.jpg)

demo一下:

执行makefile

![](https://pic1.zhimg.com/v2-2b09a3f27a2c7556cdbcdf5fc642dd1c_b.jpg)

![](https://pic2.zhimg.com/v2-f400ed5eb214c66955044d66dec4201d_b.jpg)

**Makefile 整个知识点就到这边。**