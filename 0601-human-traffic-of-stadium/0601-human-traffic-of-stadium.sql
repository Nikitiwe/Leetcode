SELECT id, visit_date, people
FROM(
    SELECT t1.id AS id,
        t1.visit_date AS visit_date,
        t1.people AS people
    FROM Stadium AS t1 JOIN Stadium AS t2 ON t1.id = t2.id + 1 JOIN Stadium AS t3 ON t1.id = t3.id + 2
    WHERE t1.people >= 100 AND t2.people >= 100 AND t3.people >= 100
    UNION
    SELECT t1.id AS id,
        t1.visit_date AS visit_date,
        t1.people AS people
    FROM Stadium AS t1 JOIN Stadium AS t2 ON t1.id = t2.id + 1 JOIN Stadium AS t3 ON t1.id = t3.id - 1
    WHERE t1.people >= 100 AND t2.people >= 100 AND t3.people >= 100
    UNION
    SELECT t1.id AS id,
        t1.visit_date AS visit_date,
        t1.people AS people
    FROM Stadium AS t1 JOIN Stadium AS t2 ON t1.id = t2.id - 1 JOIN Stadium AS t3 ON t1.id = t3.id - 2
    WHERE t1.people >= 100 AND t2.people >= 100 AND t3.people >= 100
) AS t0
ORDER BY id ASC