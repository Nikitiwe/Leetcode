SELECT (
        CASE
        WHEN (t.id % 2 = 0)
        THEN t.id - 1
        WHEN (t.id < (SELECT MAX(id) FROM Seat))
        THEN t.id + 1
        ELSE t.id
        END
       ) AS id,
       student
FROM Seat AS t
ORDER BY id