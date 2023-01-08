#编写一个 SQL 查询，查找 Person 表中所有重复的电子邮箱。 
#
# 示例： 
#
# +----+---------+
#| Id | Email   |
#+----+---------+
#| 1  | a@b.com |
#| 2  | c@d.com |
#| 3  | a@b.com |
#+----+---------+
# 
#
# 根据以上输入，你的查询应返回以下结果： 
#
# +---------+
#| Email   |
#+---------+
#| a@b.com |
#+---------+
# 
#
# 说明：所有电子邮箱都是小写字母。 
#
# Related Topics 数据库 👍 415 👎 0


#leetcode submit region begin(Prohibit modification and deletion)
# Write your MySQL query statement below
select email.Email
from (
         select if(count(*) > 1, Email, null) as Email
         from Person
         group by Email
     ) as email
where email.Email is not null;
#leetcode submit region end(Prohibit modification and deletion)
