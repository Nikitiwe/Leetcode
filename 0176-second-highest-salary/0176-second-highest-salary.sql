SELECT MAX(salary) AS SecondHighestSalary
FROM Employee AS t1
WHERE t1.salary < (
    SELECT MAX(salary)
    FROM Employee
)