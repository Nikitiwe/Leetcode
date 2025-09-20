/*WITH categorized_sales AS (
    SELECT CASE WHEN MONTH(sale_date) IN (1, 2, 12) THEN 'Winter'
                WHEN MONTH(sale_date) IN (3, 4, 5) THEN 'Spring'
                WHEN MONTH(sale_date) IN (6, 7, 8) THEN 'Summer'
                WHEN MONTH(sale_date) IN (9, 10, 11) THEN 'Fall' END AS season,
        category,
        SUM(quantity) AS total_quantity,
        SUM(quantity * price) AS total_revenue
    FROM sales AS t1 LEFT JOIN products AS t2 USING(product_id)
    GROUP BY 1, 2
)*/
SELECT user_id, ROUND(1.0*SUM(IF(action = 'confirmed', 1, 0))/COUNT(*), 2) AS confirmation_rate
FROM Signups LEFT JOIN Confirmations AS t2 USING(user_id)
GROUP BY 1
#ORDER BY season;