# Write your MySQL query statement below
SELECT email
FROM Person
GROUP BY email 
Having Count(email)>1;