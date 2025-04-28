# Write your MySQL query statement below
select p.lastName , p.firstName , A.city ,A.state from Person p left join Address A on p.personId=A.personId 