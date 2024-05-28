#include <stdio.h>
#include <string.h>
//有一串字符：" i am from nanjing"，编码实现输出 "nanjing from am i"

void Exchange(char *str,int len)//字符串逆序显示函数
{
    for(int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 -i];
        str[len - 1 - i] = temp;
    }
}

void Exchange2(char *str, int len)
{
    int size = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            printf("%s\n",str + i - size);
            Exchange(str + i - size,size);//字符串单个单词每个开始逆序
            size = 0;
        }
        else
        {
            size ++;//统计每个单词的长度
        }
    }
}

int main()
{
    char str[] = "i am from nanjing";
    Exchange(str,strlen(str));
    Exchange2(str,strlen(str));

    printf("%s\n",str);
    return 0;
}