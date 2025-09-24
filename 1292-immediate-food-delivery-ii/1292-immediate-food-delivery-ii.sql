WITH t0 AS (
    SELECT delivery_id,
           customer_id,
           order_date,
           customer_pref_delivery_date
    FROM Delivery AS t1
    WHERE t1.order_date = (SELECT MIN(order_date) FROM Delivery AS t2 WHERE t1.customer_id = t2.customer_id)
)
SELECT ROUND(100.0*SUM(IF(order_date = customer_pref_delivery_date, 1, 0)) / COUNT(*), 2) AS immediate_percentage
FROM t0
#GROUP BY 