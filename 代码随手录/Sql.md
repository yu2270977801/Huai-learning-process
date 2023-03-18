# 1.检索数据
## 1.1 从 Customers 表中检索所有的 ID

**题目:** 
_<u>描述:</u>
现有表Customers如下：
cust_id
A
B
C_

_<u>问题:</u>
**给编写 SQL 语句，从 Customers 表中检索所有的cust_id。**_


**实例：**

```
输入：
DROP TABLE IF EXISTS `Customers`;

CREATE TABLE IF NOT EXISTS `Customers`(
    cust_id VARCHAR(255) DEFAULT NULL
);
INSERT `Customers` VALUES ('A'),('B'),('C');

输出:
A
B
C
```

**代码：**
```
select cust_id from Customers;
```

## 1.2 检索并列出已订购产品的清单
**题目:**
_<u>描述:</u>
表OrderItems含有非空的列prod_id代表商品id，包含了所有已订购的商品（有些已被订购多次）。
prod_id
a1
a2
a3
a4
a5
a6
a7_

_<u>问题:</u>
**编写SQL 语句，检索并列出所有已订购商品（prod_id）的去重后的清单。**_

**实例:**
```
输入：
DROP TABLE IF EXISTS `OrderItems`;
CREATE TABLE IF NOT EXISTS `OrderItems`(
	prod_id VARCHAR(255) NOT NULL COMMENT '商品id'
);
INSERT `OrderItems` VALUES ('a1'),('a2'),('a3'),('a4'),('a5'),('a6'),('a6')

输出：
a1
a2
a3
a4
a5
a6
```

**代码:**
```
select DISTINCT(prod_id) from OrderItems;

笔记：DISTINCT()的作用是消除结果集中的重复行。
```

## 1.3 检索所有行
**题目:**
_<u>描述:</u>
现在有Customers 表（表中含有列cust_id代表客户id，cust_name代表客户姓名）
cust_id  cust_name
a1        andy
a2	      ben
a3	      tony
a4	      tom
a5        an
a6        lee
a7        hex_

_<u>问题:</u>
**需要编写 SQL语句，检索所有列。**_

_<u>实例结果:</u>
返回所有列cust_id和cust_name。
cust_id    cust_name
a1          andy
a2	        ben
a3	        tony
a4	        tom
a5          an
a6          lee
a7	        hex_


**实例:**
```
输入：
DROP TABLE IF EXISTS `Customers`;
CREATE TABLE IF NOT EXISTS `Customers`(
	cust_id VARCHAR(255) NOT NULL COMMENT '客户id',
	cust_name VARCHAR(255) NOT NULL COMMENT '客户姓名'
);
INSERT `Customers` VALUES ('a1','andy'),('a2','ben'),('a3','tony'),('a4','tom'),('a5','an'),('a6','lee'),('a7','hex');

输出：
a1|andy
a2|ben
a3|tony
a4|tom
a5|an
a6|lee
a7|hex
```

**代码:**
```
select * from Customers;
```

# 2.排序检索数据
## 2.1 检索顾客名称并且排序
**题目:**
_<u>描述:</u>
有表Customers，cust_id代表客户id，cust_name代表客户姓名。
cust_id     cust_name
a1          andy
a2	        ben
a3	        tony
a4	        tom
a5          an
a6          lee
a7	        hex_

_<u>问题:</u>
**从 Customers 中检索所有的顾客名称（cust_name），并按从 Z 到 A 的顺序显示结果。**_

_<u>实例结果:</u>
返回客户姓名cust_name
cust_name
tony
tom
lee
hex
ben
andy
an_


**实例:**
```
输入：
DROP TABLE IF EXISTS `Customers`;
CREATE TABLE IF NOT EXISTS `Customers`(
	cust_id VARCHAR(255) NOT NULL COMMENT '客户id',
	cust_name VARCHAR(255) NOT NULL COMMENT '客户姓名'
);
INSERT `Customers` VALUES ('a1','andy'),('a2','ben'),('a3','tony'),('a4','tom'),('a5','an'),('a6','lee'),('a7','hex');

输出：
cust_name
tony
tom
lee
hex
ben
andy
an
```

**代码:**
```
select cust_name from Customers order by cust_name desc;

笔记：order by 排序字段，order by默认采用升序（asc），如果存在 where 子句，那么 order by 必须放到 where 询句后面。
```
