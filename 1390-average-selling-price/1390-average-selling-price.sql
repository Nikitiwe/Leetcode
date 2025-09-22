/*WITH t0 AS (
    SELECT product_id,
           price,
           units
    FROM Prices AS t1 LEFT JOIN UnitsSold AS t2 USING(product_id)
    WHERE t2.purchase_date >= t1.start_date AND t2.purchase_date <= t1.end_date
)
SELECT product_id,
       COALESCE(ROUND(SUM(price*units) / IF(SUM(units) != 0, SUM(units), 1), 2), 0) AS average_price
FROM t0
#WHERE conditions LIKE 'DIAB1%' OR conditions LIKE '% DIAB1%'
GROUP BY 1
#ORDER BY product_id ASC
*/
WITH t0 AS (
    SELECT p.product_id,
           p.price,
           us.units
    FROM Prices p
    LEFT JOIN UnitsSold us
      ON p.product_id = us.product_id
     AND us.purchase_date BETWEEN p.start_date AND p.end_date
)
SELECT product_id,
       COALESCE(ROUND(SUM(price * units) / SUM(units), 2), 0) AS average_price
FROM t0
GROUP BY product_id
ORDER BY product_id;