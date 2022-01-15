--
-- @lc app=leetcode.cn id=182 lang=mysql
--
-- [182] 查找重复的电子邮箱
--
-- @lc code=start
# Write your MySQL query statement below
select email.Email
from (
        select if(count(*) > 1, Email, null) as Email
        from Person
        group by Email
    ) as email
where email.Email is not null;
-- @lc code=end