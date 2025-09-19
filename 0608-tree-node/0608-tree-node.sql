SELECT id,
       (
        CASE
            WHEN (t1.p_id IS NULL)
            THEN 'Root'
            WHEN ( 0 = (
                SELECT COUNT(*)
                FROM Tree AS t2
                WHERE t2.p_id = t1.id
            ))
            THEN 'Leaf'
            ELSE 'Inner'
        END
       ) AS type
FROM Tree AS t1