SELECT DISTINCT t1.num AS ConsecutiveNums
FROM Logs AS t1 JOIN Logs AS t2 ON t1.id = t2.id - 1 JOIN Logs AS t3 ON t1.id = t3.id + 1
WHERE t1.num = t2.num AND t1.num = t3.num
#GROUP BY 1
#HAVING SUM(IF(sale_date >= '2019-01-01' AND sale_date <= '2019-03-31', 1, 0)) > 0 AND
#ORDER BY student_id ASC, subject ASC