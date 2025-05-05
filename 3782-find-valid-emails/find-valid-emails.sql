# Write your MySQL query statement below
SELECT user_id, email
FROM Users
WHERE 
    email REGEXP '^[a-z0-9_]+@[a-z]+\\.com'