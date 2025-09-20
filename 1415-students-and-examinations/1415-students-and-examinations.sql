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
SELECT student_id,
       student_name,
       t2.subject_name,
       SUM(IF(t3.student_id = t1.student_id AND t3.subject_name = t2.subject_name, 1, 0)) AS attended_exams #, ROUND(1.0*SUM(IF(action = 'confirmed', 1, 0))/COUNT(*), 2) AS confirmation_rate
FROM Students AS t1 CROSS JOIN Subjects AS t2 LEFT JOIN Examinations AS t3 USING(student_id)
GROUP BY 1, 2, 3
/*HAVING SUM(IF(transaction_type = 'purchase', 1, 0)) >= 3 AND
       DATEDIFF(MAX(transaction_date), MIN(transaction_date)) >= 30 AND
       (1.0*SUM(IF(transaction_type = 'refund', 1, 0))/COUNT(*)) < 2.0/10*/
ORDER BY student_id ASC, t2.subject_name;