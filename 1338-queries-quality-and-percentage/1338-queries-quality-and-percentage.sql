SELECT query_name,
       ROUND(AVG((1.0*rating/position)), 2) AS quality,
       ROUND(100.0*(
        SELECT COUNT(*)
        FROM Queries AS t2
        WHERE t2.rating < 3 AND t2.query_name = t1.query_name
        ) / (
            SELECT COUNT(*)
            FROM Queries AS t3
            WHERE t3.query_name = t1.query_name
            ), 2) AS poor_query_percentage
FROM Queries AS t1 #JOIN inventory AS t2 USING(store_id)
GROUP BY query_name
#HAVING
#ORDER BY imbalance_ratio DESC, store_name ASC