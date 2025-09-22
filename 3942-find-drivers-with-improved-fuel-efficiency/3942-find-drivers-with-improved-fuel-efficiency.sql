WITH eff AS (
    SELECT driver_id,
           SUM(IF(MONTH(trip_date) <= 6, distance_km/fuel_consumed, 0)) / SUM(IF(MONTH(trip_date) <= 6, 1, 0)) AS first_half,
           SUM(IF(MONTH(trip_date) > 6, distance_km/fuel_consumed, 0)) / SUM(IF(MONTH(trip_date) > 6, 1, 0)) AS second_half
    FROM drivers JOIN trips USING(driver_id)
    GROUP BY driver_id
    )
SELECT driver_id,
       driver_name,
       ROUND(first_half, 2) AS first_half_avg,
       ROUND(second_half, 2) AS second_half_avg,
       ROUND(t2.second_half - t2.first_half, 2) AS efficiency_improvement
FROM drivers AS t1 JOIN eff AS t2 USING(driver_id)
GROUP BY t1.driver_id
HAVING first_half_avg > 0 AND second_half_avg > 0 AND efficiency_improvement > 0
ORDER BY efficiency_improvement DESC, driver_name ASC