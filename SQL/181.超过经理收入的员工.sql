--
-- @lc app=leetcode.cn id=181 lang=mysql
--
-- [181] 超过经理收入的员工
--
-- @lc code=start
# Write your MySQL query statement below
select a.Name as Employee
from Employee a
    left join Employee b on a.ManagerId = b.Id
where a.Salary > b.Salary
    and a.ManagerId is not null;
-- @lc code=end