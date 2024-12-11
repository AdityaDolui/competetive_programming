# Write your MySQL query statement below

 Select Distinct MAX(salary) as SecondHighestSalary from Employee where salary < (Select max(salary) from employee)
-- SELECT 
--     IFNULL(
-- 			(SELECT 
-- 				DISTINCT a.salary
-- 			FROM Employee a
-- 			WHERE 1 = (SELECT 
--                             COUNT(DISTINCT b.salary)
--                         FROM employee b
--                         WHERE b.salary > a.salary)
-- 			),
-- 		NULL
-- 	) AS SecondHighestSalary