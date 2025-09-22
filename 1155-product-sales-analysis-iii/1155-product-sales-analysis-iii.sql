WITH t2 AS (
    SELECT product_id,
           MIN(year) AS min_year
    FROM Sales
    GROUP BY product_id
)
SELECT product_id,
       t1.year AS first_year,
       quantity,
       price
FROM Sales AS t1 JOIN t2 USING(product_id)
WHERE t1.year = t2.min_year