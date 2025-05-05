# Write your MySQL query statement below
select id,
case
    when id%2=0 then LAG(student) over (ORDER by id)
    ELSE coalesce(LEAD(student) over (ORDER by id),student) 
    END as student

from seat