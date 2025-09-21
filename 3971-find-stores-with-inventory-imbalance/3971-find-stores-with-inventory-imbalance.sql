SELECT store_id,
       store_name,
       location,
       (
        SELECT product_name
        FROM inventory AS t4
        WHERE t4.store_id = t1.store_id AND t4.price = (
            SELECT MAX(price)
            FROM inventory AS t10
            WHERE t10.store_id = t1.store_id
        )
       ) AS most_exp_product,
       (
        SELECT product_name
        FROM inventory AS t5
        WHERE t5.store_id = t1.store_id AND t5.price = (
            SELECT MIN(price)
            FROM inventory AS t11
            WHERE t11.store_id = t1.store_id
        )
       ) AS cheapest_product,
       ROUND((SELECT quantity
    FROM inventory AS t8
    WHERE t8.store_id = t1.store_id AND t8.price = (
        SELECT MIN(price)
        FROM inventory AS t9
        WHERE t9.store_id = t1.store_id
    LIMIT 1
    ))/(SELECT quantity
    FROM inventory AS t6
    WHERE t6.store_id = t1.store_id AND t6.price = (
        SELECT MAX(price)
        FROM inventory AS t7
        WHERE t7.store_id = t1.store_id
    LIMIT 1
    )), 2) AS imbalance_ratio
FROM stores AS t1 JOIN inventory AS t2 USING(store_id)
WHERE 3 <= (
    SELECT COUNT(inventory_id)
    FROM inventory AS t3
    WHERE t3.store_id = t1.store_id
)
GROUP BY store_id
HAVING (
    SELECT quantity
    FROM inventory AS t6
    WHERE t6.store_id = t1.store_id AND t6.price = (
        SELECT MAX(price)
        FROM inventory AS t7
        WHERE t7.store_id = t1.store_id
    LIMIT 1
    )
) <
(
    SELECT quantity
    FROM inventory AS t8
    WHERE t8.store_id = t1.store_id AND t8.price = (
        SELECT MIN(price)
        FROM inventory AS t9
        WHERE t9.store_id = t1.store_id
    LIMIT 1
    )
)
ORDER BY imbalance_ratio DESC, store_name ASC