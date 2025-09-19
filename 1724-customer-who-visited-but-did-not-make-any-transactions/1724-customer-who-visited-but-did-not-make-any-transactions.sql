SELECT *
FROM (
    SELECT customer_id, SUM(IF(t3.amount = 0, 1, 0)) AS count_no_trans
    FROM (
        SELECT customer_id, SUM(IF(amount IS NULL, 0, amount)) AS amount, visit_id
        FROM Visits AS t1 LEFT JOIN Transactions AS t2 USING(visit_id)
        GROUP BY 1, 3
    ) AS t3
    GROUP BY customer_id
) AS tt
WHERE count_no_trans != 0
#ORDER BY transaction_date ASC