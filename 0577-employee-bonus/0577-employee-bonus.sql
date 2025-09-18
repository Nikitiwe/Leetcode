SELECT name,
       bonus
FROM Employee LEFT JOIN Bonus USING(empId)
GROUP BY empId
HAVING bonus < 1000 OR bonus IS NULL