这次更新扩充一下内容，系统版本是openSUSE 15.6，增加图片，以及安装系统过程，增加了一些常用的软件，另外有些网站的域名也发生了变化，这次一并更新。

**目录**

[1 系统安装篇](#1%20%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85%E7%AF%87)

[1.1 安装VMWare Workstation Pro 17.5](#t0)

[1.2 下载openSUSE 15.6安装镜像](#t1)

[1.3 虚拟机安装openSUSE 15.6](#t2)

[2 系统初始化篇](#2%20%E7%B3%BB%E7%BB%9F%E5%88%9D%E5%A7%8B%E5%8C%96%E7%AF%87)

[2.1 开启SSH远程操作](#t3)

[​2.2 换源与更新](#t4)

[2.3 安装视频解码依赖](#t5)

[2.4 安装防火墙](#t6)

[2.5 安装vim](#t7)

[2.6 安装GCC](#t8)

[2.7 安装make](#t9)

[2.8 安装curl](#t10)

[3 虚拟机安装篇](#t11)

[3.1 安装VMWare Workstation Pro 17.6 For Linux](#t12)

[4 开发环境安装篇](#t13)

[4.1 安装JDK8](#t14)

[4.2 安装Node.js](#t15)

[4.3 安装SVN](#t16)

[4.4 安装Git](#t17)

[4.5 安装Redis](#t18)

[4.6 安装NGINX](#t19)

[4.7 安装MongoDB](#t20)

[4.8 安装Python3](#4.8%20%E5%AE%89%E8%A3%85Python3)

[5 数据库安装篇](#t21)

[5.1 安装MySQL 5.7](#t22)

[5.2 安装PostgreSQL](#t23)

[6 压缩软件安装篇](#7%20%E5%8E%8B%E7%BC%A9%E8%BD%AF%E4%BB%B6%E5%AE%89%E8%A3%85%E7%AF%87)

[6.1 安装7zip](#t24)

[6.2 安装zip](#t25)

[7 浏览器安装篇](#t26)

[7.1 安装Edge浏览器](#t27)

[7.2 安装Chrome](#t28)

[8\. 开发辅助工具安装篇](#t29)

[8.1 安装Another Redis Desktop Manager](#t30)

[8.2 安装SSH工具electerm](#t31)

[8.3 安装FTP/SFTP工具FileZilla](#t32)

[8.4 安装VS Code](#t33)

[9 办公软件安装篇](#t34)

[9.1 安装百度网盘](#t35)

[9.2 安装WPS](#t36)

[9.3 安装微信](#t37)

[9.4 安装QQ](#t38)

[9.5 安装钉钉](#t39)

[9.6 安装迅雷](#t40)

[9.7 安装本地文件搜索软件](#t41)

[9.7.1 Fsearch](#t42)

[9.8 安装PDF阅读器Okular](#t43)

[10 影音软件安装篇](#t44)

[10.1 安装视频/音频播放器](#t45)

[10.1.1 SMPlayer](#t46)

[10.1.2 VLC](#t47)

[10.2 安装网络音乐播放器](#t48)

[10.2.1 QQ音乐](#t49)

[10.3 安装图片软件](#t50)

[10.3.1 nomacs](#t51)

[10.3.2 Gwenview](#t52)

[11 格式软件安装篇](#t53)

[11.1 安装mkvtoolnix](#t54)

[11.2 安装格式转换工具](#t55)

[11.2.1 ffmpeg](#t56)

[11.2.2 Curlew](#t57)

[12 硬件工具安装](#t58)

[12.1 安装烧录工具](#t59)

[12.1.1 balenaEtcher(可烧录Linux，不能烧录Windows)](#t60)

[12.1.2 WoeUSB(可烧录Windows，不能烧录Linux)](#t61)

[13 远程工具安装篇](#t62)

[13.1 安装桌面远程工具ToDesk](#t63)

[13.2 安装内网穿透工具](#t64)

[13.2.1 nattunnel(收费)](#t65)

[13.3 安装异地组网工具](#t66)

[13.3.1 openlink/zerotier(收费)(不能保证一定成功)](#t67)

[13.3.2 蒲公英(收费)](#t68)

[14 模拟器篇](#t69)

[14.1 安卓模拟器](#t70)

* * *

1 [系统安装](https://so.csdn.net/so/search?q=%E7%B3%BB%E7%BB%9F%E5%AE%89%E8%A3%85&spm=1001.2101.3001.7020)篇
-------------------------------------------------------------------------------------------------------

### 1.1 [安装VMWare](https://so.csdn.net/so/search?q=%E5%AE%89%E8%A3%85VMWare&spm=1001.2101.3001.7020) Workstation Pro 17.5

VMWare Workstation Pro 17.5允许个人用户免费用于学习，默认自行安装完成，由于VMWare已经被博通收购，所以下载前需要注册成功博通的账号，并且处于登录状态，下载地址如下

[Please select your identity provider. - Support Portal![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware+Workstation+Pro](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware+Workstation+Pro "Please select your identity provider. - Support Portal")![](https://i-blog.csdnimg.cn/blog_migrate/39ffbad6dc79bbba5b9448169fb38092.png)

![](https://i-blog.csdnimg.cn/blog_migrate/e320f02a53cab3934b43d55a10a4128e.png)

### 1.2 下载openSUSE 15.6安装镜像

官网下载页面地址

[openSUSE Leap - 获取 openSUSE了解并免费下载 openSUSE 发行版![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://get.opensuse.org/zh\_CN/leap](https://get.opensuse.org/zh_CN/leap "openSUSE Leap -        获取 openSUSE")openSUSE 15.6镜像直接下载地址

[https://mirror.nyist.edu.cn/opensuse/distribution/leap/15.6/iso/openSUSE-Leap-15.6-DVD-x86\_64-Build710.3-Media.iso](https://mirror.nyist.edu.cn/opensuse/distribution/leap/15.6/iso/openSUSE-Leap-15.6-DVD-x86_64-Build710.3-Media.iso "https://mirror.nyist.edu.cn/opensuse/distribution/leap/15.6/iso/openSUSE-Leap-15.6-DVD-x86_64-Build710.3-Media.iso")

### 1.3 [虚拟机安装](https://so.csdn.net/so/search?q=%E8%99%9A%E6%8B%9F%E6%9C%BA%E5%AE%89%E8%A3%85&spm=1001.2101.3001.7020)openSUSE 15.6

![](https://i-blog.csdnimg.cn/blog_migrate/769de820a61622783eaeb36ef891d480.png)

![](https://i-blog.csdnimg.cn/blog_migrate/bb6d1e4f250adf06524025f8a7add733.png)

![](https://i-blog.csdnimg.cn/blog_migrate/a10d32b96f74de5041651b19206fe73d.png)

![](https://i-blog.csdnimg.cn/direct/99e4237150844d08b4f03488c777ffa7.png)

![](https://i-blog.csdnimg.cn/direct/b7620b18c545463ab959f8ce38105000.png)

![](https://i-blog.csdnimg.cn/direct/654b52ac234140a1be8d7d79dfa18abf.png)

![](https://i-blog.csdnimg.cn/direct/a0d6fdd633a94ce2b2940d8eebef6fb1.png)

![](https://i-blog.csdnimg.cn/blog_migrate/411abc919ac9793ceb387cf64a522d6c.png)

![](https://i-blog.csdnimg.cn/blog_migrate/614325d3f41519fb0c6ec5406db1cea7.png)

![](https://i-blog.csdnimg.cn/direct/af28d631021a43aa84bfd92fb9db6895.png)

![](https://i-blog.csdnimg.cn/blog_migrate/9e313462ea1cda19e7d3732dbefef27d.png)

![](https://i-blog.csdnimg.cn/direct/dd149e135e5149cc94fd2596bd72ff2d.png)

![](https://i-blog.csdnimg.cn/direct/1490de77b49e48389f62252df416fcef.png)

![](https://i-blog.csdnimg.cn/direct/1705634887b14bd792c720e370c11a04.png)

![](https://i-blog.csdnimg.cn/direct/22f6c498e3dd499386e9e6cdc8b301b7.png)

![](https://i-blog.csdnimg.cn/direct/733cb68ab65742d9a1d31000dfde01f0.png)

![](https://i-blog.csdnimg.cn/direct/157190c023a44d58ae7c35a4dfe7205a.png)

建议把3D减速关掉

![](https://i-blog.csdnimg.cn/direct/df0d2e47fb7b4a048b2c4698284517ee.png)

![](https://i-blog.csdnimg.cn/direct/f06a1721cca745869c5f56c4a2b8fd4a.png)

​开始安装

![](https://i-blog.csdnimg.cn/direct/895c4585b0434f3dad17f2ce6492e681.png)

![](https://i-blog.csdnimg.cn/direct/bfc7e4532a6f402aa0db3e487d476cc3.png)

可选可不选，建议不选

![](https://i-blog.csdnimg.cn/direct/529099ae869e4881b082f8d28ebd53af.png)

我选了GNOME桌面

![](https://i-blog.csdnimg.cn/direct/b9c366510c2b4fdead7539f1d4a5cc57.png)

![](https://i-blog.csdnimg.cn/direct/0788c78328c74c46a50b0e744a6a711b.png)

![](https://i-blog.csdnimg.cn/direct/8485596a01f54961b2985242d64331b6.png)

![](https://i-blog.csdnimg.cn/direct/ca213d4a29bc4bd99e298ec8ab28e82d.png)

![](https://i-blog.csdnimg.cn/direct/211910347cd049e18b0d9a983b72f7ef.png)

![](https://i-blog.csdnimg.cn/direct/37c198ed4a6b4867aa0ea9761cc63e2a.png)

![](https://i-blog.csdnimg.cn/direct/d4a7275c45fd4df99a6eaefc1d7ab89b.png)

安装完成

虚拟机关机，去掉安装介质

![](https://i-blog.csdnimg.cn/direct/ee01bca6a79244c7907f0a8fd0ccc99e.png)

![](https://i-blog.csdnimg.cn/direct/c57c12eb791d4072ba840e83f499deb5.png)

**2 系统初始化篇**
------------

### 2.1 开启SSH远程操作

VMWare Tools在安装openSUSE 15.6时已自动安装

打开终端，输入ip addr查看ip地址

![](https://i-blog.csdnimg.cn/direct/81b20dd2f42c4c84b98442e5634c7911.png)

​开启ssh

```null
sudo systemctl start sshd;sudo systemctl enable sshd;
```

放开22端口，重新加载防火墙

```null
sudo firewall-cmd --permanent --zone=public --add-port=22/tcp;sudo firewall-cmd --reload;
```

使用远程工具，远程成功

![](https://i-blog.csdnimg.cn/direct/c4eef7742e5f4797a3f1c9a1498069c0.png)

![](https://i-blog.csdnimg.cn/direct/6fe1494b933a4a919b8b7c95ce856607.png)

### ​2.2 换源与更新

首先禁用官方源

```null
sudo zypper mr -da;
```

 添加UTSC镜像源

```null
sudo zypper ar -fcg https://mirrors.ustc.edu.cn/opensuse/distribution/leap/\$releasever/repo/oss USTC:OSSsudo zypper ar -fcg https://mirrors.ustc.edu.cn/opensuse/distribution/leap/\$releasever/repo/non-oss USTC:NON-OSSsudo zypper ar -fcg https://mirrors.ustc.edu.cn/opensuse/update/leap/\$releasever/oss USTC:UPDATE-OSSsudo zypper ar -fcg https://mirrors.ustc.edu.cn/opensuse/update/leap/\$releasever/non-oss USTC:UPDATE-NON-OSSsudo zypper ar -fcg https://mirrors.ustc.edu.cn/opensuse/update/leap/\$releasever/sle USTC:UPDATE-SLEsudo zypper ar -fcg https://mirrors.ustc.edu.cn/packman/suse/openSUSE_Leap_\$releasever/ USTC:PACKMAN
```

刷新软件源

```null
sudo zypper ref
```

更新

```null
sudo zypper --non-interactive update
```

### 2.3 安装视频解码依赖

```null
sudo zypper install --allow-vendor-change  ffmpeg lame gstreamer-plugins-bad gstreamer-plugins-ugly gstreamer-plugins-ugly-orig-addon gstreamer-plugins-libav libavdevice56 libavdevice58 libdvdcss2 vlc-codecs
```

### 2.4 安装防火墙

防火墙已自动安装

启用防火墙，开机自启动防火墙

```null
sudo systemctl start firewalld;sudo systemctl enable firewalld;
```

### 2.5 安装vim

vim已自动安装，如果手动安装，执行

```null
sudo zypper --non-interactive install vim;
```

### 2.6 安装GCC

```null
sudo zypper --non-interactive install gcc gcc-c++;
```

### 2.7 安装make

```null
sudo zypper --non-interactive install make;
```

### 2.8 安装curl

curl已自动安装，如果手动安装，执行

```null
sudo zypper --non-interactive install curl;
```

3 虚拟机安装篇
--------

### 3.1 安装VMWare Workstation Pro 17.6 For Linux

用于在Linux中使用无法兼容的Windows应用

下载地址和1中是一样的，就是要选不同的下载项

[Please select your identity provider. - Support Portal![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware+Workstation+Pro](https://support.broadcom.com/group/ecx/productdownloads?subfamily=VMware+Workstation+Pro "Please select your identity provider. - Support Portal")

![](https://i-blog.csdnimg.cn/direct/98f95f2c12a341049125119dac33fa2f.png)

![](https://i-blog.csdnimg.cn/direct/52592517c5cc4e078ae8b1d301748553.png)

安装前VMWare Workstation Pro For Linux务必要先安装gcc

安装依赖

```null
sudo zypper --non-interactive install kernel-default-devel;sudo zypper --non-interactive install kernel-devel kernel-headers;
```

```null
sudo chmod +x VMware-Workstation-Full-17.6.0-24238078.x86_64.bundle;sudo ./VMware-Workstation-Full-17.6.0-24238078.x86_64.bundle;
```

进入控制台，找到VMWare，开始安装，安装过程同Windows

如果碰到

Before you canrun VMware, several modules must be compiled andloaded into the running kernel.

需要重启一下虚拟机，再次打开VMWare，安装install

![](https://i-blog.csdnimg.cn/direct/1c9d0381cb2047cd8d1e4e6901eb39a6.png)

![](https://i-blog.csdnimg.cn/direct/afce5c23b45343379dd2862af935740f.png)

![](https://i-blog.csdnimg.cn/direct/da883526bbdf4a1bb1fe41640b2d61c1.png)

![](https://i-blog.csdnimg.cn/direct/3cb99bc1e7a54a228c935a3db82610b4.png)

![](https://i-blog.csdnimg.cn/direct/d4624fcc52e74f02b22c5038b7ac024e.png)

![](https://i-blog.csdnimg.cn/direct/14afb91da2d446c0a3d2ee7768bf8c65.png)

![](https://i-blog.csdnimg.cn/direct/ac96c66cc19c4916968a41ed32ecf10c.png)

如果在虚拟机中开虚拟机，需要把虚拟机的CPU下几个选项勾上 

![](https://i-blog.csdnimg.cn/direct/04c01630a63e4d7faea5c48ab260189d.png)

![](https://i-blog.csdnimg.cn/direct/ebf4c1076a0646e8a0eb5dd63713cbc4.png)

4 开发环境安装篇
---------

### 4.1 安装JDK8

卸载自带的openjdk11

```null
sudo zypper --non-interactive remove *openjdk*
```

安装jdk8

```null
sudo zypper --non-interactive install java-1_8_0-openjdk;
```

### 4.2 安装Node.js

node14和npm6，版本已不再更新，这里是为了适配ruoyi-cloud，仍使用旧版本

```null
sudo curl -o- https://185.199.108.133/nvm-sh/nvm/v0.40.0/install.sh | bash
```

如果不行，试试

```null
sudo curl -o- https://raw.gitmirror.com/nvm-sh/nvm/v0.40.0/install.sh | bash;
```

如果还不行，补一个文件

[https://pan.baidu.com/s/1g1xY21ZrMcOLTZX9S2WVXA?pwd=f9kd](https://pan.baidu.com/s/1g1xY21ZrMcOLTZX9S2WVXA?pwd=f9kd "https://pan.baidu.com/s/1g1xY21ZrMcOLTZX9S2WVXA?pwd=f9kd")

创建~/.nvm文件夹

```null
mkdir ~/.nvm
```

下载后上传里面的nvm.sh文件和bash\_completion，到~/.nvm文件夹下，执行

```null
vim ~/.bash_profile
```

插入

```null
export NVM_DIR="$HOME/.nvm"[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"[ -s "$NVM_DIR/bash_completion" ] && . "$NVM_DIR/bash_completion"
```

执行

```null
source ~/.bash_profile
```

安装nodejs14

```null
nvm install 14;
```

查看安装情况

![](https://i-blog.csdnimg.cn/direct/a990ffab69514c7aa875ce92ac7b92b5.png)

​配置npm源，阿里云的镜像站域名已经发生变化 

```null
npm config set registry https://registry.npmmirror.com;npm config set registry https://registry.npmjs.org;yarn config set registry https://registry.npmmirror.com -g;yarn config set sass_binary_site https://cdn.npmmirror.com/dist/node-sass -g;npm install -g cnpm -registry=https://registry.npmmirror.com;cnpm install -g @vue/cli@3;
```

### 4.3 安装SVN

```null
sudo zypper --non-interactive install subversion;
```

### 4.4 安装Git

```null
sudo zypper --non-interactive install git;
```

### 4.5 安装Redis

```null
sudo zypper --non-interactive install redis;
```

增加配置文件

```null
sudo cp /etc/redis/default.conf.example /etc/redis/redis.conf
```

```null
sudo vim /etc/redis/redis.conf;
```

如果要远程访问，bind改为0.0.0.0，允许所有IP访问，protected-mode改为no，重启Redis

![](https://i-blog.csdnimg.cn/direct/7eb3d2f6272c4590a3a0b2c59907afe2.png)

创建redis.service

```null
sudo vim /etc/systemd/system/redis.service
```

写入

```null
ExecStart=/usr/sbin/redis-server /etc/redis/redis.confWantedBy=multi-user.target
```

​重启Redis，开机自启动Redis

```null
sudo systemctl daemon-reload;sudo systemctl start redis;sudo systemctl enable redis;
```

防火墙放开6379端口

```null
sudo firewall-cmd --permanent --zone=public --add-port=6379/tcp;sudo firewall-cmd --reload;
```

宿主机测试成功

![](https://i-blog.csdnimg.cn/direct/6653d0664c1647f79a9091507ae69a4a.png)

### 4.6 安装NGINX

```null
sudo zypper --non-interactive install nginx
```

修改配置文件

```null
sudo vim /etc/nginx/nginx.conf
```

![](https://i-blog.csdnimg.cn/direct/903cc2b83caf41a5a1a06edd4e4954d8.png)

重启NGINX，开机自启动NGINX

```null
sudo systemctl enable nginx;sudo systemctl restart nginx;
```

防火墙放开80端口

```null
sudo firewall-cmd --permanent --add-port=80/tcpsudo firewall-cmd --reload;
```

宿主机测试成功，403是因为主页不对，自己加个主页就行

![](https://i-blog.csdnimg.cn/direct/e37ab35ae7cf48fc8f6b3f01b2d8703c.png)

### 4.7 安装MongoDB

创建 MongoDB 的软件源

```null
sudo vim /etc/zypp/repos.d/mongodb-org-7.0.repo
```

```null
baseurl=https://repo.mongodb.org/zypper/suse/15/mongodb-org/7.0/x86_64/gpgkey=https://www.mongodb.org/static/pgp/server-7.0.asc
```

更新软件源，安装

```null
sudo zypper --non-interactive install mongodb-org
```

 启动MongoDB，开机自启动MongoDB

```null
sudo systemctl start mongod;sudo systemctl enable mongod;
```

创建用户

```null
mongosh
```

切换数据集

```null
use admin
```

创建用户

修改配置文件，允许远程访问，bindIp改成0.0.0.0

```null
sudo vim /etc/mongod.conf
```

![](https://i-blog.csdnimg.cn/direct/e1293eef6cf347f18e522323211a121b.png)

```null
sudo systemctl restart mongod;
```

防火墙放开27017端口

```null
sudo firewall-cmd --permanent --zone=public --add-port=27017/tcp;sudo firewall-cmd --reload;
```

宿主机测试成功

![](https://i-blog.csdnimg.cn/direct/7b155f788d6e4323b95c388e8e0973ab.png)

### 4.8 安装Python3

安装Python3和pip3

```null
sudo zypper --non-interactive install python3 python3-pip;
```

查看安装是否成功

加快速度可以换源

```null
pip3 config set global.index-url https://mirrors.aliyun.com/pypi/simple/
```

5 数据库安装篇
--------

### 5.1 安装MySQL 5.7

MySQL 5.7，版本已不再更新，这里是为了适配ruoyi-cloud，仍使用旧版本.

检查是否安装了mariadb，如果没有，就可以安装mysql，如果有，需要先卸载

```null
sudo zypper --non-interactive remove *mysql*sudo zypper --non-interactive remove *mariadb*
```

[MySQL :: Download MySQL Community Server![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://dev.mysql.com/downloads/mysql/](https://dev.mysql.com/downloads/mysql/ "MySQL :: Download MySQL Community Server")

使用SUSE系rpm

下载mysql-community-common，mysql-community-libs，mysql-community-client，mysql-community-server运行以下命令

安装依赖

```null
sudo zypper --non-interactive install libatomic1;sudo zypper --non-interactive install libncurses5;
```

执行安装

```null
sudo rpm -ivh mysql-community-common-5.7.44-1.sles12.x86_64.rpm;sudo rpm -ivh mysql-community-libs-5.7.44-1.sles12.x86_64.rpm;sudo rpm -ivh mysql-community-client-5.7.44-1.sles12.x86_64.rpm;sudo rpm -ivh mysql-community-server-5.7.44-1.sles12.x86_64.rpm;
```

启动MySQL，设置开机启动

```null
sudo systemctl start mysql;sudo systemctl enable mysql;sudo systemctl daemon-reload;
```

查询 root 密码，登录到 mysql

```null
sudo grep 'temporary password' /var/log/mysql/mysqld.log
```

红框中的jMFu>h9kjyel，就是root密码，因为是随机的，每次安装都不一样

![](https://i-blog.csdnimg.cn/direct/45c502bacac0470eb4510101d8d225c9.png)

登录

```null
sudo mysql -uroot -p
```

修改root密码

```null
ALTER USER 'root'@'localhost' IDENTIFIED BY '你自己设定的密码';
```

建议设置符合复杂度等级的密码，如果想设置成类似root的简单密码

**(实际生产中千万不要这么用，非常危险，仅用来测试通信情况)**

降低密码规则级别

```null
set global validate_password_policy=LOW;
```

降低密码长度

```null
set global validate_password_length=1;
```

修改root登录密码为root

```null
ALTER USER 'root'@'localhost' IDENTIFIED BY 'root';
```

允许root用户外部访问MySQL 

**(实际生产中千万不要允许root远程和用户名密码同名，非常危险，仅用来测试通信情况)**

```null
grant all privileges on *.* to 'root'@'%' identified by 'root' with grant option;
```

刷新,退出

防火墙放开3306端口

```null
sudo firewall-cmd --permanent --zone=public --add-port=3306/tcp;sudo firewall-cmd --reload;
```

 宿主机测试成功

![](https://i-blog.csdnimg.cn/direct/9ba1283c75344603b5b81b46c975c3bd.png)

### 5.2 安装PostgreSQL

卸载之前安装的PostgreSQL

```null
sudo zypper --non-interactive remove *postgresql*
```

如果直接安装15，会自动安装最新版本的16

下面使用官方源安装

```null
wget https://download.postgresql.org/pub/repos/zypp/repo/pgdg-sles-15-pg15.repo;
```

```null
sudo cp pgdg-sles-15-pg15.repo /etc/zypp/repos.d/pgdg-sles-15-pg15.repo
```

 更新软件源

```null
sudo zypper ref
```

安装

```null
sudo zypper install postgresql15-server
```

 初始化数据库

```null
sudo postgresql-15-setup initdb
```

设置开机自启动PostgreSQL，启动服务

```null
sudo systemctl enable postgresql-15;sudo systemctl start postgresql-15;
```

给postgres用户设定密码，切换到postgres用户

进入pgsql

```null
psql
```

进入后执行SQL

**(实际生产中千万不要用户名密码同名，非常危险，仅用来测试通信情况)**

```null
ALTER USER postgres WITH PASSWORD 'postgres';
```

 修改配置文件，允许远程访问

```null
sudo vim /var/lib/pgsql/15/data/postgresql.conf
```

 在port = 5432 前加上一行 listen\_addresses = '\*'

![](https://i-blog.csdnimg.cn/direct/d66909bab0f346e6993f5713b04c6518.png)

```null
sudo vim /var/lib/pgsql/15/data/pg_hba.conf
```

 Ipv4认证，地址改为0.0.0.0/0，METHOD改为md5，重启postgresql

![](https://i-blog.csdnimg.cn/direct/09820ab719dc4cb081238426bb4c5e9f.png)

```null
sudo systemctl restart postgresql-15;
```

防火墙放开5432端口

```null
sudo firewall-cmd --permanent --zone=public --add-port=5432/tcp;sudo firewall-cmd --reload;
```

宿主机测试成功

![](https://i-blog.csdnimg.cn/direct/0c44cf59239b4cf5abd640128d929633.png)

6 压缩软件安装篇
---------

### 6.1 安装7zip

```null
sudo zypper --non-interactive install 7zip;
```

sudo yum install -y p7zip p7zip-plugins;

### 6.2 安装zip

```null
sudo zypper --non-interactive install zip unzip;
```

7 浏览器安装篇
--------

### 7.1 安装Edge浏览器

官网下载[Linux版本](https://so.csdn.net/so/search?q=Linux%E7%89%88%E6%9C%AC&spm=1001.2101.3001.7020 "Linux版本")的软件：

[下载 Microsoft Edge下载 Microsoft Edge，畅享快速安全的浏览体验。在您的多台设备上同步密码、收藏夹和集锦。 ![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.microsoft.com/zh-cn/edge/download](https://www.microsoft.com/zh-cn/edge/download "下载 Microsoft Edge")历史版本见

[Index of /yumrepos/edge/Packages/m/![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://packages.microsoft.com/yumrepos/edge/Packages/m/](https://packages.microsoft.com/yumrepos/edge/Packages/m/ "Index of /yumrepos/edge/Packages/m/")openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机，或者使用wget：

```null
wget https://packages.microsoft.com/yumrepos/edge/Packages/m/microsoft-edge-stable-129.0.2792.52-1.x86_64.rpm;
```

安装 

```null
sudo rpm -ivh microsoft-edge-stable-129.0.2792.52-1.x86_64.rpm;
```

### 7.2 安装Chrome

官网下载Linux版本的软件：

[Google Chrome 网络浏览器得益于 Google 智能工具，Chrome 现在更易用、更安全、更快速。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.google.cn/chrome/index.html](https://www.google.cn/chrome/index.html "Google Chrome 网络浏览器")历史版本见

[google-chrome-google-chrome安装包下载\_开源镜像站-阿里云google-chrome-google-chrome安装包是阿里云官方提供的开源镜像免费下载服务，每天下载量过亿，阿里巴巴开源镜像站为包含google-chrome-google-chrome安装包的几百个操作系统镜像和依赖包镜像进行免费CDN加速，更新频率高、稳定安全。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://mirrors.aliyun.com/google-chrome/google-chrome/](https://mirrors.aliyun.com/google-chrome/google-chrome/ "google-chrome-google-chrome安装包下载_开源镜像站-阿里云")

openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机，或者使用wget：

```null
wget https://mirrors.aliyun.com/google-chrome/google-chrome/google-chrome-stable-129.0.6668.70-1.x86_64.rpm;
```

导入公钥，安装

```null
sudo rpm --import https://dl.google.com/linux/linux_signing_key.pub;sudo rpm -ivh google-chrome-stable-129.0.6668.70-1.x86_64.rpm;
```

8\. 开发辅助工具安装篇
-------------

### 8.1 安装Another Redis Desktop Manager

一个开源的Redis可视化工具。GitHub上下载发行版

[Releases · qishibo/AnotherRedisDesktopManager · GitHub🚀🚀🚀A faster, better and more stable Redis desktop manager \[GUI client\], compatible with Linux, Windows, Mac. - Releases · qishibo/AnotherRedisDesktopManager![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://github.com/qishibo/AnotherRedisDesktopManager/releases](https://github.com/qishibo/AnotherRedisDesktopManager/releases "Releases · qishibo/AnotherRedisDesktopManager · GitHub")Linux的软件包格式为AppImage。获取最新AppImage包，然后传入虚拟机，或者使用wget

```null
wget https://github.com/qishibo/AnotherRedisDesktopManager/releases/download/v1.6.6/Another-Redis-Desktop-Manager.1.6.6.AppImage;
```

安装

```null
sudo chmod u+x Another-Redis-Desktop-Manager.1.6.6.AppImage;
```

执行，一定要加--no-sandbox

```null
./Another-Redis-Desktop-Manager.1.6.6.AppImage --no-sandbox
```

![](https://i-blog.csdnimg.cn/direct/d0a8a80b86ad45098b19051da758e120.png)

如果要添加到桌面或者启动栏，按以下步骤

把appimage解压

```null
./Another-Redis-Desktop-Manager.1.6.6.AppImage --appimage-extract
```

进入目录，找到desktop文件，编辑，把Exec后改成Appimage的地址，图片地址改成解压后的图标地址，最好复制到其他目录，Ctrl+S保存

![](https://i-blog.csdnimg.cn/direct/f98d176a379346618c46aab5af4a06bd.png)

![](https://i-blog.csdnimg.cn/direct/4b4256553b324267b58fe3193dfdfc84.png)

​复制到桌面，允许运行

```null
cp another-redis-desktop-manager.desktop ~/桌面/another-redis-desktop-manager.desktop;
```

复制到菜单

```null
sudo cp ~/桌面/another-redis-desktop-manager.desktop /usr/share/applications/AnotherRedisDesktop.desktop;
```

![](https://i-blog.csdnimg.cn/direct/e2bb1fd9e7c54deba1289cba06755f12.png)

### 8.2 安装SSH工具electerm

官网或者GitHub下载Linux版本的软件：

[https://electerm.github.io/electerm/![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://electerm.github.io/electerm/](https://electerm.github.io/electerm/ "https://electerm.github.io/electerm/")[Releases · electerm/electerm · GitHub📻Terminal/ssh/telnet/serialport/RDP/VNC/sftp client(linux, mac, win) - Releases · electerm/electerm![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://github.com/electerm/electerm/releases](https://github.com/electerm/electerm/releases "Releases · electerm/electerm · GitHub")openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机，或者使用wget

```null
wget https://github.com/electerm/electerm/releases/download/v1.40.6/electerm-1.40.6-linux-x86_64.rpm;
```

添加工厂源

```null
sudo zypper ar -fcg 'https://mirrors.ustc.edu.cn/opensuse/tumbleweed/repo/oss' USTC-TUMBLEWEED:OSS;sudo zypper ar -fcg 'https://mirrors.ustc.edu.cn/opensuse/tumbleweed/repo/non-oss' USTC-TUMBLEWEED:NON-OSS;sudo zypper ar -fcg 'https://mirrors.ustc.edu.cn/opensuse/update/tumbleweed' USTC-TUMBLEWEED:UPDATE;
```

安装依赖

```null
sudo zypper --non-interactive install libXScrnSaver libXtst libnotify;sudo zypper addrepo https://download.opensuse.org/repositories/home:anarkrist:libuuid/15.6/home:anarkrist:libuuid.reposudo zypper install libuuid
```

安装

```null
sudo rpm -ivh electerm-1.40.6-linux-x86_64.rpm;
```

![](https://i-blog.csdnimg.cn/direct/0d1bfd60e95c474d868e82c4a507074b.png)

### 8.3 安装FTP/SFTP工具FileZilla

```null
sudo zypper --non-interactive install filezilla;
```

![](https://i-blog.csdnimg.cn/direct/0ded47bd2eb84133b2c8ac47d0f8a1e9.png)

### 8.4 安装VS Code

[Visual Studio Code August 2024Learn what is new in the Visual Studio Code August 2024 Release (1.93)![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://code.visualstudio.com/updates/](https://code.visualstudio.com/updates/ "Visual Studio Code August 2024")安装

```null
sudo rpm -ivh code-1.93.1-1726079369.el8.x86_64.rpm;
```

![](https://i-blog.csdnimg.cn/direct/9c14d9c3e7a549fcb0c383fb092b5421.png)

9 办公软件安装篇
---------

### 9.1 安装百度网盘

官网下载Linux版本的软件：

[百度网盘 客户端下载百度网盘为您提供文件的网络备份、同步和分享服务。空间大、速度快、安全稳固，支持教育网加速，支持手机端。现在注册即有机会享受2T的免费存储空间![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://pan.baidu.com/download](https://pan.baidu.com/download "百度网盘 客户端下载")openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机

安装依赖

```null
sudo zypper --non-interactive install libnotify;sudo zypper --non-interactive install libXtst-devel;
```

安装网盘

```null
sudo rpm -ivh baidunetdisk_4.17.7_x86_64.rpm;
```

如果打不开，需要将

libcrypto.so.10、libcups.so.2、libgssapi\_krb5.so.2、libk5crypto.so.3、libkrb5.so.3、libkrb5support.so.0、libssl.so.10放到/opt/baidunetdisk下面

```null
sudo mv ./so/* /opt/baidunetdisk/
```

具体见[Fedora32 成功运行百度网盘 baidunetdisk 附方法和包【fedora吧】\_百度贴吧](https://tieba.baidu.com/p/6835272793 "Fedora32 成功运行百度网盘 baidunetdisk 附方法和包【fedora吧】_百度贴吧")

缺失so文件这里给一个网盘地址

[https://pan.baidu.com/s/1OUvOaDhPkZMuHe7TwUMCoA?pwd=tw9m](https://pan.baidu.com/s/1OUvOaDhPkZMuHe7TwUMCoA?pwd=tw9m "https://pan.baidu.com/s/1OUvOaDhPkZMuHe7TwUMCoA?pwd=tw9m")

![](https://i-blog.csdnimg.cn/direct/6e7d9d7fb19f4cee8f694259d9bddf90.png)

### 9.2 安装WPS

官网下载Linux版本的软件：

[WPS Office for Linux-支持多版本下载\_WPS官方网站WPS Office For Linux,支持不同格式多版本WPS For Linux版下载，实现多人在线协同办公。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://linux.wps.cn/](https://linux.wps.cn/ "WPS Office for Linux-支持多版本下载_WPS官方网站")openSUSE的软件包格式为rpm。安装：

```null
sudo rpm -ivh wps-office-12.1.0.17885-1.x86_64.rpm;
```

wps有可能会报缺字体,缺的字体如下,双击安装

[https://pan.baidu.com/s/1oAPIXFwEWDLsTJtnQOAhbQ?pwd=ysvw](https://pan.baidu.com/s/1oAPIXFwEWDLsTJtnQOAhbQ?pwd=ysvw "https://pan.baidu.com/s/1oAPIXFwEWDLsTJtnQOAhbQ?pwd=ysvw")

也可以使用命令安装

```null
sudo cp *.ttf /usr/share/fonts/;
```

![](https://i-blog.csdnimg.cn/direct/466100b21fe7481da72b97f724ff6913.png)

### 9.3 安装微信

目前除了Windows虚拟机没有好办法，无解。虚拟机中安装微信不再详细介绍。

### 9.4 安装QQ

官网下载Linux版本的软件：

[QQ Linux版-轻松做自己QQ Linux版 全新升级。沟通更便捷，功能更全面，不一样的QQ为你而来。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://im.qq.com/linuxqq/index.shtml](https://im.qq.com/linuxqq/index.shtml "QQ Linux版-轻松做自己")

openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机

或者使用wget

```null
wget https://dldir1.qq.com/qqfile/qq/QQNT/Linux/QQ_3.2.12_240925_x86_64_01.rpm;
```

安装

```null
sudo rpm -ivh QQ_3.2.12_240925_x86_64_01.rpm;
```

![](https://i-blog.csdnimg.cn/direct/7db96f4534054f15ab7baa8e3a21fa8a.png)

### 9.5 安装钉钉

钉钉Linux版本目前只支持deb格式，github上项目[GitHub - nashaofu/dingtalk: 钉钉桌面版，基于electron和钉钉网页版开发，支持Windows、Linux和macOS](https://github.com/nashaofu/dingtalk "GitHub - nashaofu/dingtalk: 钉钉桌面版，基于electron和钉钉网页版开发，支持Windows、Linux和macOS")

目前已经停止服务，所以依旧是只能用Windows虚拟机。

也有用deb生成rpm文件的，但是这里不再实验，因为已经脱离了一般安装的流程。

### 9.6 安装迅雷

网上依旧没有资源，github上项目[GitHub - Xinkai/XwareDesktop: 桌面化迅雷固件](https://github.com/Xinkai/XwareDesktop "GitHub - Xinkai/XwareDesktop: 桌面化迅雷固件")已经停更进10年，还是只能用Windows虚拟机。

### 9.7 安装本地文件搜索软件

#### 9.7.1 Fsearch

安装snap

```null
sudo zypper addrepo https://download.opensuse.org/repositories/home:ahmedmoselhi2:branches:system:snappy/15.6/home:ahmedmoselhi2:branches:system:snappy.reposudo zypper install snapd
```

启动，开机自启

```null
sudo systemctl start snapdsudo systemctl enable snapd
```

安装

```null
sudo snap install fsearch;
```

终端打开

```null
fsearch
```

![](https://i-blog.csdnimg.cn/direct/954a98f902194b0886024146c1945715.png)

### 9.8 安装PDF阅读器**Okular**

其实目前主流浏览器都支持查看PDF，包括Chrome，Edge，Firefox

```null
sudo zypper install okular;
```

![](https://i-blog.csdnimg.cn/direct/eea3a3b61eaf402fbd93d625b48459b0.png)

10 影音软件安装篇
----------

### 10.1 安装视频/音频播放器

#### 10.1.1 SMPlayer

```null
sudo snap install smplayer
```

终端打开

```null
smplayer
```

![](https://i-blog.csdnimg.cn/direct/75f41141f06a4a979a3ec16cf19f3c6a.png)

![](https://i-blog.csdnimg.cn/direct/b27ee5ef729b4402bc867903dd4b3c8d.png)

#### 10.1.2 VLC

```null
​sudo zypper --non-interactive install vlc;
```

![](https://i-blog.csdnimg.cn/direct/595047495ea7437a929c5f3de38e2093.png)

![](https://i-blog.csdnimg.cn/direct/6a0593b1578c41d3964dd0a790ca6de9.png)

### **10.2 安装网络音乐播放器**

#### 10.2.1 QQ音乐

官网下载QQ音乐AppImage版本

[QQ音乐下载页 - QQ音乐,音乐你的生活!QQ音乐最新版官方下载。最全的高品质正版音乐曲库，任你免费试听下载。最新最热的排行榜、歌单、电台、MV天天推荐，智能音乐搜索、猜你喜欢帮你轻松发现音乐，歌词翻译、免费空间背景音乐，尽在QQ音乐。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://y.qq.com/download/download.html](https://y.qq.com/download/download.html "QQ音乐下载页 - QQ音乐,音乐你的生活!")

![](https://i-blog.csdnimg.cn/direct/63bfd3ebb8ec4918b00bb9220f201bc1.png)

安装

```null
sudo chmod u+x qqmusic-1.1.7.AppImage;
```

执行，一定要加--no-sandbox

```null
./qqmusic-1.1.7.AppImage --no-sandbox
```

![](https://i-blog.csdnimg.cn/direct/f2d8929255a442c2ae11d40315f445f2.png)

 如果要添加到桌面或者启动栏，按以下步骤

把appimage解压

```null
./qqmusic-1.1.7.AppImage --appimage-extract
```

进入目录，找到desktop文件，编辑，把Exec后改成Appimage的地址，图片地址改成解压后的图标地址，最好复制到其他目录，Ctrl+S保存

![](https://i-blog.csdnimg.cn/direct/a340e330c0f343e4a5eee99ab000195a.png)

![](https://i-blog.csdnimg.cn/direct/4a548ef107cb43ee8c28d56f1d1afa03.png)

复制到桌面，允许运行

```null
cp qqmusic.desktop ~/桌面/qqmusic.desktop;
```

复制到菜单

```null
sudo cp ~/桌面/qqmusic.desktop /usr/share/applications/qqmusic.desktop;
```

![](https://i-blog.csdnimg.cn/direct/ab7fe5a7b4cd40308523821af0fe218e.png)

### 10.3 安装图片软件

#### 10.3.1 **nomacs**

```null
​sudo zypper --non-interactive install nomacs;
```

![](https://i-blog.csdnimg.cn/direct/e809fa872c734a6abf507d8e8ce000c4.png)

![](https://i-blog.csdnimg.cn/direct/8d670031be1146bcbe37c90bcc74ca64.png)

#### 10.3.2 **Gwenview**

```null
​sudo zypper --non-interactive install gwenview;
```

![](https://i-blog.csdnimg.cn/direct/dc9ef2ece78346dcb4ec558341ec5796.png)

![](https://i-blog.csdnimg.cn/direct/a4cd9217b3b64517a8a72fb531126570.png)

11 格式软件安装篇
----------

### 11.1 安装mkvtoolnix

```null
​sudo zypper --non-interactive install mkvtoolnix mkvtoolnix-gui;
```

![](https://i-blog.csdnimg.cn/direct/ee739cfdf8d349f68982af9acee62e33.png)

### 11.2 安装格式转换工具

#### 11.2.1 ffmpeg

格式工厂的内核就是ffmpeg，本质格式工厂就是ffmpeg加了一个UI。

```null
sudo zypper install ffmpeg;
```

#### 11.2.2 Curlew

Curlew的内核也是ffmpeg，也相当于ffmpeg加了一个UI，可以认为是Linux下的格式工厂。

安装依赖

```null
sudo zypper --non-interactive install curlew
```

![](https://i-blog.csdnimg.cn/direct/70c013f01140478e863d10f34bfb77a1.png)

12 硬件工具安装
---------

### 12.1 安装烧录工具

#### 12.1.1 balenaEtcher(可烧录Linux，不能烧录Windows)

直接在GitHub上下载，不要用最新的，测试1.18.0能在openSUSE上使用。

[Releases · balena-io/etcher · GitHubFlash OS images to SD cards & USB drives, safely and easily. - Releases · balena-io/etcher![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://github.com/balena-io/etcher/releases](https://github.com/balena-io/etcher/releases "Releases · balena-io/etcher · GitHub")或者使用wget

```null
​wget https://github.com/balena-io/etcher/releases/download/v1.18.0/balena-etcher-1.18.0.x86_64.rpm;
```

安装

```null
sudo rpm -ivh balena-etcher-1.18.0.x86_64.rpm;
```

虚拟机控制器调整到USB3.1 ，并显示所有USB输入设备

![](https://i-blog.csdnimg.cn/direct/68eb807840b74ca6932f9ebbd1ec9880.png)

插入U盘，连接到虚拟机，打开balenaEtcher

![](https://i-blog.csdnimg.cn/direct/a7f2cbed01b847b8a2fd1c952e4fe0c8.png)

上传一个deepin的ISO镜像至虚拟机进行测试

![](https://i-blog.csdnimg.cn/direct/f79885a28fb64e4f8e08ec1f2466a7b0.png)

![](https://i-blog.csdnimg.cn/direct/5dbe603f24744c5f8166074883c26630.png)

烧录完成，退回到宿主机，新建一个虚拟机进行测试，结果没有问题

![](https://i-blog.csdnimg.cn/direct/792d6dd3f0e44d8ebb77480c2e6f2908.png)

烧录Windows镜像会发出警告，经测试确实不能用

#### 12.1.2 WoeUSB(可烧录Windows，不能烧录Linux)

GitHub上下载发行版

[https://github.com/WoeUSB/WoeUSB/releases![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://github.com/WoeUSB/WoeUSB/releases](https://github.com/WoeUSB/WoeUSB/releases "https://github.com/WoeUSB/WoeUSB/releases")下载对应版本的bash文件，或者使用wget

```null
wget https://github.com/WoeUSB/WoeUSB/releases/download/v5.2.4/woeusb-5.2.4.bash;
```

添加权限，下载依赖

```null
sudo chmod +x woeusb-5.2.4.bash;sudo zypper --non-interactive install git zip python3-pip;
```

使用命令查看U盘挂载点

```null
lsblk;
```

![](https://i-blog.csdnimg.cn/direct/e275b4e797704764a32d0fb499d3b9ca.png)

一般 /dev/+NAME为挂载点，我这里为/dev/sda

获取Windows ISO文件路径，我这里为~/softwares/ISO/SW\_DVD9\_WIN\_ENT\_LTSC\_2021\_32BIT\_ChnSimp\_MLF\_X22-84401.ISO

卸载U盘

格式化磁盘

```null
sudo mkfs.vfat -F 32 -I /dev/sda;
```

烧录前准备

安装依赖

```null
sudo zypper --non-interactive install wimlib*;sudo zypper install ntfs-3g* ntfsprogs;
```

```null
wget https://download.opensuse.org/repositories/home:/dirkmueller:/Factory/standard/src/wimlib-1.14.4-26.1.src.rpm;sudo rpm -ivh wimlib-1.14.4-26.1.src.rpm;wget https://download.opensuse.org/repositories/openSUSE:/Factory/standard/x86_64/wimtools-1.14.4-1.2.x86_64.rpm;sudo rpm -ivh wimtools-1.14.4-1.2.x86_64.rpm;
```

执行烧录命令

```null
sudo ./woeusb-5.2.4.bash --device ISO文件路径 U盘路径;sudo ./woeusb-5.2.4.bash --device ~/softwares/ISO/SW_DVD9_WIN_ENT_LTSC_2021_32BIT_ChnSimp_MLF_X22-84401.ISO /dev/sda;
```

![](https://i-blog.csdnimg.cn/direct/2aa62c4c5ea6407aa207d49e30c9ab09.png)

烧录完成，退回到宿主机，新建一个虚拟机进行测试，结果没有问题

![](https://i-blog.csdnimg.cn/direct/0d851352d3074ac187a5465ba18b62a4.png)

测试烧录Linux，发现正常使用有问题，因此建议烧录Linux用balenaEtcher

13 远程工具安装篇
----------

### 13.1 安装桌面远程工具ToDesk

官网下载Linux版本的软件：

[ToDesk远程桌面软件-免费安全流畅的远程连接电脑手机ToDesk远程控制软件是一款稳定流畅的远程控制电脑手机连接软件,可远程桌面办公,远程协助运维.采用端对端加密,让每一次远程访问都安全可靠。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.todesk.com/linux.html](https://www.todesk.com/linux.html "ToDesk远程桌面软件-免费安全流畅的远程连接电脑手机")

openSUSE的软件包格式为rpm。获取最新rpm包，然后传入虚拟机

安装依赖

```null
sudo zypper  --non-interactive install libappindicator3-1
```

安装

```null
sudo rpm -ivh todesk-v4.7.2.0-x86_64.rpm;
```

![](https://i-blog.csdnimg.cn/direct/d596d90376d54532b7cc924d9813e8f6.png)

### 13.2 安装内网穿透工具

#### 13.2.1 nattunnel(收费)

量子互联网站注册，按产品缴费，注册缴费过程官网自行查看

[量子互联 – 内网映射 内网穿透 内外网互联工作站 远程异地组网网关量子互联提供各种网络解决方案,提供内网穿透,异地组网,动态域名,智能路由器多种网络产品![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.uulap.com/](https://www.uulap.com/ "量子互联 – 内网映射 内网穿透 内外网互联工作站 远程异地组网网关")下载nattunnel客户端

[NATTUNNEL 内网穿透 – 量子互联![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.uulap.com/nattunnel#download](https://www.uulap.com/nattunnel#download "NATTUNNEL 内网穿透 – 量子互联")

![](https://i-blog.csdnimg.cn/direct/5d9bb1289d354e79b3c96536ffd04c9f.png)

或者使用wget

```null
wget https://www.uulap.com/download/nattunnel.linux.amd64/nattunnel;
```

添加权限

```null
sudo chmod +x nattunnel;
```

启动内网穿透

```null
sudo nohup ./nattunnel -t<网络TOKEN> &
```

![](https://i-blog.csdnimg.cn/direct/5d17964cec8b40acab15e287c91ea293.png)

连接成功

![](https://i-blog.csdnimg.cn/direct/19adf62c9ef4435f88075c3899587377.png)

### 13.3 安装异地组网工具

#### 13.3.1 openlink/zerotier(收费)(不能保证一定成功)

量子互联网站注册，按产品缴费，注册缴费过程官网自行查看

[量子互联 – 内网映射 内网穿透 内外网互联工作站 远程异地组网网关量子互联提供各种网络解决方案,提供内网穿透,异地组网,动态域名,智能路由器多种网络产品![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://www.uulap.com/](https://www.uulap.com/ "量子互联 – 内网映射 内网穿透 内外网互联工作站 远程异地组网网关")进入网站下载合适的rpm

[https://download.zerotier.com/redhat/fc/40/![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://download.zerotier.com/redhat/fc/40/](https://download.zerotier.com/redhat/fc/40/ "https://download.zerotier.com/redhat/fc/40/")或者使用wegt

```null
wget https://download.zerotier.com/redhat/fc/40/zerotier-one-1.14.1-1.fc40.x86_64.rpm;
```

安装

```null
sudo rpm -ivh zerotier-one-1.14.1-1.fc40.x86_64.rpm;
```

启动

```null
sudo zerotier-one -d;
```

加入网络

```null
sudo zerotier-cli join 网络ID;
```

网络ID

![](https://i-blog.csdnimg.cn/direct/894ed564786f45a9a1dd99c439fa5680.png)

查看状态

```null
sudo zerotier-cli listnetworks;
```

如果是虚拟机，不能保证一定成功。

#### 13.3.2 蒲公英(收费)

官网下载

[贝锐蒲公英软件客户端最新版官方下载，蒲公英联机组网平台软件下载 - 贝锐蒲公英官网贝锐蒲公英官网为你提供蒲公英快速联机组网软件安卓版，IOS版，windows版，macOS版，Linux/树莓派版，Docker版本的最新客户端软件下载。贝锐蒲公英路由器是一款采用云虚拟局域网技术实现sd-wan智能组网的企业工业路由器,具有视频监控功能。无需公网IP，2台或多台使用，能将异地局域网通过贝锐蒲公英快速组建虚拟局域网，共享平台资源。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://pgy.oray.com/download](https://pgy.oray.com/download "贝锐蒲公英软件客户端最新版官方下载，蒲公英联机组网平台软件下载 - 贝锐蒲公英官网")或者使用wget

```null
wget https://pgy.oray.com/softwares/153/download/2156/PgyVisitor_6.2.0_x86_64.rpm;
```

安装

```null
sudo rpm -ivh PgyVisitor_6.2.0_x86_64.rpm;
```

登录

```null
sudo pgyvisitor login;
```

![](https://i-blog.csdnimg.cn/direct/3189a073ef9a477db5b3f6dd77d159bf.png)

![](https://i-blog.csdnimg.cn/direct/9d33c80e9e4a4de98436b4d21f7d351d.png)

14 模拟器篇
-------

### 14.1 安卓模拟器

1\. 用Windows虚拟机

2\. 用Andriod Studio虚拟出安卓设备，然后用adb安装apk

第1种方法，兼容性较好，不过注意在Linux虚拟机中，再开Windows虚拟机，再开安卓模拟器，主流模拟器大概率会卡VT，因此不建议这么用，宿主机最好就是Linux系统，还有希望能成功。

第2种方法，有些apk会不兼容闪退，也可能是这些apk检测到了开发环境主动退出，但是大部分主流apk，还是没啥问题的，但是运行速度不算快，能用，下面详细介绍第2种。

首先确保要安装了JDK，Android Studio需要JVM启动

打开官网页面，下载Linux版Android Studio，传入Linux虚拟机

[下载 Android Studio 和应用工具 - Android 开发者  |  Android DevelopersAndroid Studio 提供了一些应用构建器以及一个已针对 Android 应用进行优化的集成式开发环境 (IDE)。立即下载 Android Studio。![](https://csdnimg.cn/release/blog_editor_html/release2.3.7/ckeditor/plugins/CsdnLink/icons/icon-default.png?t=O83A)
https://developer.android.google.cn/studio?hl=zh-cn](https://developer.android.google.cn/studio?hl=zh-cn "下载 Android Studio 和应用工具 - Android 开发者  |  Android Developers")

![](https://i-blog.csdnimg.cn/direct/282d91580c5548ffb9ce28dadaeef23b.png)

安装依赖

```null
sudo zypper install zlib-devel-* libncurses* bzip2 lbzip2

```

解压，进入 

```null
tar -zxvf android-studio-2024.1.1.11-linux.tar.gz;
```

设置代理，mirrors.neusoft.edu.cn

![](https://i-blog.csdnimg.cn/direct/b9278037a6d64e84813515c44b761c1b.png)

![](https://i-blog.csdnimg.cn/direct/89a30d0ac1184f63bc9e9e517134571e.png)

![](https://i-blog.csdnimg.cn/direct/595b1b16d6874d778f22de6040b0c287.png)

![](https://i-blog.csdnimg.cn/direct/bcb75f7475b4422bbbb922a9c99ccdbe.png)

![](https://i-blog.csdnimg.cn/direct/57e2c184be6a4318917b1ed179b7fb57.png)

![](https://i-blog.csdnimg.cn/direct/ff6d44d3a4c14111aa29a08be9cc3805.png)

点击取消，因为代理还没用生效，下载不下来

选择SDK Manager

![](https://i-blog.csdnimg.cn/direct/733099dd605e4118ba4c1e11540a296c.png)

![](https://i-blog.csdnimg.cn/direct/3c012fab71af47539ffbf60cd446fe49.png)

![](https://i-blog.csdnimg.cn/direct/9e6ef67496144fabbf657d980bccf538.png)

![](https://i-blog.csdnimg.cn/direct/91e3c02d0b3e49cfbf5c5c71e50a7a7b.png)

![](https://i-blog.csdnimg.cn/direct/5a0d3ea6e9034149a5a6ebf33e3ae05e.png)

![](https://i-blog.csdnimg.cn/direct/726abbc389eb4a278c26953860f32ef2.png)

![](https://i-blog.csdnimg.cn/direct/6a2067cc97ab4f77a4ec3caddb52cf5b.png)

我这边创建了一个Pixel 5，Android版本为12的虚拟设备

![](https://i-blog.csdnimg.cn/direct/311f82733d3b4eb4aa7139f8aa087ba0.png)

找到Android SDK的地址，我这里是/home/user/Android/Sdk，然后找到模拟器路径，开启模拟器

```null
cd /home/user/Android/Sdk/emulator;./emulator @Pixel_5_API_31;
```

![](https://i-blog.csdnimg.cn/direct/f0b8a50ec44b422f8fed24f77d9e2d53.png)

进入platform-tool目录，如果没有修改SDK地址，默认是~/Android/Sdk/platform-tools

```null
cd ~/Android/Sdk/platform-tools;
```

下载好apk，传入目录，执行

```null
./adb install xxx.apk
```

我这里下载了淘宝和京东apk，并且改了名字

![](https://i-blog.csdnimg.cn/direct/fcf4d1c940ed4a728d48af83c5fefb28.png)

```null
./adb install taobao.apk;
```

![](https://i-blog.csdnimg.cn/direct/40e00fa998684d0ea7291dbefef59877.png)

![](https://i-blog.csdnimg.cn/direct/4140529b67a04d90bbb29e71b847fb1f.png)

京东正常，淘宝闪退，所以说虚拟设备也要看运气和兼容性，如果非要更好的兼容性，只能使用第1种方式。