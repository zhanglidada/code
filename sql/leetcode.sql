595.sql

create table World(
  name        varchar(100),
  continent   varchar(100),
  area        int,
  population  int,
  gdp         int  
);

select name, area, population from World
  where area >= 3000000  or population >= 25000000;

1757.sql

select product_id from Products
  where low_fats = 'Y' and recyclable = 'Y';

584.sql
select name from customer where referee_id != 2 or referee_id is null;

183.sql
-- 因为最终搜索到的客户名均为Customers表中的客户名，所以结果需要从customer表中进行查找

select Customers.Name as 'Customers' from Customers 
  where Customers.Id not in (
    select CustomerId from Orders
  );


1873.sql
/*******************************************************************************************
 * Purpose:
 * 写出一个SQL 查询语句，计算每个雇员的奖金
 * 如果一个雇员的id是奇数并且他的名字不是以'M'开头，那么他的奖金是他工资的100%，否则奖金为0。
 * Notes:
 * 返回的结果集请按照employee_id排序。
 * 使用case when 处理
 * rlike用于进行正则匹配
 * 也可以用if函数处理
********************************************************************************************/
select employee_id,
  case when
    mod(employee_id, 2) = 1 and name not rlike '^M' 
    then 
      salary
    else
      0
    end as bonus
  from
    Employees
  order by
    employee_id;

-- 使用if，并且内部使用三元组
select
  employee_id,
  if (mod(employee_id, 2) = 1 and left(name, 1) != 'M', salary, 0) as bonus
  from Employees
  order by
    employee_id;


627.sql 
/*******************************************************************************************
 * Purpose:
 * 请你编写一个 SQL 查询来交换所有的 'f' 和 'm' （即，将所有 'f' 变为 'm' ，反之亦然），
 * 仅使用单个 update 语句 ，且不产生中间临时表。
 * Notes:
 * 注意，仅能使用一条 update 语句，且 不能 使用 select 语句
********************************************************************************************/
update salary
  set
    sex = 
    case sex
      when 'm' then 'f'
      else 'm'
    end;


196.sql
/*******************************************************************************************
 * Purpose:
 * 编写一个SQL查询来删除所有重复的电子邮件，只保留一个id最小的唯一电子邮件。
 * Notes:
 * 以 任意顺序 返回结果表。
********************************************************************************************/

--1. 将表与自身相连
select p1.*
  from Person p1, Person p2
  where p1.Email = p2.Email;

--2. 找到其他记录中具有相同电子邮件地址的更大ID
select p1.*
  from Person p1, Person p2
  where p1.Email = p2.Email and p1.Id > p2.Id;

--3. 得到已经要删除的记录，将最终语句更改为delete
DELETE p1
  FROM Person p1, Person p2
  WHERE
    p1.Email = p2.Email AND p1.Id > p2.Id;


1667.sql
/*******************************************************************************************
 * Purpose:
 * 编写一个 SQL 查询来修复名字，使得只有第一个字符是大写的，其余都是小写的。
 * Notes:
 * 返回按 user_id 排序的结果表。
********************************************************************************************/
select user_id, 
    concat(Upper(left(name, 1)), Lower(substring(name, 2))) name
    from Users
    order by user_id;



1484.sql
/*******************************************************************************************
 * Purpose:
 * 编写一个 SQL 查询来查找每个日期、销售的不同产品的数量及其名称。
 * Notes:
 * 1.每个日期的销售产品名称应按词典序排列。
 * 2.返回按 sell_date 排序的结果表。
 * 3.group_concat函数将按组分类的 非空查询结果字符串 进行连接
********************************************************************************************/
select sell_date, 
  count(distinct product) as num_sold,
  group_concat(distinct product) as products 
  from Activities
  group by sell_date
  order by sell_date;


1527.sql
/*******************************************************************************************
 * Purpose:
 * 查询患有 I 类糖尿病的患者 ID，患者姓名以及其患有的所有疾病代码
 * Notes:
 * 1.返回结果的顺序任意
 * 2. \s 在正则表达式中表示一个空格字符，制表符或者其他空白字符
********************************************************************************************/
select patient_id, patient_name, conditions
  from Patients
  where conditions rlike '^DIAB1|.*\\sDIAB1';


