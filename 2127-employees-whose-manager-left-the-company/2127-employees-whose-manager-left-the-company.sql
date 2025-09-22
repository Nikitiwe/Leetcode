SELECT t1.employee_id
FROM Employees AS t1 #JOIN Employee AS t2 ON t1.id = t2.managerId
WHERE t1.salary < 30000 AND t1.manager_id NOT IN (
    SELECT t2.employee_id
    FROM Employees AS t2
)
#GROUP BY t1.id
#HAVING COUNT(DISTINCT t2.id) >= 5
ORDER BY t1.employee_id ASC