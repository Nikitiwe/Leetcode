SELECT class
FROM Courses AS t1
#WHERE p1.product_id < p2.product_id
GROUP BY 1
HAVING COUNT(student) >= 5
#ORDER BY customer_count DESC, product1_id ASC, product2_id ASC
