SELECT t1.name
FROM Employee AS t1 JOIN Employee AS t2 ON t1.id = t2.managerId
GROUP BY t1.id
HAVING COUNT(DISTINCT t2.id) >= 5
#ORDER BY imbalance_ratio DESC, store_name ASC