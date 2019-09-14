### 爬虫

#### BeautiSoup 解析HTML文档

``` python
#导入所需要的包
import  requests
from bs4 import BeautifulSoup 
import lxml

#待解析的文本
html_doc='''<html><head><title>The Dormouse's story</title></head>
<body>
<p class="title"><b>The Dormouse's story</b></p>
<p class="story">Once upon a time there were three little sisters; and their names were
<a href="http://example.com/elsie" class="sister" id="link1">Elsie</a>,
<a href="http://example.com/lacie" class="sister" id="link2">Lacie</a> and
<a href="http://example.com/tillie" class="sister" id="link3">Tillie</a>;
and they lived at the bottom of a well.</p>
<p class="story">...</p>'''

#创建BeautifulSoup对象
bs = BeautifulSoup(html_doc,'lxml')
print(bs.prettify())

#Tag

#输出tag里第一个 a 标签
print(bs.a)
print(type(bs.a))
#name输出标签名
print(bs.a.name) 
#tag 里的属性操作与字典操作一致
print(bs.p.attrs)
print(bs.p['class'])
print(bs.p.get('class'))
bs.p['class']='newclass'
print(bs.p)
del bs.p['class']
print(bs.p)

# print(bs.title)

#NavigableString对象,标签字符串内容
print(bs.p.string)
print(type(bs.p.string))
#字符串不能被编辑，但是可以被替换
bs.p.string.replace_with("<!--The dormouse's story-->")
print(bs.p.string)

#comment 注释 （有时候需要抛弃注释）
bs=BeautifulSoup(html_doc,'lxml')
print(bs.p.string)
print(type(bs.p.string))
```

#### 遍历文档树

```python
'''
遍历文档树
'''
#1.获取直接子结点
soup=BeautifulSoup(html_doc,'lxml')
print(soup.head.contents) #标签的直接子节点会以列表形式返回
print(soup.head.contents[0]
      
#2.使用children 返回一个可迭代对象
print(soup.head.children)
for item in soup.head.children:
    print(item)
      
#3.获取父结点 parent
print(soup.title.parent)
```

#### 搜索文档树

```python
'''
搜索文档树 find_all()
'''

#1. name 参数 标签签名
soup=BeautifulSoup(html_doc,'lxml')
# A 传字符串
print(soup.find_all('p'))
# B 正则表达式
import re
#匹配以 'b' 开头的字符串
print(soup.find_all(re.compile('^b')))
# C 传列表
print(soup.find_all(['a','b']))
# D 传True
print('__________')
print(soup.find_all(True))

#2. keyword参数
print('=======')
print('first',soup.find_all(id='link1'))
print('second',soup.find_all(class_='sister')) #class 加 '_'才能用
print('third',soup.find_all(href=re.compile('elsie')))

#3.搭配使用
print('ok',soup.find_all('a',class_='sister'))

#4.attrs参数
attrs = {'data-foo':'value'}
print(soup.find_all(attrs=attrs))
#limit限制返回标签数量
print(soup.find_all('a',limit=2))

#5 .text参数
print(soup.find_all(text="The Dormouse's story"))

#6. recursive 参数 是否递归 FALSE只返回直接子节点
print(soup.find_all('head',recursive=False))
```

#### 二次解析

