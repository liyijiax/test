## 文件操作

* 在计算机中文件是怎么保存的
  * 文字在缓存里边，离开记录卡绝对是Unicode数据
  * 磁盘里边是以bytes字节串

* python解释器默认编码
  * python3 utf-8 万国码

  * python2 ASCII 不是utf-8不能直接写汉字,

    需要指定文件编码格式，*# coding:utf-8*

### 文件操作函数

```python
'''
python 内置函数
打开一个文件，返回值为一个文件对象

f = open(filename,mode)
filename:表示文件名或者文件路径
mode：表示文件的模式，是可选参数
f: 文件对象
'''

#读取单行
f= open('test_file1','r',encoding='utf-8') #不添加文件打开模式会乱码，默认值是读文件的模式’r'
print(f.readline())

#读取多行 会把文件读取到内存中，所以只适合读取小文件
f= open('test_file1','r',encoding='utf-8')
# print(f.readlines())
for index,line in enumerate(f.readlines()):
    if index == 4:
        print('-------分割线-------')
        continue
    print(line)

#读取多行，处理大文件的方法
f= open('test_file1','r',encoding='utf-8')
for line in f:  #一行行读取文件，内存中只保留一行
    print(line)

f= open('test_file1','r',encoding='utf-8')
for index,line in enumerate(f):
    print(index)
    print(line)

#a : 追加模式 文件存在接着写
# f = open('test_file1','a',encoding='utf-8') #如果文件不存在，会创建新文件
# f.write('\n这是一首新歌')

#r+ ： 读写模式：
f = open('test_file1','r+',encoding='utf-8')
for i in range(7):
    print(f.readline())
f.write('\n你会唱小星星吗') #追加

#w+ : 写读模式，如果没有创建新文件，有的话覆盖

#ab b:必须传入字节型 (如果文件存在，在文件后追加)
f = open('test_file2','ab')
f.write(bytes('哈哈',encoding='utf-8'))

#wb (如果文件存在，覆盖该文件数据) 用法同ab

#x  如果文件存在报错，如果不存在新建
f= open('test_file2','x',encoding='utf-8')
```

> a+可读可写，追加内容；
>
> r+可读可写，覆盖内容；
>
> w+可读可写，情况内容，但是它的意义是可以边写边读啊，w只能写，不能读。

### 文件截取函数

```python
#函数 truncate() 截取文件，可以清空文件
f = open('test_file2','a',encoding='utf-8')
f.truncate(3) #保留文件前n个字符，其余截断

```

### 同时打开多个文件

```python
#打开两个文件，把第一个文件的内容，写到第二个文件里
#with as

with open('test_file1',encoding='utf-8') as f1,open('test_file2','a',encoding='utf-8') as f2:
    for line in f1.readlines():
        f2.write(line)

#读取第一个文件内容，把的一个文件内容的‘的’改为‘得’
with open('test_file1',encoding='utf-8') as f1,open('test_file2','r+',encoding='utf-8') as f2:
    for line in f1.readlines():
        line=line.replace('的','得')
        print(line)
        f2.write(line)

```

### 表格

```python
#excel 表格
import xlwt

#创建表格
work_book=xlwt.Workbook()
work_sheet = work_book.add_sheet('my_sheet')

#往表格写数据 行，列，数据
work_sheet.write(0,0,label='0.0')
work_sheet.write(0,1,label='0.1')
work_book.save('lyj.xls')
```



### os

```python
'''
os
1.os.getcwd()程序所在目录
2.os.listdir()列出目录下有哪些文件，如果不写path，则默认当前目录
3.os.mkdier()创建目录
4.os.rmdir()删除目录
5.判断是否是目录os.path.isdir()文件
6.目录下所有的文件和目录
'''
import os
print(os.getcwd())
print(os.listdir())
# os.mkdir('test')
# os.rmdir('test')
print(os.path.isdir('test'))
print(os.path.isfile('test_file1'))
all_dir=os.walk('C:\\mypython_e')
for dir in all_dir:
    print(dir)
```













