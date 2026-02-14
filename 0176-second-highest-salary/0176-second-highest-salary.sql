# Write your MySQL query statement below
-- SELECT salary AS SecondHighestSalary FROM Employee 
-- ORDER BY salary DESC
-- LIMIT 1, 1;

SELECT MAX(salary) AS SecondHighestSalary FROM Employee
WHERE salary < (SELECT MAX(salary) FROM Employee);