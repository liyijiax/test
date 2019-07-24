## java

* .java 编译

* .class 类

* class java文件定义 

  * public class 类名{
  * }
  * 类名与文件名相同，区分大小写

* 类中包括：

  * 成员变量（属性）

    * 全局变量 ： 在当前类的所有位置都可以使用
    * 局部变量 ： 离他最近的一对大括号中有效
    * 类里边只能写局部变量和方法

  * 方法（函数）

    * 访问修饰符  返回值类型  方法名（参数列表）{

       														方法体

      ​												}

    * 类中的属性和方法有访问范围

      * private : 私有的，只在当前类中有效

      * public :  公有的，整个项目都可以访问

      * 返回值类型： 

        * 无返回值：void

        * 有返回值：返回值的数据类型， 需要renturn一起使用。

          ​					return 后面的数据类型与返回值类型一致，或者小

  * 不能单独写语句

  * 八种基本（原始）数据类型：

    * 整型：byte short int long
    * 浮点型： float double
    * 字符型： char
    * 布尔值： boolean（true, false)
    * 在栈中直接存的是值
    * int i = 1;

  * 引用类型（类类型）

    * String ArrayList
    * 在栈中存的是引用类型的地址
    * 栈    堆
    * ArrayList list = new ArrayList();
      * 栈里边存的是new ArrayList()的地址

* 包名、类名、变量名(见名知意)：

  * 包名：小写
  * 类名：首字母大写
  * 变量名、方法名：驼峰式，每个单词首字母大写，但第一个小写，常量第一个大写
  * 参数列表（0-n个）：（类型 参数名1， 类型 参数名2，类型 参数名3）

* 选择结构：
  * if (boolean) { }
  * if(){ }else{ }
  * if(){ }else if()...else{}
  * switch() { 
    * case :     break；
    * case :     break;
    * default: 
    * }
* 循环结构：
  * while
  * do ... while
  * for ( int i = 0 ; i < 10 ; i++) {}
    * 执行完方法体再执行 i++
  * 增强for循环
  * 泛型：
    * ArrayList list = new ArrayList（）；任何类型都可以存入集合
    * ArrayList<String> list1 = new ArrayList<String>（）；
    * list1集合中只能加String类型的数据
    * for（泛型类型 s : list1）{}
* String 字符串
  * String s = "abc" ;
  * 字符串拼接不要用String 它每次都创建一个新的
  * 拼接字符串： StringBuffer，StringBuilder
* 数组
  * int[] arr = new int [10];
  * int[] arr1 = {1, 2, 3, 4, 5};
  * 定义时设置了数组的长度， 长度固定不变
  * 数组的索引号从0开始， 索引号最大是长度-1
  * 赋值： arr1[2] = 8；
  * 取值：arr1[2]
* 集合：
  * List：有序可重复的 （ArrayList）
  * Set：无序不可重复 （HashSet）
  * Map： 键值对 key---value （HashMap)
  * 存数据
    * put
    * add
  * 取数据：
    * get
  * 实体类（pojo、entity）：数据库表对应一个类
    * ​	表中的字段（列）是对应类中的属性
  * 这三个都是接口， 要用他们的实现类
* java 三大特性 ：封装， 继承， 多态
  * 封装： 属性私有化， 写属性的getter 和 setter 方法 （首字母小写）
  * 继承： 子类继承父类（一个子类一个父类），父类有多个子类，
    * extends 类是单继承的
    * 继承父类可继承的属性和方法
    * 重写：子类可以重写父类的方法
    * 重载：在同一个类中，同一个功能，需要的参数可能不同
    * 当父类中的某一个方法，无法满足所有的子类（无意义），定义成abstract抽象方法
    * 抽象类：抽象方法必须在抽象类中，抽象类中可以有普通方法，如果父类中有抽象方法，那么子类必须实现父类的抽象方法，或者子类也是一个抽象类
    * public abstract void run() ;
* 接口
  * public interface 接口名{
  *  都是抽象方法
  * 方法的abstract可以省略
  * }
  * implements 实现接口
  * abstract 抽象
* 线程

## jdbc

* 第三方jar包

  1. 加载驱动
     
1. Class.forName("驱动名") ; Driver
   
2. 数据库服务器的ip地址，数据库端口号
  
   数据库名，用户名，密码
  
     ```java
     java.sql.Connection conn = DriverManager.getConnection("位置", "用户名", "密码")
     Statement sta = conn.createStatement();
     ```
  
  3. ```java
     PreparedStatement pst = conn.prepareStatement(sql);
     
     select * from T_user where username='"+username+"' and password =  ’”+password“‘
     ```
   ```
  
4. 使用预定义语句解决3中的漏洞
  
     ```java
     select *from t_user where username=? and password = ?
     现用？ 占位
     pst.setString(索引号，值) ；索引号从一
     pst.setString（索引号，值）；
   ```

  5. 执行sql语句

### MVC三层架构

* mvc三层架构
  * M--model模型层（服务层service（接口、实现类）、数据库操作层dao（接口、实现类）（hibernate、Mybatis））
  * V--view视图层，展示的jsp，html
  * C--Control控制层，处理发送的请求
  * spring，依赖注入
* 同一个类中不同方法相互调用，直接写方法名
  * 如果某个方法使用static修饰的，那么调用的其他方法或属性也必须用static修饰
  * static：
    * 修饰的属性：全局共享
    * 修饰方法：那么调用的本类中其他方法或属性也必须用static修饰
    * static修饰的属性和方法，可以不用实例化类的对象，就可以使用类名、属性或方法
    * 修饰静态块：初始化赋值
  * final：
    * 类：修饰的类不能被继承
    * 属性：无法修改值
    * 方法：不能被重写
  * 框架多看别人怎么写

### C/S B/S

* 界面美观，兼容性要求高
* 维护成本低，界面图片有要求
* 项目运行环境、中间件
* Tomcat基于容器
* 发布到webapps,或者conf配置xml文件。.apche
* http://localhost:8080/student
* 视图用jsp（页面）发送请求
  * 超链接<a href="请求路径"></a>
  * 表单<form action="请求" method=""></form> 数据交互到数据库
    * method:
    * post: 数据量大
    * get: 修改地址栏中的内容
    * 容器中找相匹配的地址
    * 基于配置文件的，基于注解的
    * web.xml中进行配置
    * 找到对应的类，方法处理中去操作dao的方法
    * servlet成对出现的

* 甲骨文724