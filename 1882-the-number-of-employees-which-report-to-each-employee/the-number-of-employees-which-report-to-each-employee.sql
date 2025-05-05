# Write your MySQL query statement below
select mgr.employee_id , mgr.name, count(emp.reports_to ) as reports_count, Round(avg(emp.age)) as average_age 
from Employees emp join Employees mgr
on emp.reports_to =mgr.employee_id 
group by employee_id
order by employee_id