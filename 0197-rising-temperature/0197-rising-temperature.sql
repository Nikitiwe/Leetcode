SELECT id
FROM Weather AS t1
WHERE temperature > (
    SELECT temperature
    FROM Weather AS t2
    WHERE DATEDIFF(t2.recordDate, t1.recordDate) = -1
)
ORDER BY id ASC