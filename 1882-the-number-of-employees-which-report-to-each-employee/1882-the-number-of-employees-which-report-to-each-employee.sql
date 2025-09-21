SELECT employee_id,
       name,
       (
        SELECT COUNT(*)
        FROM Employees AS t2
        WHERE t2.reports_to = t1.employee_id
       ) AS reports_count,
       (
        SELECT ROUND(AVG(age), 0)
        FROM Employees AS t3
        WHERE t3.reports_to = t1.employee_id
       ) AS average_age
FROM Employees AS t1
WHERE employee_id IN (
    SELECT reports_to
    FROM Employees
)
ORDER BY employee_id ASC