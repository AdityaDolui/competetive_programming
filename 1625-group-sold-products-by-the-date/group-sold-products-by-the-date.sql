# Write your MySQL query statement below
select sell_date , count(Distinct product ) as num_sold ,
group_concat(Distinct product  order by product) as products

from Activities 
group by sell_date  