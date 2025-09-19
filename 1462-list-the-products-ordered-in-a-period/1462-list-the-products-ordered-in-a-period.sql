SELECT product_name,
       SUM(t2.unit) AS unit
FROM Products AS t1 JOIN Orders AS t2 USING(product_id)
WHERE MONTH(order_date) = 2 AND YEAR(order_date) = 2020
GROUP BY product_id
HAVING unit >= 100