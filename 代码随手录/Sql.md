# 1.��������
## 1.1 �� Customers ���м������е� ID

**��Ŀ:** 
_<u>����:</u>
���б�Customers���£�
cust_id
A
B
C_

_<u>����:</u>
**����д SQL ��䣬�� Customers ���м������е�cust_id��**_


**ʵ����**

```
���룺
DROP TABLE IF EXISTS `Customers`;

CREATE TABLE IF NOT EXISTS `Customers`(
    cust_id VARCHAR(255) DEFAULT NULL
);
INSERT `Customers` VALUES ('A'),('B'),('C');

���:
A
B
C
```

**���룺**
```
select cust_id from Customers;
```

## 1.2 �������г��Ѷ�����Ʒ���嵥
**��Ŀ:**
_<u>����:</u>
��OrderItems���зǿյ���prod_id������Ʒid�������������Ѷ�������Ʒ����Щ�ѱ�������Σ���
prod_id
a1
a2
a3
a4
a5
a6
a7_

_<u>����:</u>
**��дSQL ��䣬�������г������Ѷ�����Ʒ��prod_id����ȥ�غ���嵥��**_

**ʵ��:**
```
���룺
DROP TABLE IF EXISTS `OrderItems`;
CREATE TABLE IF NOT EXISTS `OrderItems`(
	prod_id VARCHAR(255) NOT NULL COMMENT '��Ʒid'
);
INSERT `OrderItems` VALUES ('a1'),('a2'),('a3'),('a4'),('a5'),('a6'),('a6')

�����
a1
a2
a3
a4
a5
a6
```

**����:**
```
select DISTINCT(prod_id) from OrderItems;

�ʼǣ�DISTINCT()������������������е��ظ��С�
```

## 1.3 ����������
**��Ŀ:**
_<u>����:</u>
������Customers �����к�����cust_id����ͻ�id��cust_name����ͻ�������
cust_id  cust_name
a1        andy
a2	      ben
a3	      tony
a4	      tom
a5        an
a6        lee
a7        hex_

_<u>����:</u>
**��Ҫ��д SQL��䣬���������С�**_

_<u>ʵ�����:</u>
����������cust_id��cust_name��
cust_id    cust_name
a1          andy
a2	        ben
a3	        tony
a4	        tom
a5          an
a6          lee
a7	        hex_


**ʵ��:**
```
���룺
DROP TABLE IF EXISTS `Customers`;
CREATE TABLE IF NOT EXISTS `Customers`(
	cust_id VARCHAR(255) NOT NULL COMMENT '�ͻ�id',
	cust_name VARCHAR(255) NOT NULL COMMENT '�ͻ�����'
);
INSERT `Customers` VALUES ('a1','andy'),('a2','ben'),('a3','tony'),('a4','tom'),('a5','an'),('a6','lee'),('a7','hex');

�����
a1|andy
a2|ben
a3|tony
a4|tom
a5|an
a6|lee
a7|hex
```

**����:**
```
select * from Customers;
```

# 2.�����������
## 2.1 �����˿����Ʋ�������
**��Ŀ:**
_<u>����:</u>
�б�Customers��cust_id����ͻ�id��cust_name����ͻ�������
cust_id     cust_name
a1          andy
a2	        ben
a3	        tony
a4	        tom
a5          an
a6          lee
a7	        hex_

_<u>����:</u>
**�� Customers �м������еĹ˿����ƣ�cust_name���������� Z �� A ��˳����ʾ�����**_

_<u>ʵ�����:</u>
���ؿͻ�����cust_name
cust_name
tony
tom
lee
hex
ben
andy
an_


**ʵ��:**
```
���룺
DROP TABLE IF EXISTS `Customers`;
CREATE TABLE IF NOT EXISTS `Customers`(
	cust_id VARCHAR(255) NOT NULL COMMENT '�ͻ�id',
	cust_name VARCHAR(255) NOT NULL COMMENT '�ͻ�����'
);
INSERT `Customers` VALUES ('a1','andy'),('a2','ben'),('a3','tony'),('a4','tom'),('a5','an'),('a6','lee'),('a7','hex');

�����
cust_name
tony
tom
lee
hex
ben
andy
an
```

**����:**
```
select cust_name from Customers order by cust_name desc;

�ʼǣ�order by �����ֶΣ�order byĬ�ϲ�������asc����������� where �Ӿ䣬��ô order by ����ŵ� where ѯ����档
```
