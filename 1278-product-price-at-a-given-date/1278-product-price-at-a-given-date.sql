WITH t AS
    (SELECT DISTINCT product_id
    FROM Products),
tt AS
    (SELECT product_id,
           new_price,
           change_date,
           RANK() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rn
    FROM Products
    WHERE change_date <= '2019-08-16')
SELECT product_id,
       COALESCE(new_price, 10) AS price
FROM t LEFT JOIN tt USING(product_id)
WHERE rn = 1 OR rn IS NULL