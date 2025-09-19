SELECT name AS Employee
FROM Employee AS t1
WHERE t1.salary > (
    SELECT salary
    FROM Employee AS t2
    WHERE t2.id = t1.managerId
)