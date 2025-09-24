SELECT request_at AS Day,
       ROUND(SUM(IF(t1.status != 'completed', 1, 0)) / SUM(IF(TRUE, 1, 0)), 2) AS 'Cancellation Rate'
FROM Trips AS t1 JOIN Users AS t2 ON t1.client_id = t2.users_id JOIN Users AS t3 ON t1.driver_id = t3.users_id
WHERE t2.banned = 'No' AND t3.banned = 'No' AND request_at >= '2013-10-01' AND  request_at <= '2013-10-03'
GROUP BY 1
#HAVING SUM(IF(t1.status = 'completed', 1, 0)) > 0