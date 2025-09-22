SELECT product_id,
       product_name
FROM Product AS t1 JOIN Sales AS t2 USING(product_id)
GROUP BY 1
HAVING SUM(IF(sale_date >= '2019-01-01' AND sale_date <= '2019-03-31', 1, 0)) > 0 AND
       SUM(IF(sale_date < '2019-01-01' OR sale_date > '2019-03-31', 1, 0)) = 0
#ORDER BY student_id ASC, subject ASC