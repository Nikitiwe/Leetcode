SELECT customer_id
FROM Customer AS t1 LEFT JOIN Product USING(product_key)
#WHERE p1.category < p2.category
GROUP BY 1
HAVING COUNT(DISTINCT product_key) = (
    SELECT COUNT(product_key)
    FROM Product
)
#ORDER BY COUNT(order_number) DESC
#LIMIT 1