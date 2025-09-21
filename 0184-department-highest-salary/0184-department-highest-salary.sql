SELECT Department.name AS Department,
       t1.name AS Employee,
       salary AS Salary
FROM Employee AS t1 LEFT JOIN Department ON t1.departmentId = Department.id
WHERE salary = (
    SELECT MAX(salary)
    FROM Employee AS t2
    WHERE t1.departmentId = t2.departmentId
    GROUP BY t2.departmentId
) #AS t