> 本地环境：Winodws 11 家庭版；
>
> 软件版本：Navicat Premium 16.3.7;
>
> 本地虚拟机版本：Fedora-Workstation-Live-x86_64-40-1.14.iso；
>
> 参考连接：
>
> [1.远程连接Mysql](https://blog.csdn.net/a648119398/article/details/122420906?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522172345980516800178547823%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=172345980516800178547823&biz_id=0&spm=1018.2226.3001.4187)；
>
> 2.[【五种方案全面总结！】navicat远程连接服务器数据库mysql提示错误10060](https://blog.csdn.net/weixin_72499901/article/details/138229485?ops_request_misc=&request_id=&biz_id=102&spm=1018.2226.3001.4187)；
>
> 3.[虚拟机下 Linux|Ubuntu 下mysql mysql8.0的安装以及如何连接外部主机Navicat](https://www.bilibili.com/video/BV1mM411o7rZ/)

# 一、安装MySQL版本

## （1）更新系统：确保系统是最新的

```shell
sudo dnf update
```

## （2）安装 MySQL

Fedora 提供了 MySQL 软件包，你可以直接使用 `dnf` 命令进行安装：

```shell
sudo dnf install @mysql
```

## （3）启动并启用 MySQL 服务

安装完成后，启动 MySQL 服务并设置为开机启动：

```shell
sudo systemctl start mysqld
sudo systemctl enable mysqld
```

## （4）运行安全脚本（可选）

MySQL 提供了一个安全脚本 `mysql_secure_installation`，可以帮助你设置 root 密码并删除一些不必要的测试用户和数据库：

```shell
sudo mysql_secure_installation
```

在自用情况下，为了方便自用，步骤可参考以下选择：

a）脚本执行到提示“Would you like to setup VALIDATE PASSWORD component? Press y|Y for Yes, any other key for No:”

输入除y|Y之外的任意按键，选择不启用密码验证组件。

b）提示“Please set the password for root here. New password: Re-enter new password:”密码这里输入两遍“1”，方便后面测试

c）遇到“Normally, root should only be allowed to connect from 'localhost'. This ensures that someone cannot guess at the root password from the network. Disallow root login remotely? (Press y|Y for Yes, any other key for No) :”

输入除y|Y之外的任意按键，然后 ... skipping. 这被视为"任何其他键"，因此脚本跳过了禁止root远程登录的设置。这意味着root用户仍然可以远程登录MySQL。

d）现在，脚本询问您最后一个问题："Reload privilege tables now? (Press y|Y for Yes, any other key for No) :"，这个选项是关于是否立即重新加载权限表。强烈建议选择重新加载权限表。这将确保您刚才所做的所有更改立即生效。如果不重新加载，您的更改可能要到MySQL重启后才会生效。

## （5）验证 MySQL 是否运行

使用以下命令检查 MySQL 服务状态：

```shell
sudo systemctl status mysqld	// Ubuntu环境下没有最后的字母d
```

## （6）登录 MySQL

可以使用以下命令登录 MySQL 数据库：

```shell
mysql -u root -p
```

输入你在 `mysql_secure_installation` 步骤中设置的 root 用户密码即可登录 MySQL。

# 二、远程连接服务器（虚拟机）中的MySQL

## 1.执行完上述脚本后，保证在普通用户下输入（非root）：

```shell
 mysql -u root -p
```

输入前面设置的MySQL的root密码，和自己root密码不一样，这里输入前面设置的‘1’，出来如下界面

```shell
josiah@192:~$ mysql -uroot -p
Enter password: 
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 13
Server version: 8.0.37 Source distribution

Copyright (c) 2000, 2024, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.
```

## 2.查看mysql服务当前的默认端口

```mysql
use mysql;    ## 选择mysql数据库
select user,host from user;    ## 查看用户访问端口
```

结果如下：

```mysql
mysql> use mysql
Reading table information for completion of table and column names
You can turn off this feature to get a quicker startup with -A

Database changed
mysql> select user,host from user;    ## 查看用户访问端口
+------------------+-----------+
| user             | host      |
+------------------+-----------+
| mysql.infoschema | localhost |
| mysql.session    | localhost |
| mysql.sys        | localhost |
| root             | localhost |
+------------------+-----------+
4 rows in set (0.00 sec)
```

**说明**：root用户默认的是localhost，说明只允许从本地登录mysql服务。而我们要从远程以root用户连接数据库，就必须修改host的值，改为**‘%’**：允许任何ip访问。

## 3.修改host允许任何ip访问

继续在命令面板输入以下指令：

```mysql
update user set host = '%' where user = 'root';
```

看到以下信息说明修改成功：

```mysql
mysql> update user set host = '%' where user = 'root';
Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0
```

这时再使用之前的命令：

```mysql
select user,host from user;    ## 查看用户访问端口
```

会看到：root用户的host已经修改为’%'！

> ！！！注意：修改完成后 还需要刷新一下服务配置，不然修改不会生效，并且第4步会执行失败。

接着在命令面板输入：

```mysql
mysql> FLUSH PRIVILEGES;    ## 刷新服务配置项                                                                         
Query OK, 0 rows affected (0.00 sec)        
```

显示**Query OK**,表示刷新完成。现在就可以配置我们想要远程登录的用户权限了。

## 4.授权root用户可以进行远程登录

输入命令：

```mysql
mysql> ALTER USER 'root'@'%' IDENTIFIED WITH mysql_native_password BY '1'; ## 授权root远程登录 后面的root_pwd代表 录密码
Query OK, 0 rows affected (0.00 sec)
```

输入完之后，看到Query OK，说明执行成功！

```makefile
说明：此命令可以授权任何在mysql数据库user表中的用户以远程登录的方式访问数据库，本例中以'root'作为举例，若想授权其他用户，只需修改'root'的值为指定用户即可，'1'为'root'用户对应的登录密码，可以修改为你想要授权用户的登录密码。
```

## 5.启动本地Navicat连接

打开Navicat客户端，新建mysql连接，输入相关信息：主机（虚拟机ip）、端口（默认3306），用户（root），密码：（我们设置的'1'），连接成功；

若无法连接，请先检查 MySQL 配置；接着检查Linux（服务器）中的防火墙设置，参考上方的参考链接进行设置；

## 6.配置 MySQL 允许远程连接

1. 编辑 MySQL 配置文件：

   ```shell
   sudo nano /etc/mysql/mysql.conf.d/mysqld.cnf		 #vim也可
   ```

2. 查找 `bind-address` 设置： 找到类似 `bind-address = 127.0.0.1` 的配置项，将其修改为

   ```shell
   bind-address = 0.0.0.0
   ```

   - 这允许 MySQL 接受来自任何 IP 地址的连接。

3. **保存并退出**：按 `Ctrl + X` 然后 `Y` 保存更改。

4. 重启 MySQL 服务

   - 修改配置文件后，需要重启 MySQL 服务以应用更改：

   ```shell
   sudo systemctl restart mysql
   ```

5. 检查 3306 端口是否在监听

   - 在终端中使用以下命令确认 MySQL 是否在监听 3306 端口

     ```shell
     sudo netstat -plnt | grep 3306如果输出显示 `0.0.0.0:3306`，说明 MySQL 已监听所有 IP 地址的 3306 端口。否则，需重新检查 `mysqld.cnf` 中的 `bind-address` 设置
     ```

   - 如果输出显示 `0.0.0.0:3306`，说明 MySQL 已监听所有 IP 地址的 3306 端口。否则，需重新检查 `mysqld.cnf` 中的 `bind-address` 设置

6. 检查虚拟机网络设置(可不选，本地上述操作已足够)

   确保您的虚拟机网络设置为 **桥接模式**，以便获得与主机网络相同的 IP 段，从而让其他设备能够访问虚拟机。