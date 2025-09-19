SELECT name AS Customers
FROM Customers AS t1 LEFT JOIN Orders AS t2 ON t2.customerId = t1.id
GROUP BY t1.id
HAVING COUNT(t2.id) = 0