1965.sql
/*******************************************************************************************
 * Purpose:
 * 查询丢失信息的雇员：
 * 1.雇员姓名丢失
 * 2.雇员薪水信息丢失
 * Notes:
 * 选出两个表中不一致的id即可
 * union可以将两个select语句的结果集作为一个整体显示，且自动压缩结果集中重复的结果
 * union all则不压缩
********************************************************************************************/
-- 雇员的姓名或者薪水信息丢失，都会导致employee_id在employees和salaries的并集表里面仅出现一次
select employee_id
  from (
    select employee_id from employees
    union all
    select employee_id from salaries
  ) as t
  group by 
    employee_id
  having 
    count(employee_id) = 1
  order by 
    employee_id;


1795.sql
/*******************************************************************************************
 * Purpose:
 * 重构 Products 表，查询每个产品在不同商店的价格，使得输出的格式变为(product_id, store, price)
 * 如果这一产品在商店里没有出售，则不输出这一行。
********************************************************************************************/
select product_id, 'store1' store, store1 as price
    from Products where store1 is not NULL
    union all
select product_id, 'store2' store, store2 as price
    from Products where store2 is not NULL
    union all
select product_id, 'store3' store, store3 as price
    from Products where store3 is not NULL;


608.sql
/*******************************************************************************************
 * Purpose:
 * 给定一个表 tree，id 是树节点的编号， p_id 是它父节点的 id 。
 * Notes:
 * 输出所有节点的编号和节点类型，并将结果按照节点编号排序
********************************************************************************************/

/************************* 使用case when 条件判断语句 *********************/
select id,
  case
    -- root节点只有一个
    when tree.id = (select t.id from tree as t where t.p_id is NULL)
      then 'Root'
    -- 当前节点也为其它节点的父节点
    when tree.id in (select t.p_id from tree as t where t.p_id is not NULL)
      then 'Inner'
    else
      'Leaf'
  end as 'Type'
  from tree
  order by id;

/************************* 使用if函数 *********************/
select
  atree.id,
  -- if 函数的使用类似于一个三元组
  if(ISNULL(atree.p_id), 'Root',
    if(atree.id in (select p_id from tree), 'Inner','Leaf')) Type
  from
  tree atree
order by atree.id;

/************************* 最简单的union *********************/
-- 首先查找root节点，只有子节点
select t.id, 'Root' as Type
  from tree as t where t.p_id is NULL
  union
-- 其次查找inner节点，有父节点且为其他节点的父节点
select t.id, 'Inner' as Type
  from tree as t where t.id in (
    select p_id from tree where p_id is not null
  )
  and t.p_id is not null
  union
-- 最后查找leaf，只有父节点且无子节点
select t.id, 'Leaf' as Type
  from tree as t where t.id not in (
    select p_id from tree where p_id is not null
  )
  and t.p_id is not NULL;



176.sql
/*******************************************************************************************
 * Purpose:
 * 查询employee表中第二高的薪水，不存在则返回null
 * Notes:
 * 使用了mysql中的limit函数，指定查询结果从哪条记录开始，一共显示几条记录
 *
 * 注意：查询记录中id下标从1开始
 *
 * 三种用法：
   1. “LIMIT 初始位置，记录数”  ： 第一条记录位置为0
   2. “LIMIT 记录数”  ：从第一条记录开始显示
   3. “LIMIT 记录数 OFFSET 初始位置”  ： limit结合offset使用，从offset位置的记录开始查询指定个数的记录
********************************************************************************************/
select
  -- 将查询结果作为一个临时表，防止不存在第二高薪水问题
  (select
    distinct salary
    from Employee
    -- desc 用于降序排列
    order by Salary desc
    limit 1,1)
  as SecondHighestSalary;

-- 方法2，使用ifnull 以及limit子句结合
select
  -- 判断字段是否为空并给予赋值
  ifnull(
    (select
      distinct salary
      from Employee
      order by Salary desc
      limit 1,1),
    NULL)
as SecondHighestSalary;


175.sql

1581.sql

1148.sql

197.sql

607.sql

1141.sql

1693.sql

1729.sql

586.sql

511.sql

1890.sql

1741.sql

1393.sql

1407.sql

1158.sql

182.sql

1050.sql

1587.sql

1084.sql