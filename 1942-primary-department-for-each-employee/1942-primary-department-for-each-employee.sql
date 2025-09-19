SELECT employee_id,
       department_id
FROM Employee
/*WHERE Email IN (
    SELECT Email
    FROM Person
    GROUP BY Email
    HAVING COUNT(Email) > 1
)*/
GROUP BY employee_id
HAVING COUNT(employee_id) = 1
UNION
SELECT employee_id,
       department_id
FROM Employee
WHERE primary_flag = 'Y'