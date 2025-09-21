SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance AS t1 #JOIN inventory AS t2 USING(store_id)
WHERE t1.tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance AS t2
    WHERE t2.pid != t1.pid
) AND CONCAT(t1.lat,',',t1.lon) NOT IN (
    SELECT CONCAT(t3.lat,',',t3.lon)
    FROM Insurance AS t3
    WHERE t3.pid != t1.pid
)
#GROUP BY store_id
#HAVING
#ORDER BY imbalance_ratio DESC, store_name ASC